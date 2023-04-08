#ifndef STRINGCHECK_H
#define STRINGCHECK_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stdlib.h>

void delayText(std::string inputText);

int charLength(char input[]);

bool iterDigit(char input[]);

bool iterDecDigit(char input[]);

bool iterAlpha(char input[]);

int GetIntNum(int min, int max);

double GetAnyDec(int min, int max);

std::vector<std::string> alphabetize(std::vector<std::string> toBeAlpha);

#endif