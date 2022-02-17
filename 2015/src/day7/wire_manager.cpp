//
// Created by kieran McNamara on 19/12/2021.
//

#include <iostream>
#include "../../inc/day7/wire_manager.h"

WireManager::WireManager() {
  _map_wires.clear();
}
void WireManager::PrintWireValues() {
  std::cout << std::endl;
  std::cout << "Wire: Signal" << std::endl;
  for (auto const & [str_wireName, p_wire] : _map_wires) {
    std::cout << str_wireName << ": " << p_wire->GetSignalVal() << std::endl;
  }
}

static bool IsNumber(const std::string& str) {
  return str.find_first_not_of("0123456789") == std::string::npos;
}

void WireManager::SetWire(const std::string& str_wireName, uint16_t u16_val) {

  Wire* p_wire;

  if (this->IsWireInMap(str_wireName)) {

    p_wire = _map_wires.at(str_wireName);
    p_wire->SetSignalVal(u16_val);

  } else {

    p_wire = new Wire(u16_val);
    _map_wires.insert({str_wireName, p_wire});

  }
}
bool WireManager::IsWireInMap(const std::string& str_wireName) {
  return !(_map_wires.find(str_wireName) == _map_wires.end());
}

Wire* WireManager::GetWire(const std::string &str_wireName) {
  for (auto const & [str_wire, p_wire] : _map_wires) {
    if (str_wireName == str_wire) {
      return p_wire;
    }
  }
  
  std::cerr << "Error could not find " << str_wireName << " in map.";
   
  return nullptr;
}

WireManager::~WireManager() {
    for (auto const & [str_wireName, p_wire] : _map_wires) {
      free(p_wire);
    }
  _map_wires.clear();
}

void WireManager::And(const std::string &str_dest, const std::string &str_w1, const std::string &str_w2) {
  Wire* p_w1 = this->GetWire(str_w1);
  Wire* p_w2 = this->GetWire(str_w2);

  if (!this->IsWireInMap(str_dest)) {
    SetWire(str_dest, 0);
  }
  
  Wire *p_wDest = this->GetWire(str_dest);
  p_wDest->And(p_w1, p_w2);
}

void WireManager::Or(const std::string& str_dest, const std::string& str_w1, const std::string& str_w2) {
  Wire* p_w1 = this->GetWire(str_w1);
  Wire* p_w2 = this->GetWire(str_w2);

  if (!this->IsWireInMap(str_dest)) {
    SetWire(str_dest, 0);
  }
  
  Wire *p_wDest = this->GetWire(str_dest);
  p_wDest->Or(p_w1, p_w2);
}
void WireManager::Not(const std::string& str_dest, const std::string& str_w1) {
  Wire* p_w1 = this->GetWire(str_w1);

  if (!this->IsWireInMap(str_dest)) {
    SetWire(str_dest, 0);
  }
  
  Wire *p_wDest = this->GetWire(str_dest);
  p_wDest->Not(p_w1);
}
void WireManager::LShift(const std::string& str_dest, const std::string& str_w1, uint16_t u16_n) {
  Wire* p_w1 = this->GetWire(str_w1);

  if (!this->IsWireInMap(str_dest)) {
    SetWire(str_dest, 0);
  }
  
  Wire *p_wDest = this->GetWire(str_dest);
  p_wDest->LShift(p_w1, u16_n);
}

void WireManager::RShift(const std::string& str_dest, const std::string& str_w1, uint16_t u16_n) {
  Wire* p_w1 = this->GetWire(str_w1);

  if (!this->IsWireInMap(str_dest)) {
    SetWire(str_dest, 0);
  }
  
  Wire *p_wDest = this->GetWire(str_dest);
  p_wDest->RShift(p_w1, u16_n);
}

