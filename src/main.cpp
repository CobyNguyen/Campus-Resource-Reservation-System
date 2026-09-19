#include <cctype>
#include <cstdlib>
#include <string>
#include <iostream>
#include "../include/Reservation.h"
#include "../include/ReservationManager.h"

using namespace std;


string VALID_COMMANDS[4] = { "exit", "create reservation", "cancel reservation", "undo cancellation"};
string userInput = "";
int userCommand = -1;

//Since we are dealing with C++ Strings, we need our own toLower method
string stringToLowercase(string str){ //Returns a lowercase version of the input string
    string out = str;
    for (int i = 0; i < out.length(); i++){ //Replaces each character in the string with its lowecase counterpart
        out.at(i) = tolower(out.at(i));
    }
    return out;
}

void runCommand(int commandIndex){
    switch (commandIndex){
        case 0: //Exit
            cout << "Exiting...";
            break;

        case 1: //Create Reservation
            cout << "Create Reservation N/A" << endl;
            break;

        case 2: //Cancel Reservation
            cout << "Cancel Reservation N/A" << endl;
            break;

        case 3: //Undo Cancellation
            cout << "Undo Cancellation N/A" << endl;
            break;

        default:
            cout << "Command '" << userInput << "' not found..." << endl;
            cout << "Valid commands:" << endl;
            for (int i = 0; i < VALID_COMMANDS->size(); i++){
                cout << " - " << VALID_COMMANDS[i] << endl;
            }
    };
}

int validateCommand(string commandEntered){ //Returns the index of the input command if the command is contained in VALID_COMMANDS. Otherwise outputs -1
    int valid = -1;
    for (int i = 0; i < VALID_COMMANDS->size(); i++){
        if (stringToLowercase(commandEntered) == VALID_COMMANDS[i]){
            valid = i;
            break;
        }
    }
    return valid;
}

int main(){

    while (userCommand != 0){ //Main user input loop
        cout << "Please enter a command: ";
        cin.clear();
        getline(cin, userInput);
        cout << endl;

        userCommand = validateCommand(userInput);
        runCommand(userCommand);
        //Validates then runs the command the user input
    }

    exit(0);
}