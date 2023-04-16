#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bool.h"
#ifndef STRING_H
#define STRING_H
typedef struct Stirng {
  char *String;
  size_t Size;
} String;

#define MAKE_CLEAR_STRING \
  { NULL, 0 }

void AddChar(String *string, char symb);
void ClearString(String *string);
String MakeClearString(void);
bool IsDigit(char symb);
String ReadStringWithoutSpaces(FILE *file);
String Remove(String *string, char symb);
bool IsEqual(String str1, String str2);
String Replace(String string, const String replacement, char symb);

#define foreach(string, el)                             \
  {                                                     \
    bool exit = false;                                  \
    for (size_t i = 0; i < string.Size && !exit; i++) { \
      char el = string.String[i];

#define end \
  }         \
  }

#endif
