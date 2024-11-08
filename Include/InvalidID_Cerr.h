#pragma ocne
#include "Exception.h"

namespace edition {
    class InvalidID : public cli::Exception {
        public:
        using ID = size_t;

        public:
        InvalidID(const Messeage&, ID = 0, Location = Location::current());
        ~InvalidID() = default;
        void setMesseage() override;
        
        private:
        ID m_invalidId{0};
    };    
}; //namespace edition