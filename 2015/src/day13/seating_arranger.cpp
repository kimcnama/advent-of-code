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

int SeatingArranger::GetOptimalArrangementScore() const {
    return this->_i32_optimalArrangement;
}

void SeatingArranger::ProcessArrangements() {
    // Largest negative number hex
    this->_i32_optimalArrangement = 0x80000000;
    SeatingNeighbour* p_curr;
    int i32_currCount;
    std::map<std::string, bool> map_visited;

    for (const auto & it : this->_map_graph) {

        i32_currCount = 0;
        for (const auto & it_clear : this->_map_graph) {
            map_visited[it_clear.first] = false;
        }
        std::cout << std::endl;
        this->RecursiveSearch(it.first, it.first, i32_currCount, map_visited, 0);
    }
}

void SeatingArranger::RecursiveSearch(const std::string& str_headName, const std::string& str_currName,
                                      int& i32_currCount, std::map<std::string, bool>& map_visited,
                                      const int i32_happiness) {

    if (map_visited[str_currName]) {
        return;
    }

//    this->_vec_currArrangment.push_back(str_currName);

    SeatingNeighbour* pt_tempNeighbour;
    SeatingNeighbour* pt_currNeighbourHead = this->GetNeighboursHead(str_currName);

    i32_currCount += i32_happiness;
    map_visited[str_currName] = true;

    std::cout << " " << str_currName << " ";

    bool b_allVisited = true;
    for (const auto & it : map_visited) {
        if (!it.second) {
            b_allVisited = false;
            break;
        }
    }

    if (b_allVisited) {
        pt_tempNeighbour = pt_currNeighbourHead;
        while (pt_tempNeighbour != nullptr && pt_tempNeighbour->str_neighbour != str_headName) {
            pt_tempNeighbour = pt_tempNeighbour->pt_next;
        }
        if (pt_tempNeighbour != nullptr) {
            i32_currCount += pt_tempNeighbour->i32_happiness;
        }

        std::cout << " Curr Happiness: " << i32_currCount << std::endl;

        if (i32_currCount > this->_i32_optimalArrangement) {
            this->_i32_optimalArrangement = i32_currCount;
            std::cout << "\nNew Happiness: " << this->_i32_optimalArrangement << std::endl;
            i32_currCount -= i32_happiness;
            map_visited[str_currName] = false;

            if (pt_tempNeighbour != nullptr) {
                i32_currCount -= pt_tempNeighbour->i32_happiness;
            }
        }
        return;
    }

    std::cout << " Curr Happiness: " << i32_currCount << std::endl;

    for (const auto & it : this->_map_graph) {
        if (it.first == str_currName) {
            continue;
        }
        pt_tempNeighbour = pt_currNeighbourHead;
        while (pt_tempNeighbour != nullptr && pt_tempNeighbour->str_neighbour != it.first) {
            pt_tempNeighbour = pt_tempNeighbour->pt_next;
        }
        this->RecursiveSearch(str_headName, it.first, i32_currCount, map_visited, pt_tempNeighbour->i32_happiness);
    }

    i32_currCount -= i32_happiness;
    map_visited[str_currName] = false;
}

void SeatingArranger::AddEdge(const std::string &str_characterName, const std::string &str_neighbourName,
                              int i32_happiness) {
    this->UpdateMap(str_characterName, str_neighbourName, i32_happiness);
    this->UpdateMap(str_neighbourName, str_characterName, i32_happiness);
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

    SeatingNeighbour* pt_curr = this->GetNeighboursHead(str_characterName);
    SeatingNeighbour* pt_tail;

    if (pt_curr == nullptr) {
        SeatingNeighbour* sn = CreateNewNeighbour(str_neighbourName, i32_happiness);
        this->_map_graph[str_characterName] = sn;
    } else {

        do {
            if (pt_curr->str_neighbour == str_neighbourName) {
                pt_curr->i32_happiness += i32_happiness;
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
