#include "serverSends.h"
#include "serverConnect.h"
#include <QThread>
#include <functional>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QTimer>

serverSends::serverSends(QObject *parent)
    : QTcpServer(parent)
{}

void serverSends::incomingConnection(qintptr socketDescriptor)
{
    serverConnect *worker = new serverConnect(this);
    if (!worker->setSocketDescriptor(socketDescriptor)) {
        worker->deleteLater();
        return;
    }
    connect(worker, &serverConnect::disconnectedFromClient, this, std::bind(&serverSends::userDisconnected, this, worker));
    connect(worker, &serverConnect::error, this, std::bind(&serverSends::userError, this, worker));
    connect(worker, &serverConnect::jsonReceived, this, std::bind(&serverSends::jsonReceived, this, worker, std::placeholders::_1));
    connect(worker, &serverConnect::logMessage, this, &serverSends::logMessage);
    m_clients.append(worker);
    emit logMessage(QStringLiteral("New client Connected"));
}
void serverSends::sendJson(serverConnect *destination, const QJsonObject &message)
{
    Q_ASSERT(destination);
    destination->sendJson(message);
}
void serverSends::broadcast(const QJsonObject &message, serverConnect *exclude)
{
    for (serverConnect *worker : m_clients) {
        Q_ASSERT(worker);
        if (worker == exclude)
            continue;
        sendJson(worker, message);
    }
}

void serverSends::jsonReceived(serverConnect *sender, const QJsonObject &doc)
{
    Q_ASSERT(sender);
    emit logMessage(QLatin1String("JSON received ") + QString::fromUtf8(QJsonDocument(doc).toJson()));
    jsonFromLoggedIn(sender, doc);
}

void serverSends::userDisconnected(serverConnect *sender)
{
    m_clients.removeAll(sender);
    emit logMessage(QLatin1String(" disconnected"));
    sender->deleteLater();
}

void serverSends::userError(serverConnect *sender)
{
    Q_UNUSED(sender)
    emit logMessage(QLatin1String("Error from client"));
}

void serverSends::stopServer()
{
    for (serverConnect *worker : m_clients) {
        worker->disconnectFromClient();
    }
    close();
}

void serverSends::jsonFromLoggedIn(serverConnect *sender, const QJsonObject &docObj)
{
    Q_ASSERT(sender);
    const QJsonValue typeVal = docObj.value(QLatin1String("type"));
    if (typeVal.isNull() || !typeVal.isString())
        return;
    if (typeVal.toString().compare(QLatin1String("message"), Qt::CaseInsensitive) != 0)
        return;
    const QJsonValue textVal = docObj.value(QLatin1String("text"));
    if (textVal.isNull() || !textVal.isString())
        return;
    const QString text = textVal.toString().trimmed();
    if (text.isEmpty())
        return;
    QJsonObject message;
    message[QStringLiteral("type")] = QStringLiteral("message");
    message[QStringLiteral("text")] = text;
    broadcast(message, sender);
}


