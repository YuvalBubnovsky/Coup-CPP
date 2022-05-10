#include "Assassin.hpp"
#include "Player.hpp"

namespace coup
{
    bool Assassin::coup(Player &target)
    {
        if (this->game->turn() != this->name)
        {
            throw "This is not your turn!";
        }
        if (this->coins() < A_COUP_COST)
        {
            throw "Not Enough Coins For Coup!";
        }
        if (target.get_life() == false)
        {
            throw "Target Is Already Dead!";
        }
        if (this->coins() >= COUP_COINS)
        {
            Player::coup(target);
            return 1;
        }
        int new_coins = this->coins();
        this->set_coins(new_coins - A_COUP_COST);
        this->game->remove_player(&target);
        this->last_action.clear();
        this->last_action.push_back("special coup");
        this->last_action.push_back(to_string(target.get_id()));
        this->game->_turn++;
    }
}