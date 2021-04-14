#include "widget.h"
#include "ui_widget.h"
#include "server.h"
#include "QMessageBox"

widget::widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
    mLocalServer = new Server(this);
}

widget::~widget()
{
    delete ui;
}


void widget::on_start_clicked()
{
    if(!mLocalServer->listen(ui->ser->text()))
        QMessageBox::critical(this,"Error",mLocalServer->errorString());
    else {
        QMessageBox::information(this,"Servidor","Iniciado...");
    }
}

void widget::on_send_clicked()
{

    mLocalServer->envia(ui->msj->text());
}

void widget::on_exit_clicked()
{
    close();
}
