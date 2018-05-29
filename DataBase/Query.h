//
// Created by karina on 25/05/18.
//

#ifndef SERVERDATABASE_QUERY_H
#define SERVERDATABASE_QUERY_H

#include "../rapidjson/document.h"
#include "../rapidjson/filereadstream.h"
#include <cstdio>
#include "../rapidjson/filewritestream.h"
#include "../rapidjson/writer.h"
#include "../DataStructures/SimpleLinkedList.h"
#include "Metadata.h"
#include "Userdata.h"

using namespace rapidjson;

class Query {
public:
    void readFile(std::string path);
    void findValue(std::string);
    bool checkCredentials(std::string user, std::string password);
    SimpleLinkedList<Metadata> getAllTracks();
    SimpleLinkedList<Metadata> getTrackByArtist(std::string artist);
    SimpleLinkedList<Metadata> getTrackByName(std::string name);
    SimpleLinkedList<Userdata> getUsers();
    SimpleLinkedList<std::string> getUserFriends(std::string username);
    SimpleLinkedList<std::string> getUserPreferences(std::string username);

};


#endif //SERVERDATABASE_QUERY_H
