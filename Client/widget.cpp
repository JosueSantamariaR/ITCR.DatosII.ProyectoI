#include "widget.h"
#include "ui_widget.h"
#include <QLocalSocket>
#include <QTextStream>
#include "Tokens/Tokenizer.h"
#include "Interpreter/Interpreter.h"
#include "clientsends.h"
#include <iostream>
#include<QTextStream>
#include <QFile>
#include <QStandardItemModel>
#include <QInputDialog>
#include <QMessageBox>
#include <QHostAddress>
#include <QtCore>

using namespace std;
using namespace interpreter;



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_chatClient(new clientSends(this)) // create the chat client
    , m_chatModel(new QStandardItemModel(this)) // create the model to hold the messages
{
    ui->setupUi(this);
    // the model for the messages will have 1 column

    // connect the signals from the chat client to the slots in this ui
    connect(m_chatClient, &clientSends::connected, this, &Widget::connectedToServer);
    connect(m_chatClient, &clientSends::messageReceived, this, &Widget::messageReceived);
    connect(m_chatClient, &clientSends::disconnected, this, &Widget::disconnectedFromServer);
    connect(m_chatClient, &clientSends::error, this, &Widget::error);

    // connect the connect button to a slot that will attempt the connection
    m_chatClient->connectToServer(QHostAddress("127.0.0.1"), 1967);
    // connect the click of the "send" button and the press of the enter while typing to the slot that sends the message
    connect(ui->startButton, &QPushButton::clicked, this, &Widget::sendMessage);

}

Widget::~Widget()
{
    delete ui;
}
void Widget::connectedToServer()
{
    // once we connected to the server we ask the user for what username they would like to use
    ui->startButton->setEnabled(true);
    ui->plainTextEdit->setEnabled(true);
    ui->plainTextEdit_2->setEnabled(true);
}
void Widget::messageReceived( const QString &text)
{
    // store the index of the new row to append to the model containing the messages
    int newRow = m_chatModel->rowCount();
    // we display a line containing the username only if it's different from the last username we displayed

    m_chatModel->insertRow(newRow);

    // store the message in the model
    m_chatModel->setData(m_chatModel->index(newRow, 0), text);
    // set the alignment for the message
    m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignVCenter), Qt::TextAlignmentRole);
    // scroll the view to display the new message

}
void Widget::sendMessage()
{
    static QString a;
    static QString b;

    try {

            QString filename = "/home/garroakion/Desktop/C!/ITCR.DatosII.ProyectoI/Client/test.myc";
            QFile file(filename);
                if (file.open(QIODevice::ReadWrite)) {
                        QTextStream stream(&file);
                        stream<< ui->plainTextEdit->toPlainText();
                    }

            FILE *fh = fopen("/home/garroakion/Desktop/C!/ITCR.DatosII.ProyectoI/Client/test.myc", "r");
            if (!fh) { cerr << "Can't find file." << endl; }
            fseek(fh, 0, SEEK_END);
            size_t fileSize = ftell(fh);
            fseek(fh, 0, SEEK_SET);
            string fileContents(fileSize, ' ');
            fread((void *) fileContents.data(), 1, fileSize, fh);

            Tokenizer tokenizer;
            vector<Token> tokens = tokenizer.parse(fileContents);
            a = fileContents.c_str();

            for(Token currToken : tokens) {
                currToken.debugPrint();
            }


            Interpreter interpreter;
            interpreter.parse(tokens);
            interpreter.debugPrint();
            interpreter.writeInLog().c_str();
            ui->stdout->append(interpreter.writeInLog().c_str());



           /*

                    string str =interpreter.debugPrint();
                    qstr = QString::fromStdString(str);
          */

        }


        catch (exception& err) {
                cerr << "Error: " << err.what() << endl;

            } catch (...) {
                cerr << "Unknown Error." << endl;

            }

        ui->plainTextEdit_2->setPlainText(a);


    m_chatClient->sendMessage(ui->plainTextEdit->toPlainText());
    // now we add the message to the list
    // store the index of the new row to append to the model containing the messages
    const int newRow = m_chatModel->rowCount();
    // insert a row for the message
    m_chatModel->insertRow(newRow);
    // store the message in the model
    m_chatModel->setData(m_chatModel->index(newRow, 0), ui->plainTextEdit->toPlainText());
    // set the alignment for the message
    m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignRight | Qt::AlignVCenter), Qt::TextAlignmentRole);
    // clear the content of the message editor






}

