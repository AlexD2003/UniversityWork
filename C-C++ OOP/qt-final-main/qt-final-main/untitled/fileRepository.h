#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <locale>
#include "song.h"
#include <algorithm>
#include <string>
#include "repository.h"
using namespace std;

class FileRepository: public Repository {
private:
    //def
    string file_path;
    vector<Song> data;
    vector<Song> collection;

public:
    //constructor
explicit FileRepository(const std::string& fileName) {
        loadSongs(fileName);
    }
//load funtion
void loadSongs(const std::string& filename);
//get function
vector<Song> getAllSongs() const;
//save on file function
void save_data();
};
