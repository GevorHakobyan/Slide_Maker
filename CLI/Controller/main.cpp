#include <iostream>
#include "Controller.h"

int main() {
    cli::Controller m_controller;
    m_controller.start(std::cin);
    return 0;
}