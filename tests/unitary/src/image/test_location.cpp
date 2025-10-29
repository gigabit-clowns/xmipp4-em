// SPDX-License-Identifier: GPL-3.0-only

#include <catch2/catch_test_macros.hpp>

#include <xmipp4/em/image/location.hpp>

#include <vector>
#include <string>
#include <sstream>

using namespace xmipp4::image;

TEST_CASE("find contiguous location run", "[image location]")
{
    SECTION("no postion")
    {
        const std::vector<location> data = {
            location("aaaa", location::no_position),
            location("aaaa", location::no_position),
            location("bbbbb", location::no_position),
        };

        REQUIRE( std::distance(data.begin(), find_contiguous_location_run(data.begin(), data.end())) == 1 );
    }

    SECTION("position jump")
    {
        const std::vector<location> data = {
            location("aaaa", 1),
            location("aaaa", 2),
            location("aaaa", 3),
            location("aaaa", 4),
            location("aaaa", 6),
        };

        REQUIRE( std::distance(data.begin(), find_contiguous_location_run(data.begin(), data.end())) == 4 );
    }
    
    SECTION("different file")
    {
        const std::vector<location> data = {
            location("aaaa", 1),
            location("aaaa", 2),
            location("aaaa", 3),
            location("bbbb", 4),
        };

        REQUIRE( std::distance(data.begin(), find_contiguous_location_run(data.begin(), data.end())) == 3 );
    }

    SECTION("fully contiguous")
    {
        const std::vector<location> data = {
            location("aaaa", 12),
            location("aaaa", 13),
            location("aaaa", 14),
            location("aaaa", 15),
            location("aaaa", 16),
            location("aaaa", 17),
        };

        REQUIRE( std::distance(data.begin(), find_contiguous_location_run(data.begin(), data.end())) == 6 );
    }
}

TEST_CASE("parse image location", "[image location]")
{
    SECTION("without position")
    {
        const std::string path = "/home/xmipp4/image.mrc";

        location loc;
        REQUIRE( parse_location(path, loc) );
        REQUIRE( loc.get_filename() == path );
        REQUIRE( loc.get_position() == location::no_position );
    }

    SECTION("with position")
    {
        const std::string path = "1234@/home/xmipp4/image.mrc";

        location loc;
        REQUIRE( parse_location(path, loc) );
        REQUIRE( loc.get_filename() == "/home/xmipp4/image.mrc" );
        REQUIRE( loc.get_position() == 1234 );
    }

    SECTION("with invalid position")
    {
        const std::string path = "1234a@/home/xmipp4/image.mrc";

        location loc("previous/filename", 987);
        REQUIRE( !parse_location(path, loc) );
        REQUIRE( loc.get_filename() == "previous/filename" );
        REQUIRE( loc.get_position() == 987 );
    }
}

TEST_CASE("image location to ostream", "[image location]")
{
    std::ostringstream oss;

    SECTION("without position")
    {
        oss << location("example/location", location::no_position);
        REQUIRE( oss.str() == "example/location" );
    }

    SECTION("with position")
    {
        oss << location("example/location", 1234);
        REQUIRE( oss.str() == "1234@example/location" );
    }
}
