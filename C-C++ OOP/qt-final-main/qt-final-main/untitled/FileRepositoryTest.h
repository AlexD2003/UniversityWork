#ifndef FILEREPOSITORYTEST_H
#define FILEREPOSITORYTEST_H

#include <cassert>
#include "filerepository.h"
#include "song.h"

class FileRepositoryTest {
public:
    void runTests() {
        testLoadAndSave();
        testStoreAndFind();
    }

private:
    void testLoadAndSave() {
        FileRepository repository("test_songs.txt");

        repository.load();

        const Song& song1 = repository.findSong("Song 1", "Artist 1");
        assert(song1.getTitle() == "Song 1");
        assert(song1.getArtist() == "Artist 1");

        const Song& song2 = repository.findSong("Song 2", "Artist 2");
        assert(song2.getTitle() == "Song 2");
        assert(song2.getArtist() == "Artist 2");

        // Modify and save songs
        Song modifiedSong1 = song1;  // Create a modifiable copy
        modifiedSong1.setYear("2022");
        repository.store(modifiedSong1);
        repository.store(createSong("Song 3", "Artist 3", "2023"));

        repository.save();

        // Reload repository
        repository.load();

        const Song& updatedSong1 = repository.findSong("Song 1", "Artist 1");
        assert(updatedSong1.getYear() == "2022");

        const Song& song3 = repository.findSong("Song 3", "Artist 3");
        assert(song3.getTitle() == "Song 3");
        assert(song3.getArtist() == "Artist 3");
    }

    void testStoreAndFind() {
        FileRepository repository("test_songs.txt");
        repository.load();

        Song song = createSong("Song 4", "Artist 4", "2024");

        repository.store(song);

        const Song& foundSong = repository.findSong("Song 4", "Artist 4");
        assert(foundSong.getTitle() == "Song 4");
        assert(foundSong.getArtist() == "Artist 4");
    }

    Song createSong(const std::string& title, const std::string& artist, const std::string& year) {
        Song song(title, artist, year);
        return song;
    }
};

#endif // FILEREPOSITORYTEST_H
