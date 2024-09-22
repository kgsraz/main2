#pragma once
#ifndef STATICARRAY_H
#define STATICARRAY_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>

class Graph {
public:
    void addEdge(const std::string& person1, const std::string& person2);
    void findThreeDegreeConnections() const;

private:
    std::unordered_map<std::string, std::set<std::string>> adjList;
};

#endif // STATICARRAY_H
