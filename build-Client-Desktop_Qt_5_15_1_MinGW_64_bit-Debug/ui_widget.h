/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFrame *line_4;
    QFrame *line_2;
    QTableWidget *ramLiveView;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_5;
    QFrame *line;
    QPlainTextEdit *plainTextEdit;
    QPushButton *clearLogButton;
    QLabel *server;
    QLabel *label_4;
    QPushButton *exit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *startButton;
    QPushButton *pushButton_19;
    QPushButton *pushButton_16;
    QPushButton *pushButton_18;
    QPushButton *connect;
    QLineEdit *servertex;
    QListWidget *listWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(852, 876);
        line_4 = new QFrame(Widget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(10, 55, 838, 3));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(Widget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 436, 838, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        ramLiveView = new QTableWidget(Widget);
        if (ramLiveView->columnCount() < 4)
            ramLiveView->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        ramLiveView->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        ramLiveView->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        ramLiveView->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        ramLiveView->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (ramLiveView->rowCount() < 11)
            ramLiveView->setRowCount(11);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        ramLiveView->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        ramLiveView->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        ramLiveView->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        ramLiveView->setVerticalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        ramLiveView->setVerticalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        ramLiveView->setVerticalHeaderItem(5, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        ramLiveView->setVerticalHeaderItem(6, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        ramLiveView->setVerticalHeaderItem(7, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        ramLiveView->setVerticalHeaderItem(8, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        ramLiveView->setVerticalHeaderItem(9, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        ramLiveView->setVerticalHeaderItem(10, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        ramLiveView->setItem(0, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        ramLiveView->setItem(0, 1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        ramLiveView->setItem(0, 2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        ramLiveView->setItem(0, 3, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        ramLiveView->setItem(1, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        ramLiveView->setItem(1, 1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        ramLiveView->setItem(1, 2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        ramLiveView->setItem(1, 3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        ramLiveView->setItem(2, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        ramLiveView->setItem(2, 1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setTextAlignment(Qt::AlignCenter);
        ramLiveView->setItem(2, 2, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        ramLiveView->setItem(3, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        ramLiveView->setItem(3, 1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        ramLiveView->setItem(3, 3, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        ramLiveView->setItem(4, 0, __qtablewidgetitem29);
        ramLiveView->setObjectName(QString::fromUtf8("ramLiveView"));
        ramLiveView->setEnabled(false);
        ramLiveView->setGeometry(QRect(437, 70, 411, 360));
        ramLiveView->setMinimumSize(QSize(410, 340));
        plainTextEdit_2 = new QPlainTextEdit(Widget);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        plainTextEdit_2->setEnabled(false);
        plainTextEdit_2->setGeometry(QRect(10, 479, 838, 359));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 445, 412, 28));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(300, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_5->setFont(font);
        label_5->setIndent(75);
        line = new QFrame(Widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(428, 57, 3, 373));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 70, 412, 360));
        clearLogButton = new QPushButton(Widget);
        clearLogButton->setObjectName(QString::fromUtf8("clearLogButton"));
        clearLogButton->setGeometry(QRect(720, 840, 131, 21));
        server = new QLabel(Widget);
        server->setObjectName(QString::fromUtf8("server"));
        server->setGeometry(QRect(10, 840, 44, 17));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(480, 10, 300, 32));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(300, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label_4->setFont(font1);
        label_4->setIndent(75);
        exit = new QPushButton(Widget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(490, 840, 80, 25));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 395, 30));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        startButton = new QPushButton(layoutWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        horizontalLayout_10->addWidget(startButton);

        pushButton_19 = new QPushButton(layoutWidget);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));

        horizontalLayout_10->addWidget(pushButton_19);

        pushButton_16 = new QPushButton(layoutWidget);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setBaseSize(QSize(0, 0));

        horizontalLayout_10->addWidget(pushButton_16);

        pushButton_18 = new QPushButton(layoutWidget);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));

        horizontalLayout_10->addWidget(pushButton_18);

        connect = new QPushButton(Widget);
        connect->setObjectName(QString::fromUtf8("connect"));
        connect->setGeometry(QRect(210, 840, 80, 25));
        servertex = new QLineEdit(Widget);
        servertex->setObjectName(QString::fromUtf8("servertex"));
        servertex->setGeometry(QRect(60, 840, 142, 21));
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(290, 840, 194, 21));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        QTableWidgetItem *___qtablewidgetitem = ramLiveView->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Widget", "Dir", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = ramLiveView->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Widget", "Data", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = ramLiveView->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Widget", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = ramLiveView->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Widget", "Ref", nullptr));

        const bool __sortingEnabled = ramLiveView->isSortingEnabled();
        ramLiveView->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = ramLiveView->item(0, 0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Widget", "0x00", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = ramLiveView->item(0, 1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Widget", "500", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = ramLiveView->item(0, 2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Widget", "a", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = ramLiveView->item(0, 3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Widget", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = ramLiveView->item(1, 0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Widget", "0x04", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = ramLiveView->item(1, 1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Widget", "x", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = ramLiveView->item(1, 2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Widget", "c", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = ramLiveView->item(1, 3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Widget", "1", nullptr));
        ramLiveView->setSortingEnabled(__sortingEnabled);

        label_5->setText(QCoreApplication::translate("Widget", "Application Log", nullptr));
        clearLogButton->setText(QCoreApplication::translate("Widget", "Clear Log", nullptr));
        server->setText(QCoreApplication::translate("Widget", "Server", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Ram Live View", nullptr));
        exit->setText(QCoreApplication::translate("Widget", "Server exit", nullptr));
        startButton->setText(QCoreApplication::translate("Widget", "Star", nullptr));
        pushButton_19->setText(QCoreApplication::translate("Widget", "Restart", nullptr));
        pushButton_16->setText(QCoreApplication::translate("Widget", "Previous", nullptr));
        pushButton_18->setText(QCoreApplication::translate("Widget", "Next", nullptr));
        connect->setText(QCoreApplication::translate("Widget", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
