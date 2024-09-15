#pragma once
#include "GUI_Interactor.h"
#include "CLI_Interactor.h"
#include "Vis_Interactor.h"

namespace commander {
    template <typename T>
    class Commander {
        public://usings
        using Cli_ptr = std::unique_ptr<Cli_Interactor<T>>;
        using Gui_ptr = std::unique_ptr<Gui_Interactor<T>>;
        using Vis_ptr = std::unique_ptr<Vis_Interactor<T>>;
        using Commander_ptr = std::shared_ptr<Commander>;

        public://methods
        static Commander_ptr getInstance();

        private://methods
        Commander() = default;
        ~Commander() = default;

        private: //data members
        static Commander_ptr m_ptr;
        Cli_ptr m_cliPtr{nullptr};
        Gui_ptr m_guiPtr{nullptr};
        Vis_ptr m_visPtr{nullptr};        
    };
}//namespace commander