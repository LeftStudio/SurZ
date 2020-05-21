#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "aboutdialog.h"
#include "gitdialog.h"
#include "helpdialog.h"
#include "imagesizedialog.h"
#include "insertdatedialog.h"
#include "searchframe.h"
#include "tomatobellframe.h"
#include "tomatobelldialog.h"

#include "my_texteditor.h"
#include "my_statusbar.h"
#include "my_file.h"

class QLabel;
class QSpinBox;
class QFontComboBox;
class QActionGroup;
class QSettings;
class QFile;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() Q_DECL_OVERRIDE ;

private slots:
    void on_actFontBold_triggered(bool checked);

    void on_actFontItalic_triggered(bool checked);

    void on_actFontUnder_triggered(bool checked);

    void on_actFontStrikeout_triggered(bool checked);

    void on_actToolbarStyle_triggered(bool checked);

    void on_actOpen_triggered();

    void on_actSave_triggered();

    void on_actNew_triggered();

    void on_actSaveAs_triggered();

    void on_actSetTextColor_triggered();

    void on_actSearch_triggered();

    void on_actAbout_triggered();

    void on_actUpdateToGit_triggered();

    void on_actClear_triggered();

    void on_actHelp_triggered();

    void on_actIndent_triggered(bool checked);

    void on_actClearData_triggered();

    void on_actInsterPicture_triggered();

    void on_actInsterForm_triggered();

    void on_actCreateLink_triggered();

    void on_actInsertDate_triggered();

    void on_actConcise_triggered(bool checked);

    void on_actTomatobell_triggered();

    /* 文本框信号槽 */
    void on_txtEdit_openFile(QString);          // 打开拖拽文件
    void on_txtEdit_textChanged();              // 文字改变
    void on_txtEdit_cursorPositionChanged();    // 光标位置改变
    void on_txtEdit_currentCharFormatChanged(const QTextCharFormat &);  // 光标字体改变
    void on_txtEdit_copyAvailable(bool b);      // 可复制状态改变

    void spinFontSize_valueChanged(int);                    // 改变字体大小
    void comboFont_currentIndexChanged(const QString &);    // 选中文字改变(更新cut,copy,paste状态)

    void TextSearch(QString,bool,bool);                     // 搜索文本
    void TextDisplace(QString,QString, bool);               // 替换文本

    void on_recentlyOpenedMenu_triggered(QAction *);        // 打开最近访问文件
    void on_backgroundMenu_triggered(QAction *);            // 更换背景

private:
    Ui::MainWindow *ui;

    /* 自定义窗口 */
    InsertDateDialog *m_InsertDateDialog = nullptr;
    TomatobellDialog *m_TomatobellDialog = nullptr;
    ImageSizeDialog  *m_ImageSizeDialog  = nullptr;
    AboutDialog      *m_AboutDialog      = nullptr;
    HelpDialog       *m_HelpDialog       = nullptr;
    GitDialog        *m_GitDialog        = nullptr;
    TomatobellFrame  *m_TomatobellFrame  = nullptr;
    SearchFrame      *m_SearchFrame      = nullptr;
    my_StatusBar     *m_StatusBar        = nullptr;

    QSpinBox      *spinFontSize    = nullptr;   // 文本大小
    QFontComboBox *comboFont       = nullptr;   // 文本字体
    QActionGroup  *alignmentGroup  = nullptr;   // 字体对齐动作组
    QActionGroup  *backgroundGroup = nullptr;   // 更换背景动作组

    /* 功能性对象 */
    my_File   *m_File   = nullptr;      // 当前文件
    QSettings *settings = nullptr;      // 设置

    /* 更新窗口位置 */
    inline void SearchFrameUpdate();
    inline void TomatobellFrameUpdate();

    /* 初始化 */
    void initUI();
    void initFile();
    void initSignalSlots();

    bool checkFileSave();   // 检查文件是否保存

    /* 设置操作函数 */
    void loadSettings();    // 加载设置
    void saveSettings();    // 保存设置

    /* 事件重写 */
    void closeEvent(QCloseEvent *event)   Q_DECL_OVERRIDE ;
    void resizeEvent(QResizeEvent* event) Q_DECL_OVERRIDE ;
};

#endif // MAINWINDOW_H
