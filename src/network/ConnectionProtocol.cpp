#include "network/ConnectionProtocol.h"

const Network::ConnectionProtocol Network::ConnectionProtocol::UNKNOWN = ConnectionProtocol(-2147483647);
const Network::ConnectionProtocol Network::ConnectionProtocol::HANDSHAKE = ConnectionProtocol(-1);
const Network::ConnectionProtocol Network::ConnectionProtocol::PLAY = ConnectionProtocol(0);
const Network::ConnectionProtocol Network::ConnectionProtocol::STATUS = ConnectionProtocol(1);
const Network::ConnectionProtocol Network::ConnectionProtocol::LOGIN = ConnectionProtocol(2);