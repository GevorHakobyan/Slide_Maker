#pragma once
#include "GUI_Interactor.h"
#include "Editor_Interactor.h"
#include "Vis_Interactor.h"

namespace commander {
    template <typename T>
    class Commander {
        public://usings
        using Command = cli::I_Command;
        using Gui_ptr = std::unique_ptr<Gui_Interactor<T>>;
        using Vis_ptr = std::unique_ptr<Vis_Interactor<T>>;
        using Edit_ptr = std::unique_ptr<Editor_Interactor<T>>
        using Commander_ptr = std::shared_ptr<Commander>;

        public://methods
        static Commander_ptr getInstance();
        void sendCommandTo(Command&);

        private://methods
        Commander() = default;
        ~Commander() = default;

        private: //data members
        static Commander_ptr m_ptr;
        Gui_ptr m_guiPtr{nullptr};
        Vis_ptr m_visPtr{nullptr};  
        Edit_ptr m_editPtr{nullptr};      
    };
}//namespace commander