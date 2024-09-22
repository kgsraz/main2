#include "staticarray.h"

// ���������� ����� ����� ����� ������
void Graph::addEdge(const std::string& person1, const std::string& person2) {
    adjList[person1].insert(person2);
    adjList[person2].insert(person1); // ���� �����������������
}

// ����� ���� ��� ��������� ����� ��� �����������
void Graph::findThreeDegreeConnections() const {
    for (const auto& person : adjList) {
        const std::string& first = person.first;
        const auto& friends1 = person.second;

        // ������� ��������� ��� �������� ������ �� ���� ������������
        std::set<std::string> friendsOfFriends;

        // �������� �� ������� ������� ��������
        for (const auto& friend1 : friends1) {
            // �������� ������ ������� �����
            const auto& friends2 = adjList.at(friend1);
            for (const auto& friend2 : friends2) {
                if (friend2 != first && friends1.find(friend2) == friends1.end()) {
                    friendsOfFriends.insert(friend2);
                }
            }
        }

        // ������� ���������� ��� �������� ��������
        std::cout << "���� �������� ����� ��� ����������� ��� " << first << ":" << std::endl;
        for (const auto& friendOfFriend : friendsOfFriends) {
            std::cout << "  " << first << " - " << friendOfFriend << std::endl;
        }
    }
}
