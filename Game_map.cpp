//
// Created by tombr on 29/08/2017.
//

#include "Game_map.h"

Game_map::Game_map()  {
    map = {
            "=======================================================================================================",
            "|     ###         ~~ ~~                                ###########                                    |",
            "|                  ~     ###########    ###########                                    ####           |",
            "|    ######             ###########   #############        #        #######        #########          |",
            "|   ########             ###########    ###########        ###         #######        ######          |",
            "|   ####                    #####         #######        ######          #######                      |",
            "|                   #####                   ###                            ########     #######       |",
            "|      ####         ######    ~~~~~~                ########    ######        ######       ######     |",
            "|   #########    #######       ~~~~      ########             ##########                      #####   |",
            "|   #########       #######  ~~~     #########            ########           ~~~~~            ######  |",
            "|     #####         #######                          #####               ###   ~~~~~~~                |",
            "|                   ############        ########              ########              ##########        |",
            "|########             #############    ######                 ########       #####                    |",
            "|########                             ####       ######          #########           ######           |",
            "|                ######               ###      ######             #######               ######        |",
            "|   #########            ########            #############                                            |",
            "|   #########             ########                  #####    #############                #####       |",
            "|   #########                 ######                       #######                   #####            |",
            "|                    #######   #########          ######                #########                     |",
            "|############                                 ############              #####                         |",
            "|############                 ##############                ######                       #####        |",
            "|              ~~~   ~~~      ##############                ######                                    |",
            "|               ~~~~~~        ##############                ######            ~~~~~   ~~~~            |",
            "|            ~~~~~   ~~~      ##############                ######              ~~~~~~                |",
            "|                                                           ######                                    |",
            "=======================================================================================================",
    };

    victory = {
            "=========================================================================================================",
            "*           Congratulations the mighty warrior you have managed to escape from the dungeons!            *",
            "=========================================================================================================",

    };
}

rang::fg get_color_for(char c){
    switch (c){
        case 'X':
            return rang::fg::red;
        case '*':
            return rang::fg::green;
        case '#':
            return rang::fg::green;
        case '@':
            return rang::fg::magenta;
        case '.':
            return rang::fg::magenta;
        case '=':
            return rang::fg::green;
        case '|':
            return rang::fg::green;
        case '~':
            return rang::fg::blue;
        case '%':
            return rang::fg::red;
        default:
            return rang::fg::reset;
    }
}


void Game_map::print_base(){
    for (auto& line : map){
        for(auto& c : line) {
            std::cout << rang::style::dim << rang::bg::black << rang::fgB::green << rang::style::reset << get_color_for(c) << c <<
                      rang::style::reset;
        }
        std::cout << '\n';
    }
}

// Function to print message about victory when user gets to X
void Game_map::print_victory(bool* end_game){
    std::cout << victory.size() << '\n';
    for (auto& line : victory){
        for (auto& c: line){
            std::cout << rang::style::blink << rang::bg::green << rang::fgB::black << rang::style::reset << get_color_for(c) << c <<
                      rang::style::reset;
        }
        std::cout << '\n';
        *end_game = false;

    }
}


// function that will provide me with size of Map for placing objects in random places
Game_map::Coordinates Game_map::size_of_map()const {

    size_t x = map.size()-1;
    size_t y = map.at(x).size() -1;

    return {x, y};
}


// Function that generates random numbers that can be used after verification to randomly place monsters, users and possibly in future other objects on the map
Game_map::Coordinates Game_map::Pick_Random_FreeSpot(){
    size_t min_number = 0;

    Game_map::Coordinates max_size_of_array = size_of_map();

    size_t maxX = static_cast<int>(max_size_of_array.x);
    size_t maxY = static_cast<int>(max_size_of_array.y);
    Game_map::Coordinates randomXY;

    do {

        size_t randomX = random_value_generator(min_number, maxX);
        size_t randomY = random_value_generator(min_number, maxY);
        randomXY.x = randomX;
        randomXY.y = randomY;


    }while (!is_valid_move(randomXY));
    return {randomXY};
}


