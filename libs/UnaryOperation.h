#ifndef UNARY_OPERATION_H
#define UNARY_OPERATION_H

#include "IOperation.h"

typedef struct UnaryOperation {
  void (*Execute)(IOperation *, Stack *);
  double (*Operation)(double);
  OperationCode Code;
} UOperation;

IOperation *CreateUnaryOperation(double (*op)(double), OperationCode code);

#endif
