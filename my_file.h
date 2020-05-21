#ifndef MY_FILE_H
#define MY_FILE_H

#include <QObject>
#include <QFile>
#include <QFileInfo>

class QFileSystemWatcher;

class my_File : public QObject
{
    Q_OBJECT
public:
    explicit my_File(const QString& filename ,QObject *parent = nullptr);
    ~my_File() {}

    bool readFile(QString& Text);

    bool writeFile(const QString& Text);

    bool isRichTextFile() const { return !(m_FileInfo.suffix()=="txt"); }

    void setFileName(const QString& fileName);

    QFileSystemWatcher *getFileWatcher() const { return m_FileWatcher; }

    QFileInfo getFileInfo() const { return m_FileInfo; }

signals:
    void fileChanged();

private:
    QFile m_File;
    QFileInfo m_FileInfo;
    QFileSystemWatcher *m_FileWatcher = nullptr;

};

#endif // MY_FILE_H
