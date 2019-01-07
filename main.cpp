#include <iostream>
#include <bytebuffer.h>

int main(int argc, char const *argv[])
{
    std::string str("test");

    ByteBuffer buffer(str.size(), str.data());

    std::cout << buffer << '\n';

    return 0;
}