#ifndef COMODIN_H
#define COMODIN_H

#include <QDialog>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "ficha.h"
using namespace std;

namespace Ui {
class Comodin;
}

class Comodin : public QDialog
{
    Q_OBJECT

public:
    explicit Comodin(QWidget *parent = nullptr);
    ~Comodin();
    Comodin (Ficha* ficha);
    Ficha *getFicha() const;
    void setFicha(Ficha *value);

private slots:

    void on_pushButton_clicked();

private:
    Ui::Comodin *ui;
    Ficha *ficha;
};

#endif // COMODIN_H
