#include "VariableAssigner.h"
#include "HardwareSerial.h"

HardwareSerial trace(D30,D16);
bool toto=false;
float r;
Assign test(&trace);

void setup(void) {
	Serial.begin(115200);
  trace.begin(230400);
	Serial.println(toto);
	test.AssignToVariable(0,&toto);
	test.AssignToVariable(1,&r);
}

unsigned long t;
void loop(void) {
  test.ReadCommand();
  Serial.println(r);
}