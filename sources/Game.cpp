#include "Game.hpp"
#include "Player.hpp"

namespace coup
{

    Game::Game()
    {
        this->players_obj_list.clear();
        this->players_list.clear();
        this->game_on = false;
        this->player_count = 0;
        this->_turn = 0;
        this->sequence = -1;
    }

    Game::~Game() {}

    bool Game::add_player(Player *player)
    {
        this->players_list.push_back(player->get_name());
        this->players_obj_list.push_back(player);
        this->set_player_count(players_list.size());
        int num = this->get_sequence();
        this->set_sequence(num++);
        return true;
    }

   /* bool Game::remove_player(Player *player)
    {
        player->is_alive = false;
        // TODO: fix/update player removal
        // this->players_list.erase(this->players_list.begin(),this->players_list.begin()+(player->get_id()%this->players_list.size()));
       // this->players_list = this->players();
      //  this->set_player_count(players_list.size());
        return true;
    }*/

    Player *Game::get_player(size_t _id)
    {
        for (Player *player : this->players_obj_list)
        {
            if (player->get_id() == _id)
            {
                return player;
            }
        }
        return NULL;
    }

   /* bool Game::revive_player(Player* player){
        player->is_alive=true;
        return true;
    }*/

    bool Game::set_sequence(int num)
    {
        this->sequence = num;
        return true;
    }

    int Game::get_sequence() const
    {
        return this->sequence;
    }

    bool Game::set_player_count(int _count)
    {
        this->player_count = _count;
        return true;
    }

    int Game::get_player_count() const
    {
        return this->player_count;
    }
    string Game::turn()
    {
        size_t player_at = (size_t)(this->_turn % (int)this->players_obj_list.size());
        while (true)
        {
            if (this->players_obj_list.at(player_at)->get_life())
            {

                return this->players_obj_list.at(player_at)->get_name();
            }

            _turn++; /*skip dead people*/
            player_at = (size_t)(this->_turn % (int)players_obj_list.size());
        }
       // return this->players_obj_list.at(static_cast<size_t>(this->_turn) % static_cast<size_t>(this->get_player_count()))->get_name();
    }
    vector<string> Game::players()
    {
        vector<string> updated_list;
        for (Player *player : this->players_obj_list)
        {
            if (player->get_life())
            {
                updated_list.push_back(player->get_name());
            }
        }
        return updated_list;
    }
    string Game::winner()
    {
        this->players_list = players();
        if (!this->game_on)
        {
            throw "Game Hasn't Started Yet!";
        }
        if (this->players_list.size() != 1)
        {
            throw "Game Didn't Finish Yet!";
        }
            return this->players_list.at(0);
    }

}