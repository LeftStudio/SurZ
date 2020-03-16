#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QMouseEvent>

class QLabel;

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = nullptr);
    ~AboutDialog();

private:
    Ui::AboutDialog *ui;

    inline void initUI();
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // ABOUTDIALOG_H
