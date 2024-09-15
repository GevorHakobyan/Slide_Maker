#pragma once

#include "Interactor.h"

namespace commander {
    template <typename T>
    class Cli_Interactor : public Interactor<T> {
        public:
        using CliPtr = std::unique_ptr<Cli_Interactor>;

        private:
        Cli_Interactor() = default;
        ~Cli_Interactor() = default;

        public:
        Cli_Interactor(const Cli_Interactor&) = delete;
        Cli_Interactor& operator=(const Cli_Interactor&) = delete;
        static CliPtr getInstance();
        void InteractWith(std::shared_ptr<T>) override;

        private: //data members
        static CliPtr m_ptr;
    };

}//namespace commander