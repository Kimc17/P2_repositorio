//
// Created by karina on 05/05/18.
//

#include <iostream>
#include <sstream>
#include "XML_Editor.h"

std::string XML_Editor::writeUploadRequest(Metadata metadata, std::string song) {
    pugi::xml_document doc;
    // Generate XML declaration
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    // A valid XML doc must contain a single root node of any name
    auto root = doc.append_child("root");
    auto subject = root.append_child("subject");
    subject.append_child(pugi::node_pcdata).set_value("02");
    auto data = root.append_child("data");

    if(metadata.getSongName() != ""){
        auto song_data = data.append_child("name");
        song_data.append_child(pugi::node_pcdata).set_value(metadata.getSongName().c_str());
    }
    if(metadata.getArtist() != ""){
        auto song_data = data.append_child("artist");
        song_data.append_child(pugi::node_pcdata).set_value(metadata.getArtist().c_str());
    }
    if(metadata.getAlbum() != ""){
        auto song_data = data.append_child("album");
        song_data.append_child(pugi::node_pcdata).set_value(metadata.getAlbum().c_str());
    }
    if(metadata.getDuration() != ""){
        auto song_data = data.append_child("duration");
        song_data.append_child(pugi::node_pcdata).set_value(metadata.getDuration().c_str());
    }
    if(metadata.getGenre() != ""){
        auto song_data = data.append_child("genre");
        song_data.append_child(pugi::node_pcdata).set_value(metadata.getGenre().c_str());
    }
    if(metadata.getYear() != ""){
        auto song_data = data.append_child("year");
        song_data.append_child(pugi::node_pcdata).set_value(metadata.getYear().c_str());
    }

    auto song_bytes = data.append_child("song_bytes");
    song_bytes.append_child(pugi::node_pcdata).set_value(song.c_str());

    // Write complete xml document to string stream
    std::stringstream ss;
    doc.save(ss,"  ");

    return ss.str();
}

std::string XML_Editor::readMessage(const char xml[]) {
    pugi::xml_document doc;
    doc.load_string(xml);
    std::string subject = doc.child("root").child("subject").text().get();
    if(subject == "01"){

    }else if(subject == "02"){
        //upload request
        //Sacar metadata del mensaje
        Metadata metada;
        std::string songName = doc.child("root").child("subject").text().get();
    }
}


std::string XML_Editor::writeEditRequest(std::string name, std::string artist) {
    pugi::xml_document doc;
    // Generate XML declaration
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    // A valid XML doc must contain a single root node of any name
    auto root = doc.append_child("root");
    auto subject = root.append_child("subject");
    subject.append_child(pugi::node_pcdata).set_value("03");
    auto data = root.append_child("data");

    auto song_name = data.append_child("song");
    song_name.append_child(pugi::node_pcdata).set_value(name.c_str());

    auto song_artist = data.append_child("artist");
    song_artist.append_child(pugi::node_pcdata).set_value(artist.c_str());

    // Write complete xml document to string stream
    std::stringstream ss;
    doc.save(ss,"  ");

    return ss.str();
}

std::string XML_Editor::writeDeleteRequest(std::string name, std::string artist) {
    pugi::xml_document doc;
    // Generate XML declaration
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    // A valid XML doc must contain a single root node of any name
    auto root = doc.append_child("root");
    auto subject = root.append_child("subject");
    subject.append_child(pugi::node_pcdata).set_value("05");
    auto data = root.append_child("data");

    auto song_name = data.append_child("song");
    song_name.append_child(pugi::node_pcdata).set_value(name.c_str());

    auto song_artist = data.append_child("artist");
    song_artist.append_child(pugi::node_pcdata).set_value(artist.c_str());

    // Write complete xml document to string stream
    std::stringstream ss;
    doc.save(ss,"  ");

    return ss.str();
}

std::string XML_Editor::writeNameSearchRequest(std::string name) {
    pugi::xml_document doc;
    // Generate XML declaration
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    // A valid XML doc must contain a single root node of any name
    auto root = doc.append_child("root");
    auto subject = root.append_child("subject");
    subject.append_child(pugi::node_pcdata).set_value("08");
    auto data = root.append_child("data");
    auto song_bytes = data.append_child("song_name");
    song_bytes.append_child(pugi::node_pcdata).set_value(name.c_str());

    // Write complete xml document to string stream
    std::stringstream ss;
    doc.save(ss,"  ");

    return ss.str();
}

