#include "../libs/OperationImplement.h"
#include "../libs/Operations.h"

static void* operations_list[] = {
    [Add] = Op_Add,   [Sub] = Op_Sub,   [Mul] = Op_Mul,       [Div] = Op_Div,
    [Pow] = Op_Pow,   [Sqrt] = Op_Sqrt, [Cos] = Op_Cos,       [Sin] = Op_Sin,
    [Tan] = Op_Tan,   [Log] = Op_Log,   [Ln] = Op_Ln,         [Atan] = Op_Atan,
    [Acos] = Op_Acos, [Asin] = Op_Asin, [Negate] = Op_Negate, [Mod] = Op_Mod};

IOperation* CreateOperation(OperationCode code) {
  if (code >= Negate)
    return CreateUnaryOperation(operations_list[code], code);
  else
    return CreateBinaryOperation(operations_list[code], code);
}
