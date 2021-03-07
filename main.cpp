#include "hanoi.h"
#include <iostream>

int main() {
    int n = 3;
    std::cout << "Towers of Hanoi - Compute recursive Solution for n = ";
    std::cin >> n;
    std::cout << "\n--------------\n";
    Hanoi h(n);
    h.solve();
    return 0;
}