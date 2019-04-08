#ifndef PREGUNTAREXPERTO_H
#define PREGUNTAREXPERTO_H

#include <QDialog>
#include "traductorcliente.h"

namespace Ui {
class preguntarExperto;
}

class preguntarExperto : public QDialog
{
    Q_OBJECT

public:
    explicit preguntarExperto(QWidget *parent = nullptr);
    ~preguntarExperto();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::preguntarExperto *ui;
};

#endif // PREGUNTAREXPERTO_H
