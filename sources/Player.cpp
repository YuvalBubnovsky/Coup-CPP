#include "Player.hpp"

using std::move;

namespace coup
{
    Player::Player(Game *game, string name, string role)
    {
        if (game->game_on)
        {
            throw "Can't Join, Game Already Started!";
        }
        if (game->get_player_count() == MAX_PLAYERS)
        {
            throw "Can't Join, Max Players Reached!";
        }
        this->name = move(name);
        this->_role = move(role);
        this->game = game;
        this->set_coins(0);
        this->set_life(true);
        this->game->add_player(this);
        set_id(static_cast<size_t>(this->game->get_sequence()));
    }

    Player::~Player() {}

    string Player::role()
    {
        return this->_role;
    }
    bool Player::set_coins(int coins)
    {
        this->coins_num = coins;
        return 1;
    }

    bool Player::set_life(bool status)
    {
        this->is_alive = status;
        return 1;
    }

    bool Player::get_life()
    {
        return this->is_alive;
    }

    string Player::get_name()
    {
        return this->name;
    }

    bool Player::set_id(size_t id)
    {
        this->id = id;
        return 1;
    }

    int Player::get_id()
    {
        return this->id;
    }

    bool Player::income()
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
        this->coins_num++;
        this->get_action().clear();
        this->get_action().push_back("income");
        this->game->_turn++;
        return 1;
    }
    bool Player::foreign_aid()
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
        int new_coins = this->coins();
        if (new_coins == 9)
        {
            this->coins_num = 10;
            this->get_action().clear();
            this->get_action().push_back("foreign aid");
            return 1;
        }
        this->coins_num += 2;
        this->get_action().clear();
        this->get_action().push_back("foreign aid");
        this->game->_turn++;

        return 1;
    }
    bool Player::coup(Player &target)
    {
        if (this->game->turn() != this->name)
        {
            throw "This is not your turn!";
        }
        if (this->coins() < COUP_COINS)
        {
            throw "Not Enough Coins For Coup!";
        }
        if (target.get_life() == false)
        {
            throw "Target Is Already Dead!";
        }
        this->coins_num -= COUP_COINS;
        this->game->remove_player(&target);
        this->get_action().push_back("coup");
        this->get_action().push_back(to_string(this->get_id())); // TODO: is this needed?
        this->game->_turn++;
        return 1;
    }
    int Player::coins()
    {
        return this->coins_num;
    }

    vector<string> Player::get_action()
    {
        return this->last_action;
    }
}