#ifndef Operations_h
#define Operations_h

#include "BinaryOperation.h"
#include "IOperation.h"
#include "NumberOperation.h"
#include "UnaryOperation.h"

#define Create(T, ...)                                                         \
  _Generic((T), double (*)(double, double)                                     \
           : CreateBinaryOperation, double (*)(double)                         \
           : CreateUnaryOperation, double                                      \
           : CreateNumberOperation)((T), (__VA_ARGS__))
#endif /* Operations_h */