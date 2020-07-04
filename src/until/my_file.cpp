/********************/
/*  By Left Studio  */
/*     @Ho 229      */
/********************/

#include "my_file.h"

#include <QTextStream>

my_File::my_File(const QString& fileName ,QObject *parent) :
    QObject(parent)
{
    m_File.setFileName(fileName);
    m_FileInfo.setFile(m_File);
}

bool my_File::readFile(QString &Text)
{
    if((!m_File.open(QFile::ReadOnly | QFile::Text)) || (!m_File.isReadable()))
        return false;

    QTextStream in(&m_File);
    Text=in.readAll();

    m_File.close();

    return true;
}

bool my_File::writeFile(const QString &Text)
{
    if((!m_File.open(QFile::WriteOnly | QFile::Text)) || (!m_File.isWritable()))
        return false;

    QTextStream out(&m_File);
    out<<Text;

    m_File.close();
    return true;
}

/*void my_File::setFileName(const QString &fileName)
{
    m_File.setFileName(fileName);
    m_FileInfo.setFile(m_File);
    m_FileWatcher->addPath(fileName);
}*/
