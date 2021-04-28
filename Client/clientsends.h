/**
  * @file clientsends.h
  * */
#ifndef CLIENTSENDS_H
#define CLIENTSENDS_H


#include <QObject>
#include <QTcpSocket>
class QHostAddress;
class QJsonDocument;
class clientSends : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(clientSends)
public:
    explicit clientSends(QObject *parent = nullptr);
public slots:
    void connectToServer(const QHostAddress &address, quint16 port);
    void sendMessage(const QString &text);
    void disconnectFromHost();
private slots:
    void onReadyRead();
signals:
    void connected();
    void disconnected();
    void messageReceived(const QString &sender, const QString &text);
    void error(QAbstractSocket::SocketError socketError);

private:
    QTcpSocket *m_clientSocket;
    void jsonReceived(const QJsonObject &doc);
};

#endif // CLIENTSENDS_H
