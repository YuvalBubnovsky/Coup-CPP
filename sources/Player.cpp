#include "Player.hpp"

using std::move;

namespace coup
{
    Player::Player(Game *game, string name, string role)
    {
        if (game->game_on)
        {
            throw logic_error("Can't Join, Game Already Started!");
        }
        if (game->players().size() == MAX_PLAYERS)
        {
            throw logic_error("Can't Join, Max Players Reached!");
        }
        this->name = move(name);
        this->_role = move(role);
        this->game = game;
        //this->set_coins(0);
        this->coins_num=0;
        this->is_alive=true;
       // this->set_life(true);
        this->game->add_player(this);
       // set_id(static_cast<size_t>(this->game->get_sequence()));
        this->id=static_cast<size_t>(this->game->get_sequence());
    }

    Player::~Player() {}

    string Player::role() const
    {
        return this->_role;
    }
    bool Player::set_coins(int coins)
    {
        this->coins_num = coins;
        return true;
    }

    bool Player::set_life(bool status)
    {
        this->is_alive = status;
        return true;
    }

    bool Player::get_life() const
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
        return true;
    }

    int Player::get_id() const
    {
        return this->id;
    }

    bool Player::income()
    {
        if (this->coins() >= MAX_COINS)
        {
            throw logic_error("Already Over Maximum Number Of Coins!");
        }
        if (this->game->turn() != this->name)
        {
            throw logic_error("This is not your turn!");
        }
        if (!this->game->game_on && this->game->player_count == 1)
        {
            throw logic_error("One Player Left");
        }
        if (!this->game->game_on)
        {
            this->game->game_on = true;
        }
        this->coins_num++;
        this->get_action().clear();
        this->get_action().push_back("income");
        this->game->_turn++;
        return true;
    }
    bool Player::foreign_aid()
    {
        if (this->coins() >= MAX_COINS)
        {
            throw logic_error("Already Over Maximum Number Of Coins!");
        }
        if (this->game->turn() != this->name)
        {
            throw logic_error("This is not your turn!");
        }
        if (!this->game->game_on && this->game->player_count == 1)
        {
            throw logic_error("One Player Left");
        }
        if (!this->game->game_on)
        {
            this->game->game_on = true;
        }
        this->coins_num += 2;
        this->get_action().clear();
        this->get_action().push_back("foreign aid");
        this->game->_turn++;

        return true;
    }
    bool Player::coup(Player &target)
    {
        if (this->game->turn() != this->name)
        {
            throw logic_error("This is not your turn!");
        }
        if (this->coins() < COUP_COINS)
        {
            throw logic_error("Not Enough Coins For Coup!");
        }
        if (!target.get_life())
        {
            throw logic_error("Target Is Already Dead!");
        }
        this->coins_num -= COUP_COINS;
        target.is_alive=false;
        this->get_action().push_back("coup");
        this->get_action().push_back(to_string(this->get_id())); // TODO: is this needed?
        this->game->_turn++;
        return true;
    }
    int Player::coins() const
    {
        return this->coins_num;
    }

    vector<string> Player::get_action() const
    {
        return this->last_action;
    }
}