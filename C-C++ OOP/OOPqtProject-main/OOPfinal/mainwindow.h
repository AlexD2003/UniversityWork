#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QMessageBox>
#include "song.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE




class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    //song functions and message prompts
    void addSong();
    void deleteSong();
    void addToPlaylist();
    void showUpdateMessage();
    void showFilterMessage();

private:

    QVector<Song> allSongs;
    QVector<Song> playlistSongs;
    QListWidget *allSongsListWidget;
    QListWidget *playlistListWidget;
    //def
    QLabel *Info;
    QLabel *Info1;
    QLabel *Info2;
    QLabel *Info3;
    QLabel *Info4;
    QLabel *Info5;
    QLineEdit *Trait1;
    QLineEdit *Trait2;
    QLineEdit *Trait3;
    QLineEdit *Trait4;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;
    QPushButton *button7;
};
#endif // MAINWINDOW_H
