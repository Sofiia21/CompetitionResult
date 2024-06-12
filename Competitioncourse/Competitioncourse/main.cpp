#include "Participant.h"
#include "Competition.h"
#include "ResultManager.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace CompetitionLib;
using namespace std;


void printMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add Participant\n";
    cout << "2. Remove Participant\n";
    cout << "3. Record Results for All Rounds\n";
    cout << "4. Update Result\n";
    cout << "5. Print Competition Results\n";
    cout << "6. Print Final Results\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}


Competition createCompetition() {
    string competitionName;
    int numRounds = 0;
    cout << "Enter competition name: ";
    cin.ignore(); 
    getline(cin, competitionName);
    cout << "Enter number of rounds: ";
    while (!(cin >> numRounds) || numRounds <= 0) {
        cout << "Invalid input. Please enter a positive number.\n";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Enter number of rounds: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    return Competition(competitionName, numRounds);
}

template <typename T>
T getValidatedInput(const string& prompt) {
    T value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            break;
        }
        else {
            cout << "Invalid input. Please enter a valid number.\n";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }
    return value;
}

int main() {
    ResultManager manager;
    Competition currentCompetition = createCompetition();
    manager.addCompetition(currentCompetition);

    int nextParticipantId = 1; 

    while (true) {
        printMenu();
        int choice = getValidatedInput<int>("");

        if (choice == 0) break;

        string participantName;
        int participantId, round, result;

        switch (choice) {
        case 1:
            participantId = nextParticipantId++;
            cout << "Enter participant's name: ";
            getline(cin, participantName);
            manager.addParticipantToCompetition(currentCompetition.getName(), Participant(participantName, participantId));
            cout << "Added " << participantName << " with ID " << participantId << endl;
            break;

        case 2:
            participantId = getValidatedInput<int>("Enter participant's ID to remove: ");
            manager.removeParticipantFromCompetition(currentCompetition.getName(), participantId);
            cout << "Removed participant with ID " << participantId << endl;
            break;

        case 3:
            currentCompetition = manager.getCompetition(currentCompetition.getName());
            if (currentCompetition.getParticipants().empty()) {
                cout << "No participants in the competition. Please add participants first.\n";
                break;
            }
            for (int round = 1; round <= currentCompetition.getNumRounds(); ++round) {
                cout << "Round " << round << ":\n";
                for (const auto& participant : currentCompetition.getParticipants()) {
                    result = getValidatedInput<int>("Enter result for participant " + participant.getName() + " (ID: " + to_string(participant.getId()) + "): ");
                    manager.recordRoundResult(currentCompetition.getName(), participant.getId(), round, result);
                }
            }
            break;

        case 4:
            participantId = getValidatedInput<int>("Enter participant's ID: ");
            round = getValidatedInput<int>("Enter round number: ");
            result = getValidatedInput<int>("Enter new result: ");
            manager.updateResult(currentCompetition.getName(), participantId, round, result);
            cout << "Updated result to " << result << " for participant ID " << participantId << " in round " << round << endl;
            break;

        case 5:
            manager.printCompetitionResults(currentCompetition.getName());
            break;

        case 6:
            manager.printFinalResults(currentCompetition.getName());
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
