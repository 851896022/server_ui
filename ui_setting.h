/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_setting
{
public:
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *txt_ip;
    QLabel *label_3;
    QLineEdit *txt_port;
    QPushButton *addEqu;
    QHBoxLayout *horizontalLayout_6;
    QListWidget *listEqu;
    QPushButton *delcur;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QTableWidget *listChName;
    QPushButton *save;

    void setupUi(QFrame *setting)
    {
        if (setting->objectName().isEmpty())
            setting->setObjectName(QStringLiteral("setting"));
        setting->resize(1161, 523);
        verticalLayout_3 = new QVBoxLayout(setting);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(setting);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        txt_ip = new QLineEdit(frame);
        txt_ip->setObjectName(QStringLiteral("txt_ip"));

        horizontalLayout_5->addWidget(txt_ip);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        txt_port = new QLineEdit(frame);
        txt_port->setObjectName(QStringLiteral("txt_port"));
        txt_port->setMaximumSize(QSize(100, 16777215));
        txt_port->setMaxLength(11);

        horizontalLayout_5->addWidget(txt_port);

        addEqu = new QPushButton(frame);
        addEqu->setObjectName(QStringLiteral("addEqu"));

        horizontalLayout_5->addWidget(addEqu);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        listEqu = new QListWidget(frame);
        new QListWidgetItem(listEqu);
        new QListWidgetItem(listEqu);
        listEqu->setObjectName(QStringLiteral("listEqu"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listEqu->sizePolicy().hasHeightForWidth());
        listEqu->setSizePolicy(sizePolicy);
        listEqu->setMinimumSize(QSize(0, 100));

        horizontalLayout_6->addWidget(listEqu);

        delcur = new QPushButton(frame);
        delcur->setObjectName(QStringLiteral("delcur"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(delcur->sizePolicy().hasHeightForWidth());
        delcur->setSizePolicy(sizePolicy1);
        delcur->setMaximumSize(QSize(30, 9999));

        horizontalLayout_6->addWidget(delcur);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_3->addWidget(frame);

        frame_2 = new QFrame(setting);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        listChName = new QTableWidget(frame_2);
        if (listChName->columnCount() < 1)
            listChName->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        listChName->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (listChName->rowCount() < 18)
            listChName->setRowCount(18);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        listChName->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        listChName->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        listChName->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        listChName->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        listChName->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        listChName->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        listChName->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        listChName->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        listChName->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        listChName->setVerticalHeaderItem(9, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        listChName->setVerticalHeaderItem(10, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        listChName->setVerticalHeaderItem(11, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        listChName->setVerticalHeaderItem(12, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        listChName->setVerticalHeaderItem(13, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        listChName->setVerticalHeaderItem(14, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        listChName->setVerticalHeaderItem(15, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        listChName->setItem(0, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        listChName->setItem(1, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        listChName->setItem(2, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        listChName->setItem(3, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        listChName->setItem(4, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        listChName->setItem(5, 0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        listChName->setItem(6, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        listChName->setItem(7, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        listChName->setItem(8, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        listChName->setItem(9, 0, __qtablewidgetitem26);
        listChName->setObjectName(QStringLiteral("listChName"));
        listChName->setRowCount(18);
        listChName->horizontalHeader()->setDefaultSectionSize(3000);

        verticalLayout->addWidget(listChName);


        verticalLayout_3->addWidget(frame_2);

        save = new QPushButton(setting);
        save->setObjectName(QStringLiteral("save"));

        verticalLayout_3->addWidget(save);

        verticalLayout_3->setStretch(1, 5);

        retranslateUi(setting);

        QMetaObject::connectSlotsByName(setting);
    } // setupUi

    void retranslateUi(QFrame *setting)
    {
        setting->setWindowTitle(QApplication::translate("setting", "Frame", nullptr));
        label->setText(QApplication::translate("setting", "\351\207\207\351\233\206\347\253\257\347\256\241\347\220\206", nullptr));
        label_2->setText(QApplication::translate("setting", "IP", nullptr));
        txt_ip->setText(QApplication::translate("setting", "192.168.0.3", nullptr));
        label_3->setText(QApplication::translate("setting", "\347\253\257\345\217\243", nullptr));
        txt_port->setText(QApplication::translate("setting", "2000", nullptr));
        addEqu->setText(QApplication::translate("setting", "\346\267\273\345\212\240", nullptr));

        const bool __sortingEnabled = listEqu->isSortingEnabled();
        listEqu->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listEqu->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("setting", "192.168.0.3:2000", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listEqu->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("setting", "192.168.0.4:2001", nullptr));
        listEqu->setSortingEnabled(__sortingEnabled);

        delcur->setText(QApplication::translate("setting", "\345\210\240\n"
"\351\231\244\n"
"\351\200\211\n"
"\344\270\255", nullptr));
        label_4->setText(QApplication::translate("setting", "\351\200\232\351\201\223\345\220\215\347\247\260\347\256\241\347\220\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem = listChName->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("setting", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = listChName->verticalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("setting", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = listChName->verticalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("setting", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = listChName->verticalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("setting", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = listChName->verticalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("setting", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = listChName->verticalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("setting", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = listChName->verticalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("setting", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = listChName->verticalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("setting", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = listChName->verticalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("setting", "9", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = listChName->verticalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("setting", "10", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = listChName->verticalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("setting", "11", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = listChName->verticalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("setting", "12", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = listChName->verticalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("setting", "13", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = listChName->verticalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("setting", "14", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = listChName->verticalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("setting", "15", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = listChName->verticalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("setting", "16", nullptr));

        const bool __sortingEnabled1 = listChName->isSortingEnabled();
        listChName->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem16 = listChName->item(0, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("setting", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = listChName->item(1, 0);
        ___qtablewidgetitem17->setText(QApplication::translate("setting", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = listChName->item(2, 0);
        ___qtablewidgetitem18->setText(QApplication::translate("setting", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = listChName->item(3, 0);
        ___qtablewidgetitem19->setText(QApplication::translate("setting", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = listChName->item(4, 0);
        ___qtablewidgetitem20->setText(QApplication::translate("setting", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = listChName->item(5, 0);
        ___qtablewidgetitem21->setText(QApplication::translate("setting", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = listChName->item(6, 0);
        ___qtablewidgetitem22->setText(QApplication::translate("setting", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = listChName->item(7, 0);
        ___qtablewidgetitem23->setText(QApplication::translate("setting", "9", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = listChName->item(8, 0);
        ___qtablewidgetitem24->setText(QApplication::translate("setting", "10", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = listChName->item(9, 0);
        ___qtablewidgetitem25->setText(QApplication::translate("setting", "11", nullptr));
        listChName->setSortingEnabled(__sortingEnabled1);

        save->setText(QApplication::translate("setting", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setting: public Ui_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
