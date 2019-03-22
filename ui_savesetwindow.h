/********************************************************************************
** Form generated from reading UI file 'savesetwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVESETWINDOW_H
#define UI_SAVESETWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_saveSetWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *txt_saveDir;
    QPushButton *btn_get;
    QPushButton *btn_save;
    QSpacerItem *verticalSpacer;

    void setupUi(QFrame *saveSetWindow)
    {
        if (saveSetWindow->objectName().isEmpty())
            saveSetWindow->setObjectName(QStringLiteral("saveSetWindow"));
        saveSetWindow->resize(861, 474);
        verticalLayout = new QVBoxLayout(saveSetWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(saveSetWindow);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        txt_saveDir = new QLineEdit(saveSetWindow);
        txt_saveDir->setObjectName(QStringLiteral("txt_saveDir"));

        horizontalLayout->addWidget(txt_saveDir);

        btn_get = new QPushButton(saveSetWindow);
        btn_get->setObjectName(QStringLiteral("btn_get"));

        horizontalLayout->addWidget(btn_get);

        btn_save = new QPushButton(saveSetWindow);
        btn_save->setObjectName(QStringLiteral("btn_save"));

        horizontalLayout->addWidget(btn_save);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 422, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(saveSetWindow);

        QMetaObject::connectSlotsByName(saveSetWindow);
    } // setupUi

    void retranslateUi(QFrame *saveSetWindow)
    {
        saveSetWindow->setWindowTitle(QApplication::translate("saveSetWindow", "Frame", nullptr));
        label->setText(QApplication::translate("saveSetWindow", "\344\277\235\345\255\230\345\234\260\345\235\200", nullptr));
        btn_get->setText(QApplication::translate("saveSetWindow", "\351\200\211\346\213\251...", nullptr));
        btn_save->setText(QApplication::translate("saveSetWindow", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class saveSetWindow: public Ui_saveSetWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVESETWINDOW_H
