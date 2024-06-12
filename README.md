CompetitionCourse
Description:
CompetitionCourse is a C++ class library designed for calculating and displaying the results of sports competitions. The library allows creating competitions, adding participants, recording round results, and generating final results.

Functionality
Participant: Class for storing information about competition participants.
Competition: Class for managing competitions and participant results.
ResultManager: Class for managing multiple competitions.
Installation and Setup in Visual Studio
1.Clone the repository:
 git clone https://github.com/your-username/CompetitionCourse.git

 Open the project in Visual Studio:

Launch Visual Studio.
Open the project by selecting "Open a project or solution" and specifying the path to the .vcxproj file of your project.
Usage
Example of using the library to create a competition, add participants, and record results:

#include "Participant.h"
#include "Competition.h"
#include "ResultManager.h"

int main() {
    ResultManager manager;
    manager.addCompetition(Competition("Running Championship", 3));

    manager.addParticipantToCompetition("Running Championship", Participant("Alice", 1));
    manager.addParticipantToCompetition("Running Championship", Participant("Bob", 2));

    std::vector<std::vector<int>> results = {{15, 13}, {14, 12}, {16, 14}};
    for (int round = 0; round < results.size(); ++round) {
        for (int id = 0; id < results[round].size(); ++id) {
            manager.recordRoundResult("Running Championship", id + 1, round + 1, results[round][id]);
        }
    }

    manager.printCompetitionResults("Running Championship");
    manager.printFinalResults("Running Championship");

    return 0;
}

License
This project is licensed under the MIT License. For more details, see the LICENSE file.

This README.md file provides a general description of the project, installation and usage instructions in Visual Studio, an example code to get started with the library, and information on running tests. It also offers recommendations for other users on how to use the library in their own projects.