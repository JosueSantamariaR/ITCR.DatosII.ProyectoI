#include "widget.h"
#include "ui_widget.h"
#include <QLocalSocket>
#include <QTextStream>
#include "Tokens/Tokenizer.h"
#include "Interpreter/Interpreter.h"
#include <iostream>
#include<QTextStream>
#include <QFile>


using namespace std;
using namespace interpreter;



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


void Widget::on_startButton_clicked()
{
    static QString a;

        try {

                QString filename = "C:\\Users\\garroakion\\Desktop\\ITCR.DatosII.ProyectoI\\Client\\test.myc";
                QFile file(filename);
                    if (file.open(QIODevice::ReadWrite)) {
                            QTextStream stream(&file);
                            stream<< ui->plainTextEdit->toPlainText();
                        }

                FILE *fh = fopen("C:\\Users\\garroakion\\Desktop\\ITCR.DatosII.ProyectoI\\Client\\test.myc", "r");
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
                interpreter.debugPrint();

               /*




                        for(Token currToken : tokens) {
                            currToken.debugPrint();
                        }




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


}

void Widget::on_clearLogButton_clicked()
{
    ui->plainTextEdit_2->clear();


    QString filename = "C:\\Users\\garroakion\\Desktop\\ITCR.DatosII.ProyectoI\\Client\\test.myc";
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly| QIODevice::Truncate)) {
            QTextStream stream(&file);
            stream.reset();
        }
}
