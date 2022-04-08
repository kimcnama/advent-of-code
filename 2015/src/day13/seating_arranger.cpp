//
// Created by Kieran McNamara on 08/04/2022.
//

#include <cstdint>
#include <string>
#include <map>
#include <utility>
#include <iostream>
#include "../../inc/day13/seating_arranger.h"

SeatingArranger::SeatingArranger() {
    this->_i32_optimalArrangement = 0;
}

SeatingArranger::~SeatingArranger() {
    SeatingNeighbour* head;
    SeatingNeighbour* curr;
    for (auto & it : this->_map_graph) {
        head = it.second;
        while (head != nullptr) {
            curr = head;
            head = head->pt_next;
            free(curr);
        }
    }
};

int SeatingArranger::GetOptimalArrangement() const {
    return this->_i32_optimalArrangement;
}

void SeatingArranger::ProcessArrangements() {
    this->_i32_optimalArrangement = 0;
}

void SeatingArranger::AddEdge(const std::string &str_characterName, const std::string &str_neighbourName,
                              int i32_happiness) {
    this->UpdateMap(str_characterName, str_neighbourName, i32_happiness);
    this->UpdateMap(str_neighbourName, str_characterName, i32_happiness);
}

void SeatingArranger::PrintOptimalArrangement() {
    return;
}


static SeatingNeighbour* CreateNewNeighbour(const std::string& str_neighbourName, int i32_NeighbourHappiness) {
    auto* sn = new SeatingNeighbour;
    sn->pt_next = nullptr;
    sn->i32_happiness = i32_NeighbourHappiness;
    sn->str_neighbour = str_neighbourName;
    return sn;
}


void SeatingArranger::UpdateMap(const std::string &str_characterName, const std::string &str_neighbourName,
                                int i32_happiness) {

    bool b_alreadyNeighbour = false;
    SeatingNeighbour* pt_curr = this->GetNeighboursHead(str_characterName);
    SeatingNeighbour* pt_tail;

    if (pt_curr == nullptr) {
        SeatingNeighbour* sn = CreateNewNeighbour(str_neighbourName, i32_happiness);
        this->_map_graph[str_characterName] = sn;
    } else {

        do {
            if (pt_curr->str_neighbour == str_neighbourName) {
                pt_curr->i32_happiness = i32_happiness;
                return;
            }
            pt_tail = pt_curr;
            pt_curr = pt_curr->pt_next;
        } while (pt_curr != nullptr);

        pt_tail->pt_next = CreateNewNeighbour(str_neighbourName, i32_happiness);

    }

}

SeatingNeighbour *SeatingArranger::GetNeighboursHead(const std::string &str_characterName) {
    auto it = this->_map_graph.find(str_characterName);
    if (this->_map_graph.end() == it ) {
        return nullptr;
    } else {
        return it->second;
    }
}

void SeatingArranger::PrintMap() {
    SeatingNeighbour* curr;

    std::cout << "Map: ";
    for (auto & it : this->_map_graph) {
        std::cout << std::endl << it.first << ": ";
        curr = it.second;
        while (curr != nullptr) {
            std::cout << curr->str_neighbour << "(" << curr->i32_happiness << "), ";
            curr = curr->pt_next;
        }
    }
}




