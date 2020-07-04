/********************/
/*  By Left Studio  */
/*     @Ho 229      */
/********************/

#include "my_networktranslator.h"

#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

my_NetworkTranslator::my_NetworkTranslator(QObject *parent)
    : QObject(parent),
      m_Manager(new QNetworkAccessManager(this))
{
    connect(m_Manager,&QNetworkAccessManager::finished,this,&my_NetworkTranslator::on_queryWordFinished);
}

void my_NetworkTranslator::queryWord(const QString &text,const QString transType)
{
    QUrl url("http://api.interpreter.caiyunai.com/v1/translator");

    QJsonObject obj;
    obj.insert("source",text);
    obj.insert("trans_type",transType);
    obj.insert("request_id","demo");
    obj.insert("detect","True");

    QNetworkRequest request(url);
    request.setRawHeader("content-type","application/json");
    request.setRawHeader("x-authorization",QString("token %1").arg(m_Token).toUtf8());

    m_Manager->post(request,QJsonDocument(obj).toJson());
}

void my_NetworkTranslator::on_queryWordFinished(QNetworkReply *reply)
{
    QByteArray data=reply->readAll();
    QJsonObject resultJson = QJsonDocument::fromJson(data).object();

    emit finished(resultJson["target"].toString(),
            resultJson["message"].toString());
}
