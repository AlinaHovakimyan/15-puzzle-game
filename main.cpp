#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication gameApplication(argc, argv);
    Dialog dialogWindow;
    dialogWindow.setStyleSheet("{background-image: url(back.jpg);}");
    dialogWindow.show();
    return gameApplication.exec();
}
