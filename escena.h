#ifndef ESCENA_H
#define ESCENA_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include "pantalla.h"
#include "ficha.h"
#include "botones.h"
#include "bolsa.h"
using namespace std;

class escena
{
public:
    escena();
    static void request(int);

private:
    QGraphicsScene *scene = new QGraphicsScene;

};

#endif // ESCENA_H
