#pragma once
#include "CommandCreator.h"


namespace commander {

    template <typename T>
    class Interactor {
        public:
        using InteractorPtr = std::shared_ptr<Interactor>;
        using CommandCreator = cli::CommandCreator::CommandCreatorPtr;
        public:
        Interactor() = default;
        ~Interactor() = default;
        virtual void InteractWith(std::shared_ptr<T>); 
    };
    
}//namespace commander