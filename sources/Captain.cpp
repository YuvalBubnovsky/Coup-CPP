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
        Player* target = this->game->get_player(static_cast<size_t>(stoi(this->last_action.at(2))));
        int captain_coins = this->coins();
        int target_coins = target->coins();
        int coins_stolen = stoi(this->last_action.at(1));
        if (coins_stolen == 1){
            this->coins_num--;
            player.coins_num++;
            return 1;
        } else if (coins_stolen == 2){
            this->coins_num-=2;
            player.coins_num+=2;
            return 1;
        }
        return 1;
    }

    bool Captain::steal(Player &player)
    {
        if (this->game->turn() != this->get_name())
        {
            throw "Not Your Turn!";
        }
        if (player.get_life() == false)
        {
            throw "Can't Steal - Player Is Dead!";
        }
        if (this->game->game_on == false)
        {
            this->game->game_on = true;
        }
        int player_coins = player.coins();
        int captain_coins = this->coins();
        switch (player.coins_num)
        {
        case 0:
            this->last_action.clear();
            this->last_action.push_back("steal");
            this->last_action.push_back("0");
            this->last_action.push_back(to_string(player.get_id()));
            this->game->_turn++;
            return 1;

        case 1:
            this->last_action.clear();
            this->last_action.push_back("steal");
            this->last_action.push_back("1");
            this->last_action.push_back(to_string(player.get_id()));
            this->coins_num++;
            player.coins_num--;
            this->game->_turn++;
            return 1;

        case 2:
            this->last_action.clear();
            this->last_action.push_back("steal");
            this->last_action.push_back("2");
            this->last_action.push_back(to_string(player.get_id()));
            this->coins_num+=2;
            player.coins_num-=2;
            this->game->_turn++;
            return 1;

        default:
            this->last_action.clear();
            this->last_action.push_back("steal");
            this->last_action.push_back("2");
            this->last_action.push_back(to_string(player.get_id()));
            this->coins_num+=2;
            player.coins_num-=2;
            this->game->_turn++;
            return 1;
        }
    }
}