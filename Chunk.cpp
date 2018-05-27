/*
 *
 *#define SIZE 2048*100
#include "Chunk.h"



using namespace std;
size_t  Chunk::Dividir(char *nombre) {
    fichero = fopen("/home/kimberlyc/Música/Believer.mp3", "rb");

    char *chunk;
    size_t result;
    if (fichero != NULL & !feof(fichero)) {
        printf("creado (ABIERTO)\n");
        chunk = (char *) malloc(sizeof(char) * SIZE);
        if (chunk == NULL) {
            fputs("Memory error", stderr);
            exit(2);
        }
        result = fread(chunk, 1, SIZE, fichero);
            if (result != SIZE) {
                fputs("Reading error", stderr);
                exit(3);
            }
        FILE *subfic;
        subfic = fopen("1.mp3", "wb");
        if (subfic != NULL) {
        }
        fwrite(chunk, result, SIZE, subfic);
        fclose(subfic);
        fclose(fichero);
        return result;
        }

    }


int Chunk::tamanio() {
    fseek(fichero, 0, SEEK_END);
    long lSize = ftell(fichero);
    cout << "El tamaño del archivo en bytes es" << lSize;
    rewind(fichero);
    return lSize;

}


string Chunk::Abase64(string resultado) {
    Base64 *base = new Base64();
    string ejemp = base->Encode(resultado);
    return ejemp;
}
string Chunk::Debase64(string resultado) {
    Base64 *base = new Base64();
    string ejemp = base->Decode(resultado);
    return ejemp;
} */