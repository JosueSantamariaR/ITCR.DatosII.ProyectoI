/**
  * @file serverSends.h
  * */
#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QTcpServer>
#include <QVector>
class QThread;
class serverConnect;
class serverSends : public QTcpServer
{
    Q_OBJECT
    Q_DISABLE_COPY(serverSends)
public:
    explicit serverSends(QObject *parent = nullptr);
protected:
    void incomingConnection(qintptr socketDescriptor) override;
signals:
    void logMessage(const QString &msg);
public slots:
    void stopServer();
private slots:
    void broadcast(const QJsonObject &message, serverConnect *exclude);
    void jsonReceived(serverConnect *sender, const QJsonObject &doc);
    void userDisconnected(serverConnect *sender);
    void userError(serverConnect *sender);
private:
    void jsonFromLoggedIn(serverConnect *sender, const QJsonObject &doc);
    void sendJson(serverConnect *destination, const QJsonObject &message);
    QVector<serverConnect *> m_clients;
};

#endif // CHATSERVER_H
