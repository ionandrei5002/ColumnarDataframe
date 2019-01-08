#include <iostream>
#include <bytebuffer.h>
#include <column.h>

int main(int argc, char const *argv[])
{
    UInt64Column column;
    uint64_t test = 32;
    ByteBuffer buffer(reinterpret_cast<char*>(&test), sizeof(test));
    for (uint64_t i = 0; i < 100'000; i++)
        column.append(buffer);

    std::cout << "column size: " << column.size() << '\n';

    ViewByteBuffer buff = column.read(0);
    std::cout << "value: " << *reinterpret_cast<uint64_t*>(buff._data) << '\n';

    return 0;
}