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

TEST_CASE("Constructors")
{
    CHECK_NOTHROW(Game game_1{});
    CHECK_NOTHROW(Player player{});
}

TEST_CASE("Individual Functions")
{

    Game game_1{};

    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    CHECK_NOTHROW(contessa.block(assassin));
    CHECK_NOTHROW(duke.tax());
    CHECK_NOTHROW(assassin.coup(duke));
    CHECK_NOTHROW(ambassador.transfer(contessa, duke));
    CHECK_NOTHROW(captain.steal(duke));
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(captain.income());
    for (int i = 0; i < 100; i++)
    {
        CHECK_NOTHROW(duke.income());
    }
}

TEST_CASE("Legitimate Game")
{
    Game game_1{};

    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(contessa.income());
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(duke.block(assassin));
    for (int i = 0; i < 100; i++)
    {
        CHECK_NOTHROW(captain.income());
    }
}

TEST_CASE("Game With Bad Actions")
{
    Game game_1{};

    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(contessa.income());
    CHECK_THROWS(assassin.income());
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_THROWS(captain.block(duke));
    CHECK_THROWS(contessa.block(assassin));
    CHECK_NOTHROW(duke.block(assassin));
    for (int i = 0; i < 100; i++)
    {
        CHECK_NOTHROW(contessa.income());
    }
}
