#include <cstring>
#include "XML.h"


using namespace std;


pugi::xml_node XML:: Cargar(char name[]){
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

/*
void Crear()
{
    pugi::xml_document doc;

    auto nodo= doc.append_child(pugi::node_declaration);
    nodo.append_attribute("version")    = "1.0";
    nodo.append_attribute("encoding")   = "ISO-8859-1";
    nodo.append_attribute("standalone") = "yes";
    // A valid XML doc must contain a single root node of any name
    auto root = doc.append_child("MyRoot");
    // Save XML tree to file.
    // Remark: second optional param is indent string to be used;
    // default indentation is tab character.
    bool saveSucceeded = doc.save_file(XML_FILE_PATH.c_str(), PUGIXML_TEXT("  "));
    assert(saveSucceeded);
    /// [create new xml file]
}
/*
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
