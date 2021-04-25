#ifndef SERVERWORKER_H
#define SERVERWORKER_H

#include <QObject>
#include <QTcpSocket>
class QJsonObject;
class ServerWorker : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ServerWorker)
public:
    explicit ServerWorker(QObject *parent = nullptr);
    virtual bool setSocketDescriptor(qintptr socketDescriptor);

    void sendJson(const QJsonObject &jsonData);
signals:
    void jsonReceived(const QJsonObject &jsonDoc);
    void disconnectedFromClient();
    void error();
    void logMessage(const QString &msg);
public slots:
    void disconnectFromClient();
private slots:
    void receiveJson();
private:
    QTcpSocket *m_serverSocket;
};

#endif // SERVERWORKER_H
