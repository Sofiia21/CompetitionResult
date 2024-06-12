# CompetitionCourse

## Опис
`CompetitionCourse` - це бібліотека класів на мові програмування C++ для підрахунку та виведення результатів спортивних змагань. Бібліотека дозволяє створювати змагання, додавати учасників, записувати результати по раундах та формувати підсумкові результати.

## Функціональність
- **Participant**: клас для зберігання інформації про учасників змагань.
- **Competition**: клас для управління змаганнями та результатами учасників.
- **ResultManager**: клас для управління декількома змаганнями.

## Встановлення та налаштування у Visual Studio

1. **Клонування репозиторію**:
   ```sh
   git clone https://github.com/ваш-користувач/CompetitionCourse.git

 2.  Відкриття проекту у Visual Studio:

 Запустіть Visual Studio.
 Відкрийте проект, вибравши опцію "Open a project or solution" та вказавши шлях до файлу .vcxproj вашого проекту.

 Використання:
 Приклад використання бібліотеки для створення змагання, додавання учасників та запису результатів:

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


Ліцензія:
Цей проект ліцензований під ліцензією MIT. Детальніше дивіться у файлі LICENSE.

Цей файл README.md містить загальний опис проекту, інструкції щодо встановлення та використання у Visual Studio, приклад коду для початку роботи з бібліотекою і інформацію про запуск тестів. Також він надає рекомендації для інших користувачів щодо використання бібліотеки у власних проектах.