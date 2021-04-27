#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QWidget>

namespace Ui {
class ServerWindow;
}
class serverSends;
class ServerWindow : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ServerWindow)
public:
    explicit ServerWindow(QWidget *parent = nullptr);
    ~ServerWindow();
private:
    Ui::ServerWindow *ui;
    serverSends *m_chatServer;
private slots:
    void toggleStartServer();
    void logMessage(const QString &msg);
    void on_startStopButton_clicked();
};

#endif // SERVERWINDOW_H
