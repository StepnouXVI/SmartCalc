#ifndef STACK_SRC_H
#define STACK_SRC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libs/Stack.h"

#define Stack(T) Stack_##T
#define Node(T) S_Node_##T

#define Inc_Node(T)        \
  typedef struct Node(T) { \
    T Data;                \
    struct Node(T) * Next; \
  }                        \
  Node(T);

bool S_isEmpty(const Stack *stack);

#define Push(T)                                             \
  void S_Push_##T(Stack *stack, const T *data) {            \
    Stack(T) *_stack = (Stack(T) *)stack;                   \
                                                            \
    Node(T) *new_node = (Node(T) *)malloc(sizeof(Node(T))); \
    new_node->Data = *data;                                 \
    new_node->Next = _stack->Top;                           \
                                                            \
    _stack->Top = new_node;                                 \
    _stack->Size++;                                         \
  }

#define Pop(T)                                   \
  void S_Pop_##T(struct Stack *stack, T *data) { \
    Stack(T) *_stack = (Stack(T) *)stack;        \
    *data = _stack->Top->Data;                   \
                                                 \
    Node(T) *node = _stack->Top->Next;           \
    free(_stack->Top);                           \
    _stack->Top = node;                          \
    _stack->Size--;                              \
  }

#define Peek(T)                                       \
  void S_Peek_##T(struct Stack *stack, T *data) {     \
    Stack(T) *_stack = (Stack(T) *)stack;             \
    if (_stack->Size != 0) *data = _stack->Top->Data; \
  }

#define Destruct(T)                          \
  void S_Destruct_##T(struct Stack *stack) { \
    Stack(T) *_stack = (Stack(T) *)stack;    \
    while (_stack->Top != NULL) {            \
      Node(T) *node = _stack->Top->Next;     \
      free(_stack->Top);                     \
      _stack->Top = node;                    \
    }                                        \
  }

#define Init(T)                                                      \
  Stack InitStack_##T() {                                            \
    Stack(T) stack;                                                  \
    stack.Push = (void (*)(struct Stack *, const void *))S_Push_##T; \
    stack.Destruct = (void (*)(struct Stack *))S_Destruct_##T;       \
    stack.Peek = (void (*)(const struct Stack *, void *))S_Peek_##T; \
    stack.Pop = (void (*)(struct Stack *, void *))S_Pop_##T;         \
    stack.IsEmpty = S_isEmpty;                                       \
    stack.Size = 0;                                                  \
    stack.Top = NULL;                                                \
                                                                     \
    Stack res = *((Stack *)&stack);                                  \
    return res;                                                      \
  }

#define Include_Stack_For_Type(T)               \
  Inc_Node(T);                                  \
  typedef struct Stack(T) {                     \
    void (*Push)(struct Stack *, const void *); \
    void (*Destruct)(struct Stack *);           \
    void (*Peek)(const struct Stack *, void *); \
    void (*Pop)(struct Stack *, void *);        \
    bool (*IsEmpty)(const struct Stack *);      \
    size_t Size;                                \
    Node(T) * Top;                              \
  }                                             \
  Stack(T);                                     \
                                                \
  Pop(T);                                       \
  Peek(T);                                      \
  Push(T);                                      \
  Destruct(T);                                  \
  Init(T);

#endif