#include "botones.h"
#include "tablero_cliente.h"
#include "mainwindow.h"
#include "traductorcliente.h"
#include <QGraphicsProxyWidget>
#include "listener.h"



botones::botones(QGraphicsItem *parent):QObject (), QGraphicsPixmapItem(parent){
   setPixmap(QPixmap(":/images/jugar.png"));

};
void botones::freeWidget(QWidget* foo)
{
    const auto proxy = foo->graphicsProxyWidget();
    MainWindow::scene->removeItem(proxy);
    proxy->setWidget(nullptr);
    foo->setParent(nullptr);
    delete proxy;
}

void botones::puntaje(int pts)
{
    if (!flagPuntaje){
        freeWidget(label);
    }
    flagPuntaje=false;
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
    if (!flagResumen){
        freeWidget(labelR);
   }
   flagResumen=false;
   labelR->setText("Resumen:" +QString::fromStdString(res));
   labelR->setGeometry(750,600,1000,100);
   labelR->QWidget::setAttribute(Qt::WA_TranslucentBackground);
   QFont font = labelR->font();
   font.setPointSize(10);
   font.setBold(true);
   labelR->setFont(font);
   MainWindow::scene->addWidget(labelR);
}
void botones::cicloPartida(int tsala, int turno)
{
    Tablero_Cliente* Tc=&Tablero_Cliente::getInstance();
    qDebug()<<turno;
    if(Tc->getC() >50){
        return;
    }
    if(Tc->getC() %tsala == turno){
        Ficha::flagTurno = true;
        Tc->setC(Tc->getC()+1);
        return;
    }
    else{
       listener *l = new listener(2,tsala,turno);
    }
}
void botones::fichaAdversario(char *letra, int *fila, int *columna, int tam)
{
    int contador=0;
    char *ptrLetra=letra;
    int *ptrFila = fila;
    int *ptrColumna = columna;
    while(contador<tam){
        Ficha *fichaAdv = new Ficha(*(ptrLetra+contador));
        fichaAdv->setX((*(ptrColumna+contador)*43.65)+42);
        fichaAdv->setY((*(ptrFila+contador)*43.65)+44);
        fichaAdv->setSejugo(true);
        fichaAdv->flagMove=false;
        MainWindow::scene->addItem(fichaAdv);
        Tablero_Cliente::getInstance().ColocarFicha(fila,columna,tam);
        contador++;
    }
}
void botones::mousePressEvent(QGraphicsSceneMouseEvent *event)

{
    TraductorCliente* TradC=&TraductorCliente::getInstance();
    Tablero_Cliente* Tc=&Tablero_Cliente::getInstance();   
    if (Ficha::flagTurno){
        string s1=Tc->ResumenFichas();
        qDebug()<<s1.c_str()<<Tc->getPuertoServidor()<<"192.168.100.11"<<true<<"PUERTO SERV";
        string respuesta;
       respuesta = Socket::getInstance().enviar(s1,Tc->getPuertoServidor(),"192.168.100.11",true);
       qDebug()<<respuesta.c_str()<<"RESPUESTA2";
       if (respuesta == "1"){
           Ficha::flagTurno=false;
           cicloPartida(Tc->getTsala(),Tc->getTurno());
           qDebug()<<"RESPUESTA";
           return;
       }
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
           cicloPartida(Tc->getTsala(),Tc->getTurno());
        }
        else{
            if (Tc->getHayFichas()){
                qDebug()<< "Fichas inválidas";
                preguntarExperto *x = new preguntarExperto();
                x->show();

            }
            else{
                preguntarExperto *x = new preguntarExperto;
                x->addText("Fin del juego. Ganador:" +Tc->getRepo());
                x->show();
                qDebug()<< "Fin del juego"<<Tc->getRepo().c_str();
            }
            Tc->RemoverFichas();
        }

    }
}
