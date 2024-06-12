#include "Participant.h"

using namespace CompetitionLib;
using namespace std;

Participant::Participant(const string& name, int id) : name(name), id(id) {}

string Participant::getName() const {
    return name;
}

int Participant::getId() const {
    return id;
}
