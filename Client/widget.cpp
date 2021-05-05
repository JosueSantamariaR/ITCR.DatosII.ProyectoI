/**
  * @file widget.cpp
  * */
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
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <stack>
#include <queue>
#include <QtGui>
using namespace std;
using namespace interpreter;

/**
 * @brief Constructor de la clase
 * @param QWidget
 * @authors Akion&Josue
 */

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


/**
 * @brief Destructor de la clase
 * @authors Akion&Josue
 */
Widget::~Widget()
{
    delete ui;
}

/**
 * @brief Metodo que se encarga de establecer la conexion con el server
 * @authors Akion&Josue
 */
void Widget::connectedToServer()
{
    // once we connected to the server we ask the user for what username they would like to use
    ui->startButton->setEnabled(true);
    ui->plainTextEdit->setEnabled(true);
    ui->plainTextEdit_2->setEnabled(true);
}


/**
 * @brief Metodo que se encarga de recibir los mensajes del servidor
 * @param QString text
 * @authors Akion&Josue
 */
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



/**
 * @brief Metodo que se encarga de enviar los mensajes al servidor y abrir el documento.
 * @authors Akion&Josue
 */
void Widget::sendMessage()
{
    static QString a;
    static QString b;
    int cols=3;
    QString** varss;
    int sizer=20;
    varss = new QString*[sizer];


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

        Interpreter interpreter;
        interpreter.parse(tokens);


        queue<string> vars;
        queue<string> dirs;

        while(!interpreter.displayLog.empty()){
            ui->plainTextEdit_2->insertPlainText(interpreter.displayLog.front().c_str());
            interpreter.displayLog.pop();
        }


        int size = tokens.size();
        int c=0;

        for(static int i=0;i<size;i++ ) {
            varss[c]= new QString[cols];
            Token currToken = tokens[i];
            string token =  currToken.mText;
            int m=0;
            if(token == "int" || token == "double" || token == "float" || token == "string" || token == "char"   ){

                int top =i+4;
                m=0;
                for(int j = i;j<top;j++){

                    Token currToken = tokens[j];

                    if (currToken.mText == "="){

                    }else{
                        string var =currToken.mText;

                        if(m==0){
                            varss[c][m]=QString::fromStdString(var);
                            //cout<<"Prueba: "+varss[c][m]<<endl;
                        }if(m==1){
                            varss[c][m]=QString::fromStdString(var);
                            //cout<<"Prueba: "+varss[c][m]<<endl;
                        }if(m==3){
                            varss[c][m-1]=QString::fromStdString(var);
                            //cout<<"Prueba: "+varss[c][m-1]<<endl;

                        }
                        vars.push(var);



                    }
                    m++;
                }
                QString s=QString("0x%1").arg((quintptr)&varss[c],QT_POINTER_SIZE *2,16,QChar('0'));
                dirs.push(s.toStdString());
                c++;
            }

             if(token == "printf"){

                int prf =i+4;

                for(int x = i;x<prf;x++){


                    Token currToken = tokens[x];
                    string prnt ="";
                    i =++x;

                    if(currToken.mText!="printf"){
                        prnt += currToken.mText;

                        ui->stdout->insertPlainText(prnt.c_str());
                        ui->stdout->insertPlainText("                                                                                                                                                                                        ");
                    }
                }

            }
        }


        int nfilas = vars.size()/3;
        for(int i=0;i<nfilas;i++){
            for(int j=0;j<3;j++){
                string it = vars.front();
                QTableWidgetItem  * item = new  QTableWidgetItem(it.c_str());
                ui->ramLiveView->setItem(i,j, item);
                vars.pop();

            }
            string di=dirs.front();
             QTableWidgetItem * item2= new QTableWidgetItem(di.c_str());
             ui->ramLiveView->setItem(i,3, item2);
             dirs.pop();
        }
    }



    catch (exception& err) {
        cerr << "Error: " << err.what() << endl;

    } catch (...) {
        cerr << "Unknown Error." << endl;

    }

    //ui->plainTextEdit_2->setPlainText(a);


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


/**
 * @brief Metodo que se encarga de notificar la desconexion del server
 * @authors Akion&Josue
 */

void Widget::disconnectedFromServer()
{
    // if the client loses connection to the server
    // comunicate the event to the user via a message box
    QMessageBox::warning(this, tr("Disconnected"), tr("The host terminated the connection"));
    // disable the ui to send and display messages

    ui->plainTextEdit->setEnabled(false);
    // enable the button to connect to the server again

}

/**
 * @brief Boton de salir
 * @authors Akion&Josue
 */


void Widget::on_startButton_clicked()
{

}

void Widget::on_clearLogButton_clicked()
{


}

/**
 * @brief Metodo que se encarga de mostrar los errores del servidor
 * @param string value
 * @authors Akion&Josue
 */

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


/**
 * @brief Metodo que se encarga de limpiar el archivo y el texto.
 * @param string value
 * @authors Akion&Josue
 */

void Widget::on_pushButton_18_clicked()
{
    ui->plainTextEdit_2->clear();
    ui->stdout->clear();
    ui->ramLiveView->clear();
    QString filename2 = "/home/garroakion/Desktop/C!/ITCR.DatosII.ProyectoI/Client/test.myc";
    QFile file2(filename2);
    if (file2.open(QIODevice::WriteOnly| QIODevice::Truncate)) {
        QTextStream stream(&file2);
        stream.reset();
    }
}
