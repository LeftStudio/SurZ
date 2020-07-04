/********************/
/*  By Left Studio  */
/*     @Ho 229      */
/********************/

#include "searchframe.h"
#include "ui_searchframe.h"

#include <QPropertyAnimation>
#include <QCloseEvent>
#include <QMessageBox>

#if _MSC_VER >= 1600
    #pragma execution_character_set("utf-8")
#endif

SearchFrame::SearchFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SearchFrame)
{
    ui->setupUi(this);
    this->initUI();
    this->initSignalSlots();
}

SearchFrame::~SearchFrame()
{
    delete ui;
}

void SearchFrame::setTextEdit(My_TextEditor *txtEdit)
{
    m_txtEdit = txtEdit;
    m_cursor = m_txtEdit->textCursor();
}

void SearchFrame::setSelectedText(const QString &text)
{
    if(!text.isEmpty())
        ui->SearchLineEdit->setText(text);
}

void SearchFrame::on_textChanged()
{
    isChanged = true;
}

void SearchFrame::startAnimation()
{
    m_animation=new QPropertyAnimation(this,"geometry");
    m_animation->setDuration(200);
    m_animation->setStartValue(QRect(this->pos().x()+385,this->pos().y(),0,0));
    m_animation->setEndValue(QRect(this->pos().x(),this->pos().y(),370,30));
    m_animation->start();
}

void SearchFrame::endAnimation()
{
    if(m_animation!=nullptr)
    {
        m_animation->setStartValue(QRect(this->pos().x(),this->pos().y(),370,this->height()));
        m_animation->setEndValue(QRect(this->pos().x()+385,this->pos().y(),0,0));
        m_animation->start();
    }
}

void SearchFrame::initUI()
{
    ui->DisplaceWidget->hide();
    this->setFixedHeight(50);
    ui->OpenBtn->setFixedHeight(30);
    ui->SearchLineEdit->setTextMargins(2,2,25,2);
}

inline void SearchFrame::initSignalSlots()
{
    connect(ui->CaseSensitive,&QPushButton::clicked,
            [this](bool checked){
        if(checked)
            ui->CaseSensitive->setIcon(QIcon(":/images/images/icon/CaseSensitive_2.ico"));
        else
            ui->CaseSensitive->setIcon(QIcon(":/images/images/icon/CaseSensitive.ico"));
    });
}

void SearchFrame::closeEvent(QCloseEvent *event)
{
    emit finished();
    event->accept();
}

void SearchFrame::showEvent(QShowEvent *event)
{
    this->startAnimation();
    event->accept();
}

void SearchFrame::on_OpenBtn_clicked()
{
    if(isOpen)
    {
        ui->DisplaceWidget->hide();
        this->setFixedHeight(50);
        ui->OpenBtn->setFixedHeight(30);
        ui->OpenBtn->setIcon(QIcon(":/images/images/icon/down.ico"));

        isOpen=false;
    }
    else
    {
        ui->DisplaceWidget->show();
        this->setFixedHeight(90);
        ui->OpenBtn->setFixedHeight(70);
        ui->OpenBtn->setIcon(QIcon(":/images/images/icon/up.ico"));

        isOpen=true;
    }
}

void SearchFrame::on_CloseBtn_clicked()
{
    this->endAnimation();

    connect(m_animation,SIGNAL(finished()),this,
            SLOT(close()));
}

bool SearchFrame::searchLast()
{
    if(ui->CaseSensitive->isChecked())
        return m_txtEdit->find(ui->SearchLineEdit->text(),
                               QTextDocument::FindBackward | QTextDocument::FindCaseSensitively);
    return m_txtEdit->find(ui->SearchLineEdit->text(),QTextDocument::FindBackward);
}

bool SearchFrame::searchNext()
{
    if(ui->CaseSensitive->isChecked())
        return m_txtEdit->find(ui->SearchLineEdit->text(),
                               QTextDocument::FindCaseSensitively);
    return m_txtEdit->find(ui->SearchLineEdit->text());
}

void SearchFrame::on_FindLastBtn_clicked()
{
    if(!ui->SearchLineEdit->text().isEmpty())
    {
        if(!m_cursor.isNull())
            m_txtEdit->setTextCursor(m_cursor);

        if(isChanged)
        {
            m_txtEdit->moveCursor(QTextCursor::Start);
            isChanged = false;
        }

        if(!this->searchLast())
            QMessageBox::warning(this,("查找"),QString("找不到 \"%1\"")
                                 .arg(ui->SearchLineEdit->text()));
        m_cursor = m_txtEdit->textCursor();
    }
}

void SearchFrame::on_FindNextBtn_clicked()
{
    if(!ui->SearchLineEdit->text().isEmpty())
    {
        if(!m_cursor.isNull())
            m_txtEdit->setTextCursor(m_cursor);

        if(isChanged)
        {
            m_txtEdit->moveCursor(QTextCursor::Start);
            isChanged = false;
        }

        if(!this->searchNext())
            QMessageBox::warning(this,("查找"),QString("找不到 \"%1\"")
                                 .arg(ui->SearchLineEdit->text()));
        m_cursor = m_txtEdit->textCursor();
    }
}

void SearchFrame::on_DisplaceBtn_clicked()
{
    if(!ui->SearchLineEdit->text().isEmpty())
    {
        if(m_txtEdit->textCursor().hasSelection())
            m_txtEdit->insertPlainText(ui->DisplaceLineEdit->text());
        else
        {
            if(this->searchNext())
                m_txtEdit->insertPlainText(ui->DisplaceLineEdit->text());
            else
                QMessageBox::warning(this,("替换"),QString("找不到 \"%1\"")
                                     .arg(ui->SearchLineEdit->text()));
        }
    }
}

void SearchFrame::on_DisplaceAllBtn_clicked()
{
    if(!ui->SearchLineEdit->text().isEmpty())
    {
        m_txtEdit->moveCursor(QTextCursor::Start);
        while(this->searchNext())
            m_txtEdit->insertPlainText(ui->DisplaceLineEdit->text());
    }
}
