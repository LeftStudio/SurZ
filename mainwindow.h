#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "aboutdialog.h"
#include "gitdialog.h"
#include "helpdialog.h"
#include "imagesizedialog.h"
#include "insertdatedialog.h"
#include "searchframe.h"

#include "my_texteditor.h"

class QLabel;
class QSpinBox;
class QFontComboBox;
class QActionGroup;
class QSettings;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actFontBold_triggered(bool checked);

    void on_txtEdit_copyAvailable(bool b);

    void on_actFontItalic_triggered(bool checked);

    void on_actFontUnder_triggered(bool checked);

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

    // 自定义槽函数
    void spinFontSize_valueChanged(int);// 改变字体大小
    void comboFont_currentIndexChanged(const QString &); // 选中文字改变(更新cut,copy,paste状态)
    void textChanged();                 // 文字改变
    void CursorIsChanged();             // 光标位置改变
    void TextSearch(QString,bool,bool); // 搜索文本
    void TextDisplace(QString,bool,QString, bool);
    void currentCharFormatChanged(const QTextCharFormat &);
    void RecentlyOpened(QAction*);      // 打开最近访问文件
    void OpenFile(QString FileName);    // 打开文件

private:
    Ui::MainWindow *ui;

    InsertDateDialog *m_InsertDateDialog=nullptr;
    ImageSizeDialog *m_ImageSizeDialog=nullptr;
    SearchFrame *m_SearchFrame=nullptr;
    AboutDialog *m_AboutDialog=nullptr;
    HelpDialog *m_HelpDialog=nullptr;
    GitDialog *m_GitDialog=nullptr;

    QString m_FileName;         // 当前文件名
    QSettings *settings;        // 设置

    QLabel *fLabCurFile;        // 文件名QLabel
    QLabel *isSaveLable;        // "文件以保存"Qlabel
    QLabel *nCurposLable;       // 光标位置QLabel
    QSpinBox *spinFontSize;     // 文本大小
    QFontComboBox *comboFont;   // 文本字体
    QActionGroup *alignmentGroup;// 字体对齐动作组

    inline void SearchFrameUpdate();

    void initUI();
    void initFile();
    void initSignalSlots();
    bool SaveFile(QString &m_FileName); // 写入文件

    void CheckFileIsSave();             // 检查文件是否保存
    void LoadSettings();                // 加载设置
    void SaveSettings();                // 保存设置

    void closeEvent(QCloseEvent *event); // 重写关闭事件
    //void moveEvent(QMoveEvent *event);
    void resizeEvent(QResizeEvent* event);
};

#endif // MAINWINDOW_H
