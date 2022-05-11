#include "Captain.hpp"
#include "Player.hpp"

namespace coup
{
    bool Captain::block(Player &player)
    {
        if (player.role() != "Captain" || player.last_action.at(0) != "steal")
        {
            throw "Illegal Block!";
        }
      // TODO:  Player* target = this->game->get_player(static_cast<size_t>(stoi(this->last_action.at(2))));
        int coins_stolen = stoi(this->last_action.at(1));
        if (coins_stolen == 1){
            this->coins_num--;
            player.coins_num++;
        } else if (coins_stolen == 2){
            this->coins_num-=2;
            player.coins_num+=2;
        }
        return true;
    }

    bool Captain::steal(Player &player)
    {
        if (this->game->turn() != this->get_name())
        {
            throw "Not Your Turn!";
        }
        if (!player.get_life())
        {
            throw "Can't Steal - Player Is Dead!";
        }
        if (!this->game->game_on)
        {
            this->game->game_on = true;
        }
        int player_coins = player.coins();
        switch (player_coins)
        {
        case 0:
            this->last_action.clear();
            this->last_action.push_back("steal");
            this->last_action.push_back("0");
            this->last_action.push_back(to_string(player.get_id()));
            this->game->_turn++;
            return true;

        case 1:
            this->last_action.clear();
            this->last_action.push_back("steal");
            this->last_action.push_back("1");
            this->last_action.push_back(to_string(player.get_id()));
            this->coins_num++;
            player.coins_num--;
            this->game->_turn++;
            return true;

        case 2:
            this->last_action.clear();
            this->last_action.push_back("steal");
            this->last_action.push_back("2");
            this->last_action.push_back(to_string(player.get_id()));
            this->coins_num+=2;
            player.coins_num-=2;
            this->game->_turn++;
            return true;
        
        default:
            return true;
        }
    }
}