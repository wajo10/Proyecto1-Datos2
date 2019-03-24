#ifndef BOLSA_H
#define BOLSA_H
class Bolsa
{
private:
 char* letras="abcdefghijklmnopqrstuvwxyz ";
 //
//0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
 int cantidad[27] = { 9,2,2,4,12,2,3,2,9,2,2,7,6,13,15,4,2,13,10,15,7,3,4,2,4,2,2};
public:
  Bolsa();
 char agarrar_ficha();
 int prueba();
 bool revisar_cantidad();
 void poner_cero();
};

#endif // BOLSA_H