// function that allow to find location of the player on the map, variable i allows to find row and result refers to column
std::vector<Game_map::Coordinates> Game_map::find_all(char player_type) { // keep an eye on return type it have Game_map:: !!!!!
       index_of_all = {};
       index_of_all.clear();
       size_t x = 0;
       size_t y = 0;
       for (const auto &row : map) {
           const auto result = std::find(row.cbegin(), row.cend(), player_type);
           if (result < std::end(row)) {
               y = (result - row.cbegin());
               Coordinates found_xy = {x, y}; // x is column and y is row
               index_of_all.push_back(found_xy);
           }
           x++;
       }
       return index_of_all;
   }



// function that provides coordinates for new move
Game_map::Coordinates Game_map::next_position(Coordinates from, Move_direction direction) {

    // using coord to perform one search to get value for x & y, this is better then:
    // size_t x = find_way().x; size_t y = find_way().y; in this line I am preforming search twice
    auto x = from.x;
    auto y = from.y;

    switch (direction){

        case Move_direction::up :
            return {x - 1,y};
        case Move_direction::down :
            return {x + 1, y};
        case Move_direction::right :
            return {x, y + 1};
        case Move_direction::left :
            return {x, y - 1};
    }
}

// function that validate move
bool Game_map::is_valid_move(const Game_map::Coordinates to) {
    return map.at(to.x).at(to.y) == ' ' || map[to.x][to.y] == '.';
}

// function that is executed on when user gets to X
bool Game_map::is_victory(const Game_map::Coordinates to){

    return map.at(to.x).at(to.y) == 'X';
}

// function that set position
void Game_map::set_position(Coordinates c, char new_Value){
    map.at(c.x).at(c.y) = new_Value;
}

// function that executes move
void  Game_map::move_player(Move_direction direction, int steps,bool* end_game, Player& my_Player){

    auto current_as_vector = find_all('@');

    Coordinates current = static_cast<Coordinates>(current_as_vector.at(0));
    while (steps-- > 0){
        Coordinates new_Position = next_position(current, direction);
        if (is_victory(new_Position)){
            return print_victory(end_game);
        }
        else if(!is_valid_move(new_Position)) {
            return;
        }
        my_Player.player_moves(); // this function decreases value of variable moves type int inside player and is passed as reference - not sure if I need that at all
        set_position(current, '.');
        set_position(new_Position, '@');
        current = new_Position;
    }
    print_base();
}

// function that will set player and monster in random spot on map
void Game_map::set_random(char player_type){

    Coordinates player_start_position = Pick_Random_FreeSpot();
    set_position(player_start_position, player_type);
}

// function that will set monster in random spot on map

void Game_map::move_monster(){ // todo change way that monster is placed randomly on the map and moved from there

    auto direction = static_cast<Move_direction>(random_value_generator(0, 3));

    auto current_as_vector = find_all('%');

    for (size_t i = 0; i < current_as_vector.size(); i++) {
        Coordinates current = static_cast<Coordinates>(current_as_vector.at(i));
        int steps = 5;

        while (steps-- > 0) {

            Coordinates new_Position = next_position(current, direction);
            if (!is_valid_move(new_Position)) {
                return;
            }
            set_position(current, '.');
            set_position(new_Position, '%');
            current = new_Position;
        }
    }
}


// Random value generator
template <class T>
T Game_map::random_value_generator(T x, T y) {
    std::default_random_engine random_value(random_dev_game());
    std::uniform_int_distribution<T> values(x, y);
    int values_to_return = values(random_value);
    return values_to_return;
}


std::ostream &operator<<(std::ostream & out, const Game_map::Coordinates& coordinates) {


    out << "x: " << coordinates.x << " Y: " << coordinates.y << '\n';
    return out;

}

