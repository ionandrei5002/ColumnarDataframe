#include <catch2/catch.hpp>

#include <string>
#include <string_view>
#include <column.h>

TEST_CASE( "Column1", "[uint8 operations]" ) 
{
    UInt8Column column;
    uint8_t test = 32;
    ByteBuffer buffer(reinterpret_cast<char*>(&test), sizeof(test));
    column.append(buffer);

    REQUIRE(column.size() == 1);

    buffer = column.read(0);

    REQUIRE(*reinterpret_cast<uint8_t*>(buffer._data) == 32);
}

TEST_CASE( "Column2", "[string operations]" ) 
{
    StringColumn column;
    std::string test = "32";
    ByteBuffer buffer(test.data(), test.size());
    column.append(buffer);

    REQUIRE(column.size() == 1);

    buffer = column.read(0);

    REQUIRE(std::string(buffer._data, buffer._size) == "32");
}