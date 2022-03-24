#include "solidblock.h"

solidBlock::solidBlock(int height, int width, QString sprite)
{
    setHeight(height);
    setWidth(width);
    pixmap = new QPixmap(sprite);
    setPixmap(pixmap->copy(getCol(),getRow(),getWidth(),getHeight()));
}

solidBlock::~solidBlock()
{
    delete pixmap;
}
