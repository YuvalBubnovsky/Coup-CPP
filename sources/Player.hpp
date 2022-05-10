#pragma once
#include <iostream>
#include <string>
#include "Game.hpp"

using std::string;
using std::vector;
using std::to_string;

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
        string _role;
        vector<string> last_action;
        int coins_num;
        bool is_alive;
        size_t id;

    public:
        Player(Game *game, string name, string role);
        ~Player();
        bool income();
        bool foreign_aid();
        virtual bool coup(Player &target);
        string role();
        int coins();
        bool set_coins(int coins);
        bool set_life(bool status);
        bool get_life();
        string get_name();
        bool set_id(int id);
        size_t get_id();
        vector<string> get_action();
    };
}