#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream fs("Text.txt");
    std::ofstream of("OutPut.txt");

    int n;
    fs >> n;

    std::vector<int> a(n * n);
    for (int i = 0; i < n * n; ++i)
        fs >> a[i];

    int mid = (n - 1) / 2;
    int idx = mid * n + mid;

    int prev = a[idx];
    int len = 1;

    int dirs[4] = { 1, -n, -1, n };

    int d = 0;

    while (idx != 0) {
        for (int rep = 0; rep < 2; ++rep) {
            for (int i = 0; i < len; ++i) {
                idx += dirs[d];

                if (idx < 0 || idx >= n * n) {
                    of << 0;
                    return 0;
                }

                if (a[idx] < prev) {
                    of << 0;
                    return 0;
                }

                prev = a[idx];
                if (idx == 0) {
                    of << 1;
                    return 0;
                }
            }
            d = (d + 1) % 4;
        }
        len++;
    }

    of << 1;
    return 0;
}
