#include <catch2/catch.hpp>

#include <string>
#include <string_view>
#include <column.h>

TEST_CASE( "Column") 
{
    SECTION("uint8") 
    {
        UInt8Column column;
        uint8_t test = 32;
        ByteBuffer buffer(reinterpret_cast<char*>(&test), sizeof(test));
        column.append(buffer);

        REQUIRE(column.size() == 1);

        ViewByteBuffer buff = column.read(0);

        REQUIRE(*reinterpret_cast<uint8_t*>(buff._data) == 32);
    }

    SECTION("uint16") 
    {
        UInt16Column column;
        uint16_t test = 32;
        ByteBuffer buffer(reinterpret_cast<char*>(&test), sizeof(test));
        column.append(buffer);

        REQUIRE(column.size() == 1);

        ViewByteBuffer buff = column.read(0);

        REQUIRE(*reinterpret_cast<uint16_t*>(buff._data) == 32);
    }

    SECTION("uint32") 
    {
        UInt32Column column;
        uint32_t test = 32;
        ByteBuffer buffer(reinterpret_cast<char*>(&test), sizeof(test));
        column.append(buffer);

        REQUIRE(column.size() == 1);

        ViewByteBuffer buff = column.read(0);

        REQUIRE(*reinterpret_cast<uint32_t*>(buff._data) == 32);
    }

    SECTION("uint64") 
    {
        UInt64Column column;
        uint64_t test = 32;
        ByteBuffer buffer(reinterpret_cast<char*>(&test), sizeof(test));
        column.append(buffer);

        REQUIRE(column.size() == 1);

        ViewByteBuffer buff = column.read(0);

        REQUIRE(*reinterpret_cast<uint64_t*>(buff._data) == 32);
    }

    SECTION("string")
    {
        StringColumn column;
        std::string test = "32";
        ByteBuffer buffer(test.data(), test.size());
        column.append(buffer);

        REQUIRE(column.size() == 1);

        ViewByteBuffer buff = column.read(0);

        REQUIRE(std::string(buff._data, buff._size) == "32");
    }
}