/*#include "startmenu.h"
#include <iostream>

startMenu::startMenu(QWidget *parent)
           :QDialog(parent)
           ,ui(new Ui::startMenu)
{
   ui->setupUi(this);
   m_object = new QObject;
   m_label = new QLabel((QWidget*)m_object);
}

startMenu::~startMenu()
{
    delete ui;
}

void startMenu::start()
{
    //ui->m_label->setText("<font color=red>15 puzzlle!</font>");
    m_label->setText("<font color=red>15 puzzlle!</font>");
   // ((QWidget*)m_object)->show();
    //QTimer::singleShot(6000, this, SLOT(showMenu()));
}

void startMenu::updateScreen() {
    std::cout << "updateScreen" << std::endl;
}

void startMenu::showMenu() {
    m_label->setText("<font color=green>MENU</font>");
}
*/
