#pragma once

#include <optional>

namespace Network {
    class ConnectionProtocol {
        public:
            static const ConnectionProtocol UNKNOWN;
            static const ConnectionProtocol HANDSHAKE;
            static const ConnectionProtocol PLAY;
            static const ConnectionProtocol STATUS;
            static const ConnectionProtocol LOGIN;

            int getId() const {
                return m_id;
            }

            static ConnectionProtocol getById(int t_id) {
                // FIXME: Probably a better way to do this
                // Replace UNKNOWN with std::optional?
                if(t_id == HANDSHAKE.getId()) return HANDSHAKE;
                else if(t_id == PLAY.getId()) return PLAY;
                else if(t_id == STATUS.getId()) return STATUS;
                else if(t_id == LOGIN.getId()) return LOGIN;
                return UNKNOWN;
            }

        private:
            ConnectionProtocol(int t_id) : m_id(t_id) {}

            int m_id;
    };
}