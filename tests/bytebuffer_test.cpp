#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <string>
#include <string_view>
#include <bytebuffer.h>

TEST_CASE( "ByteBuffer", "[basic operations]" ) 
{
    std::string test("test");
    ByteBuffer buffer(test.data(), test.size());
    REQUIRE(test.size() == buffer._size); 
    REQUIRE(std::string_view(buffer._data, buffer._size) == test);
}