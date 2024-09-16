#pragma once
#include <utility>
#include <cstddef>

namespace document {

    struct S_Geometry {
        public: //usings
        using Location = std::pair<size_t, size_t>;
        using Size = std::pair<size_t, size_t>;
        
        public: //methods
        S_Geometry(const Location&, const Size&);
        void setLocation(Location);
        void setSize(Size);
        const Location& getLocation() const;
        const Size& getSize() const;

        //data members
        private:
        Location m_Location;
        Size m_Size;
    };

} // namespace document