bool WireManager::ExeInstructionLine(std::string &str_instruction) {

  std::string AND = " AND ";
  std::string OR = " OR ";
  std::string NOT = "NOT ";
  std::string LSHIFT = " LSHIFT ";
  std::string RSHIFT = " RSHIFT ";
  std::string EQUALS = " -> ";

  std::string str_dest = str_instruction.substr(str_instruction.find(EQUALS) + EQUALS.size());
  std::string str_equalsRemoved = str_instruction.substr(0, str_instruction.find(EQUALS));

  std::string w1, w2;

  if (str_equalsRemoved.find(AND) != std::string::npos) {

    w1 = str_equalsRemoved.substr(0, str_equalsRemoved.find(AND));
    w2 = str_equalsRemoved.substr(str_equalsRemoved.find(AND)+ AND.size());

    if (IsNumber(w1) && !this->IsWireInMap(w1)) {
      this->SetWire(w1, (uint16_t)std::atoi(w1.c_str()));
    }

    if (IsNumber(w2) && !this->IsWireInMap(w2)) {
      this->SetWire(w2, (uint16_t)std::atoi(w2.c_str()));
    }

    if (this->IsWireInMap(w1) && this->IsWireInMap(w2)) {
      this->And(str_dest, w1, w2);
    } else {
      return false;
    }

  } else if (str_equalsRemoved.find(OR) != std::string::npos) {

    w1 = str_equalsRemoved.substr(0, str_equalsRemoved.find(OR));
    w2 = str_equalsRemoved.substr(str_equalsRemoved.find(OR) + OR.size());

    if (IsNumber(w1) && !this->IsWireInMap(w1)) {
      this->SetWire(w1, (uint16_t)std::atoi(w1.c_str()));
    }

    if (IsNumber(w2) && !this->IsWireInMap(w2)) {
      this->SetWire(w2, (uint16_t)std::atoi(w2.c_str()));
    }

    if (this->IsWireInMap(w1) && this->IsWireInMap(w2)) {
      this->Or(str_dest, w1, w2);
    } else {
      return false;
    }

  } else if (str_equalsRemoved.find(NOT) != std::string::npos) {

    w1 = str_equalsRemoved.substr(NOT.size());

    if (IsNumber(w1) && !this->IsWireInMap(w1)) {
      this->SetWire(w1, (uint16_t)std::atoi(w1.c_str()));
    }

    if (this->IsWireInMap(w1)) {
      this->Not(str_dest, w1);
    } else {
      return false;
    }

  } else if (str_equalsRemoved.find(LSHIFT) != std::string::npos) {

    w1 = str_equalsRemoved.substr(0, str_equalsRemoved.find(LSHIFT));
    w2 = str_equalsRemoved.substr(str_equalsRemoved.find(LSHIFT) + LSHIFT.size());

    if (IsNumber(w1) && !this->IsWireInMap(w1)) {
      this->SetWire(w1, (uint16_t)std::atoi(w1.c_str()));
    }

    if (IsNumber(w2) && !this->IsWireInMap(w2)) {
      this->SetWire(w2, (uint16_t)std::atoi(w2.c_str()));
    }

    if (this->IsWireInMap(w1)) {
      this->LShift(str_dest, w1, std::atoi(w2.c_str()));
    } else {
      return false;
    }

  } else if (str_equalsRemoved.find(RSHIFT) != std::string::npos) {

    w1 = str_equalsRemoved.substr(0, str_equalsRemoved.find(RSHIFT));
    w2 = str_equalsRemoved.substr(str_equalsRemoved.find(RSHIFT) + RSHIFT.size());

    if (IsNumber(w1) && !this->IsWireInMap(w1)) {
      this->SetWire(w1, (uint16_t)std::atoi(w1.c_str()));
    }

    if (IsNumber(w2) && !this->IsWireInMap(w2)) {
      this->SetWire(w2, (uint16_t)std::atoi(w2.c_str()));
    }

    if (this->IsWireInMap(w1)) {
      this->RShift(str_dest, w1, (uint16_t)std::atoi(w2.c_str()));
    } else {
      return false;
    }

  } else {

    if (!IsNumber(str_equalsRemoved)) {
      if (!this->IsWireInMap(str_equalsRemoved)) {
        return false;
      }
      Wire* w = this->GetWire(str_equalsRemoved);
      this->SetWire(str_dest, w->GetSignalVal());

    } else {
      this->SetWire(str_dest, (uint16_t)std::atoi(str_equalsRemoved.c_str()));
    }

  }

  return true;
}

void WireManager::ResetWires(uint16_t u16_val) {
  for (auto const & [str_wireName, p_wire] : _map_wires) {
    if (!IsNumber(str_wireName)) {
      this->SetWire(str_wireName, u16_val);
    }
  }
}

