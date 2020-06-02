#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

class QMovie;

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = nullptr);
    ~AboutDialog() Q_DECL_OVERRIDE ;

private:
    Ui::AboutDialog *ui;

    QMovie *m_LogoGif = nullptr;

    inline void initUI();
    bool eventFilter(QObject *obj, QEvent *event) Q_DECL_OVERRIDE ;
};

#endif // ABOUTDIALOG_H
