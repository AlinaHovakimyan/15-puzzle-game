#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <QTimer>
#include <QSound>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QInputDialog>
#include <QPixmap>
#include <fstream>
#include <cstdlib>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    m_state = dontShowHelp;
    m_level = 0;
    m_prevLevel = 0;
    windowType = other;

    createLevelButtons();
    initLabels();
    QTimer::singleShot(3000, this, SLOT(showMenu()));
    setOne(true);

    setInitStyles();
    setInitGeometries();
    setInitVisibilites();
    createConnections();
 }

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::createConnections()
{
    connect(ui->setLevel, SIGNAL(clicked()), this, SLOT(on_setLevel_clicked()));
    connect(ui->nextLevel, SIGNAL(clicked()), this, SLOT(on_newGame_clicked()));
}

void Dialog::startGame()
{
    field.initNew();
}

void Dialog::recalculateField()
{
    std::vector<int> nums = field.getField();
    for (int i = 0; i < field.SIZE; ++i)
    {
        labels[i]->setText(QString::number(nums[i]));
        labels[i]->setStyleSheet("QLabel { background-color: sienna; }");
        if (nums[i] == -1)
        {
            labels[i]->setStyleSheet("QLabel { background-color: white; }");
            labels[i]->setText("");
            m_emptyLabelIndex = i;
            field.setEmptyLabel(i);
        }
    }
}

void Dialog::createLabels() {
    std::vector<int> nums = field.getField();
    int row = 0, col = 0;
    for (int i = 0; i < field.SIZE; ++i) {
          labels[i]->setText(QString::number(nums[i]));
          if (nums[i] == -1)
          {
              labels[i]->setStyleSheet("QLabel { background-color: white; }");
              labels[i]->setText("");
              m_emptyLabelIndex = i;
              field.setEmptyLabel(i);
          }
          row = i / 4;
          col = i % 4;
          ui->grid->addWidget(labels[i], row, col);
     }
}

void Dialog::initLabels()
{
    QFont font;
    font.setBold(true);
    font.setPixelSize(20);
    for (int i = 0; i < field.SIZE; ++i)
    {
        labels[i] = new QLabel("+");
        labels[i]->setFont(font);
        labels[i]->setStyleSheet("QLabel { background-color: sienna; }");
        labels[i]->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
        QGraphicsDropShadowEffect * shadow = new QGraphicsDropShadowEffect();
        shadow->setBlurRadius(3);

        labels[i]->setGraphicsEffect(shadow);
    }
}

int Dialog::getIndex(int x, int y) const
{
    return x / 100 + y / 100 * 4;
}

void Dialog::showMenu()
{
    ui->gameName->setVisible(false);
    ui->menu->setVisible(true);
}

void Dialog::showTime()
{
    if (playingTime.sec == 60) {
        ++playingTime.min;
        playingTime.sec = 0;
    }
    if (playingTime.min == 60) {
        ++playingTime.hour;
        playingTime.min = 0;
    }
    QString time_text = QString("%1:%2:%3").arg(QString::number(playingTime.hour), 2, QChar('0'))
                                           .arg(QString::number(playingTime.min), 2, QChar('0'))
                                           .arg(QString::number(playingTime.sec), 2, QChar('0'));
    ui->DigitalClock->setText(time_text);
    ++playingTime.sec;
}

void Dialog::startTimer()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
}

