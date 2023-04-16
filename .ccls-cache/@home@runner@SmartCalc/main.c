#include "libs/Operations.h"
#include "libs/Stack.h"
#include "stdio.h"

include_stack(double);

double sum(double a, double b) { return a + b; }

double negate(double a) { return -a; }

int main() {
  double n = 90.9;
  IOperation *Num = Create(n, Number);

  NOperation *N = (NOperation *)Num;
  printf("|%f|\n", N->Number);

  IOperation *Unary = Create(negate, Negate);
  IOperation *Binary = Create(sum, Negate);

  Stack s = InitStack(double);
  double a = 1, b = 2, c = 3;
  s.Push(&s, &a);
  s.Push(&s, &b);
  s.Push(&s, &c);

  double pr;

  s.Peek(&s, &pr);
  printf("[%f]\n", pr);

  Unary->Execute(Unary, &s);

  s.Peek(&s, &pr);
  printf("[%f]\n", pr);

  Binary->Execute(Binary, &s);

  s.Peek(&s, &pr);
  printf("[%f]\n", pr);

  Num->Execute(Num, &s);

  s.Peek(&s, &pr);
  printf("[%f]\n", pr);

  s.Destruct(&s);
    free(Num);
    free(Binary);
    free(Unary);
  printf("It works!!\n");
}