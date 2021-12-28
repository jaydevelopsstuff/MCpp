#include "network/packet/status/SPongResponsePacket.h"

#include "io/VariableSizeByteBuffer.h"

IO::ReadOnlyByteBuffer Network::SPongResponsePacket::serialize() {
    IO::VariableSizeByteBuffer writeBuffer;

    writeBuffer << time;

    return writeBuffer.toReadOnly();
}

void Network::SPongResponsePacket::deserialize(IO::ReadOnlyByteBuffer buffer) {
    buffer >> time;
}