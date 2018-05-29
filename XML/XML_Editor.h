//
// Created by karina on 05/05/18.
//

#ifndef PROYECTO2_ODISSEY_XMLEDITOR_H
#define PROYECTO2_ODISSEY_XMLEDITOR_H

#include "pugixml.hpp"
#include "../DataStructures/SimpleLinkedList.h"
#include "../DataBase/Metadata.h"
#include "../DataBase/Query.h"

class XML_Editor {
private:
    Query query;
public:
    std::string readMessage(const char xml[]);
    std::string writeEditRequest(std::string name, std::string artist);
    std::string writeDeleteRequest(std::string name, std::string artist);
    std::string writeNameSearchRequest(std::string name);
    std::string writeArtistSearchRequest(std::string artist);
    std::string writeAlbumSearchRequest(std::string albumName);
    std::string writeLyricSearchRequest(std::string lyric);
    std::string writeEditResponse(Metadata metadata);
    std::string writeSearchResponse(SimpleLinkedList<Metadata> tracks);
    std::string writeUploadRequest(Metadata metadata, std::string song);
    std::string writeChunkRequest(int chunk);
};


#endif //PROYECTO2_ODISSEY_XMLEDITOR_H
