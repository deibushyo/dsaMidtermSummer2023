#include <stdio.h>
#include <stdlib.h>
#include "MyHeader.h"

int main(int argc, char *argv[]) {
	Pokedex p;
	GameUser user1 = newGameUser("Godwin Monserate");
	
	initPokedex(&p);
	addPokemon(&p, newPokemon(1, "Balbasaur", newType(136), (Stat){1,1,1,1,1,1,1}));
	addPokemon(&p, newPokemon(2, "Ivysaur", newType(136), (Stat){1,1,1,1,1,1,1}));
	addPokemon(&p, newPokemon(3, "Venusaur", newType(136), (Stat){1,1,1,1,1,1,1}));
	addPokemon(&p, newPokemon(4, "Charizard", newType(514), (Stat){1,1,1,1,1,1,1}));
	addPokemon(&p, newPokemon(5, "Gengar", newType(8320), (Stat){1,1,1,1,1,1,1}));
	
	
	
	printf("Pokedex\n");
	displayPokemonLinkedList(p);
	
	system("PAUSE");
	system("CLS");
	
	printf("Player\n");
	displayGameUser(user1);
	
	system("PAUSE");
	return 0;
}
