#include "BoolCube.hpp"
#include <algorithm>
#include <iostream>

void PrintSphere(const std::vector<bool>& center, unsigned int radius) {
    std::vector<bool> a(center);
    std::vector<bool> mask;

    for (int i = 0; i < a.size(); ++i) {
        if (i <= (a.size() - radius)) {
            mask.push_back(false);
        }
        else {
            mask.push_back(true);
        }
    }
    do {
        XorVector(a, mask);
        PrintBoolVector(a);
        XorVector(a, mask);
    } while (std::next_permutation(mask.begin(), mask.end()));
}

void PrintBoolVector(const std::vector<bool>& vec) {
    std::cout << "(";
    for (bool b : vec) {
        std::cout << b;
    }
    std::cout << ")" << std::endl;
}

void XorVector(std::vector<bool>& lval, const std::vector<bool>& rval) {
    if (lval.size() != rval.size()) {
        throw new std::invalid_argument("Inconsistent vector size");
    }
    for (int i = 0; i < lval.size(); ++i) {
        lval[i] = lval[i] ^ rval[i];
    }
}