void Dialog::cultivateScore()
{
    Time playTime;
    playTime.hour = playingTime.hour;
    playTime.min = playingTime.min;
    playTime.sec = playingTime.sec;
    QString filename = m_filePath + "scores.txt";
    QFile file(filename);
    if(!file.exists()){
            qDebug() << "file "<<filename << " doesn't exist";
    }else{
            qDebug() << filename<<" readed...";
    }
    int count = 0;
    QString best_score;
    Time best;
    int size = 0;
    std::vector<QString> lines;

    if (file.open(QIODevice::ReadWrite)){
        QTextStream stream(&file);
        stream >> count;
        if (!stream.atEnd()) {
            std::vector<QString> newScores;
            bool ok;
            int i = 0;
            QString bestTime;
            while (!stream.atEnd()){
                   QString line;
                   QString lineForVector;
                   stream >> line;
                   if (i == 0) {
                       bestTime = line;
                       i = 1;
                   }
                   lineForVector = line;
                   stream >> line;
                   lineForVector += ' ' + line + '\n';
                   lines.push_back(lineForVector);
                   size += lineForVector.size();
            }
            QStringList timeList = bestTime.split(':');
            best.hour = timeList[0].toInt();
            best.min = timeList[1].toInt();
            best.sec = timeList[2].toInt();
            QString bestLine = (QString::number(playTime.hour) + ':' + QString::number(playTime.min) + ':' + QString::number(playTime.sec));
            if (playTime.hour < best.hour ||
                    (playTime.hour == best.hour && playTime.min < best.min) ||
                     (playTime.hour == best.hour && playTime.min == playTime.min && playTime.sec < best.sec)) {
                QString playerName = QInputDialog::getText(this, tr("WINNER"),
                                                         tr("Name:"), QLineEdit::Normal,
                                                         QDir::home().dirName(), &ok);
                if (ok && !playerName.isEmpty()) {
                   bestLine += (' ' + playerName);
                   bestLine += '\n';
                   if (count < 5) {
                        lines.insert(lines.begin(),bestLine);
                        ++count;
                    } else {
                        for(int i = lines.size() - 1; i > 0 ;--i) {
                            lines[i] = lines[i-1];
                        }
                        lines[0] = bestLine;
                    }
                }
            }
       }
    }
    file.close();
    // write to scores file
    if ( file.open( QIODevice::ReadWrite | QIODevice::Truncate)) {
        QTextStream stream(&file);
        stream << count << endl;
        for (int i = 0; i < lines.size() - 1; ++i) {
            stream << lines[i];
        }
    }
    file.close();
}

QImage createSubImage(QImage* image, const QRect & rect)
{
        size_t offset = rect.x() * image->depth() / 8
                        + rect.y() * image->bytesPerLine();
        return QImage(image->bits() + offset, rect.width(), rect.height(),
                      image->bytesPerLine(), image->format());
}

void Dialog::createLabelsWithImage()
{
    QImage* pic = new QImage(m_img);
    std::vector<int> nums = field.getField();
    int row = 0, col = 0;
    int xl = 0;
    int yl = 0;
    const int length = 100;
    const int height = 100;
    for (int i = 0; i < field.SIZE; ++i) {
        if (nums[i] == -1)
        {
            labels[i]->setStyleSheet("QLabel { background-color: white; }");
            labels[i]->setText("");
            m_emptyLabelIndex = i;
            field.setEmptyLabel(i);
        } else {
              yl = ((nums[i] - 1) / 4) * height;
              xl = ((nums[i] % 4) - 1) * length;
              QImage imjPiece = createSubImage(pic, QRect(xl, yl, length, height));
              labels[i]->setPixmap(QPixmap::fromImage(imjPiece));
         }
          row = i / 4;
          col = i % 4;
          ui->grid->addWidget(labels[i], row, col);
     }
}

void Dialog::recalculateImgField()
{
    QImage* pic = new QImage(m_img);
    std::vector<int> nums = field.getField();
    int row = 0, col = 0;
    int xl = 0;
    int yl = 0;
    const int length = 100;
    const int height = 100;
    for (int i = 0; i < field.SIZE; ++i) {
        if (nums[i] == -1)
        {
            labels[i]->clear();
            labels[i]->setStyleSheet("QLabel { background-color: white; }");
            labels[i]->setText("");
            m_emptyLabelIndex = i;
            field.setEmptyLabel(i);
        } else {
              yl = ((nums[i] - 1) / 4) * height;
              xl = ((nums[i] % 4) - 1) * length;
              QImage imjPiece = createSubImage(pic, QRect(xl, yl, length, height));
              labels[i]->setPixmap(QPixmap::fromImage(imjPiece));
         }
          row = i / 4;
          col = i % 4;
     }
}

