#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include <algorithm>
#include "song.h"
#include "songException.h"
using namespace std;
class Repository {
protected:
    vector<Song> songs_;

public:
    //constructor
    Repository() = default;
    //store in repo
    void addSong(const Song& song);
    //find song by title and artist
    const Song& findSong(const std::string& title, const std::string& artist) const;
    //return all songs in repo
    const vector<Song>& getAllSongs() const {
        return songs_;
    }
    //remove a song from repo using song exception
    void remove(const Song& s) {
        auto it = find(songs_.begin(), songs_.end(), s);

        if (it == songs_.end()) {
            throw SongException("The song '" + s.title + "' by '" + s.artist + "' does not exist.");
        }

        songs_.erase(it);
    }

};
#endif // REPOSITORY_H
