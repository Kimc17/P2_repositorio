#ifndef MAIN_XML_H
#define MAIN_XML_H
#include <iostream>
#include "pugixml.hpp"

class XML {
public:

    pugi::xml_document Nuevo();
    pugi::xml_document AgregarNodo(pugi::xml_document doc, char nombre[], char descripcion[], char valor[]);
    pugi::xml_node  Cargar(char name[]);
    bool buscanombre(pugi::xml_node node, char name[]);

};





#endif //MAIN_XML_H
