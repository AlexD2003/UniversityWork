#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <deque>
#include <vector>
#include <algorithm>
#include <random>


#include "song.h"
using namespace std;
class Playlist : public vector<Song>{
public:
    //add function
    void add(const Song& song);
    //clear of class
    void clear();
    //remove a song from a playlist
    void remove(const Song& song);
    //random playlist
    void generateRandom(int n, const vector<Song>& songs);

private:
    vector<Song> playlist;
};

#endif // PLAYLIST_H
