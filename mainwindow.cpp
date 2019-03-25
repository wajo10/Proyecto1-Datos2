#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "pantalla.h"
#include "ficha.h"
#include "botones.h"
#include "bolsa.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Bolsa *bolsa = new Bolsa();
    string ptrIniciales = bolsa->fichas_turno(7);
    char array[7];


    //Crear scene
    QGraphicsScene * scene = new QGraphicsScene();


    //Crear view
    QGraphicsView * view = new QGraphicsView(scene);
    view->show();
    view-> setFixedSize(1300,700);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setSceneRect(0,0,1300,700);

    //Hud
    pantalla * Pantalla = new pantalla();
    scene->addItem(Pantalla);
    int xInicial = 807;
    //Creacion de fichas
    for (int i=0;i<7;i++){
        array[i] = ptrIniciales[i];
        Ficha * ficha = new Ficha(array[i]);
        ficha->setX(xInicial);
        ficha->setY(237);
        scene->addItem(ficha);
        xInicial+=57;
    }

    //Boton
    botones *Boton = new botones();
    Boton->setX(1000);
    Boton->setY(404);
    scene->addItem(Boton);
}

void MainWindow::on_lineEdit_editingFinished()
{

}
