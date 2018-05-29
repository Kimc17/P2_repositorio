//
// Created by karina on 27/05/18.
//

#include "Metadata.h"

Metadata::Metadata(std::string songName, std::string artist,
                   std::string album, std::string duration,
                   std::string genre, std::string year) {

    this->songName = songName;
    this->artist = artist;
    this->album = album;
    this->duration = duration;
    this->genre = genre;
    this->year = year;
}

std::string Metadata::getSongName() {
    return songName;
}

std::string Metadata::getArtist() {
    return artist;
}

std::string Metadata::getAlbum() {
    return album;
}

std::string Metadata::getDuration() {
    return duration;
}

std::string Metadata::getGenre() {
    return genre;
}

std::string Metadata::getYear() {
    return year;
}

void Metadata::setSongName(const std::string &songName) {
    Metadata::songName = songName;
}

void Metadata::setArtist(const std::string &artist) {
    Metadata::artist = artist;
}

void Metadata::setAlbum(const std::string &album) {
    Metadata::album = album;
}

void Metadata::setDuration(const std::string &duration) {
    Metadata::duration = duration;
}

void Metadata::setGenre(const std::string &genre) {
    Metadata::genre = genre;
}

void Metadata::setYear(const std::string &year) {
    Metadata::year = year;
}

Metadata::Metadata(){
    this->songName = "";
    this->artist = "";
    this->album = "";
    this->duration = "";
    this->genre = "";
    this->year = "";
}
