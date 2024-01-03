#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "song.h"
#include "songException.h"
#include "songcontroller.h"
#include <QMessageBox>
#include <algorithm>
#include <string>
using namespace std;
MainWindow::MainWindow(SongController* controller, QWidget *parent)
    : QWidget(parent), songController(controller)
{
    setWindowTitle("PlayListQt");
    repository = new Repository();
    songController = new SongController(*repository);
    Info = new QLabel("All songs");
    Info1 = new QLabel("Playlist");
    Info2 = new QLabel("Title:");
    Info3 = new QLabel("Artist:");
    Info4 = new QLabel("Year:");
    Info5 = new QLabel("Lyrics:");
    Info6 = new QLabel("URL:");
    button1 = new QPushButton("Add");
    button2 = new QPushButton("Delete");
    button3 = new QPushButton("Update");
    button4 = new QPushButton("Filter");
    button5 = new QPushButton(">");
    button6 = new QPushButton("Play");
    button7 = new QPushButton("Next");

    Trait1 = new QLineEdit();
    Trait2 = new QLineEdit();
    Trait3 = new QLineEdit();
    Trait4 = new QLineEdit();
    Trait5 = new QLineEdit();

    allSongsListWidget = new QListWidget();
    playlistListWidget = new QListWidget();

    // Action buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(button1);
    buttonLayout->addWidget(button2);
    buttonLayout->addWidget(button3);

    // Filter button
    QHBoxLayout *buttonLayout1 = new QHBoxLayout;
    buttonLayout1->addWidget(button4, 0, Qt::AlignCenter);

    // Arrow button
    QVBoxLayout *buttonLayout2 = new QVBoxLayout;
    buttonLayout2->addStretch();
    buttonLayout2->addWidget(button5, Qt::AlignCenter);
    buttonLayout2->addStretch();
    buttonLayout2->setAlignment(Qt::AlignVCenter);

    // Top Layout
    QVBoxLayout *topLayout = new QVBoxLayout();
    topLayout->addWidget(Info);
    topLayout->addWidget(allSongsListWidget);
    topLayout->addWidget(Info2);
    topLayout->addWidget(Trait1);
    topLayout->addWidget(Info3);
    topLayout->addWidget(Trait2);
    topLayout->addWidget(Info4);
    topLayout->addWidget(Trait3);
    topLayout->addWidget(Info5);
    topLayout->addWidget(Trait4);
    topLayout->addWidget(Info6);
    topLayout->addWidget(Trait5);
    topLayout->addWidget(button1);
    topLayout->addLayout(buttonLayout);
    topLayout->addLayout(buttonLayout1);

    // Middle Layout
    QVBoxLayout *middleLayout = new QVBoxLayout();
    middleLayout->addLayout(buttonLayout2);

    // Bottom Layout
    QVBoxLayout *bottomLayout = new QVBoxLayout();
    bottomLayout->addWidget(Info1);
    bottomLayout->addWidget(playlistListWidget);
    bottomLayout->addWidget(button6);
    bottomLayout->addWidget(button7);

    // Main Layout
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addLayout(topLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(middleLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(bottomLayout);
    mainLayout->setAlignment(topLayout, Qt::AlignLeft);
    mainLayout->setAlignment(middleLayout, Qt::AlignCenter);
    mainLayout->setAlignment(bottomLayout, Qt::AlignRight);
    buttonLayout2->setAlignment(Qt::AlignVCenter);
    sortTitleButton = new QPushButton("Sort by Title");
    sortArtistButton = new QPushButton("Sort by Artist");
    connect(sortTitleButton, &QPushButton::clicked, this, &MainWindow::sortByTitle);
    connect(sortArtistButton, &QPushButton::clicked, this, &MainWindow::sortByArtist);
    bottomLayout->addWidget(sortTitleButton);
    bottomLayout->addWidget(sortArtistButton);

    // Signal and Slot connections
    connect(button1, &QPushButton::clicked, this, &MainWindow::addSong);
    connect(button2, &QPushButton::clicked, this, &MainWindow::deleteSong);
    connect(button5, &QPushButton::clicked, this, &MainWindow::addToPlaylist);
    connect(button6, &QPushButton::clicked, this, &MainWindow::playSong);
    connect(button7, &QPushButton::clicked, this, &MainWindow::playNextSong);

    // Initialize the song list
    updateAllSongsList();
}

MainWindow::~MainWindow()
{

}
//update function
void MainWindow::updateAllSongsList()
{
    allSongsListWidget->clear();
    const vector<Song>& songs = repository->getAllSongs();
    for (const Song& song : songs) {
        QString songInfo = song.getTitle().c_str() + QString(" - ") + song.getArtist().c_str();
        allSongsListWidget->addItem(songInfo);
    }
}
//add song function
void MainWindow::addSong()
{
    string title = Trait1->text().toStdString();
    string artist = Trait2->text().toStdString();
    string year = Trait3->text().toStdString();

    try {
        songController->addSong(title, artist, year);
        updateAllSongsList();
    } catch (const SongException& exception) {
        QMessageBox::critical(this, "Error", exception.what());
    }

    Trait1->clear();
    Trait2->clear();
    Trait3->clear();
}
//remove song
void MainWindow::deleteSong()
{
    int selectedIndex = allSongsListWidget->currentIndex().row();
    if (selectedIndex >= 0) {
        const vector<Song>& songs = repository->getAllSongs();
        if (selectedIndex < static_cast<int>(songs.size())) {
            const Song& song = songs[selectedIndex];
            repository->remove(song);
            updateAllSongsList();
        }
    }
}

void MainWindow::addToPlaylist()
{
    int selectedIndex = allSongsListWidget->currentIndex().row();
    if (selectedIndex >= 0) {
        const vector<Song>& songs = repository->getAllSongs();
        if (selectedIndex < static_cast<int>(songs.size())) {
            const Song& song = songs[selectedIndex];
            playlist.push_back(song);
            QString songInfo = song.getTitle().c_str() + QString(" - ") + song.getArtist().c_str();
            playlistListWidget->addItem(songInfo);
        }
    }
}
//display song info
void MainWindow::playSong()
{
    int selectedIndex = playlistListWidget->currentIndex().row();
    if (selectedIndex >= 0) {
        if (selectedIndex < static_cast<int>(playlist.size())) {
            const Song& song = playlist[selectedIndex];
            QString message = "Now playing: " + QString::fromStdString(song.getTitle()) + " - " + QString::fromStdString(song.getArtist());
            QMessageBox::information(this, "Play", message);
        }
    }
}
//increment to next song
void MainWindow::playNextSong()
{
    if (!playlist.empty()) {
        playlist.erase(playlist.begin());
        delete playlistListWidget->takeItem(0);
    }
}
//sort by tutle ascending
void MainWindow::sortByTitle()
{
    bool ascending = true;
    vector<Song> sortedSongs = songController->getSortedByTitle(ascending);
    updateAllSongsList();
    for (const Song& song : sortedSongs) {
        QString songInfo = song.getTitle().c_str() + QString(" - ") + song.getArtist().c_str();
        allSongsListWidget->addItem(songInfo);
    }
}
//sort by artist ascending
void MainWindow::sortByArtist()
{
    bool ascending = true;
    vector<Song> sortedSongs = songController->getSortedByArtist(ascending);
    updateAllSongsList();
    for (const Song& song : sortedSongs) {
        QString songInfo = song.getTitle().c_str() + QString(" - ") + song.getArtist().c_str();
        allSongsListWidget->addItem(songInfo);
    }
}
