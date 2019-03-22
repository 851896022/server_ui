/********************************************************************************
** Form generated from reading UI file 'ch.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CH_H
#define UI_CH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ch
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *play;
    QLabel *name;
    QProgressBar *apm;
    QProgressBar *saveProgress;

    void setupUi(QFrame *ch)
    {
        if (ch->objectName().isEmpty())
            ch->setObjectName(QStringLiteral("ch"));
        ch->resize(1398, 23);
        horizontalLayout = new QHBoxLayout(ch);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        play = new QPushButton(ch);
        play->setObjectName(QStringLiteral("play"));

        horizontalLayout->addWidget(play);

        name = new QLabel(ch);
        name->setObjectName(QStringLiteral("name"));
        name->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(name);

        apm = new QProgressBar(ch);
        apm->setObjectName(QStringLiteral("apm"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(apm->sizePolicy().hasHeightForWidth());
        apm->setSizePolicy(sizePolicy);
        apm->setStyleSheet(QLatin1String("QProgressBar::chunk{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:0.0454545 rgba(255, 247, 0, 255), stop:1 rgba(85, 170, 0, 255));\n"
"};"));
        apm->setValue(24);
        apm->setAlignment(Qt::AlignCenter);
        apm->setTextVisible(true);
        apm->setOrientation(Qt::Horizontal);
        apm->setInvertedAppearance(true);

        horizontalLayout->addWidget(apm);

        saveProgress = new QProgressBar(ch);
        saveProgress->setObjectName(QStringLiteral("saveProgress"));
        saveProgress->setMaximum(60);
        saveProgress->setValue(24);
        saveProgress->setAlignment(Qt::AlignCenter);
        saveProgress->setInvertedAppearance(false);

        horizontalLayout->addWidget(saveProgress);


        retranslateUi(ch);

        QMetaObject::connectSlotsByName(ch);
    } // setupUi

    void retranslateUi(QFrame *ch)
    {
        ch->setWindowTitle(QApplication::translate("ch", "Frame", nullptr));
        play->setText(QApplication::translate("ch", "\346\222\255\346\224\276", nullptr));
        name->setText(QApplication::translate("ch", "\351\200\232\351\201\223\345\220\215\347\247\260", nullptr));
        apm->setFormat(QApplication::translate("ch", "%p", nullptr));
        saveProgress->setFormat(QApplication::translate("ch", "C :/mp3/asd6/asg\345\267\262\345\275\225\345\210\266%p%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ch: public Ui_ch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CH_H
