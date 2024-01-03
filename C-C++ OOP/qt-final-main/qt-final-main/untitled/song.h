#ifndef SONG_H
#define SONG_H
#include <QtWidgets>
#include <string>
using namespace std;
class Song {
public:
    //def
    string title;
    string artist;
    string year;
    string lyrics;
    string url;
    //comparatpr operator overload for song
    bool operator==(const Song& other) const {
        return (title == other.title) && (artist == other.artist) && (year == other.year) && (lyrics == other.lyrics) && (url == other.url);
    }
    //constructor
    Song(const string& title = "", const string& artist = "", string year = "0", const string& lyrics = "", const string& url = "")
        : title(title), artist(artist), year(year), lyrics(lyrics), url(url)
    {
    }
    //getters/setters
    const string& getArtist() const {
        return artist;
    }

    const string& getTitle() const {
        return title;
    }
    string getYear() const {
        return year;
    }

    string getLyrics() const {
        return lyrics;
    }

    void setTitle(string& title2) {
        title = title2;
    }

    void setArtist(string& artist2) {
        artist = artist2;
    }

    void setYear(const string& year2)
    {
        year = year2;
    }

    void setLyrics(string& lyrics2) {
        lyrics = lyrics2;
    }
    void setURL(string& URL2){
        url=URL2;
    }
    const string& getUrl() const {
        return url;
    }
};
#endif // SONG_H
