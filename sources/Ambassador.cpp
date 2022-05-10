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
        src.set_coins(src_coins--);
        dest.set_coins(dest_coins++);
        return 1;
    }
    bool Ambassador::block(Player &player)
    {
        if (player.role() != "Captain" || player.get_action().at(0) != "steal")
        {
            throw "Illegal Block!";
        }
        int player_coins1 = player.coins();
        player.set_coins(player_coins1-2);
        int player_coins2 = player.coins();
        if(player_coins2<0){
            player.set_coins(0);
        }
        // TODO: Finish updating 2 coins to the player stolen from
        this->last_action.clear();
        return 1;
    }
}