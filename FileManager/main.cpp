#include <QCoreApplication>
#include <thread>
#include <iostream>
#include <QDir>
#include "filemanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create test files
    QFile file1("../file1.txt");
    QFile file2("../file2.txt");
    if (!file1.open(QIODevice::WriteOnly) || !file2.open(QIODevice::WriteOnly)) {
        std::cerr << "Cannot create test files and directories" << std::endl;
        return 1;
    }
    file1.write("Hello, world!");
    file2.write("Goodbye, world!");
    file1.close();
    file2.close();

    FileMonitoring& fileMonitoring = FileMonitoring::Instance();

    QTimer* timer = new QTimer();
    timer->setInterval(100);

    fileMonitoring.addFile("../file1.txt");
    fileMonitoring.addFile("../file2.txt");
    fileMonitoring.addFile("../file3.txt");

    fileMonitoring.startTimer(timer);

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    fileMonitoring.removeFile("../file2.txt");
    fileMonitoring.removeFile("../file3.txt");

    return a.exec();
}
