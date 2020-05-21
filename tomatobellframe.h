#ifndef TOMATOBELLFRAME_H
#define TOMATOBELLFRAME_H

#include <QFrame>
#include <QDateTime>

class QTimer;
class QPropertyAnimation;

namespace Ui {
class TomatobellFrame;
}

class TomatobellFrame : public QFrame
{
    Q_OBJECT

public:
    explicit TomatobellFrame(QWidget *parent = nullptr);
    ~TomatobellFrame() Q_DECL_OVERRIDE;

    void startAnimation();

    void initTomatobell(int w, int r, int num);

signals:
    void finished();

private slots:
    void update();

    void on_StopBtn_clicked();

    void on_PauseBtn_clicked();

private:
    Ui::TomatobellFrame *ui;

    QPropertyAnimation *animation;
    int workMin=0,relaxMin=0,tomatobellNum=0;
    int workSec=0,relaxSec=0;
    int workStep=0,relaxStep=0;
    bool isWork=true;
    QTimer *m_Timer=nullptr;
    QDateTime time;

    inline void initUI();

    inline void work();
    inline void relax();

    void closeEvent(QCloseEvent *)     Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *) Q_DECL_OVERRIDE;
};

#endif // TOMATOBELLFRAME_H
