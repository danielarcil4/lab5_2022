#ifndef SOFTBLOCK_H
#define SOFTBLOCK_H
#include "basicobject.h"

class softBlock:public basicObject
{
public:
    softBlock(int height,int width,QString sprite);
    ~softBlock();

};

#endif // SOFTBLOCK_H
