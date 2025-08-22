#include "Card.h"
#include <iostream>
#include <Windows.h>

Card::Card() { }

Card::Card(int id, const char* name, const char* type, int cost, int rarity) : id(id), cost(cost), rarity(rarity)
{
	int nameLength = (int)strlen(name);
	this->name = new char[nameLength + 1];
	strcpy_s(this->name, nameLength + 1, name);
	
	int typeLength = (int)strlen(type);
	this->type = new char[typeLength + 1];
	strcpy_s(this->type, typeLength + 1, type);
}

Card::Card(const Card& other) : id(other.id), cost(other.cost), rarity(other.rarity)
{
	int nameLength = (int)strlen(other.name);
	name = new char[nameLength + 1];
	strcpy_s(name, nameLength + 1, other.name);

	int typeLength = (int)strlen(other.type);
	type = new char[typeLength + 1];
	strcpy_s(type, typeLength + 1, other.type);
}

Card::~Card()
{
	delete[] name;
	delete[] type;
	name = nullptr;
	type = nullptr;
}

void Card::Show()
{
	std::cout << "---------------------------------" << '\n';
	std::cout << "| id	:" << id << "			|" << '\n';
	std::cout << "|				|" << '\n';
	std::cout << "| name	: " << name << "		|" << '\n';
	std::cout << "|				|" << '\n';
	std::cout << "| type	: " << type << "			|" << '\n';
	std::cout << "|				|" << '\n';
	std::cout << "| cost	: " << cost << "			|" << '\n';
	std::cout << "|				|" << '\n';
	std::cout << "| rarity : " << rarity << "			|" << '\n';
	std::cout << "|				|" << '\n';
	std::cout << "|				|" << '\n';
	std::cout << "|				|" << '\n';
	std::cout << "|				|" << '\n';
	std::cout << "---------------------------------" << '\n';
}

Card& Card::operator=(const Card& other)
{
	if (this != &other)
	{
		delete[] name;
		delete[] type;

		id = other.id;
		cost = other.cost;
		rarity = other.rarity;

		int nameLength = (int)strlen(other.name);
		name = new char[nameLength + 1];
		strcpy_s(name, nameLength + 1, other.name);

		int typeLength = (int)strlen(other.type);
		type = new char[typeLength + 1];
		strcpy_s(type, typeLength + 1, other.type);
	}

	return *this;
}
