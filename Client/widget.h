/**
  * @file widget.h
  * */
#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>
#include <QAbstractSocket>
QT_BEGIN_NAMESPACE
class clientSends;
class QStandardItemModel;
namespace Ui { class Widget; }
QT_END_NAMESPACE
class QLocalSocket;
class Widget : public QWidget
{

    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_startButton_clicked();
    void on_clearLogButton_clicked();
    void connectedToServer();
    void messageReceived(const QString &text);
    void sendMessage();
    void disconnectedFromServer();
    void error(QAbstractSocket::SocketError socketError);

    void on_pushButton_19_clicked();

    void on_pushButton_18_clicked();

private:
    Ui::Widget *ui;
    clientSends *m_chatClient;
    QStandardItemModel *m_chatModel;
};
#endif // WIDGET_H
