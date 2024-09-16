#pragma once

#include "Interactor.h"

namespace commander {
    template <typename T>
    class Vis_Interactor : public Interactor<T> {
        public:
        using VisPtr = std::unique_ptr<Vis_Interactor>;

        private:
        Vis_Interactor() = default;
        ~Vis_Interactor() = default;

        public:
        Vis_Interactor(const Vis_Interactor&) = delete;
        Vis_Interactor& operator=(const Vis_Interactor&) = delete;
        static VisPtr getInstance();
        void InteractWith(std::shared_ptr<T>) override;

        private: //data members
        static VisPtr m_ptr;
    };
}//namespace commander