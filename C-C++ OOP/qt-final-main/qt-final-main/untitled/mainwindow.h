#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "song.h"
#include "repository.h"
#include "songController.h"
#include "playlist.h"
using namespace std;
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(SongController* controller, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addSong();
    void deleteSong();
    void addToPlaylist();
    void showUpdateMessage();
    void showFilterMessage();
    void playSong();
    void playNextSong();
    void sortByTitle();
    void sortByArtist();
    void updateAllSongsList();

private:
    Playlist playlist;
    Repository* repository;
    SongController* songController;
    QVector<Song> allSongs;
    QVector<Song> playlistSongs;
    QListWidget *allSongsListWidget;
    QListWidget *playlistListWidget;
    QLabel *Info;
    QLabel *Info1;
    QLabel *Info2;
    QLabel *Info3;
    QLabel *Info4;
    QLabel *Info5;
    QLabel *Info6;
    QLineEdit *Trait1;
    QLineEdit *Trait2;
    QLineEdit *Trait3;
    QLineEdit *Trait4;
    QLineEdit *Trait5;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;
    QPushButton *button7;
    QPushButton *sortTitleButton;
    QPushButton *sortArtistButton;
};

#endif // MAINWINDOW_H
