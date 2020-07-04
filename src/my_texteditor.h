#ifndef MY_TEXTEDITOR_H
#define MY_TEXTEDITOR_H

#include "imagesizedialog.h"
#include "translatedialog.h"

#include <QTextEdit>

class My_TextEditor : public QTextEdit
{
    Q_OBJECT

public:
    My_TextEditor(QWidget *parent = nullptr);

    QMenu *getContextMenu() const { return this->m_contextMenu; }

signals:
    void openFile(QString);

private:
    void dropImage(const QUrl &url, const QImage &image);

    bool canInsertFromMimeData(const QMimeData *source) const Q_DECL_OVERRIDE;
    void insertFromMimeData(const QMimeData *source)          Q_DECL_OVERRIDE;

    void contextMenuEvent(QContextMenuEvent *event)           Q_DECL_OVERRIDE;

    ImageSizeDialog *m_ImageSizeDialog = nullptr;

    QMenu *m_contextMenu = nullptr;
};

#endif // MY_TEXTEDITOR_H
