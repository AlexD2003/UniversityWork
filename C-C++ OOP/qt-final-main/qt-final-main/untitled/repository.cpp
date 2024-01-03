#include "repository.h"
using namespace std;
void Repository::addSong(const Song& song) {
    songs_.push_back(song);
}

const Song& Repository::findSong(const string& title, const string& artist) const {
    auto it = find_if(songs_.begin(), songs_.end(), [&](const Song& song) {
        return song.getTitle() == title && song.getArtist() == artist;
    });

    if (it != songs_.end()) {
        return *it;
    }

    static Song emptySong;
    return emptySong;
}
