#include "IOperation.h"

#ifndef BINARY_OPERATION_H
#define BINARY_OPERATION_H

#include "IOperation.h"

typedef struct BinaryOperation {
  void (*Execute)(IOperation *, Stack *);
  double (*Operation)(double, double);
  OperationCode Code;
} BOperation;

IOperation *CreateBinaryOperation(double (*op)(double, double),
                                  OperationCode code);
#endif