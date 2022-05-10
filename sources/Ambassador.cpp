#include "Ambassador.hpp"
#include "Player.hpp"

namespace coup
{
    bool Ambassador::transfer(Player &src, Player &dest)
    {
        if (this->game->turn() != this->name)
        {
            throw "This is not your turn!";
        }
        if (src.get_life() == false || dest.get_life() == false)
        {
            throw "One Or More Players Requested Are Dead!";
        }
        if (this->game->game_on == false)
        {
            this->game->game_on = true;
        }
        int src_coins = src.coins();
        int dest_coins = dest.coins();
        if (src_coins == 0)
        {
            throw "Player Has No Coins To Transfer From!";
        }
        src.coins_num--;
        dest.coins_num++;
        this->last_action.clear();
        this->last_action.push_back("transfer");
        this->game->_turn++;
        return 1;
    }
    bool Ambassador::block(Player &player)
    {
        if (player.role() != "Captain" || player.last_action.at(0) != "steal")
        {
            throw "Illegal Block!";
        }
        int player_coins1 = player.coins();
        player.coins_num-=2;
        int player_coins2 = player.coins();
        if (player_coins2 < 0)
        {
            player.coins_num = 0;
        }
        // TODO: Finish updating 2 coins to the player stolen from
        this->last_action.clear();
        this->game->_turn++;

        return 1;
    }
}