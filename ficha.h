#ifndef FICHA_H
#define FICHA_H


class Ficha
{
private:
    char letra;
public:
    Ficha(char letra);
    char getLetra() const;
    void setLetra(char value);
};

#endif // FICHA_H
