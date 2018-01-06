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
//============API's==============
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

//============Structures=========
typedef struct {
		char name[10];
		int score;
		int playerPosition;
		int cards[13];
		int cardPlayed[13];
		char cardFace;
}Player;

//========Global Data Members=======
//Array of players & number of players in game
Player players[10];
// 2,3,4,5,6,7,8,9,10,11,12,13,14
//int playerHands[10][13];
int handsize = 13;
int numPlayers;
int cardCount = 0;


//===========Functions================
// create_player() > create players for game
void create_player()
{
	do {
		printf("Please enter amount of players between 2 and 10:\n");
		scanf("%d", &numPlayers);
	} while (!(numPlayers >= 2 && numPlayers <= 10));

	printf("A game has been created with %d Players.\n", numPlayers);
	//decrement numPlayers to handle players[] position
	numPlayers -= 1;
	//Get player names and set score + positions to zero
	for (int i = 0; i <= numPlayers; i++) {
		printf("Please enter a name for player %d:\n", i);
		scanf("%s", players[i].name);
		printf("You have entered %s\n", players[i].name);
		players[i].score = 0;
		players[i].playerPosition = 0;
		//initialize player hand
		for (int j = 2; j <= 14; j++) {
			players[i].cards[j-2] = j;
		}
	}
}//end create_player()

//shuffle_hand()
void shuffle_AI_hand(int *array, int n) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < n - 1; i++) {
		size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
		int t = array[j];
		array[j] = array[i];
		array[i] = t;
	}
}//end shuffle_hand()

// display_players() > print player stats to screen
void display_players(int n) {
	printf("Players: %d\n\n", numPlayers + 1);
	for (int i = 0; i <= numPlayers; i++) {
		printf("Name: %s \tPosition: %d \tScore: %d\n", players[i].name, players[i].playerPosition, players[i].score);
		//print player hand to screen - *for testing shuffle
		printf("Player Hand:\n");
		for (int j = 0; j < 13; j++) {
			printf("%d ", players[i].cards[j]);
		}
		printf("\n");
	/*	for (int k = 0; k <= n;k++) {
			printf("Card Played: %d\n", players[i].cardPlayed[n]);
		}*/
	}
}//end display_players()

void clear(void)
{
	while (getchar() != '\n');
}//end clear

void play_round(int n) {
	//User selects card
	do {
		printf("Select a card to play: Choose from 2 - 14, (11 - 14 = J, Q, K, A).\n");
		scanf("%d", &players[0].cardPlayed[n]);
	} while (!(players[0].cardPlayed[n] >= 2 && players[0].cardPlayed[n] <= 14));

//	printf("Player %s chose %d\n", players[0].name, players[0].cardPlayed[n]);

	//AI plays card from top of deck
	for (int i = 1; i <= numPlayers; i++) {
		players[i].cardPlayed[n] = players[i].cards[n];
		//printf("Player %s chose: %d\n", players[i].name, players[i].cardPlayed[n]);
	}
}//end round() 

void check_card(int n) {
	for (int i = 0; i <= numPlayers; i++) {
		switch (players[i].cardPlayed[n]) {
		case 2:
			players[i].cardFace = '2';
			break;
		case 3:
			players[i].cardFace = '3';
			break;
		case 4:
			players[i].cardFace = '4';
			break;
		case 5:
			players[i].cardFace = '5';
			break;
		case 6:
			players[i].cardFace = '6';
			break;
		case 7:
			players[i].cardFace = '7';
			break;
		case 8:
			players[i].cardFace = '8';
			break;
		case 9:
			players[i].cardFace = '9';
			break;
		case 10:
			players[i].cardFace = 'T';
			break;
		case 11:
			players[i].cardFace = 'J';
			break;
		case 12:
			players[i].cardFace = 'Q';
			break;
		case 13:
			players[i].cardFace = 'K';
			break;
		case 14:
			players[i].cardFace = 'A';
			break;
		}//end switch

		printf("Player %s played %c\n", players[i].name, players[i].cardFace);
	}//end for
}

