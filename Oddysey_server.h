#ifndef MAIN_ODDYSEY_SERVER_H
#define MAIN_ODDYSEY_SERVER_H


#include <stdlib.h>
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>
#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //Permite el write
#include<pthread.h> //Biblioteca de Threads , asociada a lpthread
#include <jsoncpp/json/json.h>
//#include "pugixml.cpp"


class Server {
public:
    int crear();




};

#endif //MAIN_ODDYSEY_SERVER_H