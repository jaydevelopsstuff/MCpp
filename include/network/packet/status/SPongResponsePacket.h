#pragma once

#include "network/packet/Packet.h"

namespace Network {
    class SPongResponsePacket : public Packet {
        public:
            s64 time;

            SPongResponsePacket(s64 t_time) : time(t_time) {}

            SPongResponsePacket(IO::ReadOnlyByteBuffer buffer) {
                deserialize(buffer);
            }

            IO::ReadOnlyByteBuffer serialize() override;

            void deserialize(IO::ReadOnlyByteBuffer buffer) override;
    };
}