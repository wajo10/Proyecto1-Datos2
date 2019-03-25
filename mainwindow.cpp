#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "pantalla.h"
#include "ficha.h"
#include "botones.h"
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

    //Primera Ficha
    Ficha * ficha = new Ficha('m');
    ficha->setX(807);
    ficha->setY(237);
    scene->addItem(ficha);

    //Segunda Ficha
    Ficha * ficha1 = new Ficha('z');
    ficha1->setX(862);
    ficha1->setY(237);
    scene->addItem(ficha1);

    //Tercera Ficha
    Ficha * ficha2 = new Ficha('a');
    ficha2->setX(920);
    ficha2->setY(237);
    scene->addItem(ficha2);

    //Boton
    botones *Boton = new botones();
    Boton->setX(1000);
    Boton->setY(404);
    scene->addItem(Boton);
}

void MainWindow::on_lineEdit_editingFinished()
{

}
