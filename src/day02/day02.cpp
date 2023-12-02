#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>

using lines = std::vector<std::string>;

lines load_input(const std::string& file){
    lines lines;
    std::ifstream fs(file);
    std::string line;

    while (std::getline(fs, line)) {
        lines.push_back(line);
    }

    return lines;
}

int part1(const lines& lines) {
    std::map<char, int> maxValue {
        { 'r', 12},
        { 'g', 13 } ,
        { 'b', 14 }
    };

    std::vector<int> digits{};
    std::string value{};
    int sum{};


    for(auto& line : lines) {
        int id{};

        for (int i = 0; i < line.size(); i++) {
            if(auto& c = line[i]; std::isdigit(c)) {
                value += c;
            } else {
                if(value.empty()) {
                    continue;
                }

                if(id == 0) {
                    id = std::stoi(value);
                    sum += id;
                } else {
                   if(std::stoi(value) > maxValue[line[i+1]]) {
                       value = "";
                       sum -= id;
                       break;
                   }
                }
                value = "";
            }
        }
    }
    return sum;
}




int part2(const lines& lines) {
    std::map<char, int> m {
        { 'r', 0},
        { 'g', 0 } ,
        { 'b', 0 }
    };

    std::vector<int> digits{};
    std::string value{};
    int sum{};

    for(auto& line : lines){
        int start = line.find(':');

        for (int i = start; i < line.size(); i++) {
            if(auto& c = line[i]; std::isdigit(c)) {
                value += c;
            } else {
                if(value.empty()) {
                    continue;
                }

                auto color = line[i+1];
                int max = std::stoi(value);

                if(max > m[color]) {
                    m[color] = max;
                }
                value = "";
            }
        }
        sum += m['r'] * m['g'] * m['b'];
        m['r'] = 0;
        m['g'] = 0;
        m['b'] = 0;
    }
    return sum;
}

int main()
{
    lines test_values = load_input("../src/day02/test.txt");
    lines input = load_input("../src/day02/input.txt");

    std::cout << "part1: " << part1(test_values) << std::endl;
    std::cout << "part1: " << part1(input) << std::endl;

    std::cout << "part2: " << part2(test_values) << std::endl;
    std::cout << "part2: " << part2(input) << std::endl;

    return 0;
}