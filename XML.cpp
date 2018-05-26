/*
#include <cstring>
#include "XML.h"


using namespace std;

pugi::xml_document XML::crear(){
    pugi::xml_document doc;
    return doc;
}
pugi::xml_node XML::agregarRaiz(pugi::xml_document doc,const char nombreNodo){
    pugi::xml_node nodo = doc.append_child(nombreNodo);
    return nodo;
}
pugi::xml_node XML::agregar(pugi::xml_node raiz, string nombreNodo, const char valor){
    pugi::xml_node nodo = raiz.append_child(nombreNodo);
    nodo.append_child(pugi::node_pcdata).set_value(valor);
    return nodo;
}
void XML::agregarAHijo( pugi::xml_node nodo, string nombre,const char valor){
    nodo.append_attribute(nombre) = valor;
}


void XML::imprimir( pugi::xml_document doc){
    doc.print(std::cout);
}
void XML::guardar( pugi::xml_document doc){
    doc.save_file("/home/kimberlyc/Documentos/holi.xml");
}





/*
c XML:: Cargar(char name[]){
    pugi::xml_document doc;

// Para cargar el documento
    pugi::xml_parse_result result = doc.load_file(name);
    std::cout << "Parseado con éxito: " << result.description() << std::endl;
//Asignar el primer nodo a una variable
    pugi::xml_node players = doc.first_child();
    return players;
}
bool buscanombre(pugi::xml_node node, char name[])
{
    return (!strcmp(node.name(), name));
}

string nombreNodo(pugi::xml_node nodo){
    return nodo.name();
}
string valorHijo(pugi::xml_node nodo){
    return nodo.child_value();
}
pugi::xml_node IralHijo(pugi::xml_node nodo){
    return  nodo.next_sibling();
}

pugi::xml_node Crear() {
    pugi::xml_document doc;

    pugi::xml_node nodo = doc.append_child(pugi::node_declaration);
    return nodo;
}
void agregar(string etiqueta, string descrip, pugi::xml_node nodo) {
    nodo.append_attribute(etiqueta) = descrip;
}
pugi::xml_node agregarHijo(pugi::xml_node  doc) {
    pugi::xml_node root = doc.append_child("MyRoot");
    return root;
}


void guardar(pugi::xml_node  doc){
     doc.save_file(XML_FILE_PATH.c_str(), PUGIXML_TEXT("  "));
    //assert(saveSucceeded);
}

pugi::xml_document XML::AgregarNodo(pugi::xml_document doc, char nombre[], char descripcion[], char valor[] ) {
    pugi::xml_node node = doc.append_child(nombre);
    pugi::xml_node descr = node.append_child(descripcion);
    descr.append_child(pugi::node_pcdata).set_value(valor);
    return doc;
}

pugi::xml_document XML::RemoverDescripNodo(pugi::xml_document doc, char nombre[],char descripcion[]) {

    pugi::xml_node node = doc.child(nombre);
    node.remove_child(descripcion);
}
pugi::xml_document XML::RemoverValorNodo(pugi::xml_document doc, char nombre[], char* param[],char valor[]) {

    pugi::xml_node param = doc.child(nombre).child(*param);
    param.remove_attribute(valor);
}

*/
