#include "GUIAssigner.h"

Assign::Assign(HardwareSerial *port) {
	_port = port;
}


void Assign::AssignToVariable(uint8_t channel, bool *value){
	variableBool[channel] = value;
	type[channel] = BOOL;
}

void Assign::AssignToVariable(uint8_t channel, uint8_t *value){
	variableUint8[channel] = value;
	type[channel] = UINT8;
}

void Assign::AssignToVariable(uint8_t channel, int8_t *value){
	variableInt8[channel] = value;
	type[channel] = INT8;
}

void Assign::AssignToVariable(uint8_t channel, uint16_t *value){
	variableUint16[channel] = value;
	type[channel] = UINT16;
}

void Assign::AssignToVariable(uint8_t channel, int16_t *value){
	variableInt16[channel] = value;
	type[channel] = INT16;
}

void Assign::AssignToVariable(uint8_t channel, uint32_t *value){
	variableUint32[channel] = value;
	type[channel] = UINT32;
}

void Assign::AssignToVariable(uint8_t channel, int32_t *value){
	variableInt32[channel] = value;
	type[channel] = INT32;
}

void Assign::AssignToVariable(uint8_t channel, float *value){
	variableFloat[channel] = value;
	type[channel] = FLOAT;
}

void Assign::AssignToVariable(uint8_t channel, double *value){
	variableDouble[channel] = value;
	type[channel] = DOUBLE;
}

void Assign::ReadCommand(void) {
	uint8_t channel = 0;
	double value=0;
	switch(type[channel]) {
		case BOOL :
			*variableBool[channel] = (bool)value;
			break;
		case UINT8 :
			*variableUint8[channel] = (uint8_t)value;
			break;
		case INT8 :
			*variableInt8[channel] = (int8_t)value;
			break;
		case UINT16 :
			*variableUint16[channel] = (uint16_t)value;
			break;
		case INT16 :
			*variableInt16[channel] = (int16_t)value;
			break;
		case UINT32 :
			*variableUint32[channel] = (uint32_t)value;
			break;
		case INT32 :
			*variableInt32[channel] = (int32_t)value;
			break;
		case FLOAT :
			*variableFloat[channel] = (float)value;
			break;
		case DOUBLE :
			*variableDouble[channel] = value;
			break;
	}
}
