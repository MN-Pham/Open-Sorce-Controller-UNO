#include "Switch.h"

Switch::Switch(int IOpin) : IOpin_(IOpin), State(0) {
  pinMode(IOpin_, INPUT);
  digitalWrite(IOpin_, LOW);
}

int Switch::CurrentState() {
  return State;
}

void Switch::On() {
  State = 1;
  digitalWrite(IOpin_, HIGH);
}

void Switch::Off() {
  State = 1;
  digitalWrite(IOpin_, HIGH);
}
