#ifndef REPOSITORYTEST_H
#define REPOSITORYTEST_H
#include <cassert>
#include "repository.h"
#include "song.h"

class RepositoryTest {
public:
    void runTests() {
        testStoreAndFind();
    }

private:
    void testStoreAndFind() {
        Repository repository;
        Song song1 = createSong("Song 1", "Artist 1", "2021");
        Song song2 = createSong("Song 2", "Artist 2", "2022");

        repository.addSong(song1);
        repository.addSong(song2);

        const Song& foundSong1 = repository.findSong("Song 1", "Artist 1");
        assert(foundSong1.title == "Song 1");
        assert(foundSong1.artist == "Artist 1");

        const Song& foundSong2 = repository.findSong("Song 2", "Artist 2");
        assert(foundSong2.title == "Song 2");
        assert(foundSong2.artist == "Artist 2");
    }


    Song createSong(const std::string& title, const std::string& artist, const std::string& year) {
        Song song;
        song.title = title;
        song.artist = artist;
        song.year = year;
        return song;
    }
};
#endif // REPOSITORYTEST_H