void Widget::disconnectedFromServer()
{
    // if the client loses connection to the server
    // comunicate the event to the user via a message box
    QMessageBox::warning(this, tr("Disconnected"), tr("The host terminated the connection"));
    // disable the ui to send and display messages

    ui->plainTextEdit->setEnabled(false);
    // enable the button to connect to the server again

}


void Widget::on_exit_clicked()
{
    close();
}


void Widget::on_startButton_clicked()
{

}

void Widget::on_clearLogButton_clicked()
{


}

void Widget::error(QAbstractSocket::SocketError socketError)
{
    // show a message to the user that informs of what kind of error occurred
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
    case QAbstractSocket::ProxyConnectionClosedError:
        return; // handled by disconnectedFromServer
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::critical(this, tr("Error"), tr("The host refused the connection"));
        break;
    case QAbstractSocket::ProxyConnectionRefusedError:
        QMessageBox::critical(this, tr("Error"), tr("The proxy refused the connection"));
        break;
    case QAbstractSocket::ProxyNotFoundError:
        QMessageBox::critical(this, tr("Error"), tr("Could not find the proxy"));
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::critical(this, tr("Error"), tr("Could not find the server"));
        break;
    case QAbstractSocket::SocketAccessError:
        QMessageBox::critical(this, tr("Error"), tr("You don't have permissions to execute this operation"));
        break;
    case QAbstractSocket::SocketResourceError:
        QMessageBox::critical(this, tr("Error"), tr("Too many connections opened"));
        break;
    case QAbstractSocket::SocketTimeoutError:
        QMessageBox::warning(this, tr("Error"), tr("Operation timed out"));
        return;
    case QAbstractSocket::ProxyConnectionTimeoutError:
        QMessageBox::critical(this, tr("Error"), tr("Proxy timed out"));
        break;
    case QAbstractSocket::NetworkError:
        QMessageBox::critical(this, tr("Error"), tr("Unable to reach the network"));
        break;
    case QAbstractSocket::UnknownSocketError:
        QMessageBox::critical(this, tr("Error"), tr("An unknown error occured"));
        break;
    case QAbstractSocket::UnsupportedSocketOperationError:
        QMessageBox::critical(this, tr("Error"), tr("Operation not supported"));
        break;
    case QAbstractSocket::ProxyAuthenticationRequiredError:
        QMessageBox::critical(this, tr("Error"), tr("Your proxy requires authentication"));
        break;
    case QAbstractSocket::ProxyProtocolError:
        QMessageBox::critical(this, tr("Error"), tr("Proxy comunication failed"));
        break;
    case QAbstractSocket::TemporaryError:
    case QAbstractSocket::OperationError:
        QMessageBox::warning(this, tr("Error"), tr("Operation failed, please try again"));
        return;
    default:
        Q_UNREACHABLE();
    }

    ui->plainTextEdit->setEnabled(false);

}





void Widget::on_pushButton_19_clicked()
{


}




void Widget::on_pushButton_18_clicked()
{
    ui->plainTextEdit_2->clear();
    QString filename2 = "/home/garroakion/Desktop/C!/ITCR.DatosII.ProyectoI/Client/test.myc";
    QFile file2(filename2);
    if (file2.open(QIODevice::WriteOnly| QIODevice::Truncate)) {
            QTextStream stream(&file2);
            stream.reset();
        }
}
