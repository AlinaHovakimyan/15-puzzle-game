#include "dialog.h"
#include "ui_dialog.h"
#include <fstream>

void Dialog::on_mixPiecesButton_clicked()
{
    field.initNew();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    ui->DigitalClock->setText("00:00:00");
    playingTime = 0;
    startTimer();
    field.createSolvablePuzzle();
    if (m_level == 1) {
        recalculateField();
    } else {
        recalculateImgField();
    }
}

void Dialog::on_closeBurron_clicked()
{
    QString filename = m_filePath + "gameState.txt";
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        stream << playingTime.hour << " " << playingTime.min << " " << playingTime.sec << " ";
        std::vector<int> nums = field.getField();
        std::vector<int>::iterator it = nums.begin();
        for(; it != nums.end(); ++it) {
         stream << *it << " ";
        }
     }
    filename = m_filePath + "gameStateInf.txt";
    QFile file2(filename);
    if (file2.open(QIODevice::WriteOnly)){
        QTextStream stream(&file2);
        stream << m_level<< " " << m_img;
    }
    ui->image->close();
    window()->close();
}

void Dialog::on_newGame_clicked()
{
    if (m_state == win) {
        m_music->stop();
        m_gif->deleteLater();
    }
    srand ( time(NULL) );
    if (m_level == 1) {
        m_img = "C:/Users/ahovakim/Documents/lessons/15puzzle-master/pictures/first.jpg";
    } else {
        const char* filename = getFileName();
        std::ifstream stream;
        stream.open(filename);
        int range;
        stream >> range;
        int num = rand() % range;
        readNthLine(stream, num);
        stream.close();
    }
    m_state = showHelp;
    windowType = newGame;
    ui->DigitalClock->setText("00:00:00");
    playingTime = 0;
    setNewGameVisibilities();
    //disconnect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    startTimer();
    field.initNew();
    field.createSolvablePuzzle();
    recalculateField();
    if (m_level == 1) {
        createLabels();
    } else {
        createLabelsWithImage();
    }
}

void Dialog::on_continueGame_clicked()
{
    m_prevLevel = m_level;
    m_state = showHelp;
    windowType = continueGame;
    std::vector<int> numbers;
    setContinueGameVisibilities();
    readPrevGameState(numbers);
    field.initField(numbers);
    readPrevGameStateInf();
    if (m_level == 1) {
        createLabels();
    } else {
        createLabelsWithImage();
    }
    startTimer();
}

void Dialog::on_bestScores_clicked()
{
    ui->menu->setVisible(false);
    ui->textLabel->setVisible(true);
    ui->back->setVisible(true);
    readFile("scores.txt", false);
}

void Dialog::on_setLevel_clicked()
{
    ui->menu->setVisible(false);
    ui->back->setVisible(true);
    ui->picLabel->setVisible(true);
    ui->groupBox->setVisible(true);
}

void Dialog::on_help_clicked()
{
    ui->menu->setVisible(false);
    ui->textLabel->setVisible(true);
    ui->back->setVisible(true);

    ui->textLabel->setStyleSheet("font-size: 18px;");
    ui->back->setStyleSheet("background-color: rgb(248, 235, 226)");
    readFile("help.txt", true);
}

void Dialog::on_aboutUs_clicked()
{
    ui->menu->setVisible(false);
    ui->textLabel->setVisible(true);
    ui->back->setVisible(true);
    readFile("aboutUs.txt", true);
    ui->textLabel->setStyleSheet("font-size: 20px");
}

void Dialog::on_backToMenu_clicked()
{
    if (m_state == win) {
        m_music->stop();
    }
    m_state = dontShowHelp;
    ui->image->close();
    setBackToMenuVisibilities();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    writeGameState();
    writeGameStateInf();
    if (windowType == continueGame){
        m_level = m_prevLevel;
    }
    windowType = other;
}

void Dialog::on_back_clicked()
{
    ui->textLabel->clear();
    ui->textLabel->setVisible(false);
    ui->menu->setVisible(true);
    ui->back->setVisible(false);
    ui->picLabel->setVisible(false);
    ui->groupBox->setVisible(false);
}

void Dialog::setOne(bool on)
{
    if (on) {
        m_level = 1;
    }
    QImage img("C:/Users/ahovakim/Documents/lessons/15puzzle-master/pictures/first.jpg");
    QImage img2 = img.scaled(200, 200, Qt::KeepAspectRatio);
    ui->picLabel->setPixmap(QPixmap::fromImage(img2));
}

void Dialog::setTwo(bool on)
{
    if (on) {
        m_level = 2;
    }
    QImage img("C:/Users/ahovakim/Documents/lessons/15puzzle-master/pictures/2/bear.jpeg");
    QImage img2 = img.scaled(200, 200, Qt::KeepAspectRatio);

    ui->picLabel->setPixmap(QPixmap::fromImage(img2));
}

void Dialog::setThree(bool on)
{
    if (on) {
        m_level = 3;
    }
    QImage img("C:/Users/ahovakim/Documents/lessons/15puzzle-master/pictures/3/mona-liza.jpg");
    QImage img2 = img.scaled(200, 200, Qt::KeepAspectRatio);

    ui->picLabel->setPixmap(QPixmap::fromImage(img2));
}

void Dialog::setFour(bool on)
{
    if (on) {
        m_level = 4;
    }
    QImage img("C:/Users/ahovakim/Documents/lessons/15puzzle-master/pictures/4/flowers1.jpg");
    QImage img2 = img.scaled(200, 200, Qt::KeepAspectRatio);

    ui->picLabel->setPixmap(QPixmap::fromImage(img2));
}

// events
void Dialog::keyPressEvent(QKeyEvent *pe)
{
    switch (pe->key()) {
    case Qt::Key_A:  // key left
        field.swap(lft);
        break;
    case Qt::Key_D:  // key right
        field.swap(rght);
        break;
    case Qt::Key_W:  // key up
        field.swap(up);
        break;
    case Qt::Key_S:  // key down
        field.swap(down);
        break;
    default:
        break;
    }
    if(m_level == 1) {
        recalculateField();
    } else {
        recalculateImgField();
    }
    if (field.win())
    {
        handleWin();
    }
}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    if (windowType == newGame || windowType == continueGame) {
        int x = event->x();
        int y = event->y();
        int index = getIndex(x,y);
        if (index == m_emptyLabelIndex - 1){
            field.swap (lft);
        } else if (index == m_emptyLabelIndex + 1) {
            field.swap(rght);
        } else if (index == m_emptyLabelIndex - 4) {
            field.swap(up);
        } else if (index == m_emptyLabelIndex + 4) {
            field.swap(down);
        }

        if (m_level == 1) {
            recalculateField();
        } else {
            recalculateImgField();
        }
        if (field.win())
        {
            handleWin();
        }
    }
}

bool Dialog::event(QEvent *event)
{
    if(event->type() == QEvent::EnterWhatsThisMode) {
        if (m_state == showHelp) {
            ui->image->setPixmap(QPixmap(m_img));
            ui->image->show();
        }
    } else if (event->type() == QEvent::Close) {
            ui->image->close();
            window()->close();
    }
    return QWidget::event(event);
}
