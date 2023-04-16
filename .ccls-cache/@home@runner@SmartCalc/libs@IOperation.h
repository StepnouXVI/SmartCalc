

#ifndef OPERATION_H
#define OPERATION_H

#include "OperationsCodes.h"
#include "Stack.h"

typedef struct IOperation {
  void (*Execute)(struct IOperation *, Stack *);
  void *Operation;
  OperationCode Code;
} IOperation;

#endif