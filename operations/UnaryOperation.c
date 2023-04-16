#include "../libs/UnaryOperation.h"

static void Execute(IOperation *io_this, Stack *stack) {
  double arg, res;
  stack->Pop(stack, &arg);
  UOperation *uo_this = (UOperation *)io_this;
  res = uo_this->Operation(arg);
  stack->Push(stack, &res);
}

IOperation *CreateUnaryOperation(double (*op)(double), OperationCode code) {

  UOperation *res = malloc(sizeof(UOperation));
  res->Code = code;
  res->Execute = Execute;
  res->Operation = op;

  return (IOperation *)res;
}