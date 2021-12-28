#pragma once

#include "io/ReadOnlyByteBuffer.h"
#include "network/packet/Packet.h"
#include "Types.h"
#include "network/ConnectionProtocol.h"

namespace Network {
    class CIntentionPacket : public Packet {
        public:
            s32 protocolVersion;
            char* hostname;
            s32 port;
            ConnectionProtocol intention;

            CIntentionPacket(s32 t_protocolVersion, char* t_hostname, s32 t_port, ConnectionProtocol t_intention) : protocolVersion(t_protocolVersion), hostname(t_hostname), port(t_port), intention(t_intention) {}

            IO::ReadOnlyByteBuffer serialize() override;

            void deserialize(IO::ReadOnlyByteBuffer buffer) override;
    };
}