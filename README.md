# Introduction

In this programming assignment you are going to write a program that plays a simple text-based version of the game [**Keno**](https://en.wikipedia.org/wiki/Keno). A free online graphic version of the game can be found [**here**](http://www.kenoonline.org/).

Keno is a popular gambling game with similarities to a lottery or bingo. Players place a bet and choose anywhere from one to twenty numbers between 1 and 80, inclusive. Once the players have chosen their numbers, the game generates twenty random numbers between 1 and 80, and players receive a payoff based on how many numbers they picked that matched the chosen numbers.

For example, if a player picked seven numbers and all seven were chosen (very unlikely!), she might win around $10.000 for a ten dollar bet. The actual payoffs are based on the probabilities of hitting k numbers out of n chosen.


# The Gameplay

< Describe the gameplay her...>

# TODO

- [X] Implement the class KenoBet
- [X] Read data of a file with the player's bet
- [X] Implement main() with game loop.
- [X] Implement the class KenoGame
- [X] Creats doxygen documentation

# How to build

	`$ g++ -Wall -std=c++11 src/keno.cpp src/kenogame.cpp src/kenobet.cpp -I include -o build/keno`

	`$ ./build/keno data/bet.dat`

# Authorship

Program developed by _Edivânia Pontes de Oliveira_ (< *edivaniap@ufrn.edu.br* >), 2017.1

&copy; IMD/UFRN 2017.
