#include "filemanager.h"
#include <QDebug>

FileMonitoring::FileMonitoring() {
    m_logger = new Logger();
    connect(this, &FileMonitoring::existFileInfo, m_logger, &Logger::printExistInfo);
    connect(this, &FileMonitoring::changedFileInfo, m_logger, &Logger::printChangedInfo);
}

FileMonitoring::~FileMonitoring() {
    delete m_logger;
}

void FileMonitoring::addFile(const QString& path) {
    File file(path);

    if (file.checkExists())
        m_files.push_back(file);

    emit existFileInfo(&file);
}

void FileMonitoring::removeFile(const QString& path) {
    int index = -1;
    QFileInfo removeFileInfo(path);

    for (int i = 0; i < m_files.size(); ++i) {
        if (m_files[i].getFilePath() == removeFileInfo.absoluteFilePath()) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        m_files.removeAt(index);
        qDebug() << "File removed from monitoring: " << path;
    } else {
        qDebug() << "File not found in monitoring list: " << path;
    }
}

void FileMonitoring::updateFileStatus() {
    for (auto& it : m_files) {
        QFileInfo updatedFileInfo(it.getFilePath());

        if (updatedFileInfo.lastModified() != it.getLastChanged()) {
            it.refreshFileInfo();
            emit changedFileInfo(&it);
        }
    }
}
