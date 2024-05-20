#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QFileInfo>
#include <QDateTime>

class File {
public:
    File(const QString& path);

    bool checkExists() const;
    QString getFilePath() const;
    QString getFileName() const;
    qint64 getFileSize() const;
    QDateTime getLastChanged() const;

    void refreshFileInfo();

private:
    QString m_filePath;
    QFileInfo m_fileInfo;
};

#endif // FILE_H
