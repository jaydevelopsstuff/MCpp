#include "network/packet/status/CPingRequestPacket.h"

#include "io/VariableSizeByteBuffer.h"

IO::ReadOnlyByteBuffer Network::CPingRequestPacket::serialize() {
    IO::VariableSizeByteBuffer writeBuffer;

    writeBuffer << time;

    return writeBuffer.toReadOnly();
}

void Network::CPingRequestPacket::deserialize(IO::ReadOnlyByteBuffer buffer) {
    buffer >> time;
}