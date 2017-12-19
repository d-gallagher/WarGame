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

//struct player {
//	int playerNum;
//	int hand[13];
//	int score;
//	char cardPlayed;
//};
typedef struct {
		int playerNum;
		int hand[13];
		int score;
		char cardPlayed;
}player;

create_player(int playerNum, int hand[13], int score, char cardPlayed);
//void playerStart(struct player aPlayer);
//struct player aPlayer;

void main() {
	//Data Members
	int playerHand[13];
	int numPlayers;
	//counters
	int i;

	//Start Game
	printf("Please enter number of players between 2 & 13: \n");
	scanf("%d", &numPlayers);
	printf("Beginning game for %d players.\n", numPlayers);
	for (i = 0; i < numPlayers; i++) {
		create_player(numPlayers,playerHand[13],0,'A');
		for (i = 0; i < (sizeof(playerHand) / sizeof(playerHand[0])); i++) {
			playerHand[i] = i + 1;
	}
	

}// End Main


struct player* create_player(int playerNum,int hand[13],int score,char cardPlayed)
{
	struct player* newPlayer = (struct player*)malloc(sizeof(struct player));
	if (newPlayer)
	{
		newPlayer->playerNum = playerNum;
		newPlayer->hand[13] = hand[13];
		newPlayer->score = score;
		newPlayer->cardPlayed = cardPlayed;
	}

	return newPlayer;
}

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
