#include "staticarray.h"

// Добавление ребра между двумя людьми
void Graph::addEdge(const std::string& person1, const std::string& person2) {
    adjList[person1].insert(person2);
    adjList[person2].insert(person1); // Граф неориентированный
}

// Поиск всех пар знакомств через три рукопожатия
void Graph::findThreeDegreeConnections() const {
    for (const auto& person : adjList) {
        const std::string& first = person.first;
        const auto& friends1 = person.second;

        // Создаем множество для хранения друзей на трех рукопожатиях
        std::set<std::string> friendsOfFriends;

        // Проходим по друзьям первого человека
        for (const auto& friend1 : friends1) {
            // Получаем друзей первого друга
            const auto& friends2 = adjList.at(friend1);
            for (const auto& friend2 : friends2) {
                if (friend2 != first && friends1.find(friend2) == friends1.end()) {
                    friendsOfFriends.insert(friend2);
                }
            }
        }

        // Выводим результаты для текущего человека
        std::cout << "Пары знакомых через три рукопожатия для " << first << ":" << std::endl;
        for (const auto& friendOfFriend : friendsOfFriends) {
            std::cout << "  " << first << " - " << friendOfFriend << std::endl;
        }
    }
}
