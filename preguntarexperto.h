#ifndef PREGUNTAREXPERTO_H
#define PREGUNTAREXPERTO_H

#include <QDialog>
#include "traductorcliente.h"
#include "socket.h"
#include "tablero_cliente.h"

namespace Ui {
class preguntarExperto;
}

class preguntarExperto : public QDialog
{
    Q_OBJECT

public:
    explicit preguntarExperto(QWidget *parent = nullptr);
    ~preguntarExperto();
    void addText(string s);
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_textEdit_textChanged();

private:
    Ui::preguntarExperto *ui;
    bool finalizo = false;
};

#endif // PREGUNTAREXPERTO_H
