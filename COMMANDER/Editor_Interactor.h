#pragma once

namespace commander {
template <typename T>
    class Editor_Interactor : public Interactor<T> {
        public:
        using EditPtr = std::unique_ptr<Editor_Interactor>;

        private:
        Editor_Interactor() = default;
        ~Editor_Interactor() = default;

        public:
        Editor_Interactor(const Editor_Interactor&) = delete;
        Editor_Interactor& operator=(const Editor_Interactor&) = delete;
        static VisPtr getInstance();
        void InteractWith(std::shared_ptr<T>) override;

        private: //data members
        static EditPtr m_ptr;
    };

}; //namespace commander