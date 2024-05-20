#ifndef FILEMONITORING_H
#define FILEMONITORING_H

#include <QObject>
#include <QFileInfo>
#include <QString>
#include <QTimer>
#include <QList>
#include "file.h"
#include "logger.h"

class FileMonitoring : public QObject {
    Q_OBJECT

public:
    static FileMonitoring& Instance(){
        static FileMonitoring temp;
        return temp;
    }

    void addFile(const QString& path);
    void removeFile(const QString& path);

    void startTimer(QTimer* timer);

private:
    FileMonitoring();
    ~FileMonitoring();

public slots:
    void updateFileStatus();

signals:
    void existFileInfo(File* file);
    void changedFileInfo(File* file);

private:
    QList<File> m_files;
    Logger* m_logger;
};

#endif // FILEMONITORING_H

