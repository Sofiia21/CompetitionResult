# CompetitionCourse

## ����
`CompetitionCourse` - �� �������� ����� �� ��� ������������� C++ ��� ��������� �� ��������� ���������� ���������� �������. ��������� �������� ���������� ��������, �������� ��������, ���������� ���������� �� ������� �� ��������� �������� ����������.

## ���������������
- **Participant**: ���� ��� ��������� ���������� ��� �������� �������.
- **Competition**: ���� ��� ��������� ���������� �� ������������ ��������.
- **ResultManager**: ���� ��� ��������� ��������� ����������.

## ������������ �� ������������ � Visual Studio

1. **���������� ����������**:
   ```sh
   git clone https://github.com/���-����������/CompetitionCourse.git

 2.  ³������� ������� � Visual Studio:

 �������� Visual Studio.
 ³������� ������, �������� ����� "Open a project or solution" �� �������� ���� �� ����� .vcxproj ������ �������.

 ������������:
 ������� ������������ �������� ��� ��������� ��������, ��������� �������� �� ������ ����������:

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


˳�����:
��� ������ ����������� �� ����糺� MIT. ��������� ������� � ���� LICENSE.

��� ���� README.md ������ ��������� ���� �������, ���������� ���� ������������ �� ������������ � Visual Studio, ������� ���� ��� ������� ������ � ��������� � ���������� ��� ������ �����. ����� �� ���� ������������ ��� ����� ������������ ���� ������������ �������� � ������� ��������.