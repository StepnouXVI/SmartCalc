#include "../libs/BinaryOperation.h"

static void b_Execute(IOperation *io_this, Stack *stack) {
  double arg_1, arg_2, res;
  stack->Pop(stack, &arg_1);
  stack->Pop(stack, &arg_2);

  BOperation *bo_this = (BOperation *)io_this;
  res = bo_this->Operation(arg_1, arg_2);
  stack->Push(stack, &res);
}

IOperation *CreateBinaryOperation(double (*op)(double, double),
                                  OperationCode code) {

  BOperation *res = malloc(sizeof(BOperation));
  res->Code = code;
  res->Execute = b_Execute;
  res->Operation = op;

  return (IOperation *)res;
}
