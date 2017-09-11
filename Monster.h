//
// Created by tombr on 09/09/2017.
//

#ifndef GAME_WITH_MONSTERS_MONSTER_H
#define GAME_WITH_MONSTERS_MONSTER_H

#include "Life_form.h"

class Monster : public Life_form {
private:
    int steps;
    int life;
    double power;
public:
    Monster();

    Monster(int steps, int life, double power);


};


#endif //GAME_WITH_MONSTERS_MONSTER_H
