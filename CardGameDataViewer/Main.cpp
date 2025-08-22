#include <iostream>
#include "CSVParser.h"
#include "Card.h"
#include "CardInventory.h"
#include "InputSystem.h"
#include <Windows.h>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CSVParser csvParser;
	ReadResult readResult = csvParser.ReadCSVFile("CardData.txt");
	Vector<Card*> cards = csvParser.ConvertToCards(readResult);

	CardInventory inventory(cards);
	InputSystem inputSystem;

	inventory.ShowCard(0);

	while (true)
	{
		inputSystem.ProcessInput();
		
		if (inputSystem.GetKeyDown(VK_RIGHT)) inventory.ShowNextCard();
		if (inputSystem.GetKeyDown(VK_LEFT)) inventory.ShowPrevCard();
		if (inputSystem.GetKeyDown(VK_ESCAPE)) break;

		inputSystem.SavePreviousKeyStates();
	}

	for (int i = 0; i < cards.Size(); ++i) delete cards[i];
	for (int i = 0; i < readResult.header.Size(); ++i) delete[] readResult.header[i];
	for (int i = 0; i < readResult.tokens.Size(); ++i) delete[] readResult.tokens[i];

	_CrtDumpMemoryLeaks();
}