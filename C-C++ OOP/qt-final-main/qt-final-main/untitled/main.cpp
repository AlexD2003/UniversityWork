#include "mainwindow.h"
#include <QApplication>
#include "repository.h"
#include "songController.h"
#include "RepositoryTest.h"
#include "SongControllerTest.h"
#include "fileRepository.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Run repository and song controller tests
    RepositoryTest repositoryTest;
    repositoryTest.runTests();
    SongControllerTest songControllerTest;
    songControllerTest.runTests();

    Repository* repo = new FileRepository("song.txt");
    SongController* ctrl = new SongController(*repo);
    MainWindow w(ctrl);
    return a.exec();
}
