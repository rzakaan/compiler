#include <fstream>
#include <iostream>
#include <sstream>

//#include <stdlib.h>

enum class TokenType {
    _return,
    int_lit
};

struct Token {
    TokenType tokenType;
    std::optional<std::string> value{};
};

std::vector<Token> tokenize(const std::string& str) {
    std::vector<Token> tokens;
    std::string buff;
    for (int i = 0; i < str.length(); i++) {
        char c = str.at(i);
        if (std::isspace(c)) {
            continue;
        }
        else if (std::isalpha(c)) {
            buff.push_back(c);
            i++;
            while (std::isalpha(str.at(i))) {
                buff.push_back(str.at(i));
                i++;
            }
            i--;
            if (buff == "return") {
                tokens.push_back({ .tokenType = TokenType::_return });
                buff.clear();
                continue;
            }
            else {
                std::cerr << "You messed up!" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        else if (std::isdigit(c)) {
            buff.push_back(c);
            i++;
            //!TOOD
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Incorrect usage !" << std::endl;
        return EXIT_FAILURE;
    }

    // loading string from file
    std::string contents;
    std::fstream input(argv[1], std::ios::in);
    std::stringstream ss;
    ss << input.rdbuf();
    contents = ss.str();
    input.close();
    std::cout << contents << std::endl;

    std::vector<Token> tokens = tokenize(contents);

    return EXIT_SUCCESS;
}