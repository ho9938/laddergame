#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "ladder.h"
using namespace std;

Ladder::Ladder(int entryNum, int targetNum, int ladderLen)
{
    this->entryNum = entryNum;
    this->targetNum = targetNum;
    this->ladderLen = ladderLen;

    for (int i = 0; i < entryNum; i++)
        entryList.push_back("entry" + to_string(i));

    srand(time(0));
    for (int i = 0; i < ladderLen; i++)
    {
        vector<bool> curColumn;
        for (int j = 0; j < entryNum - 1; j++)
            curColumn.push_back(rand() % 2);
        curColumn.push_back(false);
        bridgeList.push_back(curColumn);
    }

    for (int i = 0; i < entryNum - targetNum; i++)
        targetList.push_back(false);
    for (int i = 0; i < targetNum; i++)
        targetList.push_back(true);
    auto rng = default_random_engine{};
    random_shuffle(targetList.begin(), targetList.end());
};

void Ladder::setEntryName(int index, string name)
{
    if (index >= entryNum)
        return;

    entryList.at(index) = name;
}

void Ladder::printLine(int bridgeNum)
{
    vector<string>::iterator nameIter;
    vector<bool>::iterator bridgeIter;

    if (bridgeNum != -1)
        bridgeIter = bridgeList.at(bridgeNum).begin();

    char curChar = ' ';
    for (nameIter = entryList.begin(); nameIter != entryList.end(); nameIter++)
    {
        cout << string((*nameIter).length() / 2, curChar);

        if (bridgeNum != -1 && *(bridgeIter++))
            curChar = '-';
        else
            curChar = ' ';

        cout << '|' << string(((*nameIter).length() + 1) / 2, curChar);
    }

    cout << endl;
}

void Ladder::printLadder()
{
    vector<string>::iterator nameIter;
    vector<int>::iterator widthIter;
    vector<bool>::iterator targetIter;

    for (nameIter = entryList.begin(); nameIter != entryList.end(); nameIter++)
        cout << *nameIter << ' ';
    cout << endl;

    for (int i = 0; i < ladderLen; i++)
    {
        printLine(-1);
        printLine(i);
    }
    printLine(-1);

    targetIter = targetList.begin();
    for (nameIter = entryList.begin(); nameIter != entryList.end(); nameIter++)
    {
        cout << string((*nameIter).length() / 2, ' ');
        cout << (*(targetIter++) ? 'X' : 'O');
        cout << string(((*nameIter).length() + 1) / 2, ' ');
    }
}