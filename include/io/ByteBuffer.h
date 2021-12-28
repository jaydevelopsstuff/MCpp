#pragma once

#include <array>
#include <vector>

#include "Types.h"
#include "io/ReadOnlyByteBuffer.h"

namespace IO {
    class ByteBuffer {
        public:
            ByteBuffer(int t_allocation);

            ByteBuffer(std::vector<u8> t_buffer);

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
}