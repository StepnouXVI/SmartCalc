#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>

#include "Bool.h"

typedef struct Queue {
  void (*Push)(struct Queue *, const void *);
  void (*Destruct)(struct Queue *);
  void (*Peek)(const struct Queue *, void *);
  void (*Pop)(struct Queue *, void *);
  bool (*IsEmpty)(const struct Queue *);
  size_t Size;
  void *First;
  void *Last;
} Queue;

#define InitQueue(T) InitQueue_##T();

#endif