void Dialog::handleWin()
{
    setWinVisibilities();
    //stopTimer();
     m_state = win;
     if (m_level < 4) {
         ++m_level;
     }
     QMovie *fire = new QMovie("C:/Users/ahovakim/Documents/lessons/15puzzle-master/pictures/win.gif");
     m_gif = fire;
     // set textlabels chackboxs visible false;

      ui->textLabel->setMovie(fire);
      //QMediaPlaylist *playlist = new QMediaPlaylist();
      //playlist->addMedia(QUrl("C:/Users/ahovakim/Documents/lessons/15puzzle-master/sounds/salut.wav"));
      //playlist->setPlaybackMode(QMediaPlaylist::Loop);

      //QMediaPlayer *music = new QMediaPlayer();
     // m_music = music;
     // music->setPlaylist(playlist);
     // music->play();
      fire->start();
      ui->continueGame->setEnabled(false);
      cultivateScore();
      return;
}

// wark with files
const char* Dialog::getFileName() {
    switch(m_level) {
    case 1:
        break;
    case 2:
        return "C:/Users/ahovakim/Documents/lessons/15puzzle-master/files/2LevelImgPaths.txt";
        break;
    case 3:
        return "C:/Users/ahovakim/Documents/lessons/15puzzle-master/files/3LevelImgPaths.txt";
        break;
    case 4:
        return "C:/Users/ahovakim/Documents/lessons/15puzzle-master/files/4LevelImgPaths.txt";
        break;
    }
}

void Dialog::readFile(const QString& name, bool readFirstLine)
{
    QString filename = m_filePath + name;
    QFile file(filename);
    if(!file.exists()){
        qDebug() << "file "<<filename << " doesn't exist";
    }else{
        qDebug() << filename<<" readed...";
        QString line;
        ui->textLabel->clear();
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream stream(&file);
            if (!readFirstLine) {
                QString ignore = "";
                ignore = stream.readLine();
            }
            while (!stream.atEnd()){
               line = stream.readLine();
               ui->textLabel->setText(ui->textLabel->text()+line+"\n");
            }
        }
    }
}

void Dialog::readPrevGameState(std::vector<int>& numbers)
{
    // init labels with gameState.txt file
    QString filename = m_filePath + "gameState.txt";
    QFile file(filename);
    if(!file.exists()){
            qDebug() << "file "<<filename << " doesn't exist";
    }else{
            qDebug() << filename<<" readed...";
    }
    int number = 0;
    int i = 0;
    numbers.resize(field.SIZE + 1);
    if (file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        stream >> playingTime.hour >> playingTime.min >> playingTime.sec;
        while (!stream.atEnd()){
               stream >> number;
               numbers[i++] = number;
         }
     }
}

void Dialog::readPrevGameStateInf()
{
    QString filename = m_filePath + "gameStateInf.txt";
    QFile file2(filename);
    if(!file2.exists()){
            qDebug() << "file "<<filename << " doesn't exist";
    }else{
            qDebug() << filename<<" readed...";
    }
    if (file2.open(QIODevice::ReadOnly)){
        QTextStream stream(&file2);
        stream >> m_level;
        stream >> m_img;
    }
}

void Dialog::writeGameState()
{
    QFile file(m_filePath + "gameState.txt");
    if (file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        stream << playingTime.hour << " " << playingTime.min << " " << playingTime.sec << " ";
        std::vector<int> nums = field.getField();
        std::vector<int>::iterator it = nums.begin();
        for(; it != nums.end(); ++it) {
         stream << *it << " ";
        }
     }
}

void Dialog::writeGameStateInf()
{
    QFile file2(m_filePath + "gameStateInf.txt");
    if (file2.open(QIODevice::WriteOnly)){
        QTextStream stream(&file2);
        stream << m_level<< " " << m_img;
    }
}

void Dialog::readNthLine(std::istream& in, int n) {
    std::cout << "n:" << n << std::endl;
    std::string ignore = "";
  for (int i = 0; i <= n; ++i) {
      getline(in, ignore);
  }
  in >> ignore;
  m_img = QString::fromStdString(ignore);
}

bool Pair::operator<(const Pair& anotherPair) const
{
    return ((m_x + m_y) < (anotherPair.m_x + anotherPair.m_y));
}

const QString Dialog::m_filePath = "C:/Users/ahovakim/Documents/lessons/15puzzle-master/files/";
