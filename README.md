# Introduction

	In this programming assignment you are going to write a program that plays a simple text-based version of the game [**Keno**](https://en.wikipedia.org/wiki/Keno). A free online graphic version of the game can be found [**here**](http://www.kenoonline.org/).

	Keno is a popular gambling game with similarities to a lottery or bingo. Players place a bet and choose anywhere from one to twenty numbers between 1 and 80, inclusive. Once the players have chosen their numbers, the game generates twenty random numbers between 1 and 80, and players receive a payoff based on how many numbers they picked that matched the chosen numbers.

	For example, if a player picked seven numbers and all seven were chosen (very unlikely!), she might win around $10.000 for a ten dollar bet. The actual payoffs are based on the probabilities of hitting k numbers out of n chosen.


# The Gameplay

	After a valid bet is processed, the game runs **NR** rounds, waging in each round **IC/NR** credits. For each individual round the game should randomly pick 20 winning numbers, the draw, and display them on the screen. The player’s bet numbers, i.e. the spots, are then compared to the draw numbers to determine how many of them match. The set of correct numbers picked by the player are called hits. The number of hits determines the payout factor, which, in turn, is multiplied by the round’s wage to determine whether the player wins or looses credits.

- NR: number of rounds
- IC: player’s initial credit

# TODO

- [X] Implement the class KenoBet
- [X] Read data of a file with the player's bet
- [X] Implement main() with game loop.
- [X] Implement the class KenoGame
- [X] Creats doxygen documentation

# How to build

	`$ g++ -Wall -std=c++11 src/keno.cpp src/kenogame.cpp src/kenobet.cpp -I include -o build/keno`

	`$ ./build/keno data/bet.dat`

#Git repository

	[http://projetos.imd.ufrn.br/edivaniap/keno_game](http://projetos.imd.ufrn.br/edivaniap/keno_game)

# Authorship

Program developed by _Edivânia Pontes de Oliveira_ (< *edivaniap@ufrn.edu.br* >), 2017.1

&copy; IMD/UFRN 2017.
