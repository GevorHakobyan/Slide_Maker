#pragma once
#include "string"
#include <vector>

namespace cli {
    class I_Command {
        public: //usings
        using name = std::string_view;
        using argList = std::vector<std::string_view>;
        using options = std::vector<std::string_view>;

        public:
        I_Command(name, argList, options);
        I_Command() = default;
        ~I_Command() = default;
        public://setters and getters
        void setName(const name);
        void setArguments(const argList&);
        void setOptions(const options&);
        const name getName() const;
        const argList& getArguments() const;
        const options& getOptions() const;

        private:
        name m_name;
        argList m_arguments;
        options m_options;
    };
} //namespace cli