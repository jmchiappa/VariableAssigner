#include "GUIAssigner.h"

bool toto=false;
float r;
Assign test(&Serial);

void setup(void) {
	Serial.begin(115200);
	Serial.println(toto);
	test.AssignToVariable(0,&toto);
	test.AssignToVariable(1,&r);
	test.ReadCommand();
	Serial.println(toto);
}

void loop(void) {
	
}