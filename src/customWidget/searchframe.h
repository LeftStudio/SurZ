#ifndef SEARCHFRAME_H
#define SEARCHFRAME_H

#include <QFrame>

#include "my_texteditor.h"

class QPropertyAnimation;

namespace Ui {
class SearchFrame;
}

class SearchFrame : public QFrame
{
    Q_OBJECT

public:
    explicit SearchFrame(QWidget *parent = nullptr);
    ~SearchFrame() Q_DECL_OVERRIDE ;

    void setTextEdit(My_TextEditor* txtEdit);

    void setSelectedText(const QString &text);

public slots:
    void on_textChanged();

private slots:
    void on_OpenBtn_clicked();

    void on_CloseBtn_clicked();

    void on_FindLastBtn_clicked();

    void on_FindNextBtn_clicked();

    void on_DisplaceBtn_clicked();

    void on_DisplaceAllBtn_clicked();

signals:
    void finished();

private:
    Ui::SearchFrame *ui;

    bool isOpen = false;      // 是否展开
    bool isChanged = false;
    QPropertyAnimation *m_animation = nullptr;
    My_TextEditor      *m_txtEdit   = nullptr;
    QTextCursor m_cursor;

    inline void initUI();
    inline void initSignalSlots();

    inline void startAnimation();
    inline void endAnimation();

    inline bool searchLast();
    inline bool searchNext();

    void showEvent(QShowEvent *event)   Q_DECL_OVERRIDE;
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;
};

#endif // SEARCHFRAME_H
