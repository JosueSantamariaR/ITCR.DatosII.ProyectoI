#include "widget.h"
#include "ui_widget.h"
#include <QLocalSocket>
#include <QTextStream>
//hola
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket= new QLocalSocket(this);
    connect(mSocket,&QLocalSocket::readyRead,[&]()
     { QTextStream T(mSocket);
            ui->listWidget->addItem(T.readAll());
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_connect_clicked()
{
    mSocket->connectToServer(ui->servertex->text());
}

void Widget::on_exit_clicked()
{
    close();
}
