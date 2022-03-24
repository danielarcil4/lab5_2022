#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);

    musicInGame = new QMediaPlayer;
    musicInGame->setMedia(QUrl("qrc:/Sprites/MusicInGame.mp3"));
    musicInGame->play();

    bombExplosion = new QMediaPlayer;
    bombExplosion->setMedia(QUrl("qrc:/Sprites/Bomb.mp3"));

    player1 = new player(60,60,":/Sprites/walk.png");
    player1->setPos(-840,-120);
    scene->addItem(player1);

   /* live = new lives();
    live->setPos(100,-640);
    scene->addItem(live);
*/
    //door1 = new door(60,60,":/Sprites/door.png");
    //door1->setPlayerWin(player1);
    createMap();
    createEnemies();
    //int randomPos = door1->addRamdomPos(softBlocks);
    //scene->removeItem(softBlocks[randomPos]);
    //scene->addItem(door1);
    //scene->addItem(softBlocks[randomPos]);

    timeGame = new ownClock;
    timeGame->setPos(100,-440);
    scene->addItem(timeGame);

    points = new score;
    points->setPos(-800,-440);
    scene->addItem(points);

    connect(timerBomb,SIGNAL(timeout()),this,SLOT(timerBombs()));
    timerBomb->start(500);
}

MainWindow::~MainWindow()
{
    //delete enemy1;
    delete bombExplosion;
    delete musicInGame;
    delete timeGame;
    for(short int i=0;i<enemies.length();i++){
        enemies[i]->~enemy();
        delete enemies[i];
    }
    for(short int i=0;i<solidBlocks.length();i++){
        solidBlocks[i]->~solidBlock();
        delete solidBlocks[i];
    }
    for(short int i=0;i<softBlocks.length();i++){
        softBlocks[i]->~softBlock();
        delete softBlocks[i];
    }
    player1->~player();
    delete player1;
    delete scene;
    delete ui; 
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    player1->walk(event->key());
    player1->colliding(solidBlocks,softBlocks,event->key());

    //put bombs
    if(event->key()==Qt::Key_Space){
        bombs = player1->putBomb(bombs);
        if(bombs.length()<=3)scene->addItem(bombs.back());
    }
}

void MainWindow::timerBombs()
{
    int numberPoints=0;
    setSec(getSec()+1);
    if(!bombs.empty() and bombs[0]->getSec()>=5){
        //create explosion
        exploits = bombs[0]->exploit(exploits);
        //delete bombs
        //scene->removeItem(bombs.front());
        bombExplosion->play();
        for(short int I=0;I<solidBlocks.length();I++)
            scene->removeItem(solidBlocks[I]);

        for(short int i = exploits.length()-5;i<exploits.length();i++)
            scene->addItem(exploits[i]);

        for(short int I=0;I<solidBlocks.length();I++)
            scene->addItem(solidBlocks[I]);

        numberPoints= softBlocks.length()+enemies.length();
        for(short int i=0;i<exploits.length();i++){
            softBlocks = exploits[i]->doDamage(softBlocks);
            enemies = exploits[i]->doDamage(enemies);
        }
        for (short int i=0;i<enemies.length();i++)
            enemies[i]->setCollisionsSFB(softBlocks);


        points->setPoints(points->getPoints()+(numberPoints-softBlocks.length()-enemies.length()));
        points->updateScore();
    }
    if(!bombs.empty() and bombs.front()->getSec()>=8){
        //bombs.front()->~bomb();
        delete bombs.front();
        bombs.pop_front();
        for(short int i=0;i<exploits.length();i++){
            //exploits[i]->~explotation();
            delete exploits[i];
        }
        exploits.clear();
        setSec(0);
    }

}

void MainWindow::createMap()
{
    for(int x=-900;x<980;x+=60){
        //top blocks
        solidBlocks.push_back(new solidBlock(60,60,":/Sprites/solidBlock.png"));
        solidBlocks.back()->setPos(x,-360);

        //under blocks
        solidBlocks.push_back(new solidBlock(60,60,":/Sprites/solidBlock.png"));
        solidBlocks.back()->setPos(x,420);
    }

    for(int y=-300;y<420;y+=60){
        //left blocks
        solidBlocks.push_back(new solidBlock(60,60,":/Sprites/solidBlock.png"));
        solidBlocks.back()->setPos(-900,y);

        //right blocks
        solidBlocks.push_back(new solidBlock(60,60,":/Sprites/solidBlock.png"));
        solidBlocks.back()->setPos(960,y);
    }

    for(int x=-780;x<920;x+=120)
        for(int y=-240;y<420;y+=120){
            solidBlocks.push_back(new solidBlock(60,60,":/Sprites/solidBlock.png"));
            solidBlocks.back()->setPos(x,y);
        }

    int x=0,y=0;
    for(unsigned int i=0;i<70;i++){
        softBlocks.push_back(new softBlock(60,60,":/Sprites/softBlock.png"));
        x = rand()%28,y=rand()%11;
        softBlocks.back()->setPos(-780+60*x,-240+60*y);

        for(unsigned short int I=0;I<solidBlocks.length();I++)
            if(abs(softBlocks.back()->x()-solidBlocks[I]->x())<60 and abs(softBlocks.back()->y()-solidBlocks[I]->y())<60){
                delete softBlocks.back();
                softBlocks.pop_back();
                i--;
            }
        for(unsigned short int I=0;I<softBlocks.length()-1;I++)
            if((abs(softBlocks.back()->x()-softBlocks[I]->x())<60 and abs(softBlocks.back()->y()-softBlocks[I]->y())<60) or (abs(player1->x()-softBlocks[I]->x())<60 and abs(player1->y()-softBlocks[I]->y())<60)){
                delete softBlocks.back();
                softBlocks.pop_back();
                i--;
            }
    }
    for(short int i=0;i<solidBlocks.length();i++)
        scene->addItem(solidBlocks[i]);

    for(short int i=0;i<softBlocks.length();i++)
        scene->addItem(softBlocks[i]);

}



void MainWindow::createEnemies()
{
    int x=0,y=0;
    for(unsigned int i=0;i<10;i++){
        enemies.push_back(new enemy(60,60,":/Sprites/enemy1.png"));
        x = rand()%28,y=rand()%11;
        enemies.back()->setPos(-780+60*x,-240+60*y);
        enemies.back()->setCollisionsSFB(softBlocks);
        enemies.back()->setCollisionsSLB(solidBlocks);

        for(unsigned short int I=0;I<solidBlocks.length();I++)
            if(abs(enemies.back()->x()-solidBlocks[I]->x())<60 and abs(enemies.back()->y()-solidBlocks[I]->y())<60){
                delete enemies.back();
                enemies.pop_back();
                i--;
            }
        for(unsigned short int I=0;I<softBlocks.length();I++)
            if((abs(enemies.back()->x()-softBlocks[I]->x())<60 and abs(enemies.back()->y()-softBlocks[I]->y())<60)){
                delete enemies.back();
                enemies.pop_back();
                i--;
            }
        for(unsigned short int I=0;I<enemies.length()-1;I++)
            if((abs(enemies.back()->x()-enemies[I]->x())<60 and abs(enemies.back()->y()-enemies[I]->y())<60) or (abs(player1->x()-enemies[I]->x())<60 and abs(player1->y()-enemies[I]->y())<60)){
                delete enemies.back();
                enemies.pop_back();
                i--;
            }
    }

    for(short int i=0;i<enemies.length();i++){
        scene->addItem(enemies[i]);  
    }

}

int MainWindow::getSec() const
{
    return sec;
}

void MainWindow::setSec(int value)
{
    sec = value;
}


