#include "io/ByteBuffer.h"

#include <iterator>
#include <vector>

IO::ByteBuffer::ByteBuffer(int t_allocation) {
    m_allocation = t_allocation;
    m_buffer = std::vector<u8>(m_allocation);
}

IO::ByteBuffer::ByteBuffer(std::vector<u8> t_buffer) {
    m_allocation = t_buffer.size();
    m_buffer = t_buffer;
}


u8 IO::ByteBuffer::readUByte() {
    m_readerIndex++;
    return m_buffer.at(m_readerIndex - 1);
}

s8 IO::ByteBuffer::readSByte() {
    return (s8)readUByte();
}


u16 IO::ByteBuffer::readUShort() {
    // Big Endian
    return (u16)(readUByte() << 8 | readUByte());
}

s16 IO::ByteBuffer::readSShort() {
    // Big Endian
    return (s16)readUShort();
}


u32 IO::ByteBuffer::readUInt() {
    // Big Endian
    return (u32)(readUByte() << 24 | readUByte() << 16 | readUByte() << 8 | readUByte());
}

s32 IO::ByteBuffer::readSInt() {
    // Big Endian
    return (s32)readUInt();
}


u64 IO::ByteBuffer::readULong() {
    // Big Endian
    u32 num1 = (u32)(readUByte() << 24 | readUByte() << 16 | readUByte() << 8 | readUByte());
    u32 num2 = (u32)(readUByte() << 24 | readUByte() << 16 | readUByte() << 8 | readUByte());

    return (u64)((long)num1 << 32 | num2);
}

s64 IO::ByteBuffer::readSLong() {
    // Big Endian
    return (s64)readULong();
}


void IO::ByteBuffer::writeUByte(u8 ubyte) {
    m_buffer.at(m_writerIndex) = ubyte;
}

void IO::ByteBuffer::writeSByte(s8 sbyte) {
    writeUByte((u8)sbyte);
}


void IO::ByteBuffer::writeUShort(u16 ushort) {
    writeUByte((u8)(ushort >> 8));
    writeUByte((u8)ushort);
}

void IO::ByteBuffer::writeSShort(s16 sshort) {
    writeUShort((u16)sshort);
}


void IO::ByteBuffer::writeUInt(u32 uint) {
    writeUByte((u8)(uint >> 24));
    writeUByte((u8)(uint >> 16));
    writeUByte((u8)(uint >> 8));
    writeUByte((u8)uint);
}

void IO::ByteBuffer::writeSInt(s32 sint) {
    writeUInt((u32)sint);
}


void IO::ByteBuffer::writeULong(u64 ulong) {
    writeUByte((u8)(ulong >> 56));
    writeUByte((u8)(ulong >> 48));
    writeUByte((u8)(ulong >> 40));
    writeUByte((u8)(ulong >> 32));
    writeUByte((u8)(ulong >> 24));
    writeUByte((u8)(ulong >> 16));
    writeUByte((u8)(ulong >> 8));
    writeUByte((u8)ulong);
}

void IO::ByteBuffer::writeSLong(s64 slong) {
    writeULong((u64)slong);
}