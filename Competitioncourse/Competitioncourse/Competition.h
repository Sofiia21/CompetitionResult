#ifndef COMPETITION_H
#define COMPETITION_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Participant.h"

namespace CompetitionLib {

    class Competition {
    private:
        std::string name;
        int numRounds; 
        std::vector<Participant> participants;
        std::unordered_map<int, std::vector<int>> roundResults; 

    public:
        Competition() = default; 
        Competition(const std::string& name, int numRounds);

        void addParticipant(const Participant& participant);
        void removeParticipant(int participantId);
        void recordRoundResult(int participantId, int round, int result);
        void updateResult(int participantId, int round, int newResult);
        void printResults() const;
        void printFinalResults() const; 
        std::string getName() const;
        int getNumRounds() const; 
        const std::vector<Participant>& getParticipants() const;
        int getRoundResult(int participantId, int round) const;
        std::unordered_map<int, std::vector<int>> getRoundResults() const;
        Participant getParticipant(int participantId) const;
    };

} // namespace CompetitionLib

#endif // COMPETITION_H
