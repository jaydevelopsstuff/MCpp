#pragma once

#include <array>
#include <vector>

#include "Types.h"

namespace IO {
    class ReadOnlyByteBuffer {
        public:
            ReadOnlyByteBuffer(int t_allocation);

            ReadOnlyByteBuffer(std::vector<u8> t_buffer);

            u8 readUByte();
            s8 readSByte();

            u16 readUShort();
            s16 readSShort();

            u32 readUInt();
            s32 readSInt();

            u64 readULong();
            s64 readSLong();

            // char* readString();
            // std::string readString();

            int getAllocation() const {
                return m_allocation;
            }

            int getReaderIndex() const {
                return m_readerIndex; 
            }

            int getWriterIndex() const {
                return m_writerIndex;
            }

        private:
            std::vector<u8> m_buffer;
            int m_allocation;
            int m_readerIndex;
            int m_writerIndex;
    };

    ReadOnlyByteBuffer& operator >> (ReadOnlyByteBuffer& byteBuffer, u8& ubyte);
    ReadOnlyByteBuffer& operator >> (ReadOnlyByteBuffer& byteBuffer, s8& sbyte);

    ReadOnlyByteBuffer& operator >> (ReadOnlyByteBuffer& byteBuffer, u16& ushort);
    ReadOnlyByteBuffer& operator >> (ReadOnlyByteBuffer& byteBuffer, s16& sshort);

    ReadOnlyByteBuffer& operator >> (ReadOnlyByteBuffer& byteBuffer, u32& uint);
    ReadOnlyByteBuffer& operator >> (ReadOnlyByteBuffer& byteBuffer, s32& sint);

    ReadOnlyByteBuffer& operator >> (ReadOnlyByteBuffer& byteBuffer, u64& ulong);
    ReadOnlyByteBuffer& operator >> (ReadOnlyByteBuffer& byteBuffer, s64& slong);
}