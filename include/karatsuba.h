#ifndef KARATSUBA_H
#define KARATSUBA_H

#include <iostream>
#include <vector>

long karatsubaMul(const int a, const int b);
int giveSizeBase(int num, int base);
void cut(const int num, const int place, int& left, int& right);
long basePow(const int base, const int pow);
long recursiveMul(const int x, const int y);

#endif // KARATSUBA_H