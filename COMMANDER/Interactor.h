#pragma once
#include "CommandCreator.h"


namespace commander {

    template <typename T>
    class Interactor {
        public:
        using InteractorPtr = std::shared_ptr<Interactor>;
        using CommandCreator = cli::CommandCreator::CommandCreatorPtr;

        public:
        static InteractorPtr getInstance();
        virtual void InteractWith(std::shared_ptr<T>); 

        private:
        Interactor() = default;
        ~Interactor() = default;

        private:
        InteractorPtr m_ptr;
    };
    
}//namespace commander