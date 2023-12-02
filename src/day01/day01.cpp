#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>

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

int getValue(const char& c) {
    return c - '0';
}

int part1(const lines& lines){
    int sum = 0;
    for(auto& line : lines){
        int digit{};
        for (const auto c : line) {
            if(std::isdigit(c)) {
                if(digit == 0) {
                    sum += 10 * getValue(c);
                }
                digit = getValue(c);
            }
        }
        sum += digit;
    }

    return sum;
}

int part2(const lines& lines) {
    constexpr std::array<std::string_view, 9> words = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };

    int sum{};
    for (const auto& line : lines) {
        int digit{};
        for (int i = 0; i < line.size(); i++) {
            if (const auto c = line[i]; std::isdigit(c)) {
                if (0 == digit) {
                    sum += 10 * getValue(c);
                }
                digit = getValue(c);
            } else {
                for (int j = 1; j <= words.size(); j++) {
                    if (const auto& word = words[j - 1]; 0 == line.compare(i, word.size(), word)) {
                        if (digit == 0) {
                            sum += 10 * j;
                        }
                        digit = j;
                        break;
                    }
                }
            }
        }
        sum += digit;
    }
    return sum;
}


int main()
{
    lines test_values = load_input("../src/day01/test.txt");
    lines test_values_2 = load_input("../src/day01/test_2.txt");
    lines input = load_input("../src/day01/input.txt");

    std::cout << "part1: " << part1(test_values) << std::endl;
    std::cout << "part1: " << part1(input) << std::endl;

    std::cout << "part2: " << part2(test_values_2) << std::endl;
    std::cout << "part2: " << part2(input) << std::endl;

    return 0;
}