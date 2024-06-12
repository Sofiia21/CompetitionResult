#ifndef RESULTMANAGER_H
#define RESULTMANAGER_H

#include "Competition.h"
#include <unordered_map>

namespace CompetitionLib {

    class ResultManager {
    private:
        std::unordered_map<std::string, Competition> competitions;

    public:
        void addCompetition(const Competition& competition);
        void addParticipantToCompetition(const std::string& competitionName, const Participant& participant);
        void removeParticipantFromCompetition(const std::string& competitionName, int participantId);
        void recordRoundResult(const std::string& competitionName, int participantId, int round, int result);
        void updateResult(const std::string& competitionName, int participantId, int round, int newResult);
        void printCompetitionResults(const std::string& competitionName) const;
        void printFinalResults(const std::string& competitionName) const;
        Competition& getCompetition(const std::string& competitionName); 
    };

} // namespace CompetitionLib

#endif // RESULTMANAGER_H
