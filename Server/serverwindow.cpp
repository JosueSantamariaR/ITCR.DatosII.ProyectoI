/**
  * @file serverwindow.cpp
  * */
#include "serverwindow.h"
#include "ui_serverwindow.h"
#include "serverSends.h"
#include <QMessageBox>
#include "memoryblock.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;

/**
 * @brief Constructor de la clase
 * @param Objeto de tipo QWidget
 * @authors Akion&Josue
 */
ServerWindow::ServerWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWindow)
    , m_chatServer(new serverSends(this))
{
    ui->setupUi(this);
    connect(ui->startStopButton, &QPushButton::clicked, this, &ServerWindow::toggleStartServer);
    connect(m_chatServer, &serverSends::logMessage, this, &ServerWindow::logMessage);
}

/**
 * @brief Destructor de la clase
 * @authors Akion&Josue
 */

ServerWindow::~ServerWindow()
{
    delete ui;
}


/**
 * @brief Metodo para el inicio del servidor.
 * @authors Akion&Josue
 */
void ServerWindow::toggleStartServer()
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

/**
 * @brief Metodo para escribir en la ventana del servidor
 * @param A Objeto de tipo QString
 * @authors Akion&Josue
 */
void ServerWindow::logMessage(const QString &msg)
{
    ui->logEditor->appendPlainText(msg + QLatin1Char('\n'));
}


/**
 * @brief Metodo para el boton de inicio
 * @param Objeto de tipo QWidget
 * @authors Akion&Josue
 */

void ServerWindow::on_startStopButton_clicked()
{
    static vector<MemoryBlock> memoryMap;

       MemoryBlock obj1("a",1,"25");
       memoryMap.push_back(obj1);

       MemoryBlock obj2("b",2,"65");
       memoryMap.push_back(obj2);

       MemoryBlock obj3("aasd",1,"255");
       memoryMap.push_back(obj3);

       MemoryBlock obj4("aaf",1,"2565");
       memoryMap.push_back(obj4);


       MemoryBlock obj5("fdsa",2,"2565");
       memoryMap.push_back(obj5);

       int size = memoryMap.size();
       int i=0;
       while(i<size){
           cout<<"Name:"<<memoryMap[i].getName()<<endl;
           cout<<"Type:"<<memoryMap[i].getMemoryvalue()<<endl;
           cout<<"Value:"<<memoryMap[i].getValue()<<endl;
           cout<<endl;
           i++;
       }
}
