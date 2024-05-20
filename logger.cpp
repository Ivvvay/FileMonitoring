#include "logger.h"

void Logger::printExistInfo(File* file){
    if (file->checkExists())
        qDebug() << "File exists. Name: " << file->getFileName() << ". Size: " << file->getFileSize() << " bytes.";
    else
        qDebug() << "File does not exist. Name: " << file->getFileName();
}

void Logger::printChangedInfo(File* file){
    if (file->checkExists())
        qDebug() << "File changed. Name: " << file->getFileName() << ". Size: " << file->getFileSize() << " bytes.";
    else
        qDebug() << "File deleted. Name: " << file->getFileName();
}
