#include "Competition.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <numeric> // Для використання std::accumulate

using namespace CompetitionLib;
using namespace std;

Competition::Competition(const std::string& name, int numRounds)
    : name(name), numRounds(numRounds) {}

void Competition::addParticipant(const Participant& participant) {
    participants.push_back(participant);
    roundResults[participant.getId()] = vector<int>(numRounds, 0); 
}

void Competition::removeParticipant(int participantId) {
    participants.erase(
        remove_if(participants.begin(), participants.end(),
            [participantId](const Participant& p) { return p.getId() == participantId; }),
        participants.end());
    roundResults.erase(participantId); 
}

void Competition::recordRoundResult(int participantId, int round, int result) {
    if (round < 1 || round > numRounds) {
        throw std::out_of_range("Invalid round number");
    }
    roundResults[participantId][round - 1] = result; 
}

void Competition::updateResult(int participantId, int round, int newResult) {
    if (round < 1 || round > numRounds) {
        throw std::out_of_range("Invalid round number");
    }
    roundResults[participantId][round - 1] = newResult;
}

void Competition::printResults() const {
    cout << "Results for competition: " << name << "\n";
    for (const auto& participant : participants) {
        cout << "Participant ID: " << participant.getId() << ", Name: " << participant.getName() << "\n";
        for (int round = 1; round <= numRounds; ++round) {
            int result = getRoundResult(participant.getId(), round);
            cout << "  Round " << round << ": " << (result != -1 ? to_string(result) : "N/A") << endl;
        }
    }
}

void Competition::printFinalResults() const {
    cout << "Final Results for competition: " << name << "\n";
    vector<pair<int, int>> finalResults; // pair<participantId, totalResult>

    for (const auto& participant : participants) {
        int totalResult = accumulate(roundResults.at(participant.getId()).begin(), roundResults.at(participant.getId()).end(), 0);
        finalResults.push_back({ participant.getId(), totalResult });
    }

    sort(finalResults.begin(), finalResults.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
        });

    for (size_t i = 0; i < finalResults.size(); ++i) {
        int participantId = finalResults[i].first;
        int totalResult = finalResults[i].second;
        Participant participant = getParticipant(participantId);
        cout << i + 1 << ". Participant ID: " << participantId << ", Name: " << participant.getName() << ", Total Result: " << totalResult << endl;
    }
}

std::string Competition::getName() const {
    return name;
}

int Competition::getNumRounds() const {
    return numRounds;
}

const std::vector<Participant>& Competition::getParticipants() const {
    return participants;
}

int Competition::getRoundResult(int participantId, int round) const {
    if (round < 1 || round > numRounds) {
        throw std::out_of_range("Invalid round number");
    }
    auto it = roundResults.find(participantId);
    return it != roundResults.end() ? it->second[round - 1] : -1;
}

std::unordered_map<int, std::vector<int>> Competition::getRoundResults() const {
    return roundResults;
}

Participant Competition::getParticipant(int participantId) const {
    for (const auto& participant : participants) {
        if (participant.getId() == participantId) {
            return participant;
        }
    }
    throw std::invalid_argument("Participant not found");
}
