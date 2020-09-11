/* #include <iostream>
#include <random>
using namespace std;
int main() {
    mt19937 mt(1729);
    uniform_int_distribution<int> dist(0, 99);
    for (int i = 0; i < 25; ++i) {
        std::cout << dist(mt) << " ";
    }
    std::cout << std::endl;
}
*/
#include <iostream>
#include <random>
int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 10000);
    for (int i = 0; i < 16; ++i) {
        std::cout << dist(mt) << " ";
    }
    std::cout << std::endl;
}
