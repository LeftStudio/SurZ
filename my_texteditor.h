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
    bool canInsertFromMimeData(const QMimeData *source) const Q_DECL_OVERRIDE;
    void insertFromMimeData(const QMimeData *source) Q_DECL_OVERRIDE ;
    void dropImage(const QUrl &url, const QImage &image);

    ImageSizeDialog *m_ImageSizeDialog=nullptr;

signals:
    void openFile(QString);

};

#endif // MY_TEXTEDITOR_H
