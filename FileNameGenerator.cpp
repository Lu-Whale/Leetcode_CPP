#include <iostream>
#include <string>

/**
 * Run and paste name copied from leetcode website, then copy the result as the C++ file name
 */
class Name_Generator {
public:
    static std::string generator(const std::string& s) {
        std::string result = "_";

        for (char ch : s) {
            if (ch == ' ' || ch == '-' || ch == '(' || ch == ')') {
                result += '_';
            } else if (ch != '.') {
                result += ch;
            }
        }

        if (result.back() == '_') {
            result.pop_back();
        }

        return result;
    }
};

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::cout << Name_Generator::generator(input) << std::endl;
    return 0;
}

