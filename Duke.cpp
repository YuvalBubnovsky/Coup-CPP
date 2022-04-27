#include <iostream>
#include "Duke.hpp"
#include "Player.hpp"

namespace coup{
    Duke::Duke(Game game, std::string name){
        this->name = name;
        this->game = game;
        this->coins_count = 0;
        this->player_role = "Duke";
    }
    bool Duke::tax(){ return false;}
    bool Duke::block(Player player){ return false; }
}