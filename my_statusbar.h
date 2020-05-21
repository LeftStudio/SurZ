#ifndef MY_STATUSBAR_H
#define MY_STATUSBAR_H

#include <QFrame>

namespace Ui {
class my_StatusBar;
}

class my_StatusBar : public QFrame
{
    Q_OBJECT

public:
    explicit my_StatusBar(QWidget *parent = nullptr);
    ~my_StatusBar();

    void setCurpos(const int& row, const int& col, const int& count) const ;
    void setSaved(const bool& isSave) const ;

private:
    Ui::my_StatusBar *ui;
};

#endif // MY_STATUSBAR_H
