#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class widget; }
QT_END_NAMESPACE
class Server;
class widget : public QMainWindow
{
    Q_OBJECT

public:
    widget(QWidget *parent = nullptr);
    ~widget();

private slots:
    void on_start_clicked();

    void on_send_clicked();

    void on_exit_clicked();

private:
    Ui::widget *ui;
    Server *mLocalServer;
};
#endif // WIDGET_H
