#include "fileRepository.h"
#include "song.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <QMessageBox>
#include <Qfile>
#include <QTextStream>
using namespace std;

//save data in file
void FileRepository::save_data() {
    ofstream file(file_path);
    for (const auto& song : data) {
        file << song.title << "," << song.artist << "," << song.year << "," << song.lyrics << "," << song.url << "\n";
    }
    file.close();
}
//load songs from file
void FileRepository::loadSongs(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open()) {
        throw invalid_argument("Failed to open the file.");
    }

    string line;
    string artist;
    string title;
    string lyrics;

    while (getline(file, line))
    {
        if (line.find("ARTIST") != string::npos)
        {
            line.replace(0, 7, "");
            artist = line;
        }
        else if (line.find("TITLE") != string::npos)
        {
            line.replace(0, 6, "");
            title = line;
        }
        else if (line.find("LYRICS") != string::npos)
        {
            line.replace(0, 7, "");
            lyrics = line;
        }
        else
        {
            lyrics += line;
            lyrics += " ";
            if (line == "\"")
            {
                Song song(artist, title, lyrics);
                collection.push_back(song);
            }
        }
    }

    file.close();
}
//return the songs from file
vector<Song> FileRepository::getAllSongs() const
{
    return collection;
}