std::string XML_Editor::writeArtistSearchRequest(std::string artist) {
    pugi::xml_document doc;
    // Generate XML declaration
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    // A valid XML doc must contain a single root node of any name
    auto root = doc.append_child("root");
    auto subject = root.append_child("subject");
    subject.append_child(pugi::node_pcdata).set_value("09");
    auto data = root.append_child("data");
    auto song_bytes = data.append_child("song_artist");
    song_bytes.append_child(pugi::node_pcdata).set_value(artist.c_str());

    // Write complete xml document to string stream
    std::stringstream ss;
    doc.save(ss,"  ");

    return ss.str();
}

std::string XML_Editor::writeAlbumSearchRequest(std::string albumName) {
    pugi::xml_document doc;
    // Generate XML declaration
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    // A valid XML doc must contain a single root node of any name
    auto root = doc.append_child("root");
    auto subject = root.append_child("subject");
    subject.append_child(pugi::node_pcdata).set_value("07");
    auto data = root.append_child("data");
    auto song_bytes = data.append_child("song_album");
    song_bytes.append_child(pugi::node_pcdata).set_value(albumName.c_str());

    // Write complete xml document to string stream
    std::stringstream ss;
    doc.save(ss,"  ");

    return ss.str();
}

std::string XML_Editor::writeLyricSearchRequest(std::string lyric) {
    return std::__cxx11::string();
}

std::string XML_Editor::writeEditResponse(Metadata metadata) {
    pugi::xml_document doc;
    // Generate XML declaration
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    // A valid XML doc must contain a single root node of any name
    auto root = doc.append_child("root");
    auto subject = root.append_child("subject");
    subject.append_child(pugi::node_pcdata).set_value("14");
    auto data = root.append_child("data");

    if(metadata.getSongName() != ""){
        auto song_data = data.append_child("name");
        song_data.append_child(pugi::node_pcdata).set_value(metadata.getSongName().c_str());
    }
    if(metadata.getArtist() != ""){
        auto song_data = data.append_child("artist");
        song_data.append_child(pugi::node_pcdata).set_value(metadata.getArtist().c_str());
    }
    if(metadata.getAlbum() != ""){
        auto song_data = data.append_child("album");
        song_data.append_child(pugi::node_pcdata).set_value(metadata.getAlbum().c_str());
    }
    if(metadata.getDuration() != ""){
        auto song_data = data.append_child("duration");
        song_data.append_child(pugi::node_pcdata).set_value(metadata.getDuration().c_str());
    }
    if(metadata.getGenre() != ""){
        auto song_data = data.append_child("genre");
        song_data.append_child(pugi::node_pcdata).set_value(metadata.getGenre().c_str());
    }
    if(metadata.getYear() != ""){
        auto song_data = data.append_child("year");
        song_data.append_child(pugi::node_pcdata).set_value(metadata.getYear().c_str());
    }

    // Write complete xml document to string stream
    std::stringstream ss;
    doc.save(ss,"  ");

    return ss.str();
}

//SIBABORT
std::string XML_Editor::writeSearchResponse(SimpleLinkedList<Metadata> tracks) {
    pugi::xml_document doc;
    // Generate XML declaration
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    // A valid XML doc must contain a single root node of any name
    auto root = doc.append_child("root");
    auto subject = root.append_child("subject");
    subject.append_child(pugi::node_pcdata).set_value("04");
    auto data = root.append_child("data");

    Node<Metadata> *currentTrack = tracks.getHead();
    for(int i = 0; i < tracks.getSize(); i++){
        Metadata metadata = currentTrack->getData();
        auto song = data.append_child("song");

        if(metadata.getSongName() != ""){
            auto song_data = song.append_child("name");
            song_data.append_child(pugi::node_pcdata).set_value(metadata.getSongName().c_str());
        }
        if(metadata.getArtist() != ""){
            auto song_data = song.append_child("artist");
            song_data.append_child(pugi::node_pcdata).set_value(metadata.getArtist().c_str());
        }
        if(metadata.getAlbum() != ""){
            auto song_data = song.append_child("album");
            song_data.append_child(pugi::node_pcdata).set_value(metadata.getAlbum().c_str());
        }
        if(metadata.getDuration() != ""){
            auto song_data = song.append_child("duration");
            song_data.append_child(pugi::node_pcdata).set_value(metadata.getDuration().c_str());
        }
        if(metadata.getGenre() != ""){
            auto song_data = song.append_child("genre");
            song_data.append_child(pugi::node_pcdata).set_value(metadata.getGenre().c_str());
        }
        if(!metadata.getYear().empty()){
            auto song_data = song.append_child("year");
            song_data.append_child(pugi::node_pcdata).set_value(metadata.getYear().c_str());
        }
        currentTrack = currentTrack->getNext();
    }

    // Write complete xml document to string stream
    std::stringstream ss;
    doc.save(ss,"  ");

    return ss.str();
}

