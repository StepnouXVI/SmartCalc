#include "Stack.h"

#include "../libs/IOperation.h"
Include_Stack_For_Type(int);
Include_Stack_For_Type(float);
Include_Stack_For_Type(double);
Include_Stack_For_Type(char);
Include_Stack_For_Type(IOperation);

bool S_isEmpty(const Stack *stack) { return stack->Size == 0; }