int score_round(int playerNumber, int position) {
	/*
	> iterate through each players last played card and add up total score for the round
	*/
	int totalScore = 0;

	for (int i = 0; i <= playerNumber; i++) {
		totalScore += players[i].cardPlayed[position];
	}
	printf("Total Round Score: %d\n", totalScore);
	return totalScore;
}

int round_winner(int playerNumber, int position) {
	int lastCard[10];
	int highCard;
	int highCard1;
	int highCardPos;
	int whileSentinel = -1;
	int i, j;
	
	for (int i = 0; i <= playerNumber; i++) {
		lastCard[i] = players[i].cardPlayed[position];
		printf("Round Winner Card Played Array: %d \n", lastCard[i]);
	}

	for (i = 0; i <= playerNumber; i++) {
		for (j = 1; j <= i; j++) {
			if (lastCard[i] == lastCard[j]) {
				lastCard[i] = 0;
				lastCard[j] = 0;
				break;
			}
		}
	}

//	highCard = lastCard[0];
	for (i = 0; i <= playerNumber; i++) {
			if (lastCard[i] > highCard) {
			highCard = lastCard[i];
			/* No duplicate element found between index 0 to i */
			printf("HighCard in Array: %d \n", highCard);
		}
	}
	/*for (int i = 0; i <= playerNumber; i++) {
		lastCard[i] = players[i].cardPlayed[position];
		//printf("Round Winner Card Played Array: %d \n", array[i]);
	}
	highCard = lastCard[0];

	while (whileSentinel !=0 && highCard !=0) {
		for (int i = 0; i <= playerNumber; i++) {
			if (lastCard[i] > highCard) {
				highCard1 = highCard;
				highCard = lastCard[i];
				highCardPos = i;
			}
		}

		for (int i = 0; i <= playerNumber; i++) {
			if (highCard == lastCard[i]) {
				lastCard[i] = 0;
				lastCard[highCardPos] = 0;
			}
		}

		if (highCard == 0)
			whileSentinel = 0;
			//break;
	}//end while
	*/
	//printf("HighCard: %d", highCard);
	return 0;
}
//====================== MAIN ====================
void main() {
	int round = 0;
	printf("Create_Player()\n\n");
	create_player();
	//shuffle hands of all extra players - player 0 is the user
	for (int i = 1; i <= numPlayers; i++) {
		shuffle_AI_hand(players[i].cards, 13);
	}
	
	printf("Display_Player()\n");
	display_players(round);
	printf("play_round()\n\n");
	for (int i = 0; i <= 1; i++) {
		round++;
		play_round(i);
		check_card(i);
		score_round(numPlayers, i);
		round_winner(numPlayers, i);
	}
//	printf("Display_Player()\n\n");
	display_players(round);

	

}// End Main

//*********************************Snippets**************************************

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

/*			Shuffle Array Example
#include <time.h>

void shuffle(int *array, int n) {
srand((unsigned)time(NULL));
for (int i = 0; i < n - 1; i++) {
size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
int t = array[j];
array[j] = array[i];
array[i] = t;
}
}

#define N 6

int main() {
int positions[N] = {0, 1, 2, 3, 4, 5};

for (int j = 0; j < 10; j++) {
shuffle(positions, N);
for (int x = 0; x < N; x++) printf("%d ", positions[x]);
printf("\n");
}

return 0;
}
						Create Hand method
//create_hand() > create a randomised hand for each player
/*void create_hand(Hand h, const int numPlayers) {
//create player hand array
//int numPlayers = p;
Hand playerHands[numPlayers];

//for (int i = 0; i < (sizeof(h.hand) / sizeof(h.hand[0])); i++)
for (int i = 0; i < numPlayers; i++) {
h.hand[i] = i + 1;
printf("%d", h.hand[i]);
printf("\n");
}
}*/

