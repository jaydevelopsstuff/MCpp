#pragma once

#include "io/ReadOnlyByteBuffer.h"

namespace Network {
    // Template for PacketListener? eh
    class Packet {
        public:
            virtual IO::ReadOnlyByteBuffer serialize() = 0;
            virtual void deserialize(IO::ReadOnlyByteBuffer buffer) = 0;
    };
}