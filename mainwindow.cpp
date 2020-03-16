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
//#include <QDebug>
#include <QDir>

#if _MSC_VER >= 1600
    #pragma execution_character_set("utf-8")
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
    initSignalSlots();
    initFile();
    LoadSettings();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
    // 状态栏
    fLabCurFile=new QLabel(this);
    fLabCurFile->setMinimumWidth(150);
    fLabCurFile->setText(("当前文件:"));
    ui->statusBar->addWidget(fLabCurFile);

    nCurposLable=new QLabel(this);
    nCurposLable->setMinimumWidth(130);
    nCurposLable->setText(QString("行:%1  列:%2  字数:%3")
        .arg(ui->txtEdit->textCursor().blockNumber()+1)
        .arg(ui->txtEdit->textCursor().columnNumber())
        .arg(ui->txtEdit->document()->characterCount()-1));
    ui->statusBar->addWidget(nCurposLable);

    isSaveLable=new QLabel(this);
    isSaveLable->setText(("文件已保存 "));
    isSaveLable->setVisible(true);
    ui->statusBar->addWidget(isSaveLable);

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
        m_FileName=args.at(1);
        if(!m_FileName.isEmpty())
            OpenFile(m_FileName);
    }
}

void MainWindow::initSignalSlots()
{
    // 关联自定义信号槽
    connect(spinFontSize,SIGNAL(valueChanged(int)),this,
            SLOT(spinFontSize_valueChanged(int)));
    connect(comboFont,SIGNAL(currentIndexChanged(const QString &)),this,
            SLOT(comboFont_currentIndexChanged(const QString &)));
    connect(ui->txtEdit,SIGNAL(textChanged()),this,
            SLOT(textChanged()));
    connect(ui->txtEdit,SIGNAL(cursorPositionChanged()),this,
            SLOT(CursorIsChanged()));
    connect(ui->txtEdit,SIGNAL(currentCharFormatChanged(const QTextCharFormat &)),this,
            SLOT(currentCharFormatChanged(const QTextCharFormat &)));
    connect(ui->txtEdit,SIGNAL(callOpenFile(QString)),this,
            SLOT(OpenFile(QString)));
    connect(ui->RecentlyOpenedMenu,SIGNAL(triggered(QAction*)),this,
            SLOT(RecentlyOpened(QAction*)));

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

void MainWindow::LoadSettings()
{
    settings=new QSettings(QString("./SurZ_Settings.ini"),QSettings::IniFormat,this);
    settings->setIniCodec("UTF-8");

    if(settings->contains("Window/WindowSize"))
        this->resize(settings->value("Window/WindowSize",QVariant(QSize())).toSize());
    if(settings->contains("Window/WindowPos"))
        this->move(settings->value("Window/WindowPos",QVariant(QPoint())).toPoint());

    if(settings->contains("SurZ/ToolbarText"))
    {
        bool isChecked=settings->value("SurZ/ToolbarText",QVariant(bool())).toBool();
        ui->actToolbarStyle->setChecked(isChecked);
        this->on_actToolbarStyle_triggered(isChecked);
    }

    int size=settings->beginReadArray("RecentlyOpened");
    for (int i=0;i<size;i++)
    {
        settings->setArrayIndex(i);
        ui->RecentlyOpenedMenu->addAction(new QAction(settings->value("FilePath").toString()));
    }
    settings->endArray();
}

void MainWindow::SaveSettings()
{
    settings->setValue("Window/WindowSize",QVariant(this->size()));
    settings->setValue("Window/WindowPos",QVariant(this->pos()));

    settings->setValue("SurZ/ToolbarText",QVariant(ui->actToolbarStyle->isChecked()));

    settings->beginWriteArray("RecentlyOpened");
    for (int i=2;i<ui->RecentlyOpenedMenu->actions().size();i++)
    {
        settings->setArrayIndex(i-2);
        settings->setValue("FilePath",ui->RecentlyOpenedMenu->actions().at(i)->text());
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

bool MainWindow::SaveFile(QString &FileName)
{
    //将文本框数据取出并按行排列
    QFile file(FileName);//文件命名
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))     //检测文件是否打开
        return false;
    QTextStream out(&file);                 //分行写入文件
    if(ui->actSaveToRichText->isChecked())
        out << ui->txtEdit->toHtml().toUtf8();
    else
        out << ui->txtEdit->toPlainText().toUtf8();
    file.close();
    ui->txtEdit->document()->setModified(false);
    isSaveLable->setVisible(true);
    return true;
}

void MainWindow::OpenFile(QString FileName)
{
    QFile file(FileName);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this,("错误"),("打开文件失败"));
        return;
    }
    else
    {
        if(file.isReadable())
        {
            ui->txtEdit->clear();
            QTextStream in(&file);
            if(ui->actAcceptRichText->isChecked())
                while (!in.atEnd())
                    ui->txtEdit->setHtml(in.readAll().toUtf8());
            else
                while (!in.atEnd())
                    ui->txtEdit->setPlainText(in.readAll().toUtf8());
            file.close();
            m_FileName=FileName;
            fLabCurFile->setText(QString("当前文件: %1 ").arg(FileName));
            for(QAction* act : ui->RecentlyOpenedMenu->actions())
            {
                if(act->text()==FileName)
                    ui->RecentlyOpenedMenu->removeAction(act);
            }
            ui->RecentlyOpenedMenu->addAction(new QAction(FileName,this));
        }
        else
            QMessageBox::warning(this,("错误"),("该文件不可读"));
    }
}

