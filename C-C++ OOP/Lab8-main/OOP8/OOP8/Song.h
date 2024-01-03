#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <ostream>
using namespace std;

class Song{
protected:
	string artist;
	string title;
	vector<string> lyrics;
public:
	Song();
	Song(string artist2, string title2, string lyrics2);
	vector<string> getLyrics();
	string getTitle();
	string getArtist();




	friend ostream& operator<<(ostream& os, const Song& s);
};