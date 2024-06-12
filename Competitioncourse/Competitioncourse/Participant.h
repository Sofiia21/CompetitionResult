#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>

namespace CompetitionLib {

    class Participant {
    private:
        std::string name;
        int id;

    public:
        Participant(const std::string& name, int id);
        std::string getName() const;
        int getId() const;
    };

} // namespace CompetitionLib

#endif // PARTICIPANT_H
