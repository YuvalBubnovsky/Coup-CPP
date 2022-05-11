
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
        if (!this->game->game_on && this->game->player_count == 1)
        {
            throw "One Player Left";
        }
        if (!this->game->game_on)
        {
            this->game->game_on = true;
        }
        this->coins_num += 3;
        this->last_action.clear();
        this->last_action.push_back("tax");
        this->game->_turn++;
        return true;
    }
    bool Duke::block(Player &player)
    {
        if (player.last_action.at(0) != "foreign aid")
        {
            throw logic_error("Illegal Block!");
        }
      //  int curr_coins = player.coins();
        player.coins_num -= 2;
        return true;
    }
}