#pragma once
#include "Vector.h"
#include "Card.h"

class CardInventory
{
public:
	CardInventory(Vector<Card*> cards);
	~CardInventory();

	void ShowCard(int index);
	void ShowNextCard();
	void ShowPrevCard();

private:
	Vector<Card*> cards;
	int curCardIndex = 0;
};