#include "io/VariableSizeByteBuffer.h"

#include <iterator>
#include <vector>

IO::VariableSizeByteBuffer::VariableSizeByteBuffer() {
    m_buffer = std::vector<u8>(0);
}

IO::VariableSizeByteBuffer::VariableSizeByteBuffer(std::vector<u8> t_buffer) {
    m_buffer = t_buffer;
}


u8 IO::VariableSizeByteBuffer::readUByte() {
    m_readerIndex++;
    return m_buffer.at(m_readerIndex - 1);
}

s8 IO::VariableSizeByteBuffer::readSByte() {
    return (s8)readUByte();
}


u16 IO::VariableSizeByteBuffer::readUShort() {
    // Big Endian
    return (u16)(readUByte() << 8 | readUByte());
}

s16 IO::VariableSizeByteBuffer::readSShort() {
    // Big Endian
    return (s16)readUShort();
}


u32 IO::VariableSizeByteBuffer::readUInt() {
    // Big Endian
    return (u32)(readUByte() << 24 | readUByte() << 16 | readUByte() << 8 | readUByte());
}

s32 IO::VariableSizeByteBuffer::readSInt() {
    // Big Endian
    return (s32)readUInt();
}


u64 IO::VariableSizeByteBuffer::readULong() {
    // Big Endian
    u32 num1 = (u32)(readUByte() << 24 | readUByte() << 16 | readUByte() << 8 | readUByte());
    u32 num2 = (u32)(readUByte() << 24 | readUByte() << 16 | readUByte() << 8 | readUByte());

    return (u64)((long)num1 << 32 | num2);
}

s64 IO::VariableSizeByteBuffer::readSLong() {
    // Big Endian
    return (s64)readULong();
}


void IO::VariableSizeByteBuffer::writeUByte(u8 ubyte) {
    m_buffer.push_back(ubyte);
}

void IO::VariableSizeByteBuffer::writeSByte(s8 sbyte) {
    writeUByte((u8)sbyte);
}


void IO::VariableSizeByteBuffer::writeUShort(u16 ushort) {
    writeUByte((u8)(ushort >> 8));
    writeUByte((u8)ushort);
}

void IO::VariableSizeByteBuffer::writeSShort(s16 sshort) {
    writeUShort((u16)sshort);
}


void IO::VariableSizeByteBuffer::writeUInt(u32 uint) {
    writeUByte((u8)(uint >> 24));
    writeUByte((u8)(uint >> 16));
    writeUByte((u8)(uint >> 8));
    writeUByte((u8)uint);
}

void IO::VariableSizeByteBuffer::writeSInt(s32 sint) {
    writeUInt((u32)sint);
}


void IO::VariableSizeByteBuffer::writeULong(u64 ulong) {
    writeUByte((u8)(ulong >> 56));
    writeUByte((u8)(ulong >> 48));
    writeUByte((u8)(ulong >> 40));
    writeUByte((u8)(ulong >> 32));
    writeUByte((u8)(ulong >> 24));
    writeUByte((u8)(ulong >> 16));
    writeUByte((u8)(ulong >> 8));
    writeUByte((u8)ulong);
}

void IO::VariableSizeByteBuffer::writeSLong(s64 slong) {
    writeULong((u64)slong);
}


IO::VariableSizeByteBuffer& IO::operator >> (VariableSizeByteBuffer& byteBuffer, u8& ubyte) {
    ubyte = byteBuffer.readUByte();
    return byteBuffer;
}

IO::VariableSizeByteBuffer& IO::operator >> (VariableSizeByteBuffer& byteBuffer, s8& sbyte) {
    sbyte = byteBuffer.readSByte();
    return byteBuffer;
}

IO::VariableSizeByteBuffer& IO::operator >> (VariableSizeByteBuffer& byteBuffer, u16& ushort) {
    ushort = byteBuffer.readUShort();
    return byteBuffer;
}

IO::VariableSizeByteBuffer& IO::operator >> (VariableSizeByteBuffer& byteBuffer, s16& sshort) {
    sshort = byteBuffer.readSShort();
    return byteBuffer;
}

IO::VariableSizeByteBuffer& IO::operator >> (VariableSizeByteBuffer& byteBuffer, u32& uint) {
    uint = byteBuffer.readUInt();
    return byteBuffer;
}

IO::VariableSizeByteBuffer& IO::operator >> (VariableSizeByteBuffer& byteBuffer, s32& sint) {
    sint = byteBuffer.readSInt();
    return byteBuffer;
}

IO::VariableSizeByteBuffer& IO::operator >> (VariableSizeByteBuffer& byteBuffer, u64& ulong) {
    ulong = byteBuffer.readULong();
    return byteBuffer;
}

IO::VariableSizeByteBuffer& IO::operator >> (VariableSizeByteBuffer& byteBuffer, s64& slong) {
    slong = byteBuffer.readSLong();
    return byteBuffer;
}


IO::VariableSizeByteBuffer& IO::operator << (VariableSizeByteBuffer& byteBuffer, u8 ubyte) {
    byteBuffer.writeUByte(ubyte);
    return byteBuffer;
}

IO::VariableSizeByteBuffer& IO::operator << (VariableSizeByteBuffer& byteBuffer, s8 sbyte) {
    byteBuffer.writeSByte(sbyte);
    return byteBuffer;
}

IO::VariableSizeByteBuffer& IO::operator << (VariableSizeByteBuffer& byteBuffer, u16 ushort) {
    byteBuffer.writeUShort(ushort);
    return byteBuffer;
}

IO::VariableSizeByteBuffer& IO::operator << (VariableSizeByteBuffer& byteBuffer, s16 sshort) {
    byteBuffer.writeSShort(sshort);
    return byteBuffer;
}

IO::VariableSizeByteBuffer& IO::operator << (VariableSizeByteBuffer& byteBuffer, u32 uint) {
    byteBuffer.writeUInt(uint);
    return byteBuffer;
}

IO::VariableSizeByteBuffer& IO::operator << (VariableSizeByteBuffer& byteBuffer, s32 sint) {
    byteBuffer.writeSInt(sint);
    return byteBuffer;
}

IO::VariableSizeByteBuffer& IO::operator << (VariableSizeByteBuffer& byteBuffer, u64 ulong) {
    byteBuffer.writeULong(ulong);
    return byteBuffer;
}

IO::VariableSizeByteBuffer& IO::operator << (VariableSizeByteBuffer& byteBuffer, s64 slong) {
    byteBuffer.writeSLong(slong);
    return byteBuffer;
}