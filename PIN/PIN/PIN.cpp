#include <iostream>
#include <chrono>
#include <fstream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <functional>

std::vector<std::string> _clac(const std::map<char, std::string>& m, std::string inp) {
    std::vector<std::string> vec;
    if (inp.size() == 1) {
        for (const char& c : m.at(inp[0])) {
            vec.emplace_back(std::string(1, c));
        }
    } else {
        for (const char& c : m.at(inp[0])) {
            for (std::string &s : _clac(m, inp.substr(1))) {
                vec.emplace_back(c + s);
            }
        }
    }
    return vec;
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    static const std::map<char, std::string> map = {
        {'0', "08"},
        {'1', "124"},
        {'2', "1235"},
        {'3', "236"},
        {'4', "1457"},
        {'5', "24568"},
        {'6', "3569"},
        {'7', "478"},
        {'8', "05789"},
        {'9', "689"}
    };

    std::fstream fs("Text.txt");
    std::ofstream os("Output.txt");
    std::string s;

    fs >> s;
    std::vector<std::string>res = _clac(map, s);
    for (auto& i : res) {
        os << i << " ";
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << duration.count();

}