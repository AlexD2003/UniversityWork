#include "playlist.h"
#include <algorithm>
#include <random>
using namespace std;
void Playlist::add(const Song& song) {
    playlist.push_back(song);
}

void Playlist::clear() {
    playlist.clear();
}

void Playlist::remove(const Song& song) {
    playlist.erase(std::remove(playlist.begin(), playlist.end(), song), playlist.end());
}

void Playlist::generateRandom(int n, const std::vector<Song>& songs) {
    // Clear the current playlist
    playlist.clear();

    // Create a vector of indices
    vector<int> indices(songs.size());
    for (int i = 0; i < indices.size(); ++i) {
        indices[i] = i;
    }

    //random_device rd;
    //gen(rd());
    //shuffle(indices.begin(), indices.end(), gen);


    for (int i = 0; i < n; ++i) {
        playlist.push_back(songs[indices[i]]);
    }
}
