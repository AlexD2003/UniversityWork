#pragma once
#include "Song.h"
#include <vector>
#include <set>
#include <fstream>
#include<string>
using namespace std;

class SongCollection :public Song {
	friend class Song;
private:
	vector<Song> collection;
	ifstream file;
	string path;
public:
	SongCollection(string path);
	set<string> Unique_artists();
	void loadSongs();
	void sort_by_name();
	void sort_by_title();
	void sort_by_number();
	vector<string> search(string key);
};