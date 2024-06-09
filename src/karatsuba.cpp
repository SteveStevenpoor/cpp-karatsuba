#include <karatsuba.h>

long karatsubaMul(const int x, const int y) {
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

long recursiveMul(const int x, const int y) {
    if (x < 10 || y < 10) {
        return x * y;
    }

    int pX = giveSizeBase(x, 10);
    int pY = giveSizeBase(y, 10);
    int p = (pX < pY) ? pX : pY;

    int p2 = p/2;

    int a, b, c, d;
    cut(x, p2, a, b);
    cut(y, p2, c, d);

    long ac = recursiveMul(a, c);
    long bd = recursiveMul(b, d);
    long abcd = recursiveMul(a + b, c + d);


    return basePow(10, p2*2)*ac + basePow(10, p2)*(abcd - ac - bd) + bd;
}

void cut(const int num, const int place, int& left, int& right) {
    left = num / basePow(10, place);
    right = num % basePow(10, place);
}

long basePow(const int base, const int pow) {
    long res = 1;
    for (int i = pow; i > 0; i--) {
        res *= base;
    }
    return res;
}
 
int giveSizeBase(int num, const int base) {
    int size = 0;
    while (num > 0) {
        num /= base;
        size++;
    }
    return size;
}