#ifndef MY_NETWORKTRANSLATOR_H
#define MY_NETWORKTRANSLATOR_H

#include <QObject>

class QNetworkAccessManager;
class QNetworkReply;

class my_NetworkTranslator : public QObject
{
    Q_OBJECT
public:
    explicit my_NetworkTranslator(QObject *parent = nullptr);

    void queryWord(const QString &text,const QString tranType);

signals:
    void finished(QString result,QString message);

private slots:
    void on_queryWordFinished(QNetworkReply *reply);

private:

    const QString m_Token = "wjrijs8swcpsixkaa96o";
    QNetworkAccessManager *m_Manager = nullptr;

};

#endif // MY_NETWORKTRANSLATOR_H
