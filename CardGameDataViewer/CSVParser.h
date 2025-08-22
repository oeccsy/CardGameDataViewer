#pragma once

#include "Vector.h"
#include "String.h"
#include "Card.h"

struct ReadResult
{
	int row = 0;
	int col = 0;
	Vector<char*> header;
	Vector<char*> tokens;
};

class CSVParser
{
public:
	CSVParser() = default;
	~CSVParser() = default;

	ReadResult ReadCSVFile(const char* fileName);
	Vector<Card*> ConvertToCards(ReadResult readResult);

private:
	Vector<char*> Split(char* str, char sep);
};