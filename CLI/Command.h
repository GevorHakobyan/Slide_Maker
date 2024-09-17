#pragma once
#include "string"
#include <vector>

namespace cli {
    class I_Command {
        public: //usings
        using name = std::string_view;
        using arguments = std::initializer_list<std::string_view>;
        using options = std::initializer_list<std::string_view>;

        public:
        I_Command(name, arguments = {}, options = {});
        I_Command(I_Command&&) noexcept;
        ~I_Command() = default;
        public://setters and getters
        void setName(const name);
        void setArguments(const arguments&);
        void setOptions(const options&);
        const name getName() const;
        const arguments& getArguments() const;
        const options& getOptions() const;

        private:
        name m_name{};
        arguments m_arguments{};
        options m_options{};
    };
} //namespace cli