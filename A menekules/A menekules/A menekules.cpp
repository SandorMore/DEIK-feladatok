#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <chrono>

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::fstream fs("Text.txt");
    std::ofstream os("Output.txt");
    int lab = 1;
    int tud = 1;
    std::vector<char> p;
    for (char c; fs >> c;) {
        p.emplace_back(c);
    }

    char last = p[0];
    int c{1};
    for (int i = 1; i < p.size(); ++i) {
        if (p[i] == 'P') {
            os << "1";
            return 0;
        }
        if (p[i] == 'l') {
            ++lab;
            goto forEnd;
        }
        if (p[i] == 'c') {
            ++tud;
			goto forEnd;
        }
        if (p[i] == '_') {
            c = 0;
			goto forEnd;
        }
        if (p[i] == last) {
            c++;
            continue;
        }

        switch (p[i])
        {
            case '~':
                if (tud < c)
                    goto end;
                break;
            case '|':
                if (lab < c)
                    goto end;
                break;
            default:
                break;
        }

        forEnd:
        last = p[i];
        c = 1;
    }
    end:
    os << "0";
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << duration.count();
    fs.close();

    return 0;

}
