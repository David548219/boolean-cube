#include "BoolCube.hpp"

int main() {
    std::vector<bool> center = {0, 0, 1, 1, 0};
    int radius = 3;
    PrintSphere(center, radius);
    system("pause");
    return 0;
}