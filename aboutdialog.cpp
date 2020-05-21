/********************/
/*  By Left Studio  */
/*     @Ho 229      */
/********************/

#include "aboutdialog.h"
#include "ui_aboutdialog.h"

#include <QMovie>
#include <QMessageBox>

#if _MSC_VER >= 1600
    #pragma execution_character_set("utf-8")
#endif

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    this->initUI();
    ui->logoLabel->installEventFilter(this);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

bool AboutDialog::eventFilter(QObject *obj, QEvent *event)
{
    Q_UNUSED(obj);
    if (event->type() == QEvent::MouseButtonRelease)  // 鼠标点击
    {
        static int Egg=0;

        switch (Egg)
        {
        case 0:QMessageBox::information(this,("(*^▽^*)"),("新年快乐"));
            break;
        case 1:QMessageBox::information(this,("ヽ(￣▽￣)ﾉ"),("这个程序没有彩蛋"));
            break;
        case 2:QMessageBox::information(this,("(～￣▽￣)～ "),("这个程序真的没有彩蛋"));
            break;
        case 3:QMessageBox::information(this,("￣へ￣"),("我已经告诉你这个程序没有彩蛋了"));
            break;
        case 4:QMessageBox::warning(this,("ヽ(#`Д´)ﾉ"),("停下!       "));
            break;
        case 5:QMessageBox::information(this,("o(*≧д≦)o!!"),("行行行，我给你彩蛋，你能走开吗?"));
            break;
        case 6:QMessageBox::about(this,("(｡◕ᴗ◕｡)づ╭❤～"),("╭——ゞこ≈—————ヽ☆——ャ╮\n\n  ☆喜欢..や偷看..ゞě.伱的脸ぐ ☆\n\n  ┊ず..带着ぺ股.ふ.香甜的气味..ヅ┊\n\n╰————☆╰——— .+.+.ヽ——╯"));
            break;
        default:QMessageBox::information(this,("(๑＞ڡ＜)☆"),("给开发者一点鸡腿吧!么么哒(๑＞ڡ＜)✿ "));
            break;
        }
        Egg++;
    }
    return  false;
}

void AboutDialog::initUI()
{
    /* 限定窗口大小 */
    this->setFixedSize(this->size());

    /* 播放Logo动画 */
    m_LogoGif = new QMovie(this);
    m_LogoGif->setFileName(":/images/images/Left_Studio.gif");

    connect(m_LogoGif,&QMovie::frameChanged,
           [this](int frameNumber) { if(frameNumber == 20) m_LogoGif->stop(); });

    m_LogoGif->setScaledSize(ui->logoLabel->size());
    ui->logoLabel->setMovie(m_LogoGif);
    m_LogoGif->start();

    ui->label->setOpenExternalLinks(true);      // 设置打开链接

    this->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
}
