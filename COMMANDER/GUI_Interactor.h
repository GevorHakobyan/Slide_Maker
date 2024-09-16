#pragma once

#include "Interactor.h"

namespace commander {
    template <typename T>
    class Gui_Interactor : public Interactor<T> {
        public:
        using GuiPtr = std::unique_ptr<GUI_Interactor>;

        private:
        Gui_Interactor() = default;
        ~Gui_Interactor() = default;

        public:
        Gui_Interactor(const Gui_Interactor&) = delete;
        Gui_Interactor& operator=(const Gui_Interactor&) = delete;
        static GUIPtr getInstance();
        void InteractWith(std::shared_ptr<T>) override;

        private: //data members
        static GuiPtr m_ptr;
    };

}//namespace commander