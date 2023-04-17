#ifndef STRING_PARSER_H
#define STRING_PARSER_H
#include "../libs/Bool.h"
#include "../libs/ExitCodes.h"
#include "../libs/OperationsNames.h"
#include "../libs/Stack.h"
#include "../libs/String.h"

#define DOT '.'
#define IsDot(c) (c == DOT)
#define IsDotOrNumber(C) (IsDot(C) || IsDigit(C))

exit_codes GetOperationCodeFromString(String* string, OperationCode* code);
bool CheckDotsAndGetNumberLength(const String* string, size_t* lengthOfNumber);
bool IsOperation(const String* string, OperationCode* code);
bool GetLengthOfOperation(const String* string, size_t* lengthOfOperation);
exit_codes GetStringOfOperationFromString(String* src, String* operation);
#endif