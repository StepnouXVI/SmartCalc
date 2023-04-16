#include "../libs/NumberOperation.h"

static void Execute(IOperation *io_this, Stack *stack) {
  NOperation *no_this = (NOperation *)io_this;
  stack->Push(stack, &no_this->Number);
}

IOperation *CreateNumberOperation(double number, OperationCode code) {
  NOperation *res = malloc(sizeof(NOperation));
  res->Code = code;
  res->Execute = Execute;
  res->Moke = NULL;
  res->Number = number;

  return (IOperation *)res;
}