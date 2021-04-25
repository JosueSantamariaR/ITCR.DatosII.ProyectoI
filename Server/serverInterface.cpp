#include "serverInterface.h"
#include "ui_serverInterface.h"
#include "serverSends.h"
#include <QMessageBox>
serverInterface::serverInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::serverInterface)
    , m_chatServer(new serverSends(this))
{
    ui->setupUi(this);
    connect(ui->startStopButton, &QPushButton::clicked, this, &serverInterface::toggleStartServer);
    connect(m_chatServer, &serverSends::logMessage, this, &serverInterface::logMessage);
}

serverInterface::~serverInterface()
{
    delete ui;
}

void serverInterface::toggleStartServer()
{
    if (m_chatServer->isListening()) {
        m_chatServer->stopServer();
        ui->startStopButton->setText(tr("Start Server"));
        logMessage(QStringLiteral("Server Stopped"));
    } else {
        if (!m_chatServer->listen(QHostAddress::Any, 1967)) {
            QMessageBox::critical(this, tr("Error"), tr("Unable to start the server"));
            return;
        }
        logMessage(QStringLiteral("Server Started"));
        ui->startStopButton->setText(tr("Stop Server"));
    }
}

void serverInterface::logMessage(const QString &msg)
{
    ui->logEditor->appendPlainText(msg + QLatin1Char('\n'));
}
