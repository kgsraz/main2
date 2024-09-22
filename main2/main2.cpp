#include "staticarray.h"

int main() {
    Graph socialGraph;

    // Добавляем знакомства (рукопожатия)
    socialGraph.addEdge("Олег", "Никита");
    socialGraph.addEdge("Олег", "Настя");
    socialGraph.addEdge("Никита", "Ваня");
    socialGraph.addEdge("Настя", "Ваня");
    socialGraph.addEdge("Настя", "Женя");
    socialGraph.addEdge("Ваня", "Женя");

    // Ищем пары знакомств через три рукопожатия
    socialGraph.findThreeDegreeConnections();

    return 0;
}
