#pragma once
#include <string>
bool IsOperator(char symbol) ;
bool IsValue(char symbol);
bool IsDelimiter(char symbol);
bool IsPoint(char symbol);
bool IsNormal(char symbol);
double IntermediateResult(double first, double second, char operation);
int OperationPriority(char operation);
void Transformer(std::string &expression);
int Check(std::string tested);
