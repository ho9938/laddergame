#include <iostream>
using namespace std;

#define MAX_ENTRY 10
#define MAX_LENGTH 20
#define DELAY 100000

class Ladder
{
    int entryNum;
    int loserNum;
    int ladderLen;

    string status;
    string command;

    string entryList[MAX_ENTRY];
    bool loserList[MAX_ENTRY];
    int bridgeList[MAX_LENGTH + 2];
    string ladderMap[MAX_LENGTH + 2][MAX_ENTRY];

public:
    Ladder();
    void printLadder();
    void addEntry();
    void changeEntry();
    void changeLoserNum();
    void changeLadderLen();
    void initLadderMap();
    void shuffleLadder();
    void rideLadder();
    bool rideLadder(int index, bool trace);
    void showResult();
    void terminate();
    void invalidCommand();
    void setDefaultCommand();
    void addDebugStatus();
};