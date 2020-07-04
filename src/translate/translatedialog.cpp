/********************/
/*  By Left Studio  */
/*     @Ho 229      */
/********************/

#include "translatedialog.h"
#include "ui_translatedialog.h"

#include <QTimer>
#include <QButtonGroup>
#include <QMessageBox>

#if _MSC_VER >= 1600
    #pragma execution_character_set("utf-8")
#endif

TranslateDialog::TranslateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TranslateDialog),
    m_Translater(new my_NetworkTranslator(this)),
    m_TransTimer(new QTimer(this))
{
    ui->setupUi(this);
    this->initUI();

    connect(m_TransTimer,&QTimer::timeout,[this]{
        m_TransTimer->stop();
        this->translate();
    });

    connect(m_Translater,&my_NetworkTranslator::finished,
            [this](QString result,QString message){
        if(result.isEmpty())
            QMessageBox::critical(this,"错误",
                                  QString("Error:%1\n如无法使用请联系开发团队").arg(message));
        else
            ui->resultTextEdit->setPlainText(result);
    });

    m_TransModeGroup = new QButtonGroup(this);
    m_TransModeGroup->addButton(ui->transMode_auto2zh);
    m_TransModeGroup->addButton(ui->transMode_auto2en);
    m_TransModeGroup->addButton(ui->transMode_auto2ja);
    connect(m_TransModeGroup,QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
            [this]{ this->translate(); });
}

TranslateDialog::~TranslateDialog()
{
    delete ui;
}

void TranslateDialog::setSelectedText(const QString &text)
{
    ui->queryTextEdit->setPlainText(text);
    connect(ui->queryTextEdit,&QPlainTextEdit::textChanged,[this]{ m_TransTimer->start(800); });
    this->translate();
}

void TranslateDialog::translate()
{
    if(ui->queryTextEdit->toPlainText().isEmpty())
        ui->resultTextEdit->clear();
    else
        m_Translater->queryWord(ui->queryTextEdit->toPlainText(),
            m_TransModeGroup->checkedButton()->objectName().mid(10));
}

void TranslateDialog::initUI()
{
    this->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
}
