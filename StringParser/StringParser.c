#include "StringParser.h"

exit_codes GetNumberFromString(String *string, double *res) {
  size_t number_length;

  bool is_normal_dots = CheckDotsAndGetNumberLength(string, &number_length);
  if (!is_normal_dots)
    return incorrect_input_string;

  *res = strtod(string->String, NULL);
  ShiftString(string, number_length);

  return success;
}


bool CheckDotsAndGetNumberLength(const String *string, size_t *lengthOfNumber) {
  size_t dot_count = 0, len = 0;
  for (size_t i = 0; i < string->Size && IsDotOrNumber(string->String[i]);
       i++) {
    if (IsDot(string->String[i])) {
      dot_count++;
    }
    len++;
  }

  *lengthOfNumber = len;
  return dot_count > 1;
}

exit_codes GetOperationCodeFromString(String *string, OperationCode *code) {
  exit_codes status = success;
  String operation = MakeClearString();
  status = GetStringOfOperationFromString(string, &operation);

  if (status == success && IsOperation(&operation, code))
    status = success;

  DestructString(&operation);
  return status;
}

exit_codes GetStringOfOperationFromString(String *src, String *operation) {
  size_t operation_length;
  bool is_normal_length = GetLengthOfOperation(src, &operation_length);
  if (!is_normal_length)
    return incorrect_input_string;

  ConcatN(operation, src, operation_length);
  return success;
}

bool IsOperation(const String *string, OperationCode *code) {
  bool isOp = false;
  for (size_t i = 0; i < SizeOfLexemes && !isOp; i++) {
    isOp = IsEqual(*string, Lexemes[i].fullName);
    if (isOp)
      *code = Lexemes[i].code;
  }
  return isOp;
}

bool GetLengthOfOperation(const String *string, size_t *lengthOfOperation) {
  size_t len = 0;
  for (size_t i = 0; isLetters(string->String[i]) &&
                     *lengthOfOperation <= (MaxLengthOfOperation + 1);
       i++) {
    len++;
  }
  *lengthOfOperation = len;
  return *lengthOfOperation <= MaxLengthOfOperation && *lengthOfOperation != 0;
}