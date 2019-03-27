#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <stdlib.h>
#include <string>
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
    void request(string,int);
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
