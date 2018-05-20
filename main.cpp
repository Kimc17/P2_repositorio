#include "pugixml.hpp"
/*
#include <iostream>
#include <stdio.h>
#include <cstring>

bool buscanombre(pugi::xml_node node);
//g++ build/XML.cpp -pthread  Base64.cpp Chunk.cpp pugixml.cpp  Oddysey_server.cpp -o server

int main()
{

    pugi::xml_document doc;

    // Se carga el documento
    pugi::xml_parse_result result = doc.load_file("players.xml");

    // Se comprueba que el documento se ha parseado bien
    std::cout << "Load result: " << result.description() << std::endl;

    // Se asigna a una variable el primer nodo del documento
    pugi::xml_node players = doc.first_child();

    // Se busca por predicado el nodo buscado: <PlayerList>
    // El predicado es la función buscanombre, que está definida y comentada al final del documento.
    // La función find_node hace una búsqueda recursiva sobre el SUBárbol que define el nodo al que se aplica.
    // es decir, se debe aplicar a un nodo que sea padre en algún grado del nodo buscado.
    std::cout << "Encontrado: " << players.find_node(buscanombre).name() << std::endl;

    // La parte que sigue aquí son iteraciones para buscar <PlayerList> de forma manual
    // así se ilustran las dos formas de buscar nodos. Esto es por tanto redundante
    std::cout << "Nodo: " << players.name() << " (" << players.type() << "): " << players.child_value() << std::endl;

    players = players.first_child();
    std::cout << "Nodo: " << players.name() << " (" << players.type() << "): " << players.child_value() << std::endl;

    while (strcmp(players.name(),"Team")) {
        players = players.next_sibling();
        std::cout << "Nodo: " << players.name() << " (" << players.type() << "): " << players.child_value() << std::endl;
    }

    players = players.first_child();
    std::cout << "Nodo: " << players.name() << " (" << players.type() << "): " << players.child_value() << std::endl;

   while (strcmp(players.name(),"PlayerList")) {
        players = players.next_sibling();
        std::cout << "Nodo: " << players.name() << " (" << players.type() << "): " << players.child_value() << std::endl;
    }
    players = players.first_child();

    while (players) {
        std::cout << "Jugador: " << players.first_child().next_sibling().child_value() << std::endl;
        players = players.next_sibling();
    }

    getchar();
    return 0;
}


bool buscanombre(pugi::xml_node node)
{
    return (!strcmp(node.name(), "PlayerList"));
}