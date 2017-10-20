#include "Game_map.h"
#include "Move_direction.h"
#include "Player.h"
#include "rang.hpp"
#include <iostream>

int menu(std::string &choice) {
  if (choice == "up")
    return 1;
  if (choice == "down")
    return 2;
  if (choice == "right")
    return 3;
  if (choice == "left")
    return 4;
} // todo warning: control may reach end of non-void function [-Wreturn-type]

int moves() {
  int steps = 0;
  std::cout << "Please provide number of moves min 1 - max 5: ";
  std::cin >> steps;
  if (steps > 0 && steps < 6) {

    return steps;
  } else
    return 5;
};

int main() {

  bool game_over = true;
  bool *pGame_over = &game_over;

  Game_map first;

  // setting up monsters in place....
  int monsters = first.random_value_generator(3, 9);
  std::cout << "M: " << monsters << '\n';
  for (size_t i = 0; i < monsters; i++) {
    first.set_random('%');
  }

  // setting up exit
  first.set_random('X');

  // set player on the map
  first.set_random('@');

  // print map
  first.print_base();

  // finding player and monsters
  first.find_all('@');
  first.find_all('%');

  // assigning values to player Mike at the moment not very useful
  Player Mike(5, 20, 10);

  do {
    std::cout << "\n Please provide direction (up/down/right/left): ";
    std::string choice;
    std::cin >> choice;

    switch (menu(choice)) {

    case 1: {

      first.move_monster(); // how to add more monsters?
      std::cout << "Going Up " << '\n';
      Move_direction direction_up;
      direction_up = static_cast<Move_direction>(0);
      auto steps_to_take = moves();
      first.move_player(direction_up, steps_to_take, pGame_over, Mike);

      first.size_of_map();

      Mike.player_moves();
      break;
    }

    case 2: {
      first.move_monster();
      std::cout << "Going Down" << '\n';
      Move_direction direction_down;
      direction_down = static_cast<Move_direction>(1);
      auto steps_to_take = moves();
      first.move_player(direction_down, steps_to_take, pGame_over, Mike);
      break;
    }

    case 3: {
      first.move_monster();
      std::cout << "Going Right" << '\n';
      Move_direction direction_right;
      direction_right = static_cast<Move_direction>(2);
      auto steps_to_take = moves();
      first.move_player(direction_right, steps_to_take, pGame_over, Mike);
      break;
    }

    case 4: {
      first.move_monster();
      std::cout << "Going Left" << '\n';
      Move_direction direction_left;
      direction_left = static_cast<Move_direction>(3);
      auto steps_to_take = moves();
      first.move_player(direction_left, steps_to_take, pGame_over, Mike);
      break;
    }

    default:
      std::cout << "Not going :( select valid choice!" << '\n';
      std::cout << "blah blah" << '\n';
      break;
    }
  } while (*pGame_over);

  return 0;
}
