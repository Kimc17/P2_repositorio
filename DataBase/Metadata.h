//
// Created by karina on 27/05/18.
//

#ifndef SERVERDATABASE_METADATA_H
#define SERVERDATABASE_METADATA_H


#include <string>

class Metadata {
private:
    std::string songName;
    std::string artist;
    std::string album;
    std::string duration;
    std::string genre;
    std::string year;
public:
    Metadata();
    Metadata(std::string songName, std::string artist,
             std::string album,std::string duration,
             std::string genre,std::string year);
    std::string getSongName();
    std::string getArtist();
    std::string getAlbum();
    std::string getDuration();
    std::string getGenre();
    std::string getYear();

    void setSongName(const std::string &songName);
    void setArtist(const std::string &artist);
    void setAlbum(const std::string &album);
    void setDuration(const std::string &duration);
    void setGenre(const std::string &genre);
    void setYear(const std::string &year);


};


#endif //SERVERDATABASE_METADATA_H
