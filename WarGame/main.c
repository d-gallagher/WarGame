/*	Author - David Gallagher - 
	War - Card Game - Overview
	Num Players: 2 - 10
	Rounds: 13
	Rules:
	Each Player gets 13 Cards, one of each suit from 2 - Ace
	Card Value: 2 - 14.
	----
	Each player plays a card per round - card expires once played.
	The player who plays the highest value card wins the round.
	The winner of the round gains points equal to the sum value of all cards played that round.
	If more than one of any card is played, those players cancel each other out, 
	with the highest Unique card winning the round.
	*If all cards played are duplicates, points roll over to the next round.
	*If this occurs on the final round, the sum of points are lost from the game.
*/
#include<stdio.h>
#include<string.h>

typedef struct{
	int hand[13];
	char cardPlayed;
} Hand;

typedef struct {
		char *name;
		int score;
		int playerNum;
				
}Player;
// Global Data Members
//Array of players & number of players in game
Player players[13];
int numPlayers;



void create_player()
{
//	Player players[13];
//	int playerNum = 2;
	char *playerName[10];
	do {
		printf("Please enter amount of players between 2 and 13:\n");
		scanf("%d", &numPlayers);
	} while (!(numPlayers >= 2 && numPlayers <= 13));

	printf("A game has been created with %d Players.\n", numPlayers);
	//decremet numPlayers to account for array index position
	numPlayers -= 1;
	//Get name of users player
	printf("Please enter a name for your player:\n");
	scanf("%s", playerName);
//	scanf_s("%s", players[0].name, _countof(players[0].name));
//	for (int a = 0; a <= 10; a++) {
//		players[0].name[a] = playerName[a];
//	}
//	strcpy(playerName, players[0].name);
	players[0].name = playerName;
	printf("You have entered %s\n", players[0].name);
	players[0].score = 0;
	players[0].playerNum = 1;
//	printf("You are Player 1.\n");

	for (int i = 1; i <= numPlayers; i++) {
		players[i].name = "Player";
		players[i].score = 0;
		players[i].playerNum = (i+1);
	}
}//end create_player()

void display_players() {
	printf("Players:\n\n");
	for (int i = 0; i <= numPlayers; i++) {
		printf("Name: %s %d \tScore: %d\n", players[i].name, players[i].playerNum, players[i].score);
	}
}


//==========================================
void main() {
	
	printf("Create_Player()\n\n");
	create_player();
	printf("Display_Player()\n\n");
	display_players();

}// End Main


//struct player* create_player(int playerNum,int hand[13],int score,char cardPlayed)
//{
//	struct player* newPlayer = (struct player*)malloc(sizeof(struct player));
//	if (newPlayer)
//	{
//		newPlayer->playerNum = playerNum;
//		newPlayer->hand[13] = hand[13];
//		newPlayer->score = score;
//		newPlayer->cardPlayed = cardPlayed;
//	}
//
//	return newPlayer;
//}

//struct playerStart(struct player p) {
//	int i;
//
//	//create player hand
//	for (i = 0; i < (sizeof(p.hand) / sizeof(p.hand[0])); i++) {
//		p.hand[i] = i + 1;
//		printf("%d", p.hand[i]);
//		printf("\n");
//	}
//	return p;
//}

//void create_player()
//{
//	int numPlayers;
//	printf("Please enter amount of players: ");
//	Player players[0];
//}
