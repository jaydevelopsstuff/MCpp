#include "network/packet/status/CStatusRequestPacket.h"
#include "io/ReadOnlyByteBuffer.h"

IO::ReadOnlyByteBuffer Network::CStatusRequestPacket::serialize() {
    return IO::ReadOnlyByteBuffer(0);
}

void Network::CStatusRequestPacket::deserialize(IO::ReadOnlyByteBuffer buffer) {
    
}