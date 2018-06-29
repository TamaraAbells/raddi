#ifndef RADDI_DEFAULTS_H
#define RADDI_DEFAULTS_H

#include <cstdint>

namespace raddi {
    namespace defaults {
        static constexpr std::uint16_t coordinator_listening_port = 44303; // TCP
        static constexpr std::uint16_t coordinator_discovery_port = 44303; // UDP
        static constexpr std::uint16_t socks5t_port = 9050; // default Tor SOCKS5 proxy port

        static constexpr std::size_t coordinator_max_concurrent_connection_attempts = 8;

        // coordinator_override_min_core_connections
        //  - if secured core node connections is less than 'count' for 'delay' seconds
        //    then another one is attempted even if configured to normally not to
        //
        static constexpr std::size_t coordinator_override_min_core_connections_count = 1; // max number of secured connections
        static constexpr std::size_t coordinator_override_min_core_connections_delay = 30; // s

        // coordinator_additional_leaf_[min|max]_core_connections
        //  - when configured as "leaf" node, increase requirements on core node connections
        //    to ensure we receive all data
        //
        static constexpr std::size_t coordinator_additional_leaf_min_core_connections = 1;
        static constexpr std::size_t coordinator_additional_leaf_max_core_connections = 1;

        static constexpr std::size_t connection_keep_alive_timeout = 60000; // ms


        static const wchar_t bootstrap_url [] = L"https://www.raddi.net/bootstrap.txt"; // HTTP
    }
}

#endif
