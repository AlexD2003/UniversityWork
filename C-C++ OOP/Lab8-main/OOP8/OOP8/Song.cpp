#include "Song.h"
#pragma once
#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;


Song::Song() {
	title = "";
	artist = "";
	lyrics.push_back("");
}

string Song::getTitle() {
	return this->title;
}
vector<string> Song::getLyrics() {
	return this->lyrics;
}

string Song::getArtist()
{
	return artist;
}
Song::Song(string artist, string title, string lyrics) {
	this->artist = artist;
	this->title = title;
	transform(lyrics.begin(), lyrics.end(), lyrics.begin(), tolower);
	string s;
	for (char character : lyrics)
	{
		if (isalnum(character)==true)
		{
			s += character;
		}
		else
		{
			if (s.empty()==false)
			{
				this->lyrics.push_back(s);
				s.clear();
			}
		}
	}
}


ostream& operator<<(ostream& os, const Song& s) {
	os << s.artist << endl;
	os << s.title << endl;
	for (int i = 0; s.lyrics.size() - 1; i++)
		os << s.lyrics[i] << ' ';
	return os;
}