#include <iostream>
#include <vector>
using namespace std;

class Ladder
{
    int entryNum;
    int targetNum;
    int ladderLen;
    vector<string> entryList;
    vector<bool> targetList;
    vector<vector<bool>> bridgeList;

public:
    Ladder(int entryNum = 3, int targetNum = 1, int ladderLen = 5);
    void setEntryName(int index, string name);
    void printLine(int bridgeNum);
    void printLadder();
};