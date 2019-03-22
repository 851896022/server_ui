/********************************************************************************
** Form generated from reading UI file 'edityxt.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITYXT_H
#define UI_EDITYXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditYxt
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_5;
    QComboBox *nameList;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTimeEdit *startTime;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTimeEdit *endTime;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *txtFre;
    QPushButton *btnAdd;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *timeList;
    QPushButton *btnDelete;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnSave;

    void setupUi(QFrame *EditYxt)
    {
        if (EditYxt->objectName().isEmpty())
            EditYxt->setObjectName(QStringLiteral("EditYxt"));
        EditYxt->resize(496, 562);
        verticalLayout_4 = new QVBoxLayout(EditYxt);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_4 = new QGroupBox(EditYxt);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        QFont font;
        font.setPointSize(14);
        groupBox_4->setFont(font);
        verticalLayout_5 = new QVBoxLayout(groupBox_4);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        nameList = new QComboBox(groupBox_4);
        nameList->setObjectName(QStringLiteral("nameList"));
        nameList->setFont(font);

        verticalLayout_5->addWidget(nameList);


        verticalLayout_4->addWidget(groupBox_4);

        groupBox = new QGroupBox(EditYxt);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        startTime = new QTimeEdit(groupBox);
        startTime->setObjectName(QStringLiteral("startTime"));
        startTime->setFont(font);

        verticalLayout->addWidget(startTime);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        endTime = new QTimeEdit(groupBox);
        endTime->setObjectName(QStringLiteral("endTime"));
        endTime->setFont(font);

        verticalLayout_2->addWidget(endTime);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        txtFre = new QLineEdit(groupBox);
        txtFre->setObjectName(QStringLiteral("txtFre"));
        txtFre->setFont(font);

        verticalLayout_3->addWidget(txtFre);


        horizontalLayout->addLayout(verticalLayout_3);

        btnAdd = new QPushButton(groupBox);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnAdd->sizePolicy().hasHeightForWidth());
        btnAdd->setSizePolicy(sizePolicy);
        btnAdd->setFont(font);

        horizontalLayout->addWidget(btnAdd);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(EditYxt);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        timeList = new QListWidget(groupBox_2);
        timeList->setObjectName(QStringLiteral("timeList"));
        timeList->setFont(font);

        horizontalLayout_2->addWidget(timeList);

        btnDelete = new QPushButton(groupBox_2);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        sizePolicy.setHeightForWidth(btnDelete->sizePolicy().hasHeightForWidth());
        btnDelete->setSizePolicy(sizePolicy);
        btnDelete->setFont(font);

        horizontalLayout_2->addWidget(btnDelete);


        verticalLayout_4->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(EditYxt);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnSave = new QPushButton(groupBox_3);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setFont(font);

        horizontalLayout_3->addWidget(btnSave);


        verticalLayout_4->addWidget(groupBox_3);


        retranslateUi(EditYxt);

        QMetaObject::connectSlotsByName(EditYxt);
    } // setupUi

    void retranslateUi(QFrame *EditYxt)
    {
        EditYxt->setWindowTitle(QApplication::translate("EditYxt", "Frame", nullptr));
        groupBox_4->setTitle(QApplication::translate("EditYxt", "\342\221\240\351\200\211\346\213\251\345\217\221\345\260\204\346\234\272", nullptr));
        groupBox->setTitle(QApplication::translate("EditYxt", "\342\221\241\345\241\253\345\206\231\346\227\266\351\227\264\345\222\214\351\242\221\347\216\207", nullptr));
        label->setText(QApplication::translate("EditYxt", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        startTime->setDisplayFormat(QApplication::translate("EditYxt", "hh:mm:ss", nullptr));
        label_2->setText(QApplication::translate("EditYxt", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        endTime->setDisplayFormat(QApplication::translate("EditYxt", "hh:mm:ss", nullptr));
        label_3->setText(QApplication::translate("EditYxt", "\351\242\221\347\216\207\345\246\202\357\274\2109865\357\274\211", nullptr));
        btnAdd->setText(QApplication::translate("EditYxt", "\346\267\273\345\212\240", nullptr));
        groupBox_2->setTitle(QApplication::translate("EditYxt", "\342\221\242\350\276\223\345\205\245\351\224\231\350\257\257\345\217\257\345\210\240\351\231\244", nullptr));
        btnDelete->setText(QApplication::translate("EditYxt", "\345\210\240\n"
"\351\231\244\n"
"\351\200\211\n"
"\344\270\255", nullptr));
        groupBox_3->setTitle(QApplication::translate("EditYxt", "\342\221\243\344\277\235\345\255\230", nullptr));
        btnSave->setText(QApplication::translate("EditYxt", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditYxt: public Ui_EditYxt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITYXT_H
