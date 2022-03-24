#ifndef SOLIDBLOCK_H
#define SOLIDBLOCK_H
#include "basicobject.h"

class solidBlock:public basicObject
{
public:
    solidBlock(int height,int width,QString sprite);
    ~solidBlock();
};

#endif // SOLIDBLOCK_H
