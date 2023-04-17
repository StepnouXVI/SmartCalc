

#include "OperationsCodes.h"
#include "String.h"

typedef enum TypeOfOperation { Unary, Binary } TypeOfOperation;
typedef struct OperationLexeme {
  String fullName;
  OperationCode code;
  int priority;
  TypeOfOperation type;
} OperationLexeme;

static OperationLexeme Lexemes[] = {
    {{"+", 2}, Add, 1, Binary},    {{"-", 2}, Sub, 1, Binary},
    {{"*", 2}, Mul, 2, Binary},    {{"/", 2}, Div, 2, Binary},
    {{"mod", 4}, Sub, 2, Binary},  {{"^", 2}, Pow, 2, Binary},
    {{"-", 2}, Negate, 3, Unary},  {{"cos", 4}, Cos, 3, Unary},
    {{"sin", 4}, Sin, 3, Unary},   {{"tan", 4}, Tan, 3, Unary},
    {{"log", 4}, Log, 3, Unary},   {{"ln", 3}, Ln, 3, Unary},
    {{"sqrt", 5}, Sqrt, 3, Unary}, {{"atan", 5}, Atan, 3, Unary},
    {{"acos", 5}, Acos, 3, Unary}, {{"asin", 5}, Asin, 3, Unary}};

#define MaxLengthOfOperation 4
#define MinxLengthOfOperation 1
#define SizeOfLexemes (size_t)(sizeof(Lexemes) / sizeof(OperationLexeme))