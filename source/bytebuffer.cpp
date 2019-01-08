#include "bytebuffer.h"

ByteBuffer::ByteBuffer(const char* data, uint64_t size):_size(size),_data(const_cast<char*>(data)){}

ByteBuffer::ByteBuffer(const ByteBuffer& ot)
{
    _size = ot._size;
    _data = ot._data;
}

ByteBuffer& ByteBuffer::operator=(const ByteBuffer& ot)
{
    _size = ot._size;
    _data = ot._data;
    return *this;
}

ByteBuffer::ByteBuffer(ByteBuffer&& ot)
{
    _size = ot._size;
    _data = ot._data;
    ot._data = nullptr;
}

ByteBuffer& ByteBuffer::operator=(ByteBuffer&& ot)
{
    _size = ot._size;
    _data = ot._data;
    ot._data = nullptr;
    return *this;
}

ByteBuffer::~ByteBuffer()
{
    _data = nullptr;
    _size = 0;
}

bool operator<(const ByteBuffer& lv, const ByteBuffer& rv)
{
    return std::string_view(lv._data, lv._size) < std::string_view(rv._data, rv._size);
}

bool ByteBuffer::operator ==(const ByteBuffer& value)
{
    return std::string_view(this->_data, this->_size) == std::string_view(value._data, value._size);
}

bool ByteBuffer::operator !=(const ByteBuffer& value)
{
    return std::string_view(this->_data, this->_size) != std::string_view(value._data, value._size);
}

bool ByteBuffer::operator <(const ByteBuffer& value)
{
    return std::string_view(this->_data, this->_size) < std::string_view(value._data, value._size);
}

bool ByteBuffer::operator >(const ByteBuffer& value)
{
    return std::string_view(this->_data, this->_size) > std::string_view(value._data, value._size);
}

std::ostream& operator<<(std::ostream& out, const ByteBuffer& ot)
{
    for(uint64_t i = 0; i < ot._size; ++i)
    {
        out << ot._data[i];
    }

    return out;
}

