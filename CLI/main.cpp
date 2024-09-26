#include <iostream>
#include "Parser.h"
#include <sstream>

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::istringstream obj(str);

    const auto ptr = cli::Parser::getInstance();
    const auto command = ptr->operator()(obj);
    std::cout << command.m_name << "\n";
    std::cout << command.m_options << "\n";
    std::cout << command.m_arguments << "\n";
    return 0;
}