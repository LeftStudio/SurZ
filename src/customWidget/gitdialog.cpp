/********************/
/*  By Left Studio  */
/*     @Ho 229      */
/********************/

#include "gitdialog.h"
#include "ui_gitdialog.h"

#include <QFileDialog>
#include <QMessageBox>

#ifdef Q_OS_WIN
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

#if _MSC_VER >= 1600
    #pragma execution_character_set("utf-8")
#endif

GitDialog::GitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GitDialog)
{
    ui->setupUi(this);
    this->initUI();
}

GitDialog::~GitDialog()
{
    delete ui;
}

void GitDialog::GetPath(QString FilePath)
{
    ui->GitPathEdit->setText(QFileInfo(FilePath).path());
    ui->FilePathEdit->setText(QFileInfo(FilePath).path());
}

void GitDialog::on_GitPathBtn_clicked()
{
    QString Path=QFileDialog::getExistingDirectory(this,("请选择Git目录"),
        QDir::currentPath());
    ui->GitPathEdit->setText(Path);
}

void GitDialog::on_FilePathBtn_clicked()
{
    QString Path=QFileDialog::getExistingDirectory(this,("请选择文件目录"),
        QDir::currentPath());
    ui->FilePathEdit->setText(Path);
}

void GitDialog::on_CommitBtn_clicked()
{
    m_GitPath=ui->GitPathEdit->text();
    m_FilePath=ui->FilePathEdit->text();
    m_Notes=ui->NotesEdit->toPlainText();
    if(m_GitPath.isEmpty()||m_FilePath.isEmpty())
        QMessageBox::warning(this,("警告"),("请输入Git目录和文件目录"));
    else
    {
        system(QString("cd \"%1\" & git add %2 & git commit -m \"%3\"").arg(m_GitPath)
            .arg(m_FilePath).arg(m_Notes).toUtf8().data());
    }
}

void GitDialog::initUI()
{
    ui->CommitBtn->setDefault(true);

    this->setFixedSize(this->size());
    this->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
}
