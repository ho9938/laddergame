#include "ladder.h"

int main()
{
    Ladder ladder = Ladder();
    ladder.printLadder();

    int command;
    do
    {
        cin >> command;

        ladder.initLadderMap();
        switch (command)
        {
        case 1:
            ladder.addEntry();
            break;
        case 2:
            ladder.changeEntry();
            break;
        case 3:
            ladder.changeLoserNum();
            break;
        case 4:
            ladder.changeLadderLen();
            break;
        case 5:
            ladder.shuffleLadder();
            break;
        case 6:
            ladder.rideLadder();
            break;
        case 7:
            ladder.showResult();
            break;
        case 0:
            ladder.terminate();
            break;
        default:
            ladder.invalidCommand();
            break;
        }
        ladder.printLadder();
    } while (command != 0);

    return 0;
}