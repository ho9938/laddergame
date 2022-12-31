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
    string command;

public:
    Ladder();
    void setEntryName(int index, string name);
    void printLine(int bridgeNum);
    void printLadder();
    void addEntry();
    void changeEntry();
    void changeTargetNum();
    void changeLadderLen();
    void shuffleLadder();
    void rideLadder();
    void showResult();
    void invalidCommand();
};