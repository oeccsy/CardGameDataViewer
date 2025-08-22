#include "CardInventory.h"

CardInventory::CardInventory(Vector<Card*> cards) : cards(cards) { }

CardInventory::~CardInventory() { }

void CardInventory::ShowCard(int index)
{
	if (index < 0 || cards.Size() -1 < index)
	{
		std::cout << "올바른 카드를 선택해주세요." << '\n';
		return;
	}

	curCardIndex = index;
	cards[curCardIndex]->Show();
}

void CardInventory::ShowNextCard()
{
	curCardIndex = (curCardIndex + 1) % cards.Size();
	cards[curCardIndex]->Show();
}

void CardInventory::ShowPrevCard()
{
	curCardIndex = (curCardIndex + cards.Size() - 1) % cards.Size();
	cards[curCardIndex]->Show();
}
