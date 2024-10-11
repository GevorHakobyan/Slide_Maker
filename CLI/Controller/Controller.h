#pragma once
#include "Parser.h"
#include "Initializer.h"

namespace cli {
    class Controller {
        public:
        using CommandPtr = std::unique_ptr<cli::I_Command>;
        using ParserPtr = std::unique_ptr<cli::Parser>;
        public:
        Controller();
        ~Controller() = default; 
        void start(std::istream&);

        private:
        CommandPtr fetch(std::istream&);
        void Exectute(CommandPtr&);

        private:
        ParserPtr m_parser{};        
    };
}; //namespace cli