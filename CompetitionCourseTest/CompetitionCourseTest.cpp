#include "Participant.h"
#include "Competition.h"
#include "ResultManager.h"
#include <iostream>
#include <cassert>

using namespace CompetitionLib;
using namespace std;

void testParticipant() {
    Participant p("Alice", 1);
    assert(p.getName() == "Alice");
    assert(p.getId() == 1);
    cout << "Participant tests passed!" << endl;
}

void testCompetition() {
    Competition c("Sprint", 3);
    Participant p1("Alice", 1);
    Participant p2("Bob", 2);

    c.addParticipant(p1);
    c.addParticipant(p2);

    auto participants = c.getParticipants();
    assert(participants.size() == 2);

    c.removeParticipant(1);
    participants = c.getParticipants();
    assert(participants.size() == 1);
    assert(participants[0].getId() == 2);

    c.recordRoundResult(2, 1, 10);
    assert(c.getRoundResult(2, 1) == 10);

    c.updateResult(2, 1, 15);
    assert(c.getRoundResult(2, 1) == 15);

    cout << "Competition tests passed!" << endl;
}

void testResultManager() {
    ResultManager manager;
    Competition c("Sprint", 3);
    Participant p1("Alice", 1);
    Participant p2("Bob", 2);

    manager.addCompetition(c);
    manager.addParticipantToCompetition("Sprint", p1);
    manager.addParticipantToCompetition("Sprint", p2);

    auto& competition = manager.getCompetition("Sprint");
    auto participants = competition.getParticipants();
    assert(participants.size() == 2);
    assert(participants[0].getName() == "Alice");
    assert(participants[1].getName() == "Bob");

    manager.recordRoundResult("Sprint", 1, 1, 10);
    manager.recordRoundResult("Sprint", 1, 2, 15);
    manager.recordRoundResult("Sprint", 1, 3, 20);

    manager.recordRoundResult("Sprint", 2, 1, 5);
    manager.recordRoundResult("Sprint", 2, 2, 10);
    manager.recordRoundResult("Sprint", 2, 3, 15);

    competition = manager.getCompetition("Sprint");
    assert(competition.getRoundResult(1, 1) == 10);
    assert(competition.getRoundResult(1, 2) == 15);
    assert(competition.getRoundResult(1, 3) == 20);
    assert(competition.getRoundResult(2, 1) == 5);
    assert(competition.getRoundResult(2, 2) == 10);
    assert(competition.getRoundResult(2, 3) == 15);

    manager.updateResult("Sprint", 1, 3, 25);
    competition = manager.getCompetition("Sprint");
    assert(competition.getRoundResult(1, 3) == 25);

    cout << "ResultManager tests passed!" << endl;
}

int main() {
    testParticipant();
    testCompetition();
    testResultManager();
    cout << "All tests passed!" << endl;
    return 0;
}
