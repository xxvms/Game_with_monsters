#include <iostream>
#include "Game_map.h"
#include "Move_direction.h"
#include "rang.hpp"
#include "Player.h"

int menu(std::string &choice) {
    if (choice == "up") return 1;
    if (choice == "down") return 2;
    if (choice == "right") return 3;
    if (choice == "left") return 4;
}


int moves(){
    int steps = 0;
    std::cout << "Please provide number of moves min 1 - max 5: ";
    std::cin >> steps;
    if (steps > 0 && steps < 6)
    {

        return steps;
    } else return 5;

};

bool game_over = true;
bool* pGame_over = &game_over;

int main() {

    Game_map first;

    first.print_base();
    first.find_player();
    Player Mike(5, 20, 10);

    std::cout << "Mike attack: " << Mike.attack() << '\n';
    std::cout << "Mike defense: " << Mike.defense(5) << '\n';

    Player Monster(5, 20, 3);



    do {
        std::cout << "Please provide direction (up/down/right/left): ";
        std::string choice;
        std::cin >> choice;

        switch (menu(choice)) {

            case 1:{
                std::cout << "Going Up " << '\n';
                Move_direction direction_up;
                direction_up = static_cast<Move_direction>(0);
                auto steps_to_take = moves();
                first.move_player(direction_up, steps_to_take, pGame_over);
                break;
            }

            case 2:{
                std::cout << "Going Down" << '\n';
                Move_direction direction_down;
                direction_down= static_cast<Move_direction>(1);
                auto steps_to_take = moves();
                first.move_player(direction_down, steps_to_take, pGame_over);
                break;
            }

            case 3:{
                std::cout << "Going Right" << '\n';
                Move_direction direction_right;
                direction_right = static_cast<Move_direction>(2);
                auto steps_to_take = moves();
                first.move_player(direction_right, steps_to_take, pGame_over);
                break;
            }

            case 4:{
                std::cout << "Going Left" << '\n';
                Move_direction direction_left;
                direction_left = static_cast<Move_direction>(3);
                auto steps_to_take = moves();
                first.move_player(direction_left, steps_to_take, pGame_over);
                break;
            }

            default:
                std::cout << "Not going :( select valid choice!" << '\n';
                break;
        }
    } while (*pGame_over);

    return 0;
}



