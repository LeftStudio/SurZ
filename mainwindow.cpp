/********************/
/*  By Left Studio  */
/*     @Ho 229      */
/********************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QSpinBox>
#include <QFontComboBox>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QColorDialog>
#include <QCloseEvent>
#include <QSettings>
#include <QImageReader>
#include <QInputDialog>
#include <QStandardPaths>
#include <QSound>
#include <QDebug>
#include <QDir>

#if _MSC_VER >= 1600
    #pragma execution_character_set("utf-8")
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initUI();
    this->initSignalSlots();
    this->initFile();
    this->loadSettings();
}

MainWindow::~MainWindow()
{
    if(m_File!=nullptr)
        delete m_File;

    delete ui;
}

void MainWindow::initUI()
{
    // 状态栏
    m_StatusBar=new my_StatusBar(this);
    m_StatusBar->move(360,2);
    m_StatusBar->setSaved(true);
    m_StatusBar->setCurpos(1,0,0);

    #ifndef Q_OS_WIN32
       // ui->menuBar->hide();
       // m_StatusBar->hide();
    #endif

    // 更换背景
    backgroundGroup=new QActionGroup(this);
    QList<QAction *> actions = ui->backgroundMenu->actions();
    for(QAction *act : actions)
        backgroundGroup->addAction(act);

    // 文本样式工具栏
    alignmentGroup=new QActionGroup(this);
    alignmentGroup->addAction(ui->actLeftAlign);
    alignmentGroup->addAction(ui->actCenter);
    alignmentGroup->addAction(ui->actRightAlign);

    spinFontSize=new QSpinBox(this);
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    spinFontSize->setValue(ui->txtEdit->font().pointSize());
    spinFontSize->setMinimumWidth(50);
    ui->TextStyleToolBar->addWidget(new QLabel(("字体大小 "),this));
    ui->TextStyleToolBar->addWidget(spinFontSize);
    ui->TextStyleToolBar->addSeparator();       // 分隔栏

    comboFont=new QFontComboBox(this);
    comboFont->setMinimumWidth(50);
    comboFont->setMaximumWidth(115);
    comboFont->setCurrentFont(ui->txtEdit->currentCharFormat().font());
    ui->TextStyleToolBar->addWidget(new QLabel(("字体 "),this));
    ui->TextStyleToolBar->addWidget(comboFont);
    ui->TextStyleToolBar->addSeparator();       // 分隔栏

    ui->TextStyleToolBar->addAction(ui->actSetTextColor);

    // 工具栏右键菜单
    QMenu *menu = QMainWindow::createPopupMenu();
    menu->actions().at(0)->setText(("显示主工具栏"));
    menu->actions().at(1)->setText(("显示字体样式工具栏"));
    menu->actions().at(2)->setText(("显示插入工具栏"));

    this->setCentralWidget(ui->txtEdit);
}

void MainWindow::initFile()
{
    QStringList args=QCoreApplication::arguments();
    if(args.size()==2)
    {
        QString filePath=args.at(1);
        if(!filePath.isEmpty())
        {
            my_File* newFile=new my_File(filePath);

            bool isRTF=newFile->isRichTextFile();
            ui->actAcceptRichText->setChecked(isRTF);
            ui->actSaveToRichText->setChecked(isRTF);

            QString text;
            if(newFile->readFile(text))
                ui->txtEdit->setText(text);
            else
            {
                delete newFile;
                QMessageBox::critical(this,("错误"),("文件打开失败"));
                return;
            }

            connect(newFile,&my_File::fileChanged,
                    [this]{
                if(QMessageBox::question(this,"警告","当前文件已发生变化,是否重新打开",
                                         QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes)
                    this->on_actOpen_triggered();
            });

            m_File = newFile;
            m_StatusBar->setSaved(true);
            this->setWindowTitle(QString("书知编辑器 - %1").arg(m_File->getFileInfo().fileName()));

            for(QAction* act : ui->recentlyOpenedMenu->actions())
            {
                if(act->text()==m_File->getFileInfo().absoluteFilePath())
                    ui->recentlyOpenedMenu->removeAction(act);
            }
            ui->recentlyOpenedMenu->addAction(
                        new QAction(m_File->getFileInfo().absoluteFilePath(),this));
        }
    }
}

void MainWindow::initSignalSlots()
{
    // 关联自定义信号槽
    connect(spinFontSize,SIGNAL(valueChanged(int)),this,
            SLOT(spinFontSize_valueChanged(int)));
    connect(comboFont,SIGNAL(currentIndexChanged(const QString &)),this,
            SLOT(comboFont_currentIndexChanged(const QString &)));

    connect(ui->actAboutQt,&QAction::triggered,
            [this]{ QMessageBox::aboutQt(this); });
    connect(ui->actWindowTop,&QAction::triggered,
            [this](bool checked){
        this->setWindowFlag(Qt::WindowStaysOnTopHint,checked);
        this->show();
    });

    connect(ui->actLeftAlign,&QAction::triggered,
            [this]{ ui->txtEdit->setAlignment(Qt::AlignLeft); });
    connect(ui->actCenter,&QAction::triggered,
            [this]{ ui->txtEdit->setAlignment(Qt::AlignCenter); });
    connect(ui->actRightAlign,&QAction::triggered,
            [this]{ ui->txtEdit->setAlignment(Qt::AlignRight); });

    connect(ui->actNoWrap,&QAction::triggered,
            [this]{ ui->txtEdit->setLineWrapMode(QTextEdit::NoWrap); });
    connect(ui->actWidgetWidth,&QAction::triggered,
            [this]{ ui->txtEdit->setLineWrapMode(QTextEdit::WidgetWidth); });
    connect(ui->actFixedPixelWidth,&QAction::triggered,
            [this]{ ui->txtEdit->setLineWrapMode(QTextEdit::FixedPixelWidth); });

}

void MainWindow::loadSettings()
{
    settings=new QSettings(QString("./SurZ_Settings.ini"),QSettings::IniFormat,this);
    settings->setIniCodec("UTF-8");

    if(settings->contains("Window/WindowSize"))
        this->resize(settings->value("Window/WindowSize",QVariant(QSize())).toSize());

    if(settings->contains("Window/WindowPos"))
        this->move(settings->value("Window/WindowPos",QVariant(QPoint())).toPoint());

    if(settings->contains("Window/Background"))
    {
        int background=settings->value("Window/Background",QVariant(int())).toInt();
        if(background != 0)
        {
            ui->txtEdit->setStyleSheet(QString("QTextEdit\n"
                                               "{\n"
                                               "border-image:url(:/backgrounds/backgrounds/background_%1.jpg);\n"
                                               "padding:3px;\n"
                                               "border-radius:11px;\n"
                                               "}\n"
                                               ).arg(background));
            this->findChild<QAction *>(QString("actBackground_%1").arg(background))->setChecked(true);
        }
    }

    if(settings->contains("SurZ/ToolbarText"))
    {
        bool isChecked=settings->value("SurZ/ToolbarText",QVariant(bool())).toBool();
        ui->actToolbarStyle->setChecked(isChecked);
        this->on_actToolbarStyle_triggered(isChecked);
    }

    if(settings->contains("SurZ/AutoSave"))
    {
        bool isChecked=settings->value("SurZ/AutoSave",QVariant(bool())).toBool();
        ui->actAutoSave->setChecked(isChecked);
    }

    int size=settings->beginReadArray("RecentlyOpened");
    for (int i=0;i<size;i++)
    {
        settings->setArrayIndex(i);
        ui->recentlyOpenedMenu->addAction(new QAction(settings->value("FilePath").toString()));
    }
    settings->endArray();
}

void MainWindow::saveSettings()
{
    settings->setValue("Window/WindowSize",QVariant(this->size()));
    settings->setValue("Window/WindowPos",QVariant(this->pos()));

    settings->setValue("SurZ/ToolbarText",QVariant(ui->actToolbarStyle->isChecked()));
    settings->setValue("SurZ/AutoSave",QVariant(ui->actAutoSave->isChecked()));

    settings->beginWriteArray("RecentlyOpened");
    for (int i=2;i<ui->recentlyOpenedMenu->actions().size();i++)
    {
        settings->setArrayIndex(i-2);
        settings->setValue("FilePath",ui->recentlyOpenedMenu->actions().at(i)->text());
    }
    settings->endArray();
}

void MainWindow::on_txtEdit_copyAvailable(bool b)
{
    // 更新cut,copy,paste的enabled属性
    ui->actCut->setEnabled(b);
    ui->actCopy->setEnabled(b);
    ui->actPaste->setEnabled(ui->txtEdit->canPaste());
}

void MainWindow::on_actFontBold_triggered(bool checked)
{
    // 粗体 || Normal
    QTextCharFormat fmt=ui->txtEdit->currentCharFormat();
    if(checked)
        fmt.setFontWeight((QFont::Bold));
    else
        fmt.setFontWeight(QFont::Normal);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actFontItalic_triggered(bool checked)
{
    // 斜体 || Normal
    QTextCharFormat fmt=ui->txtEdit->currentCharFormat();
    fmt.setFontItalic(checked);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actFontUnder_triggered(bool checked)
{
    // 下划线 || Normal
    QTextCharFormat fmt=ui->txtEdit->currentCharFormat();
    fmt.setFontUnderline(checked);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actFontStrikeout_triggered(bool checked)
{
    // 删除线 || Normal
    QTextCharFormat fmt=ui->txtEdit->currentCharFormat();
    fmt.setFontStrikeOut(checked);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::spinFontSize_valueChanged(int aFontSize)
{
    // 改变字体大小
    QTextCharFormat fmt=ui->txtEdit->currentCharFormat();
    fmt.setFontPointSize(aFontSize);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::comboFont_currentIndexChanged(const QString &arg1)
{
    // 选择字体
    QTextCharFormat fmt=ui->txtEdit->currentCharFormat();
    fmt.setFontFamily(arg1);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actToolbarStyle_triggered(bool checked)
{
    if(checked)
    {
        ui->mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        ui->TextStyleToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        ui->InsertToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    }
    else
    {
        ui->mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        ui->TextStyleToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        ui->InsertToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
    }
}

bool MainWindow::checkFileSave()
{
    if(ui->txtEdit->document()->isModified())
    {
        int chose = QMessageBox::question(this,("警告"),("是否保存当前文件"),
            QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);

        if(chose==QMessageBox::Cancel)
            return false;
        else
        {
            if(chose==QMessageBox::Yes)
                this->on_actSave_triggered();

            this->setWindowTitle("书知编辑器");
            delete m_File;
            m_File = nullptr;
        }
    }
    return true;
}

void MainWindow::on_recentlyOpenedMenu_triggered(QAction *act)
{
    if(act->text()!="清空记录")
    {
        if(!checkFileSave())
            return;

        my_File* newFile=new my_File(std::move(act->text()));

        bool isRTF=newFile->isRichTextFile();
        ui->actAcceptRichText->setChecked(isRTF);
        ui->actSaveToRichText->setChecked(isRTF);

        QString text;
        if(newFile->readFile(text))
            ui->txtEdit->setText(text);
        else
        {
            delete newFile;
            QMessageBox::critical(this,("错误"),("文件打开失败"));
            return;
        }

        connect(newFile,&my_File::fileChanged,
                [this]{
            if(QMessageBox::question(this,"警告","当前文件已发生变化,是否重新打开",
                                     QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes)
                this->on_actOpen_triggered();
        });

        m_File = newFile;
        m_StatusBar->setSaved(true);
        this->setWindowTitle(QString("书知编辑器 - %1").arg(m_File->getFileInfo().fileName()));

        for(QAction* act : ui->recentlyOpenedMenu->actions())
        {
            if(act->text()==m_File->getFileInfo().absoluteFilePath())
                ui->recentlyOpenedMenu->removeAction(act);
        }
        ui->recentlyOpenedMenu->addAction(
                    new QAction(m_File->getFileInfo().absoluteFilePath(),this));
    }
}

void MainWindow::on_backgroundMenu_triggered(QAction *act)
{
    if(act->objectName()=="actBackground_Null")
    {
        ui->txtEdit->setStyleSheet("QTextEdit\n"
                                   "{\n"
                                   "background-color: transparent;\n"
                                   "background:rgb(242,242,242);\n"
                                   "padding:3px;\n"
                                   "border-radius:11px;\n"
                                   "border:3px solid #DCE4EC;\n"
                                   "}\n"
                                   "\n"
                                   "QTextEdit:focus\n"
                                   "{\n"
                                   "border:3px solid #aaaaff;\n"
                                   "}");
        settings->setValue("Window/Background",QVariant(0));
    }
    else
    {
        ui->txtEdit->setStyleSheet(QString("QTextEdit\n"
                                           "{\n"
                                           "border-image:url(:/backgrounds/backgrounds/background_%1.jpg);\n"
                                           "border-radius:11px;\n"
                                           "padding:3px;\n"
                                           "}\n"
                                           ).arg(act->objectName().mid(14)));
        settings->setValue("Window/Background",QVariant(act->objectName().mid(14)));
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(!checkFileSave())
    {
        event->ignore();
        return;
    }

    saveSettings();
    event->accept();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    this->SearchFrameUpdate();
    this->TomatobellFrameUpdate();
}

void MainWindow::on_actOpen_triggered()
{
    if(!checkFileSave())
        return;

    QString filePath = QFileDialog::getOpenFileName(nullptr,("打开文件"),QDir::homePath(),
        ("富文本(*.rtf *.html);;文本文件(*.txt);;所有文件(*.*)"));
    if(filePath.isEmpty())
        return;

    my_File* newFile=new my_File(filePath);

    bool isRTF=newFile->isRichTextFile();
    ui->actAcceptRichText->setChecked(isRTF);
    ui->actSaveToRichText->setChecked(isRTF);

    QString text;
    if(newFile->readFile(text))
        ui->txtEdit->setText(text);
    else
    {
        delete newFile;
        QMessageBox::critical(this,("错误"),("文件打开失败"));
        return;
    }

    connect(newFile,&my_File::fileChanged,
            [this]{
        if(QMessageBox::question(this,"警告","当前文件已发生变化,是否重新打开",
                                 QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes)
            this->on_actOpen_triggered();
    });

    m_File = newFile;
    m_StatusBar->setSaved(true);
    this->setWindowTitle(QString("书知编辑器 - %1").arg(m_File->getFileInfo().fileName()));

    for(QAction* act : ui->recentlyOpenedMenu->actions())
    {
        if(act->text()==m_File->getFileInfo().absoluteFilePath())
            ui->recentlyOpenedMenu->removeAction(act);
    }
    ui->recentlyOpenedMenu->addAction(
                new QAction(m_File->getFileInfo().absoluteFilePath(),this));

    return;
}

void MainWindow::on_actSave_triggered()
{
    if(m_File==nullptr)
    {
        QString filePath = QFileDialog::getSaveFileName(this,("保存文件"),QDir::homePath(),
            ("富文本(*.rtf *.html);;文本文件(*.txt);;所有文件(*.*)"));
        if(filePath.isEmpty())
            return;

        m_File = new my_File(filePath);
    }

    QString text;
    if(ui->actSaveToRichText->isChecked())
        text=ui->txtEdit->toHtml();
    else
        text=ui->txtEdit->toPlainText();

    if(m_File->writeFile(text))
    {
        ui->txtEdit->document()->setModified(false);
        m_StatusBar->setSaved(true);
        this->setWindowTitle(QString("书知编辑器 - %1").arg(m_File->getFileInfo().fileName()));
        QSound::play(":/BGM/BGM/saveFileBGM.wav");
    }

    return;
}

void MainWindow::on_actNew_triggered()
{
    if(!checkFileSave())
        return;

    QString newFileName = QFileDialog::getSaveFileName(this,("新建文件"),QDir::homePath(),
        ("富文本(*.rtf *.html);;文本文件(*.txt);;所有文件(*.*)"));
    if(newFileName.isEmpty())
        return;

    my_File *newFile = new my_File(newFileName);

    bool isRTF=newFile->isRichTextFile();
    ui->actAcceptRichText->setChecked(isRTF);
    ui->actSaveToRichText->setChecked(isRTF);

    if(newFile->writeFile(std::move(QString(""))))
    {
        m_File=newFile;
        this->setWindowTitle(QString("书知编辑器 - %1").arg(m_File->getFileInfo().fileName()));
        ui->txtEdit->clear();
    }
    else
        QMessageBox::critical(this,("错误"),("文件创建失败"));

    return;
}

void MainWindow::on_actSaveAs_triggered()
{
    QString saveAsFileName = QFileDialog::getSaveFileName(this,("另存为..."),QDir::homePath(),
        ("富文本(*.rtf *.html);;文本文件(*.txt);;所有文件(*.*)"));
    if(saveAsFileName.isEmpty())
        return;

    my_File *newFile = new my_File(saveAsFileName);

    QString text;
    if(ui->actSaveToRichText->isChecked())
        text=ui->txtEdit->toHtml();
    else
        text=ui->txtEdit->toPlainText();

    if(!newFile->writeFile(text))
        QMessageBox::critical(this,("错误"),("文件另存为失败"));

    return;
}

void MainWindow::on_txtEdit_textChanged()
{
    if(ui->txtEdit->toPlainText().isEmpty())
    {
        ui->actClear->setEnabled(false);
        ui->actSearch->setEnabled(false);
    }
    else
    {
        ui->actClear->setEnabled(true);
        if(m_SearchFrame==nullptr)
            ui->actSearch->setEnabled(true);
    }
    m_StatusBar->setSaved(false);

    if(ui->actAutoSave->isChecked())
    {
        static int textChanged = 0;
        ++textChanged;

        if(textChanged == 100)
        {
            this->on_actSave_triggered();
            textChanged = 0;
        }
    }
}

void MainWindow::on_txtEdit_cursorPositionChanged()
{
    m_StatusBar->setCurpos(ui->txtEdit->textCursor().blockNumber()+1,
                           ui->txtEdit->textCursor().columnNumber(),
                           ui->txtEdit->document()->characterCount()-1);

    // 更新字体对齐状态
    Qt::Alignment align=ui->txtEdit->alignment();
    if(align==Qt::AlignLeft)
        ui->actLeftAlign->setChecked(true);
    else if(align==Qt::AlignCenter)
        ui->actCenter->setChecked(true);
    else if(align==Qt::AlignRight)
        ui->actRightAlign->setChecked(true);
}

void MainWindow::TextSearch(QString text,bool SearchWay,bool isCaseSensitive)
{
    bool isFind;
    if(SearchWay)
    {
        if(isCaseSensitive)
            isFind=ui->txtEdit->find(text,QTextDocument::FindCaseSensitively|
                                     QTextDocument::FindBackward);
        else
            isFind=ui->txtEdit->find(text,QTextDocument::FindBackward);
    }
    else
    {
        if(isCaseSensitive)
            isFind=ui->txtEdit->find(text,QTextDocument::FindCaseSensitively);
        else
            isFind=ui->txtEdit->find(text);
    }
    if(!isFind)
        QMessageBox::warning(this,("查找"),QString("找不到 \"%1\"").arg(text));
}

void MainWindow::TextDisplace(QString searchText, QString displaceText, bool mode)
{
    if(mode)
    {
        int count=ui->txtEdit->toPlainText().count(searchText,Qt::CaseInsensitive);
        ui->txtEdit->moveCursor(QTextCursor::Start);
        for(int i=0;i<count;i++)
        {
            TextSearch(searchText,false,false);
            ui->txtEdit->insertPlainText(displaceText);
        }
    }
    else
    {
        if(!ui->txtEdit->textCursor().hasSelection())
            TextSearch(searchText,false,false);
        ui->txtEdit->insertPlainText(displaceText);
    }
}

void MainWindow::on_txtEdit_currentCharFormatChanged(const QTextCharFormat &fmt)
{
    // 更新粗体，斜体和下划线3种action的checked属性
    ui->actFontBold->setChecked(fmt.font().bold());
    ui->actFontUnder->setChecked(fmt.fontUnderline());
    ui->actFontItalic->setChecked(fmt.fontItalic());

    // 更新字体栏
    if(!ui->txtEdit->textCursor().hasSelection())
    {
        comboFont->setCurrentFont(fmt.font());
        spinFontSize->setValue(ui->txtEdit->currentFont().pointSize());
    }
}

void MainWindow::on_actSetTextColor_triggered()
{
    QPalette pal=ui->txtEdit->palette();
    QColor nColor=pal.color(QPalette::Text);
    QColor ChoseColor=QColorDialog::getColor(nColor,this,("选择颜色"));
    if(ChoseColor.isValid())
    {
        QTextCharFormat fmt;                            //文本字符格式
        fmt.setForeground(ChoseColor);                  //前景色(即字体色)设为color色
        QTextCursor cursor = ui->txtEdit->textCursor(); //获取文本光标
        cursor.mergeCharFormat(fmt);                    //光标后的文字就用该格式显示
        ui->txtEdit->mergeCurrentCharFormat(fmt);       //QTextEdit使用当前的字符格式
    }
}

void MainWindow::on_actSearch_triggered()
{
    ui->actSearch->setEnabled(false);
    ui->txtEdit->moveCursor(QTextCursor::Start);

    m_SearchFrame=new SearchFrame(this);

    connect(m_SearchFrame,SIGNAL(callTextSearch(QString,bool,bool)),this,
            SLOT(TextSearch(QString,bool,bool)));
    connect(m_SearchFrame,SIGNAL(callTextDisplace(QString,QString,bool)),this,
            SLOT(TextDisplace(QString,QString,bool)));
    connect(m_SearchFrame,&SearchFrame::finished,
            [this]{
       m_SearchFrame=nullptr;
       ui->actSearch->setEnabled(true);
    });

    this->SearchFrameUpdate();
    m_SearchFrame->setAttribute(Qt::WA_DeleteOnClose);
    m_SearchFrame->show();
    m_SearchFrame->startAnimation();
}

void MainWindow::on_actTomatobell_triggered()
{
    int workMin,relaxMin,tomatobellNum;

    m_TomatobellDialog=new TomatobellDialog(this);
    m_TomatobellDialog->initTomatobellDialog(&workMin,&relaxMin,&tomatobellNum);
    m_TomatobellDialog->setAttribute(Qt::WA_DeleteOnClose);
    if(m_TomatobellDialog->exec()==QDialog::Rejected)
    {
        m_TomatobellDialog=nullptr;
        return;
    }
    m_TomatobellDialog=nullptr;

    ui->actTomatobell->setEnabled(false);

    m_TomatobellFrame=new TomatobellFrame(this);

    connect(m_TomatobellFrame,&TomatobellFrame::finished,
            [this]{
        ui->actTomatobell->setEnabled(true);
        m_TomatobellFrame=nullptr;
    });

    this->TomatobellFrameUpdate();
    m_TomatobellFrame->initTomatobell(workMin,relaxMin,tomatobellNum);
    m_TomatobellFrame->setAttribute(Qt::WA_DeleteOnClose);
    m_TomatobellFrame->show();
    m_TomatobellFrame->startAnimation();
}

void MainWindow::on_txtEdit_openFile(QString filePath)
{
    if(!checkFileSave())
        return;

    my_File* newFile=new my_File(filePath);

    bool isRTF=newFile->isRichTextFile();
    ui->actAcceptRichText->setChecked(isRTF);
    ui->actSaveToRichText->setChecked(isRTF);

    QString text;
    if(newFile->readFile(text))
        ui->txtEdit->setText(text);
    else
    {
        delete newFile;
        QMessageBox::critical(this,("错误"),("文件打开失败"));
        return;
    }

    connect(newFile,&my_File::fileChanged,
            [this]{
        if(QMessageBox::question(this,"警告","当前文件已发生变化,是否重新打开",
                                 QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes)
            this->on_actOpen_triggered();
    });

    m_File = newFile;
    m_StatusBar->setSaved(true);
    this->setWindowTitle(QString("书知编辑器 - %1").arg(m_File->getFileInfo().fileName()));

    for(QAction* act : ui->recentlyOpenedMenu->actions())
    {
        if(act->text()==m_File->getFileInfo().absoluteFilePath())
            ui->recentlyOpenedMenu->removeAction(act);
    }
    ui->recentlyOpenedMenu->addAction(
                new QAction(m_File->getFileInfo().absoluteFilePath(),this));
    return;
}

void MainWindow::on_actAbout_triggered()
{
    m_AboutDialog=new AboutDialog(this);
    m_AboutDialog->setAttribute(Qt::WA_DeleteOnClose);
    m_AboutDialog->exec();
    m_AboutDialog=nullptr;
}

void MainWindow::on_actUpdateToGit_triggered()
{
    //if(!checkFileSave())
    //    return;

    m_GitDialog=new GitDialog(this);
    m_GitDialog->GetPath(m_File->getFileInfo().absoluteFilePath());
    m_GitDialog->setAttribute(Qt::WA_DeleteOnClose);
    m_GitDialog->exec();
    m_GitDialog=nullptr;
}

void MainWindow::on_actHelp_triggered()
{
    m_HelpDialog=new HelpDialog(this);
    m_HelpDialog->setAttribute(Qt::WA_DeleteOnClose);
    m_HelpDialog->exec();
    m_HelpDialog=nullptr;
}

void MainWindow::on_actInsertDate_triggered()
{
    QString DateTimeString;
    m_InsertDateDialog=new InsertDateDialog(this);
    m_InsertDateDialog->initDateTimeString(&DateTimeString);
    m_InsertDateDialog->setAttribute(Qt::WA_DeleteOnClose);
    if(m_InsertDateDialog->exec()==QDialog::Accepted)
        ui->txtEdit->insertPlainText(DateTimeString);
    m_InsertDateDialog=nullptr;
}

void MainWindow::on_actClear_triggered()
{
    if(!ui->txtEdit->toPlainText().isEmpty())
    {
        if(QMessageBox::warning(this,("警告"),("是否清空文本内容"),
            QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
        {
            ui->txtEdit->document()->setModified();
            ui->txtEdit->clear();
        }
    }
}

void MainWindow::on_actIndent_triggered(bool checked)
{
    QTextBlockFormat fmt;
    if(checked)
    {
        QTextCharFormat curfmt=ui->txtEdit->currentCharFormat();
        fmt.setTextIndent(qMax(curfmt.font().pointSize(),curfmt.font().pixelSize())*2);
    }
    else
        fmt.setTextIndent(0.0);
    ui->txtEdit->textCursor().setBlockFormat(fmt);
}

void MainWindow::on_actClearData_triggered()
{
    while (ui->recentlyOpenedMenu->actions().size()>1)
        ui->recentlyOpenedMenu->removeAction(ui->recentlyOpenedMenu->actions()
            .at(ui->recentlyOpenedMenu->actions().size()-1));
}

void MainWindow::on_actInsterPicture_triggered()
{
    int width,height;
    // 加载图片文件
    QString ImagePath=QFileDialog::getOpenFileName(this,("插入图片"),QDir::homePath(),
        ("图片文件 (*.bmp *.jpg *jpeg *.gif *.png *.ico)"));
    if(ImagePath.isEmpty())
        return;

    QUrl ImageUrl(QString("file:%1").arg(ImagePath));
    QImage Image=QImageReader(ImagePath).read();

    if(Image.isNull())
        return;

    width=Image.width();
    height=Image.height();

    m_ImageSizeDialog=new ImageSizeDialog(this);
    m_ImageSizeDialog->initImageSize(&width,&height);
    m_ImageSizeDialog->setAttribute(Qt::WA_DeleteOnClose);
    m_ImageSizeDialog->exec();
    m_ImageSizeDialog=nullptr;

    QTextImageFormat ImageFormat;
    ImageFormat.setWidth(width);
    ImageFormat.setHeight(height);
    ImageFormat.setName(ImageUrl.toString());

    // 将图片插入到QTextEdit
    ui->txtEdit->document()->addResource(
                QTextDocument::ImageResource,ImageUrl,Image);
    ui->txtEdit->textCursor().insertImage(ImageFormat);
}

void MainWindow::on_actInsterForm_triggered()
{
    int rows,cols;
    double padding;
    bool ok;
    rows=QInputDialog::getInt(this,("获取排数"),("排:"),1,1,10000,1,&ok);
    if(!ok)
        return;
    cols=QInputDialog::getInt(this,("获取列数"),("列:"),1,1,10000,1,&ok);
    if(!ok)
        return;
    padding=QInputDialog::getDouble(this,("设置单元格大小"),("像素:"),1,1,100,1,&ok);
    if(!ok)
        return;

    QTextTableFormat fmt;
    fmt.setCellPadding(padding);
    fmt.setAlignment(ui->txtEdit->alignment());

    QTextTable *tabel=ui->txtEdit->textCursor().insertTable(rows,cols,fmt);
    Q_UNUSED(tabel);
}

void MainWindow::on_actCreateLink_triggered()
{
    //建立桌面快捷方式
    QString strDesktopLink=QString("%1/书知编辑器.lnk")
        .arg(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));
    QFile fApp(QCoreApplication::arguments().at(0));
    fApp.link(strDesktopLink);
}

void MainWindow::on_actConcise_triggered(bool checked)
{
    // 简洁模式
    ui->mainToolBar->setHidden(checked);
    ui->TextStyleToolBar->setHidden(checked);
    ui->InsertToolBar->setHidden(checked);

    QMenu *menu = QMainWindow::createPopupMenu();
    menu->actions().at(0)->setChecked(!checked);
    menu->actions().at(1)->setChecked(!checked);
    menu->actions().at(2)->setChecked(!checked);
}

void MainWindow::SearchFrameUpdate()
{
    if(m_SearchFrame!=nullptr)
        m_SearchFrame->move(QPoint(this->width()-393,70));
}

void MainWindow::TomatobellFrameUpdate()
{
    if(m_TomatobellFrame!=nullptr)
        m_TomatobellFrame->move(QPoint(this->width()-85,this->height()-75));
}
