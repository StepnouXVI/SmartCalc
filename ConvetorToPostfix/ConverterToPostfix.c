#include "../libs/ConverterToPostfix.h"

// char *ToPostfix(char *infixExpression, int N) {
//   char *postfixExpression = NULL;
//   Node *stack = NULL;
//   int length = 0;
//   for (int i = 0; i < N; i++) {
//     char c = infixExpression[i];
//     if (isNumber(c)) {
//       postfixExpression =
//           GetStringNumber(infixExpression, N, &i, &length, postfixExpression);
//       postfixExpression = AddCharToString(postfixExpression, &length, ' ');
//     } else if (c == '(') {
//       stack = push(stack, c);
//     } else if (c == ')') {
//       while (stack != NULL && peek(stack) != '(') {
//         postfixExpression =
//             AddCharToString(postfixExpression, &length, pop(&stack));
//         postfixExpression = AddCharToString(postfixExpression, &length, ' ');
//       }
//       pop(&stack);
//     } else if (isOperator(c)) {
//       char oper = c;
//       if (oper == '-' &&
//           (i == 0 || (i > 1 && isOperator(infixExpression[i - 1])))) {
//         oper = '~';
//       }
//       while (stack != NULL && (Priority(peek(stack)) >= Priority(oper))) {
//         postfixExpression =
//             AddCharToString(postfixExpression, &length, pop(&stack));
//         postfixExpression = AddCharToString(postfixExpression, &length, ' ');
//       }
//       stack = push(stack, oper);
//     } else if (c == 'x') {
//       postfixExpression = AddCharToString(postfixExpression, &length, 'x');
//       postfixExpression = AddCharToString(postfixExpression, &length, ' ');
//     }
//   }
//   while (stack != NULL) {
//     postfixExpression =
//         AddCharToString(postfixExpression, &length, pop(&stack));
//     postfixExpression = AddCharToString(postfixExpression, &length, ' ');
//   }
//   postfixExpression = AddCharToString(postfixExpression, &length, '\0');
//   return postfixExpression;
// }

// String ToPostfix(String infixString) {
//   String postfixString = MakeClearString();
//   Stack stack = InitStack_char(infixString.Size);
//   foreach (infixString, symb) {

//     if(isNumber(symb))
//     {
//         AddChar(&postfixString, symb);
//         continue;
//     }

//     if(isOpenBracket(symb))
//     {
//         Push_char(&stack, symb);
//         continue;
//     }


//   }
//   end;
// }