/*
//
// Created by myungki cho on 2024/02/12.
//

#include<iostream>
using namespace std;

int atoic(string s, int si) {
    if (si == 0) return int(s[si] - '0');
    return 10 * atoic(s, si - 1) + int(s[si] - '0');
}

int fibonacci(int a) {
    if (a == 0 || a == 1) return 1;
    return fibonacci(a - 1) + fibonacci(a - 2);
}

int gcd(int a, int b) {
    while (!b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    cout << gcd(10, 20) << "\n";
    cout << lcm(10, 20) << "\n";
    cout << fibonacci(5) << "\n";
    cout << atoic("2039", 3);
    return 0;
}*/
