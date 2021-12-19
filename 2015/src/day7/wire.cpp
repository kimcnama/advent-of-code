//
// Created by kieran McNamara on 19/12/2021.
//

#include "../../inc/day7/wire.h"

Wire::Wire(uint16_t u16_sig) {
  _u16_signal = u16_sig;
}
uint16_t Wire::GetSignalVal() {
  return _u16_signal;
}
void Wire::SetSignalVal(uint16_t u16_sig) {
  _u16_signal = u16_sig;
}
void Wire::And(Wire *w1, Wire *w2) {
  _u16_signal = w1->GetSignalVal() & w2->GetSignalVal();
}
void Wire::Not(Wire *w1) {
  _u16_signal = ~w1->GetSignalVal();
}
void Wire::LShift(Wire* w1, uint16_t u16_n) {
  _u16_signal = w1->GetSignalVal() << u16_n;
}
void Wire::RShift(Wire* w1, uint16_t u16_n) {
  _u16_signal = w1->GetSignalVal() >> u16_n;
}
void Wire::Or(Wire *w1, Wire *w2) {
  _u16_signal = w1->GetSignalVal() | w2->GetSignalVal();
}

Wire::~Wire() = default;

