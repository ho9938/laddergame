#include "ladder.h"

int main()
{
    system("clear");
    Ladder ladder = Ladder();

    char command;
    do
    {
        cin >> command;
        switch (command)
        {
        case '0':
            break;
        case '1':
            ladder.addEntry();
            break;
        case '2':
            ladder.changeEntry();
            break;
        case '3':
            ladder.changeTargetNum();
            break;
        case '4':
            ladder.changeLadderLen();
            break;
        case '5':
            ladder.shuffleLadder();
            break;
        case '6':
            ladder.rideLadder();
            break;
        case '7':
            ladder.showResult();
            break;
        default:
            ladder.invalidCommand();
            break;
        }
    } while (command != '0');

    return 0;
}