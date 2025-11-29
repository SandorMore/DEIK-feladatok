#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>
#include <chrono>

struct koordinata {
    short x;
    short y;
    koordinata() :x(0), y(0){}
    koordinata(short x_, short y_) :x(x_), y(y_) {}
};
int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<koordinata> vec;

    koordinata p;

    bool vanU = false;

    std::fstream fs("Input.txt");
    std::ofstream os("Output.txt");

    char c;
    for (int sor = 0; sor < 8; ++sor) {
		for (int oszlop = 0; oszlop < 8; ++oszlop) {
            fs >> c;
            switch (c)
            {
                case 'u':
                    if (!vanU) {
                        vanU = true;
                        vec.clear();
                    }
                    vec.emplace_back(koordinata(sor, oszlop));
                    break;
                case 'm':
                    if (!vanU) {
						vec.emplace_back(koordinata(sor, oszlop));
                    }
                    break;
                case 'p':
                    p = koordinata(sor, oszlop);
                    break;
                default:
                    break;
            }
        }
    }

    std::vector<koordinata> _;
    int m = std::numeric_limits<int>::max();
    for (koordinata& szoba : vec) {
        int tav = std::abs(p.x - szoba.x) + std::abs(p.y - szoba.y);
        if (tav < m) {
            m = tav;
            _.clear();
        }
        
        if (tav == m) {
            _.emplace_back(szoba);
        }
    }

    for (int i = 0; i < _.size();++i) {
        os << "[" << _[i].x << "," << _[i].y << "]";
        if (i < _.size()-1) {
            os << " ";
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time taken: " << duration.count() << " ms\n";

    end:
    return 0;
}
