#include <iostream>

using namespace std;


int main()
{
    int participants;

    int startingNumber;

    int startHour;
    int startMinutes;
    int startSeconds;

    int endHour;
    int endMinutes;
    int endSeconds;

    int goalHour;
    int goalMinutes;
    int goalSeconds;

    int winnerTime = 86400; //WILL BE USED TO STORE VALUE IN SECONDS, TO COMPARE TO PREVIOUS TIME IF IT IS SMALLER, IT WILL BE STORED AS WINNER
    int winnerStartingNumber;
    int winnerHour;
    int winnerMinutes;
    int winnerSeconds;

    bool exitLoop = true;


    while (exitLoop) {

            cout << "Please enter starting number of participant: " << endl;
            cin >> startingNumber;

    if (startingNumber >= 1) {


            cout << "Starting time: Enter hour, minute, and second (press enter between): " << endl;
            cin >> startHour;
            cin >> startMinutes;
            cin >> startSeconds;
            cout << "Your starting time is: " << startHour << " " << startMinutes << " " << startSeconds << endl;

            cout << "Finish time: Enter hour, minute, and second (press enter between): " << endl;
            cin >> endHour;
            cin >> endMinutes;
            cin >> endSeconds;
            cout << "Your goal time is: " << endHour <<  " " << endMinutes << " " << endSeconds << endl;

            goalHour = endHour - startHour;
            if (goalHour <= 0) {
                int temp = 24 - startHour;
                goalHour = temp + endHour;
                if (goalHour == 24) {
                    goalHour = 0;
                }
            }
            goalMinutes = endMinutes - startMinutes;
            if (goalMinutes <= 0) {
                goalHour--;
                goalMinutes = 60 + goalMinutes;
                if (goalMinutes == 60) {
                    goalHour++;
                    goalMinutes = goalMinutes - 60;
                }
            }
            goalSeconds = endSeconds - startSeconds;
            if (goalSeconds < 0) {
                goalMinutes--;
                goalSeconds = 60 + goalSeconds;
            }

            cout << "Your run time is, Hours:" << goalHour << " Minutes: " << goalMinutes << " Seconds: " << goalSeconds << endl;

            int tempTime = goalHour * 3600 + goalMinutes * 60 + goalSeconds;

            if (tempTime < winnerTime) {

                cout << "Congratulations runner " << startingNumber << ". You are the fastests one yet!" << endl;
                winnerTime = tempTime;
                winnerStartingNumber = startingNumber;
                winnerHour = goalHour;
                winnerMinutes = goalMinutes;
                winnerSeconds = goalSeconds;

            }


            participants++;


    }
    else {

            if (participants <=0) {
                cout << "No participants" << endl;
                exitLoop = false;
            }

            else {
                cout << "The winner was: " << winnerStartingNumber << endl;
                cout << "Hour: " << winnerHour << " Minutes: " << winnerMinutes << " Seconds: " << winnerSeconds << endl;

                cout << "The amount of participants were: " << participants << endl;
                exitLoop = false;


            }


    }

    }


    cout << "Programmet avslutas" << endl;
    return 0;

}
