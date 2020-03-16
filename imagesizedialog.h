#ifndef IMAGESIZEDIALOG_H
#define IMAGESIZEDIALOG_H

#include <QDialog>

namespace Ui {
class ImageSizeDialog;
}

class ImageSizeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImageSizeDialog(QWidget *parent = nullptr);
    ~ImageSizeDialog();

    void initImageSize(int *w,int *h);

private slots:

    void on_OK_Button_clicked();

    void on_KeepSizeCheck_checkedChanged(bool checked);

private:
    Ui::ImageSizeDialog *ui;

    inline void initUI();

    int *ImageWidth=nullptr;
    int *ImageHeight=nullptr;

    bool isKeepSize;
};

#endif // IMAGESIZEDIALOG_H
