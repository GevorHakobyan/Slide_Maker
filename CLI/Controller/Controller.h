#pragma once
#include "../Parser/Parser.h"

namespace cli {
    class Controller {
        public:
        using CommandPtr = std::shared_ptr<cli::I_Command>;
        using ParserPtr = std::unique_ptr<cli::Parser>;
        using thisPtr = std::shared_ptr<Controller>;
        public:
        void start(std::istream&);
        static thisPtr  getInstance();

        private:
        Controller() = default;
        ~Controller() = default; 
        CommandPtr fetch(std::istream&);
        void Exectute(CommandPtr);

        private:
        ParserPtr m_parser{};        
    };
}; //namespace cli