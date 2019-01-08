#include <iostream>
#include <bytebuffer.h>
#include <column.h>

int main(int argc, char const *argv[])
{
    std::string str("test");

    ByteBuffer buffer(str.data(), str.size());

    std::cout << buffer << '\n';

    return 0;
}