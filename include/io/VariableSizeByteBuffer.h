#pragma once

#include <vector>

#include "Types.h"
#include "io/ReadOnlyByteBuffer.h"

namespace IO {
    class VariableSizeByteBuffer {
        public:
            VariableSizeByteBuffer();

            VariableSizeByteBuffer(std::vector<u8> t_buffer);

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

            void writeUByte(u8 ubyte);
            void writeSByte(s8 sbyte);

            void writeUShort(u16 ushort);
            void writeSShort(s16 sshort);

            void writeUInt(u32 uint);
            void writeSInt(s32 sint);

            void writeULong(u64 ulong);
            void writeSLong(s64 slong);

            // void writeString(char* string);
            // void writeString(std::string string);

            ReadOnlyByteBuffer toReadOnly() {
                return ReadOnlyByteBuffer(m_buffer);
            }

            std::vector<u8> getBuffer() const {
                return m_buffer;
            }

            int getSize() const {
                return m_buffer.size();
            }

            int getReaderIndex() const {
                return m_readerIndex; 
            }

            int getWriterIndex() const {
                return getSize() + 1;
            }

        private:
            std::vector<u8> m_buffer;
            int m_readerIndex;
    };

    VariableSizeByteBuffer& operator >> (VariableSizeByteBuffer& byteBuffer, u8& ubyte);
    VariableSizeByteBuffer& operator >> (VariableSizeByteBuffer& byteBuffer, s8& sbyte);

    VariableSizeByteBuffer& operator >> (VariableSizeByteBuffer& byteBuffer, u16& ushort);
    VariableSizeByteBuffer& operator >> (VariableSizeByteBuffer& byteBuffer, s16& sshort);

    VariableSizeByteBuffer& operator >> (VariableSizeByteBuffer& byteBuffer, u32& uint);
    VariableSizeByteBuffer& operator >> (VariableSizeByteBuffer& byteBuffer, s32& sint);

    VariableSizeByteBuffer& operator >> (VariableSizeByteBuffer& byteBuffer, u64& ulong);
    VariableSizeByteBuffer& operator >> (VariableSizeByteBuffer& byteBuffer, s64& slong);


    VariableSizeByteBuffer& operator << (VariableSizeByteBuffer& byteBuffer, u8 ubyte);
    VariableSizeByteBuffer& operator << (VariableSizeByteBuffer& byteBuffer, s8 sbyte);

    VariableSizeByteBuffer& operator << (VariableSizeByteBuffer& byteBuffer, u16 ushort);
    VariableSizeByteBuffer& operator << (VariableSizeByteBuffer& byteBuffer, s16 sshort);

    VariableSizeByteBuffer& operator << (VariableSizeByteBuffer& byteBuffer, u32 uint);
    VariableSizeByteBuffer& operator << (VariableSizeByteBuffer& byteBuffer, s32 sint);

    VariableSizeByteBuffer& operator << (VariableSizeByteBuffer& byteBuffer, u64 ulong);
    VariableSizeByteBuffer& operator << (VariableSizeByteBuffer& byteBuffer, s64 slong);
}