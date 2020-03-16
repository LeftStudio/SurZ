#ifndef MY_TEXTEDITOR_H
#define MY_TEXTEDITOR_H

#include "imagesizedialog.h"

#include <QTextEdit>

class My_TextEditor : public QTextEdit
{
    Q_OBJECT

public:
    My_TextEditor(QWidget *parent = nullptr);

private:
    bool canInsertFromMimeData(const QMimeData *source) const;
    void insertFromMimeData(const QMimeData *source);
    void dropImage(const QUrl &url, const QImage &image);

    ImageSizeDialog *m_ImageSizeDialog=nullptr;

signals:
    void callOpenFile(QString);

};

#endif // MY_TEXTEDITOR_H
