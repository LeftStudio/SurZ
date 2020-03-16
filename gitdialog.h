#ifndef GITDIALOG_H
#define GITDIALOG_H

#include <QDialog>

namespace Ui {
class GitDialog;
}

class GitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GitDialog(QWidget *parent = nullptr);
        ~GitDialog();

    void GetPath(QString FilePath);

private slots:
    void on_GitPathBtn_clicked();

    void on_FilePathBtn_clicked();

    void on_CommitBtn_clicked();

private:
    Ui::GitDialog *ui;

    QString m_FilePath;
    QString m_GitPath;
    QString m_Notes;

    inline void initUI();

};

#endif // GITDIALOG_H
