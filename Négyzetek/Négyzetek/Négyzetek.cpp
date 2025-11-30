#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>
#include <string>

inline int calc(const int& k, const int& a, const int& b, const int& row = 0) {
		int h = (row + 1) * k;      // sor tetejének magassága
		if (h >= a) return 0;       // már kiléptünk a háromszögből

		// sor hix. szélessége
		double xmax = b * (1.0 - double(h) / a);

		int rCount = int(xmax / k); // annyi négyzet fér bele

		return rCount + calc(k, a, b, row + 1);
	
}

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	std::fstream fs("Text.txt");
	int esetekSzama;
	fs >> esetekSzama;
	int k, a, b;
	for (; esetekSzama--;) {
		fs >> k >> a >> b;
		calc(k, a, b);
		
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds> (end - start);
	std::cout << "\n" << duration.count();
}
