#ifndef RADDI_NOTICED_H
#define RADDI_NOTICED_H

#include "../common/lock.h"
#include "raddi_eid.h"
#include <set>
#include <map>

namespace raddi {

    // noticed
    //  - special cache for entry IDs optimized for cleaning by age
    //  - TODO: evaluate gains of replacing 'set' with sorted vector
    //
    class noticed {
        mutable ::lock                                  lock;
        std::map <std::uint32_t, std::set <raddi::iid>> data;
        mutable std::set <std::uint32_t>                changed; // changed since last successful save

    public:

        // insert
        //  - adds EID to noticed cache
        //  - returns true if successfully inserted, false if already present
        //
        bool insert (const eid & id);

        // clean
        //  - deletes all entries older than 'age'
        //
        void clean (std::uint32_t age);

        // count
        //  - returns true if EID is present in the cache
        //
        bool count (const eid & id) const;

        // size
        //  - returns total number of EIDs in the cache
        //
        std::size_t size () const;

        // load/save
        //  - loads or saves data to file at 'path'
        //
        bool load (const std::wstring & path);
        void save (const std::wstring & path) const;

    private:
        static bool parse (const wchar_t * string, std::uint32_t * output);
    };
}

#endif
