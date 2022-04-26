#include "doctest.h"
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include <vector>

using namespace coup;
using namespace std;

TEST_CASE("Constructors"){
    CHECK_NOTHROW(Game game{});
    CHECK_NOTHROW(Player player{});
}

TEST_CASE("Individual Functions"){
    // TODO: add all functions
    SUBCASE("Block"){

        SUBCASE("Role Specific Blocks - Legal"){
            CHECK(1==1); // Placeholders
        }
        SUBCASE("Role Specific Blocks - Illegal"){
            CHECK(1==1);
        }
        
        CHECK(1==1);
    }
}

TEST_CASE("Legitimate Game"){

}

TEST_CASE("Game With Bad Actions"){

}

TEST_CASE("Destructors"){
    
}