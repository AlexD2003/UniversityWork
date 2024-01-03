#include "SongCollection.h"
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>
using namespace std;


void SongCollection::loadSongs() {
	string word;
	string artist;
	string title;
	string lyrics;
	while (getline(file, word)) {
		if (word.find("ARTIST") != string::npos) {
			word.replace(0, 7, "");
			artist = word;
		}
		else if (word.find("TITLE") != string::npos) {
			word.replace(0, 6, "");
			title = word;
		}
		else if (word.find("LYRICS") != string::npos) {
			word.replace(0, 7, "");
			lyrics = word;
		}
		else {
			lyrics += word;
			lyrics += " ";
			if (word == "\"") {
				Song song(artist, title, lyrics);
				collection.push_back(song);
			}
		}
	}
}

SongCollection::SongCollection(string path){
	this->path = path;
	file.open(path, ios::in); 
		if(!file.is_open()){
			cout << "Not correct path given! incorrect path:" << path << endl;
			throw std::invalid_argument("Not correct path given!");
			return;
	}
}
void SongCollection::sort_by_name() {
	sort(collection.begin(), collection.end(), [](Song& a, Song& b) {
		return a.getArtist() < b.getArtist();
		});
}
void SongCollection::sort_by_title() {
	sort(collection.begin(), collection.end(), [](Song& a, Song& b) {
		return a.getTitle() > b.getTitle();
		});
}
void SongCollection::sort_by_number() {
	sort(collection.begin(), collection.end(), [](Song& a, Song& b) {
		return a.getLyrics().size() < b.getLyrics().size();
		});
}

set<string> SongCollection::Unique_artists()
{
	set<string> artists;
	for (int i = 0; i < collection.size(); i++)
	{
			artists.insert(collection[i].getArtist());
	}
	return artists;
}

vector<string> SongCollection::search(string key) {
	vector<string> copy;
	vector<string> result;
	for (int i = 0; i < collection.size(); i++) {
		copy = collection[i].getLyrics();
		for (int i = 0; i < copy.size(); i++) {
			if (copy[i] == key) {
				result.push_back(collection[i].getTitle());
				break;
			}
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
	return result;
}
