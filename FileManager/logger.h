#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QDebug>
#include "file.h"

class Logger : public QObject {
    Q_OBJECT

public:
    Logger() {}
    ~Logger() {}

public slots:
    void printExistInfo(File* file);
    void printChangedInfo(File* file);
};

#endif // LOGGER_H
