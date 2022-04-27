#include <iostream>
#include "Player.hpp"

namespace coup{
    bool Player::income(){
        return false;
    }
    bool Player::foreign_aid(){
        return false;
    }
    bool Player::coup(Player){
        return false;
    }
    std::string Player::role(){
        return "a";
    }
    int Player::coins(){
        return 0;
    }
}