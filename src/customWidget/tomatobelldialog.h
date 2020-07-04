#ifndef TOMATOBELLDIALOG_H
#define TOMATOBELLDIALOG_H

#include <QDialog>

namespace Ui {
class TomatobellDialog;
}

class TomatobellDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TomatobellDialog(QWidget *parent = nullptr);
    ~TomatobellDialog();

    void setTomatobell(int *w,int *r,int *num)
    {
        workMin=w;
        relaxMin=r;
        tomatobellNum=num;
    }

private slots:
    void on_OK_Btn_clicked();

private:
    Ui::TomatobellDialog *ui;

    int *workMin=nullptr,*relaxMin=nullptr,*tomatobellNum=nullptr;

    inline void initUI();
};

#endif // TOMATOBELLDIALOG_H
