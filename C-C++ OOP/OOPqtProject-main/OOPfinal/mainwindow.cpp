#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "song.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("PlayListQt");
    //def
    Info = new QLabel("All songs");
    Info1 = new QLabel("Playlist");
    Info2 = new QLabel("Title:");
    Info3 = new QLabel("Artist:");
    Info4 = new QLabel("Duration:");
    Info5 = new QLabel("Link:");
    button1 = new QPushButton("Add");
    button2 = new QPushButton("Delete");
    button3 = new QPushButton("Update");
    button4 = new QPushButton("Filter");
    button5 = new QPushButton(">");
    button6 = new QPushButton("Play");
    button7 = new QPushButton("Next");
    //Traits of song class
    Trait1 = new QLineEdit();
    Trait2 = new QLineEdit();
    Trait3 = new QLineEdit();
    Trait4 = new QLineEdit();
    //Widgets for song and playlist
    allSongsListWidget = new QListWidget();
    playlistListWidget = new QListWidget();
    //Action buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(button1);
    buttonLayout->addWidget(button2);
    buttonLayout->addWidget(button3);
    //Filter button
    QHBoxLayout *buttonLayout1 = new QHBoxLayout;
    buttonLayout1->addWidget(button4, 0, Qt::AlignCenter);
    //Arrow button
    QVBoxLayout *buttonLayout2 = new QVBoxLayout;
    buttonLayout2->addStretch();
    buttonLayout2->addWidget(button5, Qt::AlignCenter);
    buttonLayout2->addStretch();
    buttonLayout2->setAlignment(Qt::AlignVCenter);
    //TopLayout
    QFormLayout *Toplayout = new QFormLayout();
    Toplayout->addRow(Info);
    Toplayout->addRow(allSongsListWidget);
    Toplayout->addRow(Info2, Trait1);
    Toplayout->addRow(Info3, Trait2);
    Toplayout->addRow(Info4, Trait3);
    Toplayout->addRow(Info5, Trait4);
    Toplayout->addRow(button1);
    Toplayout->addRow(buttonLayout);
    Toplayout->addRow(buttonLayout1);
    //Midle Layout
    QFormLayout *Midlayout = new QFormLayout();
    Midlayout->addRow(buttonLayout2);
    //Bottom Layout
    QFormLayout *Botlayout = new QFormLayout();
    Botlayout->addRow(Info1);
    Botlayout->addRow(playlistListWidget);
    Botlayout->addRow(button6, button7);
    //Main layout
    QHBoxLayout *Mainlayout = new QHBoxLayout(this);
    Mainlayout->addLayout(Toplayout);
    Mainlayout->addStretch();
    Mainlayout->addLayout(Midlayout);
    Mainlayout->addStretch();
    Mainlayout->addLayout(Botlayout);
    Mainlayout->setAlignment(Toplayout, Qt::AlignLeft);
    Mainlayout->setAlignment(Midlayout, Qt::AlignCenter);
    Mainlayout->setAlignment(Botlayout, Qt::AlignRight);
    buttonLayout2->setAlignment(Qt::AlignVCenter);
    // Connect button signals to slots
    connect(button1, &QPushButton::clicked, this, &MainWindow::addSong);
    connect(button2, &QPushButton::clicked, this, &MainWindow::deleteSong);
    connect(button5, &QPushButton::clicked, this, &MainWindow::addToPlaylist);
    connect(button3, &QPushButton::clicked, this, &MainWindow::showUpdateMessage);
    connect(button4, &QPushButton::clicked, this, &MainWindow::showFilterMessage);
}

void MainWindow::addSong()
{
    Song song;
    //store info as text
    song.title = Trait1->text();
    song.artist = Trait2->text();
    song.duration = Trait3->text();
    song.link = Trait4->text();
    //append to all songs
    allSongs.append(song);
    //add to widget
    QListWidgetItem *item = new QListWidgetItem(song.title);
    allSongsListWidget->addItem(item);
    //free memory
    Trait1->clear();
    Trait2->clear();
    Trait3->clear();
    Trait4->clear();
}
void MainWindow::deleteSong()
{
    //remove function
    int selectedIndex = allSongsListWidget->currentRow();
    if (selectedIndex >= 0) {
        allSongs.removeAt(selectedIndex);
        delete allSongsListWidget->takeItem(selectedIndex);
    }
}
void MainWindow::addToPlaylist()
{
    //add to playlist list
    int selectedIndex = allSongsListWidget->currentRow();
    if (selectedIndex >= 0) {
        Song selectedSong = allSongs.at(selectedIndex);
        playlistSongs.append(selectedSong);
        playlistListWidget->addItem(selectedSong.title);
    }
}
//infos using QMessageBox for unimplemented features
void MainWindow::showUpdateMessage()
{
    QMessageBox::information(this, "Update", "Not implemented yet");
}

void MainWindow::showFilterMessage()
{
    QMessageBox::information(this, "Filter", "Not implemented yet");
}
//destructor
MainWindow::~MainWindow(){}

