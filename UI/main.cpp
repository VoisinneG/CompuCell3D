//
// Created by Anwar on 8/30/17.
//

#include "mainwindow.h"
#include <QApplication>

/**
 * This is the main method of a CompuCell3D program. It invokes the MainWindow for CompuCell3D.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setFocus();
    return a.exec();
}
