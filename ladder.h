#include <iostream>
using namespace std;

#define MAX_ENTRY 10
#define MAX_LENGTH 20

class Ladder
{
    int entryNum;
    int targetNum;
    int ladderLen;

    string status;
    string command;

    string entryList[MAX_ENTRY];
    bool targetList[MAX_ENTRY];
    int bridgeList[MAX_LENGTH];

public:
    Ladder();
    void printLine(int bridgeNum);
    void printLadder();
    void addEntry();
    void changeEntry();
    void changeTargetNum();
    void changeLadderLen();
    void shuffleLadder();
    void rideLadder();
    void showResult();
    void terminate();
    void invalidCommand();
    void setDefaultCommand();
};