/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QFrame *title;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QWidget *widget;
    QLCDNumber *nowTime;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *control;
    QStackedWidget *stackedWidget;
    QWidget *page_ly_state;
    QHBoxLayout *horizontalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *page_set;
    QWidget *page_saveSet;
    QWidget *page_yxt;

    void setupUi(QStackedWidget *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QStringLiteral("main_window"));
        main_window->resize(1024, 751);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        title = new QFrame(page);
        title->setObjectName(QStringLiteral("title"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy);
        title->setMinimumSize(QSize(50, 50));
        title->setMaximumSize(QSize(16777215, 50));
        title->setStyleSheet(QLatin1String("#title\n"
"{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.0113636, y2:1, stop:0 rgba(67, 166, 245, 255), stop:0.994318 rgba(0, 105, 204, 255));\n"
"}"));
        horizontalLayout = new QHBoxLayout(title);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(title);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font: 22pt \"\351\273\221\344\275\223\";\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label);

        widget = new QWidget(title);
        widget->setObjectName(QStringLiteral("widget"));

        horizontalLayout->addWidget(widget);

        nowTime = new QLCDNumber(title);
        nowTime->setObjectName(QStringLiteral("nowTime"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nowTime->sizePolicy().hasHeightForWidth());
        nowTime->setSizePolicy(sizePolicy1);
        nowTime->setLayoutDirection(Qt::LeftToRight);
        nowTime->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        nowTime->setDigitCount(19);

        horizontalLayout->addWidget(nowTime);


        verticalLayout->addWidget(title);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        control = new QListWidget(page);
        new QListWidgetItem(control);
        new QListWidgetItem(control);
        new QListWidgetItem(control);
        new QListWidgetItem(control);
        new QListWidgetItem(control);
        new QListWidgetItem(control);
        new QListWidgetItem(control);
        new QListWidgetItem(control);
        new QListWidgetItem(control);
        new QListWidgetItem(control);
        control->setObjectName(QStringLiteral("control"));
        control->setMaximumSize(QSize(105, 16777215));
        QFont font;
        font.setPointSize(14);
        control->setFont(font);
        control->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 100, 255);"));

        horizontalLayout_2->addWidget(control);

        stackedWidget = new QStackedWidget(page);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page_ly_state = new QWidget();
        page_ly_state->setObjectName(QStringLiteral("page_ly_state"));
        horizontalLayout_3 = new QHBoxLayout(page_ly_state);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(page_ly_state);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 915, 697));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_3->addWidget(scrollArea);

        stackedWidget->addWidget(page_ly_state);
        page_set = new QWidget();
        page_set->setObjectName(QStringLiteral("page_set"));
        stackedWidget->addWidget(page_set);
        page_saveSet = new QWidget();
        page_saveSet->setObjectName(QStringLiteral("page_saveSet"));
        stackedWidget->addWidget(page_saveSet);
        page_yxt = new QWidget();
        page_yxt->setObjectName(QStringLiteral("page_yxt"));
        stackedWidget->addWidget(page_yxt);

        horizontalLayout_2->addWidget(stackedWidget);


        verticalLayout->addLayout(horizontalLayout_2);

        main_window->addWidget(page);

        retranslateUi(main_window);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QStackedWidget *main_window)
    {
        main_window->setWindowTitle(QApplication::translate("main_window", "\345\214\227\344\272\254\345\233\275\345\271\277\347\224\265\347\247\221\346\212\200\346\234\211\351\231\220\345\205\254\345\217\270", nullptr));
        label->setText(QApplication::translate("main_window", "\351\237\263\351\242\221\351\223\276\350\267\257\347\233\221\346\265\213\346\234\215\345\212\241\347\253\257", nullptr));

        const bool __sortingEnabled = control->isSortingEnabled();
        control->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = control->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("main_window", "\351\237\263\351\242\221\345\275\225\345\210\266", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = control->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("main_window", "\350\256\276\345\244\207\345\217\202\346\225\260", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = control->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("main_window", "\345\275\225\351\237\263\345\217\202\346\225\260", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = control->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("main_window", "\350\277\220\350\241\214\345\233\276\350\256\276\347\275\256", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = control->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("main_window", "\345\275\225\351\237\263\345\233\236\346\224\276", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = control->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("main_window", "\345\275\225\351\237\263\345\244\207\344\273\275", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = control->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("main_window", "\345\275\225\351\237\263\344\270\212\344\274\240", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = control->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("main_window", "\350\277\220\350\241\214\345\233\276\345\217\202\346\225\260", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = control->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("main_window", "\350\277\220\350\241\214\345\233\276\346\237\245\347\234\213", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = control->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("main_window", "\345\270\256\345\212\251", nullptr));
        control->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
