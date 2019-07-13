#include "dialog.h"
#include "ui_dialog.h"

void Dialog::setInitStyles()
{
    // set Background color of dialog window
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, QColor::fromRgb(248, 235, 226));
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    ui->menu->setStyleSheet(QStringLiteral("background-image: url(:/back.png);"));
    ui->closeBurron->setStyleSheet("background-color: rgb(248, 235, 226)");
    ui->mixPiecesButton->setStyleSheet("background-color: rgb(248, 235, 226)");
    ui->backToMenu->setStyleSheet("background-color: rgb(248, 235, 226)");
    ui->nextLevel->setStyleSheet("background-color: rgb(248, 235, 226)");
    ui->back->setStyleSheet("background-color: rgb(248, 235, 226)");
    ui->DigitalClock->setStyleSheet("font-weight: bold");
    ui->groupBox->setStyleSheet("QRadioButton {"
                                "font-size : 20px"
                                "}");
}

void Dialog::setInitVisibilites()
{
    ui->gameName->setVisible(true);
    ui->menu->setVisible(false);
    ui->nextLevel->setVisible(false);
    ui->gridLayoutWidget->setVisible(false);
    ui->DigitalClock->setVisible(false);
    ui->backToMenu->setVisible(false);
    ui->mixPiecesButton->setVisible(false);
    ui->closeBurron->setVisible(false);
    ui->textLabel->setVisible(false);
    ui->back->setVisible(false);
    ui->picLabel->setVisible(false);
    ui->groupBox->setVisible(false);
}

void Dialog::setInitGeometries()
{
    ui->gridLayoutWidget->setGeometry(0, 15, 400, 380);
    ui->DigitalClock->setGeometry(300, 0, 300, 15);
    ui->picLabel->setGeometry(200, 40, 180, 200);
    ui->groupBox->setGeometry(0, 40, 180, 200);
}

void Dialog::createLevelButtons()
{

    QRadioButton *level1 = new QRadioButton(tr("First Level"));
    QRadioButton *level2 = new QRadioButton(tr("Second Level"));
    QRadioButton *level3 = new QRadioButton(tr("Third Level"));
    QRadioButton *level4 = new QRadioButton(tr("Fourth Level"));
    level1->setChecked(true);
    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->addWidget(level1);
    vbox->addWidget(level2);
    vbox->addWidget(level3);
    vbox->addWidget(level4);
    ui->groupBox->setLayout(vbox);
    connect(level1, SIGNAL(toggled(bool)),
                   this, SLOT(setOne(bool)));

    connect(level2, SIGNAL(toggled(bool)),
                   this, SLOT(setTwo(bool)));

    connect(level3, SIGNAL(toggled(bool)),
                   this, SLOT(setThree(bool)));

    connect(level4, SIGNAL(toggled(bool)),
                   this, SLOT(setFour(bool)));
}

void Dialog::setWinVisibilities()
{
    ui->textLabel->setVisible(true);
    //ui->textLabel->blockSignals(true);
    ui->gridLayoutWidget->setVisible(false);
    ui->mixPiecesButton->setVisible(false);
    ui->DigitalClock->setVisible(false);
    if (m_level < 4) {
        ui->nextLevel->setVisible(true);
    }
}

void Dialog::setBackToMenuVisibilities()
{
    ui->menu->setVisible(true);
    ui->textLabel->setVisible(false);
    ui->backToMenu->setVisible(false);
    ui->nextLevel->setVisible(false);
    ui->mixPiecesButton->setVisible(false);
    ui->closeBurron->setVisible(false);
    ui->DigitalClock->setVisible(false);
    ui->gridLayoutWidget->setVisible(false);
}
void Dialog::setNewGameVisibilities()
{
    ui->nextLevel->setVisible(false);
    ui->menu->setVisible(false);
    ui->textLabel->setVisible(false);
    ui->continueGame->setEnabled(true);
    ui->gridLayoutWidget->setVisible(true);
    ui->backToMenu->setVisible(true);
    ui->mixPiecesButton->setVisible(true);
    ui->closeBurron->setVisible(true);
    ui->DigitalClock->setVisible(true);
}

void Dialog::setContinueGameVisibilities()
{
    ui->menu->setVisible(false);
    ui->backToMenu->setVisible(true);
    ui->gridLayoutWidget->setVisible(true);
    ui->DigitalClock->setVisible(true);
    ui->mixPiecesButton->setVisible(true);
    ui->closeBurron->setVisible(true);
}
