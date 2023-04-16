#include "../libs/Queue.h"

#define Queue(T) Queue_##T
#define Node(T) Node_##T

#define Inc_Node(T)        \
  typedef struct Node(T) { \
    T Data;                \
    struct Node(T) * Next; \
  }                        \
  Node(T);

bool isEmpty(const Queue *queue);

#define Push(T)                                             \
  void Push_##T(Queue *queue, const T *data) {              \
    Queue(T) *_queue = (Queue(T) *)queue;                   \
                                                            \
    Node(T) *new_node = (Node(T) *)malloc(sizeof(Node(T))); \
    new_node->Data = *data;                                 \
    new_node->Next = NULL;                                  \
                                                            \
    _queue->Last->Next = new_node;                          \
    _queue->Last = _queue->Last->Next;                      \
    _queue->Size++;                                         \
  }

#define Pop(T)                                 \
  void Pop_##T(struct Queue *queue, T *data) { \
    Queue(T) *_queue = (Queue(T) *)queue;      \
    *data = _queue->First->Next->Data;         \
                                               \
    Node(T) *node = _queue->First->Next->Next; \
    free(_queue->First->Next);                 \
    _queue->First->Next = node;                \
    _queue->Size--;                            \
  }

#define Peek(T)                                               \
  void Peek_##T(struct Queue *queue, T *data) {               \
    Queue(T) *_queue = (Queue(T) *)queue;                     \
    if (_queue->Size != 0) *data = _queue->First->Next->Data; \
  }

#define Destruct(T)                        \
  void Destruct_##T(struct Queue *queue) { \
    Queue(T) *_queue = (Queue(T) *)queue;  \
    while (_queue->First != NULL) {        \
      Node(T) *node = _queue->First->Next; \
      free(_queue->First);                 \
      _queue->First = node;                \
    }                                      \
  }

#define Init(T)                                                    \
  Queue InitQueue_##T() {                                          \
    Queue(T) queue;                                                \
    queue.Push = (void (*)(struct Queue *, const void *))Push_##T; \
    queue.Destruct = (void (*)(struct Queue *))Destruct_##T;       \
    queue.Peek = (void (*)(const struct Queue *, void *))Peek_##T; \
    queue.Pop = (void (*)(struct Queue *, void *))Pop_##T;         \
    queue.IsEmpty = isEmpty;                                       \
    queue.Size = 0;                                                \
    queue.First = (Node(T) *)malloc(sizeof(Node(T)));              \
    queue.First->Next = NULL;                                      \
    queue.Last = queue.First;                                      \
                                                                   \
    Queue res = *((Queue *)&queue);                                \
    return res;                                                    \
  }

#define Include_Queue_For_Type(T)               \
  Inc_Node(T);                                  \
  typedef struct Queue(T) {                     \
    void (*Push)(struct Queue *, const void *); \
    void (*Destruct)(struct Queue *);           \
    void (*Peek)(const struct Queue *, void *); \
    void (*Pop)(struct Queue *, void *);        \
    bool (*IsEmpty)(const struct Queue *);      \
    size_t Size;                                \
    Node(T) * First;                            \
    Node(T) * Last;                             \
  }                                             \
  Queue(T);                                     \
                                                \
  Pop(T);                                       \
  Peek(T);                                      \
  Push(T);                                      \
  Destruct(T);                                  \
  Init(T);
