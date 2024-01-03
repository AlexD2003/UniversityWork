#ifndef SONGCONTROLLERTEST_H
#define SONGCONTROLLERTEST_H

#include <cassert>
#include "song.h"
#include "repository.h"
#include "songcontroller.h"

class SongControllerTest {
public:
    void runTests() {
        testAddSong();
        testSearchSong();
        testGetSortedByArtist();
        testGetSortedByTitle();
    }

private:
    void testAddSong() {
        Repository repository;
        SongController songController(repository);
        songController.addSong("Song 1", "Artist 1", "2021");
        songController.addSong("Song 2", "Artist 2", "2022");

        const Song& foundSong1 = repository.findSong("Song 1", "Artist 1");
        assert(foundSong1.getTitle() == "Song 1");
        assert(foundSong1.getArtist() == "Artist 1");

        const Song& foundSong2 = repository.findSong("Song 2", "Artist 2");
        assert(foundSong2.getTitle() == "Song 2");
        assert(foundSong2.getArtist() == "Artist 2");
    }

    void testSearchSong() {
        Repository repository;
        SongController songController(repository);
        songController.addSong("Song 1", "Artist 1", "2021");
        songController.addSong("Song 2", "Artist 2", "2022");

        const Song& foundSong1 = songController.searchSong("Song 1", "Artist 1");
        assert(foundSong1.getTitle() == "Song 1");
        assert(foundSong1.getArtist() == "Artist 1");

        const Song& foundSong2 = songController.searchSong("Song 2", "Artist 2");
        assert(foundSong2.getTitle() == "Song 2");
        assert(foundSong2.getArtist() == "Artist 2");
    }

    void testGetSortedByArtist() {
        Repository repository;
        SongController songController(repository);
        songController.addSong("Song 2", "Artist 2", "2022");
        songController.addSong("Song 1", "Artist 1", "2021");
        songController.addSong("Song 3", "Artist 3", "2023");

        std::vector<Song> sortedByArtist = songController.getSortedByArtist();

        assert(sortedByArtist.size() == 3);
        assert(sortedByArtist[0].getArtist() == "Artist 1");
        assert(sortedByArtist[1].getArtist() == "Artist 2");
        assert(sortedByArtist[2].getArtist() == "Artist 3");
    }

    void testGetSortedByTitle() {
        Repository repository;
        SongController songController(repository);
        songController.addSong("Song B", "Artist 2", "2022");
        songController.addSong("Song A", "Artist 1", "2021");
        songController.addSong("Song C", "Artist 3", "2023");

        std::vector<Song> sortedByTitle = songController.getSortedByTitle();

        assert(sortedByTitle.size() == 3);
        assert(sortedByTitle[0].getTitle() == "Song A");
        assert(sortedByTitle[1].getTitle() == "Song B");
        assert(sortedByTitle[2].getTitle() == "Song C");
    }
};

#endif // SONGCONTROLLERTEST_H
