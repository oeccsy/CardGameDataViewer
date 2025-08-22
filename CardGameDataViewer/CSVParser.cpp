#include "CSVParser.h"
#include <iostream>
#include <string>

ReadResult CSVParser::ReadCSVFile(const char* fileName)
{
    char fullPath[32];
    const char* path = "../Assets/";

    sprintf_s(fullPath, sizeof(fullPath), "%s%s", path, fileName);

    FILE* file = nullptr;
    fopen_s(&file, fullPath, "rt");

    if (file == nullptr)
    {
        std::cout << "CSV 파일 읽기 실패" << '\n';
        return ReadResult();
    }

    ReadResult result;

    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = new char[fileSize + 1];

    memset(buffer, 0, fileSize + 1);
    fgets(buffer, fileSize + 1, file);
    result.header = Split(buffer, ',');
    
    memset(buffer, 0, fileSize + 1);
    fread(buffer, sizeof(char), fileSize, file);
    result.tokens = Split(buffer, ',');

    result.col = result.header.Size();
    result.row = result.tokens.Size() / result.col;

    delete[] buffer;
    fclose(file);
    
    return result;
}

Vector<Card*> CSVParser::ConvertToCards(ReadResult readResult)
{
    Vector<Card*> cards;

    for (int i = 0; i < readResult.row; ++i)
    {
        int startIndex = i * readResult.col;

        int id = std::stoi(readResult.tokens[startIndex + 0]);
        char* name = readResult.tokens[startIndex + 1];
        char* type = readResult.tokens[startIndex + 2];
        int cost = std::stoi(readResult.tokens[startIndex + 3]);
        int rarity = std::stoi(readResult.tokens[startIndex + 4]);
        
        Card* card = new Card(id, name, type, cost, rarity);
        cards.PushBack(card);
    }

    return cards;
}

Vector<char*> CSVParser::Split(char* str, char sep)
{
    Vector<char*> result;
    int st = 0;
    int en = 0;

    while (str[en] != '\0')
    {
        char curChar = str[en];

        if (curChar == sep || curChar == '\n')
        {
            char* token = new char[en - st + 1];
            memcpy(token, str + st, en - st);
            token[en - st] = '\0';

            result.PushBack(token);

            st = en + 1;
        }

        ++en;
    }

    if (st < en)
    {
        char* token = new char[en - st + 1];
        memcpy(token, str + st, en - st);
        token[en - st] = '\0';

        result.PushBack(token);
    }
    
    return result;
}