void MainWindow::CheckFileIsSave()
{
    if(ui->txtEdit->document()->isModified())
    {
        if(QMessageBox::question(this,("警告"),("是否保存当前文件"),
                                 QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
            on_actSave_triggered();
    }
}

void MainWindow::RecentlyOpened(QAction *act)
{
    if(act->text()!="清空记录")
    {
        CheckFileIsSave();
        OpenFile(act->text());
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    CheckFileIsSave();
    SaveSettings();
    event->accept();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    this->SearchFrameUpdate();
}

//void MainWindow::moveEvent(QMoveEvent *event)
//{
//    QMainWindow::moveEvent(event);
//    this->SearchFrameUpdate();
//}

void MainWindow::on_actOpen_triggered()
{
    CheckFileIsSave();
    m_FileName = QFileDialog::getOpenFileName(nullptr,("打开文件"),QDir::homePath(),
        ("富文本(*.rtf *.html);;文本文件(*.txt);;源文件(*.c *.cpp *.py *.html *.xml *.js *.vbs *.bat);;所有文件(*.*)"));
    if(!m_FileName.isEmpty())
        OpenFile(m_FileName);
    return;
}

void MainWindow::on_actSave_triggered()
{
    if(m_FileName.isEmpty())
    {
        m_FileName = QFileDialog::getSaveFileName(this,("保存文件"),QDir::homePath(),
            ("富文本(*.rtf *.html);;文本文件(*.txt);;源文件(*.c *.cpp *.py *.html *.xml *.js *.vbs *.bat);;所有文件(*.*)"));
        if(m_FileName.isEmpty())
            return;
    }
    if(!SaveFile(m_FileName))
        QMessageBox::warning(this,("错误"),("文件保存失败"));
    else
        fLabCurFile->setText(QString("当前文件:%1").arg(m_FileName));
    return;
}

void MainWindow::on_actNew_triggered()
{
    QString NewFileName = QFileDialog::getSaveFileName(this,("新建文件"),QDir::homePath(),
        ("富文本(*.rtf *.html);;文本文件(*.txt);;源文件(*.c *.cpp *.py *.html *.xml *.js *.vbs *.bat);;所有文件(*.*)"));
    if(NewFileName.isEmpty())
        return;
    CheckFileIsSave();
    if(!SaveFile(NewFileName))
        QMessageBox::warning(this,("错误"),("文件创建失败"));
    else
    {
        m_FileName=NewFileName;
        fLabCurFile->setText(QString("当前文件:%1").arg(m_FileName));
        ui->txtEdit->clear();
    }
    return;
}

void MainWindow::on_actSaveAs_triggered()
{
    QString SaveAsFileName = QFileDialog::getSaveFileName(this,("另存为..."),QDir::homePath(),
        ("富文本(*.rtf *.html);;文本文件(*.txt);;源文件(*.c *.cpp *.py *.html *.xml *.js *.vbs *.bat);;所有文件(*.*)"));
    if(SaveAsFileName.isEmpty())
        return;
    if(!SaveFile(SaveAsFileName))
        QMessageBox::warning(this,("错误"),("文件另存为失败"));
    return;
}

void MainWindow::textChanged()
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
    isSaveLable->setVisible(false);

    nCurposLable->setText(QString("行:%1  列:%2  字数:%3")
        .arg(ui->txtEdit->textCursor().blockNumber()+1)
        .arg(ui->txtEdit->textCursor().columnNumber())
        .arg(ui->txtEdit->document()->characterCount()-1));
}

void MainWindow::CursorIsChanged()
{
    nCurposLable->setText(QString("行:%1  列:%2  字数:%3")
        .arg(ui->txtEdit->textCursor().blockNumber()+1)
        .arg(ui->txtEdit->textCursor().columnNumber())
        .arg(ui->txtEdit->document()->characterCount()-1));
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

void MainWindow::TextDisplace(QString searchText, bool isCaseSensitive, QString displaceText, bool mode)
{
    if(mode)
    {
        int count=ui->txtEdit->toPlainText().count(searchText,Qt::CaseInsensitive);
        ui->txtEdit->moveCursor(QTextCursor::Start);
        for(int i=0;i<count;i++)
        {
            TextSearch(searchText,false,isCaseSensitive);
            ui->txtEdit->insertPlainText(displaceText);
        }
    }
    else
    {
        if(!ui->txtEdit->textCursor().hasSelection())
            TextSearch(searchText,false,isCaseSensitive);
        ui->txtEdit->insertPlainText(displaceText);
    }
}

void MainWindow::currentCharFormatChanged(const QTextCharFormat &f)
{
    // 更新粗体，斜体和下划线3种action的checked属性
    ui->actFontBold->setChecked(f.font().bold());
    ui->actFontUnder->setChecked(f.fontUnderline());
    ui->actFontItalic->setChecked(f.fontItalic());
    // 更新字体栏
    if(!ui->txtEdit->textCursor().hasSelection())
    {
        comboFont->setCurrentFont(f.font());
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
    connect(m_SearchFrame,SIGNAL(callTextDisplace(QString,bool,QString,bool)),this,
            SLOT(TextDisplace(QString,bool,QString,bool)));
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

void MainWindow::on_actAbout_triggered()
{
    m_AboutDialog=new AboutDialog(this);
    m_AboutDialog->setAttribute(Qt::WA_DeleteOnClose);
    m_AboutDialog->exec();
    m_AboutDialog=nullptr;
}

void MainWindow::on_actUpdateToGit_triggered()
{
    CheckFileIsSave();
    m_GitDialog=new GitDialog(this);
    m_GitDialog->GetPath(m_FileName);
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
    m_InsertDateDialog->getDateTimeString(&DateTimeString);
    m_InsertDateDialog->setAttribute(Qt::WA_DeleteOnClose);
    if(m_InsertDateDialog->exec()==QDialog::Accepted)
        ui->txtEdit->append(DateTimeString);
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
    while (ui->RecentlyOpenedMenu->actions().size()>1)
        ui->RecentlyOpenedMenu->removeAction(ui->RecentlyOpenedMenu->actions()
            .at(ui->RecentlyOpenedMenu->actions().size()-1));
}

void MainWindow::on_actInsterPicture_triggered()
{
    int width,height;
    // 加载图片文件
    QString ImagePath=QFileDialog::getOpenFileName(this,("插入图片"),QDir::homePath(),
        ("图片文件 (*.bmp *.jpg *jpeg *.gif *.png)"));
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
    ui->statusBar->setHidden(checked);

    QMenu *menu = QMainWindow::createPopupMenu();
    menu->actions().at(0)->setChecked(!checked);
    menu->actions().at(1)->setChecked(!checked);
    menu->actions().at(2)->setChecked(!checked);
}

void MainWindow::SearchFrameUpdate()
{
    if(m_SearchFrame!=nullptr)
        m_SearchFrame->move(QPoint(this->width()-375,70));
}
