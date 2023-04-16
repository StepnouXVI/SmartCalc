#include "../libs/OperationsNames.h"
#include "../libs/Bool.h"



bool IsOperator(char symb)
{
    bool isOp = false;

    for(size_t i = 0; i < sizeof(BinaryNames)/sizeof(OpName) && !isOp; i++)
    {
        isOp = symb == BinaryNames[i].ShortName;
    }
    for(size_t i = 0; i < sizeof(UnaryNames)/sizeof(OpName) && !isOp; i++)
    {
        isOp = symb == UnaryNames[i].ShortName;
    }
    return isOp;
}

