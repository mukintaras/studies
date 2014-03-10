// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// struct Card 
// {
// 	char suit;
// 	char rank;
// };

int has_flush(struct Card card[5])
{
	if ( (card[0].suit == card[1].suit) && (card[0].suit == card[2].suit) && (card[0].suit == card[3].suit) && (card[0].suit == card[4].suit) )
	{
		if ( (card[0].rank > '9') && (card[1].rank > '9') && (card[2].rank > '9') && (card[3].rank > '9') && (card[4].rank > '9') )
			return 2;
		else
			return 1;
	}
	else
		return 0;
};

// int main()
// {
// 	struct Card card[5];

// 	card[0].suit = 'c'; card[0].rank = 'T';
// 	card[1].suit = 'c'; card[1].rank = 'J';
// 	card[2].suit = 'c'; card[2].rank = 'Q';
// 	card[3].suit = 'c'; card[3].rank = 'K';
// 	card[4].suit = 'c'; card[4].rank = 'A';

// 	printf("%d\n", has_flush(card));

// 	return 0;
// }