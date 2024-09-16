#pragma once
#include "Slide.h"
#

namespace document {
    //this class must be responsible for storing existing slides
    //and implementing different commands on them
    class Storage{
        private:
        class Const_Iterator{

        };
        
        public: //usings
        using List = std::vector<Slide>;

        public://methods
        Storage() = default;
        ~Storage() = default;
        void addSlide(const Slide&);
        void removeSlide(size_t);
        const Slide& getItem(size_t) const;
        Slide& getItem(size_t);

        private:
        List m_list{};
    };
} // namespace document