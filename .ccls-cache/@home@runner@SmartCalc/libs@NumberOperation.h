#include "IOperation.h"

typedef struct NumberOperation {
  void (*Execute)(IOperation *, Stack *);
  void *Moke;
  OperationCode Code;
  double Number;
} NOperation;

IOperation *CreateNumberOperation(double number, OperationCode code);