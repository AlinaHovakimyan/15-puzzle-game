/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QWidget>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *grid;
    QWidget *menu;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *newGame;
    QPushButton *continueGame;
    QPushButton *bestScores;
    QPushButton *setLevel;
    QPushButton *aboutUs;
    QPushButton *help;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *mixPiecesButton;
    QPushButton *closeBurron;
    QTextEdit *gameName;
    QLabel *textLabel;
    QLabel *image;
    QPushButton *back;
    QLabel *DigitalClock;
    QGroupBox *groupBox;
    QLabel *picLabel;
    QPushButton *backToMenu;
    QPushButton *nextLevel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(396, 437);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setMinimumSize(QSize(396, 437));
        Dialog->setMaximumSize(QSize(396, 437));
        Dialog->setStyleSheet(QStringLiteral(""));
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 10, 401, 381));
        grid = new QGridLayout(gridLayoutWidget);
        grid->setSpacing(6);
        grid->setContentsMargins(11, 11, 11, 11);
        grid->setObjectName(QStringLiteral("grid"));
        grid->setContentsMargins(0, 0, 0, 0);
        menu = new QWidget(Dialog);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setStyleSheet(QStringLiteral(""));
        menu->setGeometry(QRect(0, 10, 396, 437));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft Sans Serif"));
        font.setPointSize(25);
        verticalLayoutWidget = new QWidget(menu);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(70, 100, 231, 221));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        newGame = new QPushButton(verticalLayoutWidget);
        newGame->setObjectName(QStringLiteral("newGame"));
        newGame->setEnabled(true);

        verticalLayout->addWidget(newGame);

        continueGame = new QPushButton(verticalLayoutWidget);
        continueGame->setObjectName(QStringLiteral("continueGame"));

        verticalLayout->addWidget(continueGame);

        setLevel = new QPushButton(verticalLayoutWidget);
        setLevel->setObjectName(QStringLiteral("Level"));

        verticalLayout->addWidget(setLevel);

        bestScores = new QPushButton(verticalLayoutWidget);
        bestScores->setObjectName(QStringLiteral("bestScores"));

        verticalLayout->addWidget(bestScores);

        aboutUs = new QPushButton(verticalLayoutWidget);
        aboutUs->setObjectName(QStringLiteral("aboutUs"));

        verticalLayout->addWidget(aboutUs);

        help = new QPushButton(verticalLayoutWidget);
        help->setObjectName(QStringLiteral("help"));

        verticalLayout->addWidget(help);


        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(2, 393, 311, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mixPiecesButton = new QPushButton(layoutWidget);
        mixPiecesButton->setObjectName(QStringLiteral("mixPiecesButton"));
        mixPiecesButton->setEnabled(true);

        horizontalLayout->addWidget(mixPiecesButton);

        closeBurron = new QPushButton(layoutWidget);
        closeBurron->setObjectName(QStringLiteral("closeBurron"));

        horizontalLayout->addWidget(closeBurron);

        gameName = new QTextEdit(Dialog);
        gameName->setObjectName(QStringLiteral("gameName"));
        gameName->setGeometry(QRect(0, 10, 420, 450));
        gameName->setMaximumSize(QSize(500, 500));
        QFont font1;
        font1.setFamily(QStringLiteral("Old English Text MT"));
        font1.setPointSize(25);
        font1.setBold(false);
        font1.setWeight(50);
        gameName->setFont(font1);
        gameName->setStyleSheet(QStringLiteral("background-image: url(:/back.png);"));
        gameName->setLineWidth(0);
        gameName->setTabChangesFocus(false);
        gameName->setDocumentTitle(QStringLiteral(""));
        gameName->setLineWrapMode(QTextEdit::NoWrap);
        gameName->setAcceptRichText(false);
        gameName->setTextInteractionFlags(Qt::NoTextInteraction);
        textLabel = new QLabel(Dialog);
        textLabel->setObjectName(QStringLiteral("textLabel"));
        textLabel->setGeometry(QRect(10, 0, 381, 351));
        image = new QLabel();
        groupBox = new QGroupBox(Dialog);
        picLabel = new QLabel(Dialog);
        back = new QPushButton(Dialog);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(199, 359, 191, 31));
        DigitalClock = new QLabel(Dialog);
        DigitalClock->setObjectName(QStringLiteral("DigitalClock"));
        DigitalClock->setGeometry(QRect(284, 0, 101, 41));
        backToMenu = new QPushButton(Dialog);
        backToMenu->setObjectName(QStringLiteral("backToMenu"));
        backToMenu->setGeometry(QRect(319, 390, 71, 41));
        nextLevel = new QPushButton(Dialog);
        nextLevel->setObjectName(QStringLiteral("NEXT LEVEL"));
        nextLevel->setGeometry(QRect(150, 350, 71, 41));
        QWidget::setTabOrder(mixPiecesButton, closeBurron);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "15 Puzzle", nullptr));
        Dialog->setWindowIcon(QIcon("C:/Users/ahovakim/Documents/lessons/15puzzle-master/pictures/icon.png"));
        newGame->setText(QApplication::translate("Dialog", "New Game", nullptr));
        continueGame->setText(QApplication::translate("Dialog", "Continue", nullptr));
        bestScores->setText(QApplication::translate("Dialog", "Best Scores", nullptr));
        setLevel->setText(QApplication::translate("Dialog", "Level", nullptr));
        aboutUs->setText(QApplication::translate("Dialog", "About us", nullptr));
        help->setText(QApplication::translate("Dialog", "Help", nullptr));
        mixPiecesButton->setText(QApplication::translate("Dialog", "Mix Pieces", nullptr));
        closeBurron->setText(QApplication::translate("Dialog", "Close", nullptr));
        gameName->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Old English Text MT'; font-size:25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:100px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:26pt; font-weight:600; color:#2c2c6c;\">  </span></p>\n"
"<p style=\" margin-top:80px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:26pt; font-weight:600; color:#2c2c6c;\">           </span><span style=\" font-size:26pt; font-weight:600; color:#1a1a41;\">15</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:26pt; font-weight"
                        ":600; color:#1a1a41;\">       p u z z l e</span></p></body></html>", nullptr));
        /*textLabel->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
*/
back->setText(QApplication::translate("Dialog", "Back", nullptr));
DigitalClock->setText(QString());
backToMenu->setText(QApplication::translate("Dialog", "<-", nullptr));
nextLevel->setText(QApplication::translate("Dialog", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
