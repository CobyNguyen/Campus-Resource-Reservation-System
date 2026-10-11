#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "../include/Reservation.h"
#include "../include/ReservationManager.h"
#include "../include/Resource.h"

using namespace std;

const int COMMAND_LENGTH = 10;
string VALID_COMMANDS[COMMAND_LENGTH] = { "create reservation", "cancel reservation", "undo cancellation", "show available resources", "show all resources", "show reservations", "show waiting lists", "generate reports", "sort resources", "exit"};

string userInput = "";
int userCommand = -1;


vector<Resource> currentResources; //Will contain info from data/resources.txt


void readResourcesFile(string inputFile){ //reads from the supplied file and populates currentResources with new resource objects
    ifstream file = ifstream();
    file.open(inputFile);

    string line;

    if (file.is_open()){
        while (getline(file, line)){
            string resourceID;
            string resourceName;
            string resourceType;
            bool availability;
            
            int next = line.find('|');
            resourceID = line.substr(0, next);
            line = line.substr(next + 1);

            next = line.find('|');
            resourceName = line.substr(0, next);
            line = line.substr(next + 1);

            next = line.find('|');
            resourceType = line.substr(0, next);
            line = line.substr(next + 1);

            availability = (line == "Available");


            Resource newResource = Resource(resourceID, resourceName, resourceType, availability);
            currentResources.push_back(newResource);
        }
    }
    else{
        cout << "Failed to read data from: " << inputFile << endl;
    }

    file.close();
}

void displayAvailableResources(){
    for (size_t i = 0; i < currentResources.size(); i++){
        Resource newRs = currentResources.at(i);
        if (newRs.getAvailability()){
            newRs.print();
        }
    }
}

void displayAllResources(){
    for (size_t i = 0; i < currentResources.size(); i++){
        Resource newRs = currentResources.at(i);
        newRs.print();
    }
}

void showAllCommands(){
    cout << "Valid commands:" << endl;
    for (int i = 0; i < COMMAND_LENGTH; i++){
        cout << " - " << VALID_COMMANDS[i] << endl;
    }
    cout << endl;
}

//Since we are dealing with C++ Strings, we need our own toLower method
string stringToLowercase(string str){ //Returns a lowercase version of the input string
    string out = str;
    for (size_t i = 0; i < out.length(); i++){ //Replaces each character in the string with its lowecase counterpart
        out.at(i) = tolower(out.at(i));
    }
    return out;
}

//Implementation derived and modified from https://www.geeksforgeeks.org/cpp/cpp-program-for-quicksort/
int partition(vector<Resource>& vec, int low, int high, int condition){

    Resource pivot = vec[high];

    int i = low - 1;

    for (int j = low; j < high; j++){

        if (condition == 0){
            if (vec[j].getResourceID() <= pivot.getResourceID()){
                i++;
                swap(vec[i], vec[j]);
            }
        }
        if (condition == 1){
            if (vec[j].getResourceName() <= pivot.getResourceName()){
                i++;
                swap(vec[i], vec[j]);
            }
        }
        if (condition == 2){
            if (vec[j].getAvailability() >= pivot.getAvailability()){ //want to put available objects at the top
                i++;
                swap(vec[i], vec[j]);
            }
        }
        
    }

    swap(vec[i + 1], vec[high]);

    return i + 1;
}

void quickSort(vector<Resource>& vec, int low, int high, int condition){

    if (low < high){

        int part = partition(vec, low, high, condition);
        
        quickSort(vec, low, part - 1, condition);

        quickSort(vec, part + 1, high, condition);
    }

}

void sortReservations(){
    cout << "Sort by ID, Name, or Availability?: ";
    string input = "ID";
    cin >> input;

    input = stringToLowercase( input);

    cin.clear();
    cin.ignore();

    if (input == "id"){
        quickSort(currentResources, 0, currentResources.size() - 1, 0);
    }
    else if (input == "name"){
        quickSort(currentResources, 0, currentResources.size() - 1, 1);
    }
    else if (input == "availability"){
        quickSort(currentResources, 0, currentResources.size() - 1, 2);
    }
    else{
        cout << "\nInvalid input... aborting.";
    }
}

void runCommand(int commandIndex, ReservationManager& reservationManager){ //Any new commands and their logic should go here. Complex commands should be given their own method that is then called through this switch case.
    switch (commandIndex) {
        case 0: //Create Reservation
            reservationManager.createReservation(currentResources);
            break;

        case 1: //Cancel Reservation
            reservationManager.cancelReservation(currentResources);
            break;

        case 2: //Undo Cancellation
            reservationManager.undoCancellation(currentResources);
            break;

        case 3: //Show available resources
            displayAvailableResources();
            break;

        case 4: //Show all resources
            displayAllResources();
            break;

        case 5: //Show reservations
            reservationManager.displayReservations();
            break;
        
        case 6: //Show waiting lists
            reservationManager.displayWaitingLists();
            break;
        
        case 7: //generate reports
            cout << "Generating reports..." << endl;
            reservationManager.reportActiveReservationsCount();
            reservationManager.reportCurrentAvailability(currentResources);
            break;   

        case 8: //Sort resources by Name, ID, or Availability 
            sortReservations();
            break;

        case 9: //Exit
            cout << "Exiting...";
            break;

        default:
            cout << "Command '" << userInput << "' not found..." << endl;
            showAllCommands();
    };
}

int validateCommand(string commandEntered){ //Returns the index of the input command if the command is contained in VALID_COMMANDS. Otherwise outputs -1
    int valid = -1;
    for (int i = 0; i < COMMAND_LENGTH; i++){
        if (stringToLowercase(commandEntered) == VALID_COMMANDS[i]){
            valid = i;
            break;
        }
    }
    return valid;
}



int main(){
    ReservationManager reservationManager;

    readResourcesFile("./data/resources.txt");

    //If the exit command index is changed, make sure to update the exit condition for the main loop!
    while (userCommand != 9){ //Main user input loop; 
        cout << endl;
        showAllCommands();
        cout << "Please enter a command: ";
        if (!getline(cin, userInput)) {
            cout << endl << "Input closed. Exiting..." << endl;
            break;
        }
        cout << endl;

        userCommand = validateCommand(userInput);
        runCommand(userCommand, reservationManager);
        //Validates then runs the command the user input
    }

    exit(0);
}