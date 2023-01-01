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

void Ladder::printLadder()
{
    system("clear");

    cout << "laddergame v1" << endl;
    cout << "made by Yoon Changho ho9938@unist.ac.kr" << endl;
    cout << endl;

    for (int i = 0; i < entryNum; i++)
        cout << entryList[i] << ' ';
    cout << endl;

    for (int i = 0; i <= ladderLen + 1; i++)
    {
        for (int j = 0; j < entryNum; j++)
            cout << ladderMap[i][j];
        cout << endl;
    }

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

void Ladder::drawLadderMap()
{
    for (int i = 0; i <= ladderLen + 1; i++)
    {
        ladderMap[i][0] = string(entryList[0].length() / 2, ' ') + "|";

        for (int j = 1; j < entryNum; j++)
        {
            char curChar = (bridgeList[i] == j) ? '-' : ' ';
            ladderMap[i][j] = string((entryList[j].length() + 1) / 2, curChar);
            ladderMap[i][j] += string(entryList[j].length() / 2, curChar) + "|";
        }
    }
}

void Ladder::shuffleLadder()
{
    srand(time(0));

    bridgeList[0] = -1;
    for (int i = 1; i <= ladderLen; i++)
        bridgeList[i] = rand() % (entryNum - 1) + 1;
    bridgeList[ladderLen + 1] = -1;

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

    drawLadderMap();
    status = "shuffle ladder complete";
}

void Ladder::rideLadder()
{
    status = "ride on the ladder in progress...";
    command = "type the index of the entry you want to ride";
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
    bool result = rideLadder(index);

    status += entryList[index] + " is ";
    if (result)
        status += "loser";
    else
        status += "winner";

    setDefaultCommand();
}

bool Ladder::rideLadder(int index)
{
    int curBridge = index;

    for (int i = 0; i <= ladderLen + 1; i++)
    {
        if (bridgeList[i] == curBridge)
        {
            curBridge -= 1;
        }
        else if (bridgeList[i] == curBridge + 1)
        {
            curBridge += 1;
        }
    }

    return targetList[curBridge];
}

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

void Ladder::addDebugStatus()
{
    status += "\n";
    status += "---------------------------\n";

    status += "entryList: ";
    for (int i = 0; i < entryNum; i++)
        status += to_string(i) + ":" + entryList[i] + " ";
    status += "\n";

    status += "targetList: ";
    for (int i = 0; i < entryNum; i++)
        status += to_string(i) + ":" + to_string(targetList[i]) + " ";
    status += "\n";

    status += "bridgeList: ";
    for (int i = 0; i <= ladderLen + 1; i++)
        status += to_string(i) + ":" + to_string(bridgeList[i]) + " ";
    status += "\n";

    status += "---------------------------\n";
}