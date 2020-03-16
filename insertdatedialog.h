#ifndef INSERTDATEDIALOG_H
#define INSERTDATEDIALOG_H

#include <QDialog>

namespace Ui {
class InsertDateDialog;
}

class InsertDateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InsertDateDialog(QWidget *parent = nullptr);
    ~InsertDateDialog();

    void getDateTimeString(QString *s){ DateTimeString=s; }

private:
    Ui::InsertDateDialog *ui;

    inline void initTime();
    inline void initUI();

    QString *DateTimeString;
};

#endif // INSERTDATEDIALOG_H
