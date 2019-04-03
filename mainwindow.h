#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "pantalla.h"
#include "ficha.h"
#include "botones.h"
#include "tablero_cliente.h"
#include "traductorcliente.h"
#include "socket.h"

using namespace std;


#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static MainWindow & getInstance(){
        static MainWindow instance;
        return instance;
    }
    static void request(string s);
    explicit MainWindow(QWidget *parent = nullptr);
    static QGraphicsScene * scene;
    static void fichaAdversario(char*,int*,int*,int);
    QGraphicsScene **ptrScene = &scene;
    ~MainWindow();

    void crearTablero(string iniciales);
private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
