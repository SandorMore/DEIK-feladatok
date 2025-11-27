#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
int main() {
    std::map<std::string, bool> map;
    std::ifstream fs("Text.txt");
    std::ofstream os("Output.txt");

    std::string line;
    std::getline(fs, line);

    size_t closeBrace = line.find('}');

    std::string listPart = line.substr(0, closeBrace + 1);
    std::string targetPart = line.substr(closeBrace + 2); 

    listPart = listPart.substr(1, listPart.size() - 2);

    std::vector<std::string> vec;
    std::stringstream ss(listPart);
    std::string token;
    while (std::getline(ss, token, ',')) {
        size_t fq = token.find('"');
        size_t rq = token.rfind('"');
        if (fq != std::string::npos && rq != std::string::npos && rq > fq) {
            token = token.substr(fq + 1, rq - fq - 1);
            vec.push_back(token);
        }
    }
    if (targetPart.front() == '"' && targetPart.back() == '"') {
        targetPart = targetPart.substr(1, targetPart.size() - 2);
    }

    for (auto i : vec) {
        int a = i.find('_');
        std::string firstPart = i.substr(0, a);
        std::string secondPart = i.substr(a + 1);

        if (map.count(firstPart)) {
            if ((secondPart == "deny")) {
                map[firstPart] = 0;
            }
        } else {
            map[firstPart] = (secondPart == "allow");
        }
    }

    if (map.count(targetPart)) {
        os << map[targetPart];
        return 0;
    } else if (map.count("*")) {
        os << map["*"];
        return 0;
    }

    os << 0;
    return 0;
}
