/********************/
/*  By Left Studio  */
/*     @Ho 229      */
/********************/

#include "my_texteditor.h"

#include <QMimeData>
#include <QImageReader>
#include <QGraphicsOpacityEffect>
#include <QFileInfo>
#include <QUrl>

My_TextEditor::My_TextEditor(QWidget *parent) :
    QTextEdit(parent)
{
    // 调整字体背景色
    QPalette palette=this->palette();
    palette.setColor(QPalette::Highlight,QColor(22,155,213));
    palette.setBrush(QPalette::Base,QBrush(QColor(242,242,242,0)));

    this->setPalette(palette);

    //this->setAutoFillBackground(true);
}

bool My_TextEditor::canInsertFromMimeData(const QMimeData *source) const
{
    return source->hasImage() || source->hasUrls() ||
            QTextEdit::canInsertFromMimeData(source);
}

void My_TextEditor::insertFromMimeData(const QMimeData *source)
{
    if (source->hasImage())
    {
        static int i = 1;
        QUrl url(QString("dropped_image_%1").arg(i++));
        this->dropImage(url, qvariant_cast<QImage>(source->imageData()));
    }
    else if (source->hasUrls())
    {
        for(QUrl &url : source->urls())
        {
            QFileInfo info(url.toLocalFile());
            if (QImageReader::supportedImageFormats().contains(
                        info.suffix().toLower().toLatin1()))
                this->dropImage(url, QImage(info.filePath()));
            else
                emit openFile(url.toLocalFile());
        }
    }
    else
        QTextEdit::insertFromMimeData(source);
}

void My_TextEditor::dropImage(const QUrl &url, const QImage &image)
{
    if (!image.isNull())
    {
        int width,height;
        width=image.width();
        height=image.height();

        m_ImageSizeDialog=new ImageSizeDialog();
        m_ImageSizeDialog->initImageSize(&width,&height);
        m_ImageSizeDialog->setAttribute(Qt::WA_DeleteOnClose);
        m_ImageSizeDialog->exec();
        m_ImageSizeDialog=nullptr;

        QTextImageFormat ImageFormat;
        ImageFormat.setWidth(width);
        ImageFormat.setHeight(height);
        ImageFormat.setName(url.toString());

        this->document()->addResource(QTextDocument::ImageResource, url, image);
        this->textCursor().insertImage(ImageFormat);
    }
}

