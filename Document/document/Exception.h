#pragma once
#include <exception>
#include <source_location>
#include <string>

namespace cli {

    class Exception : public std::exception {
        public:
        using Messeage = std::string;
        using Location = std::source_location;
        public:
        Exception(const Messeage&, const Location& = std::source_location::current());
        virtual const char* what() const noexcept override;
        
        protected:
        virtual void setMesseage();
        protected:
        Messeage m_messeage{};
        Location m_ErrorLocation;
    };
}; //namespace cli