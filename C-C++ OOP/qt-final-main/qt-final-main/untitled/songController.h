#ifndef SONGCONTROLLER_H
#define SONGCONTROLLER_H
#include <stack>
#include "repository.h"
#include "song.h"
#include "fileRepository.h"
#include "songException.h"

class SongController {
public:
    //constructor
    explicit SongController(Repository& repository) : repository(repository) {}
    //add song
    void addSong(const string& title, const string& artist, const string& year) {
        const Song& existingSong = repository.findSong(title, artist);
        if (existingSong.getTitle() == title && existingSong.getArtist() == artist) {
            throw SongException("A song '" + title + "' by '" + artist + "' already exists");
        }
        Song song(title, artist, year);
        repository.addSong(song);
    }
    //search function
    const Song& searchSong(const string& title, const string& artist) {
        const Song& foundSong = repository.findSong(title, artist);
        if (foundSong.getTitle().empty() && foundSong.getArtist().empty()) {
            throw SongException("The song '" + title + "' by '" + artist + "' does not exist");
        }
        return foundSong;
    }
    //sort by artist
    vector<Song> getSortedByArtist(bool ascending = true) {
        vector<Song> songs = repository.getAllSongs();
        sort(songs.begin(), songs.end(), [ascending](const Song& s1, const Song& s2) {
            if (ascending) {
                return s1.getArtist() < s2.getArtist();
            } else {
                return s1.getArtist() > s2.getArtist();
            }
        });
        return songs;
    }
    //sort by title
    vector<Song> getSortedByTitle(bool ascending = true) {
        vector<Song> songs = repository.getAllSongs();
        sort(songs.begin(), songs.end(), [ascending](const Song& s1, const Song& s2) {
            if (ascending) {
                return s1.getTitle() < s2.getTitle();
            } else {
                return s1.getTitle() > s2.getTitle();
            }
        });
        return songs;
    }

private:
    Repository& repository;
};

#endif // SONGCONTROLLER_H
