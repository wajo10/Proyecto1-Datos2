#include "botones.h"
#include "tablero_cliente.h"
#include "mainwindow.h"
#include "traductorcliente.h"



botones::botones(QGraphicsItem *parent):QObject (), QGraphicsPixmapItem(parent){
   setPixmap(QPixmap(":/images/jugar.png"));

};
void botones::puntaje(int pts)
{
    label->setGeometry(750,500,700,100);
    label->setText("Puntaje:" + QString::number((pts)));
    label->QWidget::setAttribute(Qt::WA_TranslucentBackground);
    QFont font = label->font();
    font.setPointSize(30);
    font.setBold(true);
    label->setFont(font);
    MainWindow::scene->addWidget(label);
}

void botones::resumen(string res)
{
   labelR->setText("Resumen:" +QString::fromStdString(res));
   labelR->setGeometry(750,600,1000,100);
   labelR->QWidget::setAttribute(Qt::WA_TranslucentBackground);
   QFont font = labelR->font();
   font.setPointSize(10);
   font.setBold(true);
   labelR->setFont(font);
   MainWindow::scene->addWidget(labelR);
}

void botones::mousePressEvent(QGraphicsSceneMouseEvent *event)

{
    TraductorCliente* TradC=&TraductorCliente::getInstance();
    Tablero_Cliente* Tc=&Tablero_Cliente::getInstance();
    if (Ficha::flagTurno){
        string s1=Tc->ResumenFichas();
        string respuesta = Socket::getInstance().enviar(s1,Tc->getPuertoServidor(),"192.168.100.9",true);
        Tc->RecibirRespuesta(respuesta);
        if(Tc->getVal()){
            Ficha::flagTurno=false;
            puntaje(Tc->getPuntos());
            resumen(Tc->getResumen());
            Tc->limpiarJugadas();
            qDebug() << Tc->getRepo().c_str();
            if (Tc->getHayFichas()){
                MainWindow::request(Tc->getRepo());

            }
            else{
                qDebug()<< "no hay suficientes fichas en bolsa para reponer";
            }

        }
        else{
            if (Tc->getHayFichas()){
                qDebug()<< "Fichas inválidas";
            }
            else{
                qDebug()<< "Fin del juego";
            }
            Tc->RemoverFichas();
        }

    }
    //MainWindow::getInstance().cicloPartida(Tc->getTsala(),Tc->getTurno(),Tc->getPuertoServidor());
}
