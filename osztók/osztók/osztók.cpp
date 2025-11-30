#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <map>
#include <limits>
int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::fstream fs("Text.txt");
    std::ofstream os("Output.txt");
    int a;
    fs >> a;

    while (fs >> a) {    
        std::map<int, int> primes;
        int i = 2;
        while (i <= a) {
            if (a % i == 0) {
                if (primes.count(i) > 0) {
                    ++primes[i];
                } else {
                    primes[i] = 1;
                }
                a /= i;
            } else {
                ++i;
            }
        }

        int dCount = 1;
        int oddCount = 1;
        for (auto& p : primes) {
            dCount *= p.second + 1;

            if (p.first & 1 == 1) {
                oddCount *= p.second + 1;
            }
        }

        int evenCount = dCount - oddCount;

        if (oddCount == evenCount) {
            os << 0 << "\n";
        }
        else if (oddCount > evenCount) {
            os << 1 << "\n";
        }
        else if(evenCount > oddCount)
            os << 2 << "\n";
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds d = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << d.count();
    return 0;
}
