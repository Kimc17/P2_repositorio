//
// Created by kimberlyc on 05/05/18.
//

#ifndef MAIN_CHUNK_H
#define MAIN_CHUNK_H
#include <iostream>

#include <cstdio>

class Chunk {
private:
    FILE *fichero;
    long bytes;
public:
    size_t  Dividir(char nombre[]);
    int tamanio();
    std::string Abase64(std::string);
    std::string Debase64(std::string);

};


#endif //MAIN_CHUNK_H
