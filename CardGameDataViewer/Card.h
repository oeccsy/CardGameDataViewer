#pragma once

class Card
{
public:
	Card();
	Card(int id, const char* name, const char* type, int cost, int rarity);
	Card(const Card& other);
	~Card();

	void Show();

	Card& operator=(const Card& other);

private:
	int id;
	char* name = nullptr;
	char* type = nullptr;
	int cost;
	int rarity;
};