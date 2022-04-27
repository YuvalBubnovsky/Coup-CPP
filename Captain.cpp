#include <iostream>
#include "Captain.hpp"
#include "Player.hpp"

namespace coup{
    Captain::Captain(Game game, std::string name){
        this->name = name;
        this->game = game;
        this->coins_count = 0;
        this->player_role = "Captain";
    }
    bool Captain::block(Player player){ return false; }
    bool Captain::steal(Player player){ return false; }
}