//
// Created by Kieran McNamara on 08/04/2022.
//

#ifndef ADVENTOFCODE_SEATING_ARRANGER_H
#define ADVENTOFCODE_SEATING_ARRANGER_H

#include <cstdint>
#include <string>

struct SeatingNeighbour {
    std::string str_neighbour;
    int i32_happiness;
    SeatingNeighbour* pt_next;
};

class SeatingArranger {
public:
    SeatingArranger();
    ~SeatingArranger();
    void AddEdge(const std::string& str_characterName, const std::string& str_neighbourName, int i32_happiness);
    void ProcessArrangements();
    int GetOptimalArrangement() const;
    void PrintOptimalArrangement();
    void PrintMap();

protected:
    SeatingNeighbour* GetNeighboursHead(const std::string &str_characterName);
    void UpdateMap(const std::string& str_characterName, const std::string& str_neighbourName, int i32_happiness);

    int _i32_optimalArrangement;
    std::string _str_optimalArrangement;
    std::map<std::string, SeatingNeighbour*> _map_graph;
};

#endif //ADVENTOFCODE_SEATING_ARRANGER_H
