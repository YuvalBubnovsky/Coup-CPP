
#include "Duke.hpp"
#include "Player.hpp"

namespace coup
{
    bool Duke::tax()
    {
        if (this->coins() >= MAX_COINS)
        {
            throw "Already Over Maximum Number Of Coins!";
        }
        if (this->game->turn() != this->name)
        {
            throw "This is not your turn!";
        }
        if (this->game->game_on == false && this->game->player_count == 1)
        {
            throw "One Player Left";
        }
        if (this->game->game_on == false)
        {
            this->game->game_on = true;
        }
        int curr_coins = this->coins();
        this->coins_num += 3;
        this->last_action.clear();
        this->last_action.push_back("tax");
        this->game->_turn++;
        return 1;
    }
    bool Duke::block(Player &player)
    {
        if (player.get_action().at(0) != "foreign aid" && player.get_action().at(0) != "specialcoup") // TODO: hard coded fix, can cause trouble
        {
            throw "Illegal Block!";
        }
        int curr_coins = player.coins();
        player.coins_num -= 2;
        return 1;
    }
}