#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyHeader.h"

int allocSpace(VSpace *vs) {
	int loc = vs->avail;
	
	if(loc != -1) {
		vs->avail = vs->data[loc].pos;
	}
	
	return loc;
}

void freeSpace(VSpace *vs, int loc) {
	if(loc != -1 && loc < MAX_SPACE) {
		vs->data[loc].pos = vs->avail;
		vs->avail = loc;
	}
}

void displayPokemon(Pokemon p) {
	printf("{%d | %s - ", p.pokeID, p.pokeName);
	displayType(p.pokeType.mainType);
	printf("}\n");
}

void displayPokemonDetail(Pokemon p) {
	printf("%10s: %d\n", "ID", p.pokeID);
	printf("%10s: %s\n", "Name", p.pokeName);
	printf("");
}

void displayType(int type) {
	int i;
	String typeNames[18] = {"Normal", "Fire", "Water", "Grass", 
					"Electric", "Ice", "Fighting", "Poison",
					"Ground", "Flying", "Psychic", "Bug",
					"Rock", "Ghost", "Dark", "Dragon",
					"Steel", "Fairy"};
					
	//printf("%s ", typeNames[4]);
	//printf("%d ",type);
	
	printf("[");
	// to do code logic here
	int bit = (sizeof(type) * 8) - 1;
	int bin[32];
	unsigned int masked;
	
	for(i = 0, masked = 1<<bit; masked > 0; masked>>=1, ++i) {
		bin[i] = (type&masked)?1:0;
		//printf("%d", (type&masked)?1:0);
	}
	int k;
	for(i = 31, k = 0; i > 0; --i, k++) {
		//printf("%d ", bin[i]);
		if(bin[i] == 1) {
			printf("%s ", typeNames[k]);
		}
		//printf("%d ", bin[i]);
	}
	
	printf("] ");
}

VSpace newVSpace() {
	VSpace vs;
	int i;
	
	for(i = MAX_SPACE - 1; i >= 0; --i) {
		vs.data[i].dataDetail.pokeID = -1;	// will tag it as empty
		vs.data[i].pos = i-1;
	}
	vs.avail = MAX_SPACE - 1;
	
	return vs;
}


Tile newTile() {
	Tile t;
	
	t.start = 1;
	t.end = 2;
	
	return t;
}

Deck newDeck() {
	Deck d;
	
	d.stack = newStackList();
	d.space = newVSpace();
	
	return d;
}

StackPokemonList newDiscard(int size) {
	StackPokemonList list;
	
	list.max = size;
	list.count = 0;
	list.pokeList = malloc(sizeof(Pokemon) * list.max);
	
	return list;
}

StackList newStackList() {
	return -1;	
}

void initPokedex(Pokedex *p) {
	*p = NULL;
}

GameUser newGameUser(String playerName) {
	GameUser user;
	
	user.playerDeck = newDeck();
	user.playerTile = newTile();
	user.playerDiscard = newDiscard(MAX_POKEMON);
	
	strcpy(user.playerName, playerName);
	
	return user;
}

void displayPokemonArrayList(PokemonList pokeList) {
	int i;
	printf("{\n");
	// to do code logic here
	
	
	printf("}\n");
}

void displayPokemonStackArrayList(StackPokemonList pokeList) {
	printf("{\n");
	// to do code logic here
	
	
	printf("}\n");
}

void displayPokemonLinkedList(Pokedex p) {
	printf("{\n");
	// to do code logic here
	int i;
	Pokedex temp;
	temp = p;
	for(i = 0; i < MAX_POKEMON; i++) {
		printf("\t- {");
		printf("%d | %s - ", temp->dataInfo.pokeID, temp->dataInfo.pokeName);
		displayType(temp->dataInfo.pokeType.mainType);
		printf("}\n\n");
		if(temp->link == NULL) {
			break;
		}
		temp = temp->link;
	}
	
	printf("}\n");
	//printf("}\n");
}

void displayPokemonCircularArray(Tile t) {
	printf("{\n");
	// to do code logic here
	
	
	printf("}\n");
}

void displayPokemonDeck(VSpace vs, StackList list) {
	printf("{\n");
	// to do code logic here
	

	printf("}\n");
}

void displayGameUser(GameUser user) {
	printf("Player Name: %s\n", user.playerName);
	printf("Pokemon on Deck\n");
	displayPokemonDeck(user.playerDeck.space, user.playerDeck.stack);
	printf("Pokemon on Tile\n");
	displayPokemonCircularArray(user.playerTile);
	printf("Pokemon on Graveyard\n");
	displayPokemonArrayList(user.playerDiscard);
}

Type newType(int type) {
	Type t;
	
	t.mainType = type;
	t.resistantTo = t.strongAgainst = t.vulnerableTo = t.weakAgainst = 0;
	
	return t;
}

void initStat(Stat s, int hp, int attack, int defense, int sa, int sd, int speed, int oad) {
	s[0] = hp;
	s[1] = attack;
	s[2] = defense;
	s[3] = sa;
	s[4] = sd;
	s[5] = speed;
	s[7] = oad;
} 

Pokemon newPokemon(int pokeID, String pokeName, Type pokeType, Stat pokeStats) {
	Pokemon p;
	
	p.pokeID = pokeID;
	strcpy(p.pokeName, pokeName);
	p.pokeType = pokeType;
	memcpy(p.pokeStats, pokeStats, sizeof(int) * 7);
	
	return p;
}

void addPokemon(Pokedex *dex, Pokemon p) {
	Pokedex temp = malloc(sizeof(NodePM));
	
	if(temp != NULL) {
		temp->dataInfo = p;
		temp->link = *dex;
		*dex = temp;
	}
}
