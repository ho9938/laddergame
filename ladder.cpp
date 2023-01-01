#include <iostream>
#include "ladder.h"
using namespace std;

Ladder::Ladder()
{
    this->entryNum = 3;
    this->targetNum = 1;
    this->ladderLen = 5;

    setDefaultCommand();

    for (int i = 0; i < entryNum; i++)
        entryList[i] = "entry" + to_string(i);

    shuffleLadder();
}

void Ladder::printLine(int bridgeNum)
{
    char curChar = ' ';
    for (int i = 0; i < entryNum; i++)
    {
        cout << string(entryList[i].length() / 2, curChar);
        curChar = (bridgeNum != -1 && bridgeList[bridgeNum] == i) ? '-' : ' ';
        cout << '|' << string((entryList[i].length() + 1) / 2, curChar);
    }
    cout << endl;
}

void Ladder::printLadder()
{
    system("clear");

    cout << "laddergame v1" << endl;
    cout << "made by Yoon Changho ho9938@unist.ac.kr" << endl;
    cout << endl;

    for (int i = 0; i < entryNum; i++)
        cout << entryList[i] << ' ';
    cout << endl;

    printLine(-1);
    for (int i = 0; i < ladderLen; i++)
        printLine(i);
    printLine(-1);

    for (int i = 0; i < entryNum; i++)
    {
        cout << string(entryList[i].length() / 2, ' ');
        cout << (targetList[i] ? 'X' : 'O');
        cout << string((entryList[i].length() + 1) / 2, ' ');
    }
    cout << endl;

    cout << endl;
    cout << status << endl;
    cout << "0. exit" << endl;
    cout << "1. add entry" << endl;
    cout << "2. change entry" << endl;
    cout << "3. change number of target" << endl;
    cout << "4. change length of ladder" << endl;
    cout << "5. shuffle ladder again" << endl;
    cout << "6. ride on the ladder" << endl;
    cout << "7. show the result" << endl;

    cout << endl;
    cout << command << " : ";
}

void Ladder::addEntry()
{
    status = "add entry in progress...";

    if (entryNum == MAX_ENTRY)
    {
        status = "entry number is maximum already";
        setDefaultCommand();
        return;
    }

    // else
    entryList[entryNum] = "entry" + to_string(entryNum);
    entryNum += 1;

    shuffleLadder();

    setDefaultCommand();
    status = "add entry complete";
}

void Ladder::changeEntry()
{
    status = "change entry in progress...";
    command = "type the index of the entry you want to change";
    printLadder();

    int index;
    cin >> index;

    if (index >= entryNum)
    {
        status = "index is out of range";
        setDefaultCommand();
        return;
    }

    // else
    command = "type the new name to change to";
    printLadder();

    string name;
    cin >> name;

    entryList[index] = name;

    status = "change entry complete";
    setDefaultCommand();
}

void Ladder::changeTargetNum()
{
    status = "change number of target in progress...";
    command = "type how many targets do you want";
    printLadder();

    int num;
    cin >> num;

    if (num >= entryNum)
    {
        status = "number of target must be smaller than number of entries";
        setDefaultCommand();
        return;
    }

    // else
    targetNum = num;
    shuffleLadder();

    status = "change number of target complete";
    setDefaultCommand();
}

void Ladder::changeLadderLen()
{
    status = "change length of ladder in progress...";
    command = "type the length of ladder you want";
    printLadder();

    int len;
    cin >> len;

    if (len > MAX_LENGTH)
    {
        status = "length of ladder is out of range";
        setDefaultCommand();
        return;
    }

    // else
    ladderLen = len;
    shuffleLadder();

    status = "change length of ladder complete";
    setDefaultCommand();
}

void Ladder::shuffleLadder()
{
    srand(time(0));

    for (int i = 0; i < ladderLen; i++)
        bridgeList[i] = rand() % (entryNum - 1);

    for (int i = 0; i < entryNum; i++)
        targetList[i] = false;

    int cnt = 0;
    while (cnt < targetNum)
    {
        int curTarget = rand() % entryNum;
        if (!targetList[curTarget])
        {
            targetList[curTarget] = true;
            cnt++;
        }
    }

    status = "shuffle ladder complete";
}

void Ladder::rideLadder() {}
void Ladder::showResult() {}

void Ladder::terminate()
{
    status = "goodbye";
}

void Ladder::invalidCommand()
{
    status = "invalid command";
}

void Ladder::setDefaultCommand()
{
    command = "what command do you want to execute?";
}