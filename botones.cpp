#include "botones.h"
#include "tablero_cliente.h"
#include "mainwindow.h"
#include "traductorcliente.h"



botones::botones(QGraphicsItem *parent):QObject (), QGraphicsPixmapItem(parent){
   setPixmap(QPixmap(":/images/jugar.png"));

};
void botones::puntaje(int pts)
{
    label->setGeometry(800,600,100,100);
    label->setText("Puntaje:" + QString::number((pts)));
    label->QWidget::setAttribute(Qt::WA_TranslucentBackground);
    MainWindow::scene->addWidget(label);
}

void botones::resumen(string res)
{
   labelR->setText("Resumen:" +QString::fromStdString(res));
   labelR->setGeometry(800,500,300,100);
   labelR->QWidget::setAttribute(Qt::WA_TranslucentBackground);
   MainWindow::scene->addWidget(labelR);
}

void botones::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    puntaje(5);
    resumen("Wajo");
    //MainWindow::getInstance().resumen("A");

    MainWindow::request("qt");

    if (Ficha::flagTurno){
        TraductorCliente* TradC=&TraductorCliente::getInstance();
        Tablero_Cliente* Tc=&Tablero_Cliente::getInstance();
        string s1=Tc->ResumenFichas();
        string respuesta = Socket::getInstance().enviar(s1,Tc->getPuertoServidor(),"192.168.100.9",true);
        Tc->RecibirRespuesta(respuesta);
        if(Tc->getVal()){
            puntaje(Tc->getPuntos());
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

}
