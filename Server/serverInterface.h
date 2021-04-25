#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QWidget>
//prueba de error

namespace Ui {
class serverInterface;
}
class serverSends;
class serverInterface : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(serverInterface)
public:
    explicit serverInterface(QWidget *parent = nullptr);
    ~serverInterface();
private:
    Ui::serverInterface *ui;
    serverSends *m_chatServer;
private slots:
    void toggleStartServer();
    void logMessage(const QString &msg);
};

#endif // SERVERWINDOW_H
