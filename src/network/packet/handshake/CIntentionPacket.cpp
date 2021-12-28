#include "network/packet/handshake/CIntentionPacket.h"

#include "io/ReadOnlyByteBuffer.h"
#include "io/VariableSizeByteBuffer.h"
#include "network/ConnectionProtocol.h"

IO::ReadOnlyByteBuffer Network::CIntentionPacket::serialize() {
    IO::VariableSizeByteBuffer writeBuffer;

    writeBuffer << protocolVersion;
    // writeBuffer << hostname;
    writeBuffer << port;
    writeBuffer << intention.getId();

    return writeBuffer.toReadOnly();
}

void Network::CIntentionPacket::deserialize(IO::ReadOnlyByteBuffer buffer) {
    buffer >> protocolVersion;
    // buffer >> hostname;
    buffer >> port;
    intention = ConnectionProtocol::getById(buffer.readSInt());
}