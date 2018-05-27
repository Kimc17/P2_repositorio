/*#ifndef MAIN_XML_H
#define MAIN_XML_H
#include <iostream>
#include "pugixml.hpp"
using namespace std;
class XML {
public:

    pugi::xml_document crear();
    pugi::xml_node agregarRaiz(pugi::xml_document doc, const char nombreNodo);
    pugi::xml_node agregar(pugi::xml_node raiz,const char nombreNodo,const char valor);
    void agregarAHijo( pugi::xml_node nodo, string nombre,const char valor);
    void imprimir( pugi::xml_document doc);
    void guardar( pugi::xml_document doc);

};





#endif //MAIN_XML_H*/
