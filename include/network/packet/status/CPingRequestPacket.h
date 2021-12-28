#pragma once

#include "Types.h"
#include "io/ReadOnlyByteBuffer.h"
#include "network/packet/Packet.h"

namespace Network {
    class CPingRequestPacket : public Packet {
        public:
            s64 time;

            CPingRequestPacket(IO::ReadOnlyByteBuffer buffer) {
                deserialize(buffer);
            }

            CPingRequestPacket(s32 t_time) : time(t_time) {}

            IO::ReadOnlyByteBuffer serialize() override;

            void deserialize(IO::ReadOnlyByteBuffer buffer) override;
    };
}