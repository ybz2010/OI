#include <iostream>

// 快速幂函数
long long fastPower(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base %= modulus;

    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * base) % modulus;
        }
        exponent >>= 1;
        base = (base * base) % modulus;
    }

    return result;
}

int main() {
    long long base, exponent, modulus;
    std::cout << "请输入底数: ";
    std::cin >> base;
    std::cout << "请输入指数: ";
    std::cin >> exponent;
    std::cout << "请输入模数: ";
    std::cin >> modulus;

    long long result = fastPower(base, exponent, modulus);
    std::cout << base << "^" << exponent << " mod " << modulus << " = " << result << std::endl;

    return 0;
}