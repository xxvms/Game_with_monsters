//
// Created by tombr on 29/08/2017.
//

#ifndef GAME_GAME_MAP_H
#define GAME_GAME_MAP_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Move_direction.h"
#include "rang.hpp"
#include "Player.h"
#include <random>




class Game_map{
public:
    // variables that will be used to find location of the player on map
    struct  Coordinates  { size_t  x, y; };
private:
    std::vector<std::string> map;
    std::vector<std::string> victory;
    std::random_device random_dev_game;
    std::vector<Coordinates> index_of_all_monsters;
    std::vector<Coordinates> index_player;


public:

    // default constructor printing map
    Game_map();

    // function that will provide me with size of Map for placing objects in random places
    Coordinates size_of_map()const;

    // function that allow to find location of the player on the map, variable i allows to find row and result refers to column
    std::vector<Game_map::Coordinates> find_all(std::string player_type);

    // function that will pick random X and Y for move to be executed if it meets condition
    Coordinates Pick_Random_FreeSpot();

    // function that provides coordinates for new move
    Coordinates next_position(Coordinates from, Move_direction directions);

    // function to validate move
    bool is_valid_move(Game_map::Coordinates to);

    // function to check for victory
    bool is_victory(Game_map::Coordinates to);

    // executing user move after move has been verified and its valid
    void set_position(Coordinates c, char new_value);

    void move_player(Move_direction direction, int steps, bool* end_game, Player& my_Player);

    // function to print map
    void print_base();

    // Function to print message about victory when user gets to X
    void print_victory(bool* end_game);

    // Function that set monster on map
    void set_monster();

    // function that will set monster in random spot on map
    void move_monster();

    // Random value generator
    template <class T>
    T random_value_generator(T x, T y);


};

std::ostream& operator<< (std::ostream& out, const Game_map::Coordinates& coordinates);


#endif //GAME_GAME_MAP_H
