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
#include "bolsa.h"

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
    QGraphicsScene **ptrScene = &scene;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
