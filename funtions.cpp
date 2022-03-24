#include "funtions.h"

QList<solidBlock *> createMap(QList<solidBlock*> solidBlocks)
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

    for(int x=-780;x<920;x+=120){
        for(int y=-240;y<420;y+=120){
            solidBlocks.push_back(new solidBlock(60,60,":/Sprites/solidBlock.png"));
            solidBlocks.back()->setPos(x,y);
        }
    }

    return solidBlocks;
}
