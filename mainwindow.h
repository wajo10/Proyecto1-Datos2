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
    /**
     * @brief request Agrega las fichas de reposicion al tablero
     * @param s
     */
    static void request(string s);
    explicit MainWindow(QWidget *parent = nullptr);
    static QGraphicsScene * scene;
    QGraphicsScene **ptrScene = &scene;
    ~MainWindow();
    /**
     * @brief crearTablero creacion inicial grafica del tablero con sus fichas
     * @param iniciales
     */
    void crearTablero(string iniciales);

    void llamada(bool *flag);
private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    bool flag = false;
    bool *flagPtr = &flag;
    string inicial="";
    string *iniciales=&inicial;



};

#endif // MAINWINDOW_H
