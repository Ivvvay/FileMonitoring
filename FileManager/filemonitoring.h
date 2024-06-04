#ifndef FILEMONITORING_H
#define FILEMONITORING_H

#include <QObject>
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
    void updateFileStatus();

private:
    FileMonitoring();
    ~FileMonitoring();

signals:
    void existFileInfo(File* file);
    void changedFileInfo(File* file);

private:
    QList<File> m_files;
    Logger* m_logger;
};

#endif // FILEMONITORING_H

