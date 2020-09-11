#include <iostream>
#include <math.h>
using namespace std;
void factorize(long long n) {
    cout << 1 << "\t" << endl;
    int count = 0;
    while (!(n % 2)) {
        n /= 2;
        count++;
    }
    if (count)
        cout << 2 << "\t" << endl;
    for (long long i = 3; i <= sqrt(n); i += 2) {
        count = 0;
        while (n % i == 0) {
            cout << i << "\t" << endl;
            n = n / i;
        }
    }
    if (n > 2)
        cout << n << "\t" << endl;
}
int main() {
    long long N = 2244354;
    cout << "Os primos são: " << "\n";
    factorize(N);
    return 0;
}