#ifndef COMODIN_H
#define COMODIN_H

#include <QDialog>
#include <iostream>
#include <stdlib.h>
#include <string>

namespace Ui {
class Comodin;
}

class Comodin : public QDialog
{
    Q_OBJECT

public:
    explicit Comodin(QWidget *parent = nullptr);
    ~Comodin();

private slots:

    void on_pushButton_clicked();

private:
    Ui::Comodin *ui;
};

#endif // COMODIN_H
