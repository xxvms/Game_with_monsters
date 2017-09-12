//
// Created by tombr on 09/09/2017.
//

#include <iostream>
#include "Player.h"

Player::Player(int moves, double life, double attack) : moves(5), life(20), attackX(5.00) {}

double Player::read_power() {
    return life;
}

// function that generates random value in range 1- Max attack value that represetn strenght of an attack
double Player::attack() {
    double attack_strenght = random_value_generator(1.0, attackX);
    return attack_strenght;
}

// Function that the only job is to generate random values for my other functions - attack and defence
template <class T>
T Player::random_value_generator(T min_Value, T max_Value)  {
    std::default_random_engine random_value(random_dev());
    std::uniform_real_distribution<T> values(min_Value, max_Value);
    double values_to_return =  values(random_value);
    return values_to_return;
}

// Function that responds to the attack by lowering life by amount of attack and chance of avoiding attack all together
double Player::defense(double Monster_attack) {

    double percent = (Monster_attack / 100);// todo not finished function to deal with defense



    return life - Monster_attack;
}