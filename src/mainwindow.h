#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "aboutdialog.h"
#include "gitdialog.h"
#include "helpdialog.h"
#include "imagesizedialog.h"
#include "insertdatedialog.h"
#include "tomatobelldialog.h"
#include "translatedialog.h"

#include "searchframe.h"
#include "tomatobellframe.h"

#include "my_texteditor.h"
#include "my_statusbar.h"
#include "my_file.h"

class QLabel;
class QSpinBox;
class QFontComboBox;
class QSystemTrayIcon;
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

    void on_recentlyOpenedMenu_triggered(QAction *);        // 打开最近访问文件
    void on_backgroundMenu_triggered(QAction *);            // 更换背景

    void on_actTranslation_triggered();

private:
    Ui::MainWindow *ui;

    /* 自定义窗口 */
    InsertDateDialog *m_InsertDateDialog = nullptr;
    TomatobellDialog *m_TomatobellDialog = nullptr;
    TranslateDialog  *m_TranslateDialog  = nullptr;
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
    my_File         *m_File            = nullptr;      // 当前文件
    QSettings       *m_Settings        = nullptr;      // 设置
    QSystemTrayIcon *m_SystemTrayIcon  = nullptr;      // 系统托盘

    /* 更新窗口位置 */
    inline void SearchFrameUpdate();
    inline void TomatobellFrameUpdate();

    /* 初始化 */
    void initUI();
    void initFile();
    void initSignalSlots();
    void initSystemTrayIcon();

    bool checkFileSave();   // 检查文件是否保存

    /* 设置操作函数 */
    void loadSettings();    // 加载设置
    void saveSettings();    // 保存设置

    /* 事件重写 */
    void closeEvent(QCloseEvent *event)   Q_DECL_OVERRIDE ;
    void resizeEvent(QResizeEvent* event) Q_DECL_OVERRIDE ;

    const QString scrollbarStyleSheet =
            "QScrollArea {\n"
            "    border: none;\n"
            "    background: transparent;\n"
            "}\n"
            "\n"
            "QScrollArea > QWidget > QWidget {\n"
            "    background: transparent;\n"
            "}\n"
            "\n"
            "QScrollBar:vertical {\n"
            "    border:none;\n"
            "    background: transparent;\n"
            "    width: 10px;\n"
            "}\n"
            "\n"
            "QScrollBar::handle:vertical {\n"
            "    border-radius:5px;\n"
            "    background: #DDDDDD;\n"
            "    min-height: 60px;\n"
            "}\n"
            "QScrollBar::add-line:vertical {\n"
            "    border: none;\n"
            "    height: 0px;\n"
            "}\n"
            "\n"
            "QScrollBar::sub-line:vertical {\n"
            "    border: none;\n"
            "    height: 0px;\n"
            "}\n"
            "\n"
            "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
            "    background: transparent;\n"
            "}\n"
            "\n"
            "QScrollBar:horizontal {\n"
            "    border:none;\n"
            "    background: transparent;\n"
            "    height:10px"
                                    ";\n"
            "}\n"
            "\n"
            "QScrollBar::handle:horizontal {\n"
            "    border-radius:5px;\n"
            "    background: #DDDDDD;\n"
            "    min-width: 60px;\n"
            "}\n"
            "\n"
            "QScrollBar::add-line:horizontal {\n"
            "    border: none;\n"
            "    width: 0px;\n"
            "}\n"
            "\n"
            "QScrollBar::sub-line:horizontal {\n"
            "    border: none;\n"
            "    width: 0px;\n"
            "}\n"
            "\n"
            "QScrollBar::add-page:horizontal,\n"
            "QScrollBar::sub-page:horizontal {\n"
            "    background:  transparent;\n"
            "}";
};

#endif // MAINWINDOW_H
