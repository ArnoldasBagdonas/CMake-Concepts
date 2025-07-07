#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <string>

SCENARIO( "vector can be sized and resized" ) {
    GIVEN( "An empty vector" ) {
        auto v = std::vector<std::string>{};

        // Validate assumption of the GIVEN clause
        THEN( "The size and capacity are 0" ) {
            REQUIRE( v.size() == 0 );
            REQUIRE( v.capacity() == 0 );
        }

        // Validate one use case for the GIVEN objects
        WHEN( "push_back() is called" ) {
            v.push_back("hullo");

            THEN( "The size changes" ) {
                REQUIRE( v.size() == 1 );
                REQUIRE( v.capacity() >= 1 );
            }

            // This clause depends on the success of the outer WHEN() clause
            AND_WHEN( "element is removed" ) {
                v.erase(v.begin());

                THEN( "The size is zero" ) {
                    REQUIRE( v.size() == 0 );

                    // If you find yourself writing "and" in your THEN() text,
                    // consider using AND_THEN() instead.
                    AND_THEN( "capacity does not change") {
                        REQUIRE( v.capacity() >= 1 );
                    }
                }
            }

            // Validate a case dependent on the containing WHEN clause
            AND_GIVEN( "A movable object" ) {
                auto s = std::string{"world"};

                WHEN( "pushed" ) {
                    v.push_back( std::move(s) );

                    THEN( "The size changes" ) {
                        REQUIRE( v.size() == 2 );
                        REQUIRE( v.capacity() >= 2 );

                        AND_THEN("The values are in order") {
                            // Intentional test failure to demonstrate output
                            CHECK( v[0] == "world" );
                            CHECK( v[1] == "hullo" );
                        }
                    }
                }
            }
        }

        // Validate another use case for the GIVEN objects
        WHEN( "emplace_back() is called" ) {
            v.emplace_back("hullo");

            THEN( "The size changes" ) {
                REQUIRE( v.size() == 1 );
                REQUIRE( v.capacity() >= 1 );
            }
        }
    }
}