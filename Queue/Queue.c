#include "Queue.h"

#include "../libs/IOperation.h"

bool isEmpty(const Queue *queue) { return queue->Size == 0; }

Include_Queue_For_Type(int);
Include_Queue_For_Type(float);
Include_Queue_For_Type(double);
Include_Queue_For_Type(char);
typedef struct Node_IOperation {
  IOperation Data;
  struct Node_IOperation *Next;
} Node_IOperation;
;
typedef struct Queue_IOperation {
  void (*Push)(struct Queue *, const void *);
  void (*Destruct)(struct Queue *);
  void (*Peek)(const struct Queue *, void *);
  void (*Pop)(struct Queue *, void *);
  bool (*IsEmpty)(const struct Queue *);
  size_t Size;
  Node_IOperation *First;
  Node_IOperation *Last;
} Queue_IOperation;

void Pop_IOperation(struct Queue *queue, IOperation *data) {
  Queue_IOperation *_queue = (Queue_IOperation *)queue;
  *data = _queue->First->Next->Data;
  Node_IOperation *node = _queue->First->Next->Next;
  free(_queue->First->Next);
  _queue->First->Next = node;
  _queue->Size--;
};
void Peek_IOperation(struct Queue *queue, IOperation *data) {
  Queue_IOperation *_queue = (Queue_IOperation *)queue;
  if (_queue->Size != 0) *data = _queue->First->Next->Data;
};
void Push_IOperation(Queue *queue, const IOperation *data) {
  Queue_IOperation *_queue = (Queue_IOperation *)queue;
  Node_IOperation *new_node =
      (Node_IOperation *)malloc(sizeof(Node_IOperation));
  new_node->Data = *data;
  new_node->Next = ((void *)0);
  _queue->Last->Next = new_node;
  _queue->Last = _queue->Last->Next;
  _queue->Size++;
};
void Destruct_IOperation(struct Queue *queue) {
  Queue_IOperation *_queue = (Queue_IOperation *)queue;
  while (_queue->First != ((void *)0)) {
    Node_IOperation *node = _queue->First->Next;
    free(_queue->First);
    _queue->First = node;
  }
};
Queue InitQueue_IOperation() {
  Queue_IOperation queue;
  queue.Push = (void (*)(struct Queue *, const void *))Push_IOperation;
  queue.Destruct = (void (*)(struct Queue *))Destruct_IOperation;
  queue.Peek = (void (*)(const struct Queue *, void *))Peek_IOperation;
  queue.Pop = (void (*)(struct Queue *, void *))Pop_IOperation;
  queue.IsEmpty = isEmpty;
  queue.Size = 0;
  queue.First = (Node_IOperation *)malloc(sizeof(Node_IOperation));
  queue.First->Next = ((void *)0);
  queue.Last = queue.First;
  Queue res = *((Queue *)&queue);
  return res;
};
;

// The lexeme
