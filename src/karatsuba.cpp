#include <karatsuba.h>

int karatsubaMul(const int x, const int y) {
    if (x == 0 || y == 0) {
        return 0;
    }
    if (x < 0) {
        return (-1)*karatsubaMul(-x, y);
    }
    if (y < 0) {
        return (-1)*karatsubaMul(x, -y);
    }
    if (x == 1) {
        return y;
    }
    if (y == 1) {
        return x;
    }
    return recursiveMul(x, y);
}

int recursiveMul(const int x, const int y) {
    if (x < 10 || y < 10) {
        return x*y;
    }
    int pX = giveSizeBase(x, 10);
    int pY = giveSizeBase(y, 10);
    int p = (pX < pY) ? pX : pY;

    int p2 = p/2;

    int a, b, c, d;
    cut(x, p2, a, b);
    cut(y, p2, c, d);

    int ac = recursiveMul(a, c);
    int bd = recursiveMul(b, d);
    int abcd = recursiveMul(a + b, c + d);


    return basePow(10, p)*ac + basePow(10, p2)*(abcd - ac - bd) + bd;
}

void cut(const int num, const int place, int& left, int& right) {
    left = num / basePow(10, place);
    right = num % basePow(10, place);
}

int basePow(const int base, const int pow) {
    long res = 1;
    for (int i = pow; i > 0; i--) {
        res *= base;
    }
    return res;
}

int giveSizeBase(int num, int base) {
    int size = 0;
    while (num > 0) {
        num /= base;
        size++;
    }
    return size;
}