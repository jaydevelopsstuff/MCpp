#include "io/ReadOnlyByteBuffer.h"

#include <iterator>
#include <vector>

IO::ReadOnlyByteBuffer::ReadOnlyByteBuffer(int t_allocation) {
    m_allocation = t_allocation;
    m_buffer = std::vector<u8>(m_allocation);
}

IO::ReadOnlyByteBuffer::ReadOnlyByteBuffer(std::vector<u8> t_buffer) {
    m_allocation = t_buffer.size();
    m_buffer = t_buffer;
}


u8 IO::ReadOnlyByteBuffer::readUByte() {
    m_readerIndex++;
    return m_buffer.at(m_readerIndex - 1);
}

s8 IO::ReadOnlyByteBuffer::readSByte() {
    return (s8)readUByte();
}


u16 IO::ReadOnlyByteBuffer::readUShort() {
    // Big Endian
    return (u16)(readUByte() << 8 | readUByte());
}

s16 IO::ReadOnlyByteBuffer::readSShort() {
    // Big Endian
    return (s16)readUShort();
}


u32 IO::ReadOnlyByteBuffer::readUInt() {
    // Big Endian
    return (u32)(readUByte() << 24 | readUByte() << 16 | readUByte() << 8 | readUByte());
}

s32 IO::ReadOnlyByteBuffer::readSInt() {
    // Big Endian
    return (s32)readUInt();
}


u64 IO::ReadOnlyByteBuffer::readULong() {
    // Big Endian
    u32 num1 = (u32)(readUByte() << 24 | readUByte() << 16 | readUByte() << 8 | readUByte());
    u32 num2 = (u32)(readUByte() << 24 | readUByte() << 16 | readUByte() << 8 | readUByte());

    return (u64)((long)num1 << 32 | num2);
}

s64 IO::ReadOnlyByteBuffer::readSLong() {
    // Big Endian
    return (s64)readULong();
}


IO::ReadOnlyByteBuffer& IO::operator >> (ReadOnlyByteBuffer& byteBuffer, u8& ubyte) {
    ubyte = byteBuffer.readUByte();
    return byteBuffer;
}

IO::ReadOnlyByteBuffer& IO::operator >> (ReadOnlyByteBuffer& byteBuffer, s8& sbyte) {
    sbyte = byteBuffer.readSByte();
    return byteBuffer;
}

IO::ReadOnlyByteBuffer& IO::operator >> (ReadOnlyByteBuffer& byteBuffer, u16& ushort) {
    ushort = byteBuffer.readUShort();
    return byteBuffer;
}

IO::ReadOnlyByteBuffer& IO::operator >> (ReadOnlyByteBuffer& byteBuffer, s16& sshort) {
    sshort = byteBuffer.readSShort();
    return byteBuffer;
}

IO::ReadOnlyByteBuffer& IO::operator >> (ReadOnlyByteBuffer& byteBuffer, u32& uint) {
    uint = byteBuffer.readUInt();
    return byteBuffer;
}

IO::ReadOnlyByteBuffer& IO::operator >> (ReadOnlyByteBuffer& byteBuffer, s32& sint) {
    sint = byteBuffer.readSInt();
    return byteBuffer;
}

IO::ReadOnlyByteBuffer& IO::operator >> (ReadOnlyByteBuffer& byteBuffer, u64& ulong) {
    ulong = byteBuffer.readULong();
    return byteBuffer;
}

IO::ReadOnlyByteBuffer& IO::operator >> (ReadOnlyByteBuffer& byteBuffer, s64& slong) {
    slong = byteBuffer.readSLong();
    return byteBuffer;
}