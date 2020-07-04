#ifndef TRANSLATEDIALOG_H
#define TRANSLATEDIALOG_H

#include <QDialog>

#include "my_networktranslator.h"

class QTimer;
class QButtonGroup;

namespace Ui {
class TranslateDialog;
}

class TranslateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TranslateDialog(QWidget *parent = nullptr);
    ~TranslateDialog();

    void setSelectedText(const QString &text);

private:
    Ui::TranslateDialog *ui;

    my_NetworkTranslator *m_Translater     = nullptr;
    QTimer               *m_TransTimer     = nullptr;
    QButtonGroup         *m_TransModeGroup = nullptr;

    inline void initUI();
    inline void translate();

};

#endif // TRANSLATEDIALOG_H
