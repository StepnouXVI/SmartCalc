#ifndef STACK_LIB_H
#define STACK_LIB_H
#include <stdlib.h>

#include "Bool.h"

typedef struct Stack {
  void (*Push)(struct Stack *, const void *);
  void (*Destruct)(struct Stack *);
  void (*Peek)(const struct Stack *, void *);
  void (*Pop)(struct Stack *, void *);
  bool (*IsEmpty)(const struct Stack *);
  size_t Size;
  void *Top;
} Stack;

#define InitStack(T) InitStack_##T();
#define include_stack(T) Stack InitStack_##T();
#endif