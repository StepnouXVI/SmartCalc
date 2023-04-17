#include "../libs/String.h"

void DestructString(String *string) {
  string->Size = 0;
  if (string->String != NULL) free(string->String);
  string->String = NULL;
}

String MakeClearString(void) {
  String string = MAKE_CLEAR_STRING;
  string.Size = 1;
  string.String = malloc(sizeof(char));
  string.String[0] = '\0';
  return string;
}

void AddChar(String *string, char symb) {
  string->Size++;
  string->String = (char *)realloc(string->String, string->Size);
  string->String[string->Size - 2] = symb;
  string->String[string->Size - 1] = '\0';
}

String ReadStringWithoutSpaces(FILE *file) {
  String res = MakeClearString();
  char symb;
  while ((symb = fgetc(file)) != EOF) {
    if (symb == ' ') continue;
    AddChar(&res, symb);
  }
  return res;
}

String Remove(String *string, char symb) {
  String res = MakeClearString();
  for (size_t i = 0; i < string->Size; i++) {
    if (string->String[i] == symb) continue;
    AddChar(&res, string->String[i]);
  }
  return res;
}

bool IsEqual(String str1, String str2) {
  return strcmp(str1.String, str2.String) == 0;
}

String Replace(String string, const String replacement, char symb) {
  String res = MakeClearString();
  char *tmp = string.String, *index = NULL;

  while ((index = strstr(tmp, replacement.String)) != NULL) {
    for (long int i = 0; i < tmp - index + 1; i++) {
      AddChar(&res, tmp[i]);
    }
    AddChar(&res, symb);
    tmp = index + replacement.Size;
  }
  return res;
}

bool IsDigit(char symb) { return symb >= '0' && symb <= '9'; }

void ShiftString(String *string, size_t shift) {
  char *new_string = (char *)malloc(sizeof(char) * (string->Size - shift));
  memcpy(new_string, string->String + shift, string->Size - shift);
  free(string->String);
  string->String = new_string;
  string->Size -= shift;
}

void ConcatN(String *res, const String *src, size_t n) {
  for (size_t i = 0; i < n; i++) {
    AddChar(res, src->String[i]);
  }
}