#include "file.h"
#include <QDateTime>

File::File(const QString& path) {
    m_fileInfo = QFileInfo(path);
}

bool File::checkExists() const {
    return m_fileInfo.exists();
}

QString File::getFilePath() const {
    return m_fileInfo.absoluteFilePath();
}

QString File::getFileName() const {
    return m_fileInfo.fileName();
}

qint64 File::getFileSize() const {
    return m_fileInfo.size();
}

QDateTime File::getLastChanged() const {
    return m_fileInfo.lastModified();
}

void File::refreshFileInfo() {
    return m_fileInfo.refresh();
}
