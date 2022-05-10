#pragma once
#include <iostream>
#include <string>
#include "Game.hpp"

using std::string;
using std::to_string;
using std::vector;

#define MAX_PLAYERS 6
#define MAX_COINS 10
#define COUP_COINS 7

namespace coup
{
    class Game;
    class Player
    {
    protected:
        Game *game;
        string name;
        int id;

    public:
        Player(Game *game, string name, string role);
        ~Player();
        int coins_num;
        bool is_alive;
        string _role;
        vector<string> last_action;
        bool income();
        bool foreign_aid();
        virtual bool coup(Player &target);
        string role();
        int coins();
        bool set_coins(int coins);
        bool set_life(bool status);
        bool get_life();
        string get_name();
        bool set_id(size_t id);
        int get_id();
        vector<string> get_action();
    };
}