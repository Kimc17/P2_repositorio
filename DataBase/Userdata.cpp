//
// Created by karina on 27/05/18.
//

#include "Userdata.h"

 std::string Userdata::getUsername()  {
    return username;
}
std::string Userdata::getNombre()  {
    return nombre;
}


void Userdata::setUsername( std::string username) {
    Userdata::username = username;
}
void Userdata::setNombre( std::string nombre) {
    Userdata::nombre = nombre;
}

 std::string Userdata::getPassword()  {
    return password;
}

void Userdata::setPassword( std::string password) {
    Userdata::password = password;
}


void Userdata::setPreferences( SimpleLinkedList<std::string> preferences) {
    Userdata::preferences = preferences;
}

void Userdata::setFriends(SimpleLinkedList<std::string> friends) {
    Userdata::friends = friends;
}

Userdata::Userdata() {
    this->username = "";
    this->password = "";
}

Userdata::Userdata(std::string username, std::string password, SimpleLinkedList<std::string> friends, SimpleLinkedList<std::string> preferences) {
    this->username = username;
    this->password = password;
    this->friends = friends;
    this->preferences = preferences;
}

SimpleLinkedList<std::string> Userdata::getFriends(){
    return friends;
}

SimpleLinkedList< std::string> Userdata::getPreferences()  {
    return preferences;
}
