#ifndef BYTEBUFFER_H
#define BYTEBUFFER_H

#include <memory>
#include <memory.h>
#include <iostream>
#include <string_view>

class ViewByteBuffer;

class ByteBuffer
{
public:
    uint64_t _size = 0;
    char* _data = nullptr;
public:
    ByteBuffer():_size(0),_data(nullptr) {}
    ByteBuffer(const char* data, uint64_t size);
    ByteBuffer(const ByteBuffer& ot);
    ByteBuffer& operator=(const ByteBuffer& ot);
    ByteBuffer(ByteBuffer&& ot);
    ByteBuffer& operator=(ByteBuffer&& ot);
    ByteBuffer(ViewByteBuffer& ot);
    ~ByteBuffer();
    bool operator ==(const ByteBuffer& value);
    bool operator !=(const ByteBuffer& value);
    bool operator <(const ByteBuffer& value);
    bool operator >(const ByteBuffer& value);
    friend std::ostream& operator<<(std::ostream& out, const ByteBuffer& ot);
    friend bool operator<(const ByteBuffer& lv, const ByteBuffer& rv);
};

#endif // BYTEBUFFER_H
