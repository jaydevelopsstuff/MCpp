#pragma once

#include "network/packet/Packet.h"

namespace Network {
    class CStatusRequestPacket : public Packet {
        public:
            CStatusRequestPacket() {}
            
            CStatusRequestPacket(IO::ReadOnlyByteBuffer buffer) {}

            IO::ReadOnlyByteBuffer serialize() override;

            void deserialize(IO::ReadOnlyByteBuffer buffer) override;
    };
}