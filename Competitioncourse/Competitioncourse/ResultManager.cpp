#include "ResultManager.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace CompetitionLib;
using namespace std;

void ResultManager::addCompetition(const Competition& competition) {
    competitions[competition.getName()] = competition;
}

void ResultManager::addParticipantToCompetition(const std::string& competitionName, const Participant& participant) {
    competitions[competitionName].addParticipant(participant);
}

void ResultManager::removeParticipantFromCompetition(const std::string& competitionName, int participantId) {
    competitions[competitionName].removeParticipant(participantId);
}

void ResultManager::recordRoundResult(const std::string& competitionName, int participantId, int round, int result) {
    competitions[competitionName].recordRoundResult(participantId, round, result);
}

void ResultManager::updateResult(const std::string& competitionName, int participantId, int round, int newResult) {
    competitions[competitionName].updateResult(participantId, round, newResult);
}

void ResultManager::printCompetitionResults(const std::string& competitionName) const {
    auto it = competitions.find(competitionName);
    if (it != competitions.end()) {
        it->second.printResults();
    }
    else {
        cout << "Competition not found.\n";
    }
}

void ResultManager::printFinalResults(const std::string& competitionName) const {
    auto it = competitions.find(competitionName);
    if (it != competitions.end()) {
        it->second.printFinalResults();
    }
    else {
        cout << "Competition not found.\n";
    }
}

Competition& ResultManager::getCompetition(const std::string& competitionName) {
    return competitions.at(competitionName);
}
