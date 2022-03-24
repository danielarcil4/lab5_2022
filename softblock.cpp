#include "softblock.h"

softBlock::softBlock(int height, int width, QString sprite)
{
    setHeight(height);
    setWidth(width);
    pixmap = new QPixmap(sprite);
    setPixmap(pixmap->copy(getCol(),getRow(),getWidth(),getHeight()));
}

softBlock::~softBlock()
{
    delete pixmap;
}



