

#include "String.h"

typedef struct OperationName {
  String FullName;
  char ShortName;
  int priority;
} OpName;

static OpName BinaryNames[] = {{{"+", 2}, '+', 1},   {{"-", 2}, '-', 1},
                               {{"*", 2}, '*', 2},   {{"/", 2}, '/', 2},
                               {{"mod", 4}, '%', 2}, {{"^", 2}, '^', 3}};

static OpName UnaryNames[] = {{{"-", 2}, '-', 4},    {{"cos", 4}, 'c', 4},
                              {{"sin", 4}, 's', 4},  {{"tan", 4}, 't', 4},
                              {{"log", 4}, 'g', 4},  {{"ln", 3}, 'l', 4},
                              {{"sqrt", 5}, 'q', 4}, {{"atan", 5}, 'a', 4},
                              {{"acos", 5}, 'o', 4}, {{"asin", 5}, 'i', 4}};
