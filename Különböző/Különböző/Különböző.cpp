#include <iostream>
#include <fstream>
#include <chrono>
#include <unordered_map>
#include <string>
#include <cmath>
#include <algorithm>

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::fstream fs("Text.txt");
    std::ofstream os("Text1.txt");
    std::string N;
    fs >> N;
    std::unordered_map<std::string, bool> w;

    for (std::string s; fs >> s;) {
        std::sort(s.begin(), s.end());
        w[s] = 1;
    }

    os << w.size();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds> (end - start);
    std::cout << "\n" << duration.count();
}

