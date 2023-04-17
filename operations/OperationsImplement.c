#include "../libs/OperationImplement.h"

double Op_Add(double a, double b) { return a + b; }

double Op_Sub(double a, double b) { return a - b; }

double Op_Mul(double a, double b) { return a * b; }

double Op_Div(double a, double b) { return a / b; }

double Op_Pow(double a, double b) { return pow(a, b); }

double Op_Sqrt(double a) { return sqrt(a); }

double Op_Cos(double a) { return cos(a); }

double Op_Sin(double a) { return sin(a); }

double Op_Tan(double a) { return tan(a); }

double Op_Log(double a) { return log(a) / log(10.0); }

double Op_Ln(double a) { return log(a); }

double Op_Atan(double a) { return atan(a); }

double Op_Acos(double a) { return acos(a); }

double Op_Asin(double a) { return asin(a); }

double Op_Negate(double a) { return -a; }

double Op_Mod(double a, double b) { return fmod(a, b); }
