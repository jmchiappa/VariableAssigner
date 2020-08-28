#include "VariableAssigner.h"

#define PRINT2(p,a,b) 	{p->print(a);p->println(b);}

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
	uint8_t channel;
	double value;
  uint8_t car;
  uint8_t cmd;
  char * endPtr;
  char * Str;;
  char ch;

  while(_port->available()>0) {

    // read one by one so that find the delimiter \n
    car=_port->read();
    // push in buffer if it's a number
    buf[buf_cnt++]=car;
    // prevent buffer overflow
    buf_cnt %=BUF_SIZE;

    if(car=='\n'){
      // end of line
      //for(cmd=0;cmd<sizeof(Command) && Command[cmd]!=buf[0];cmd++);
			if(buf[0]>='A' && buf[0]<='J') {
				channel = buf[0] - 'A';
				// read the number 
				Str = &buf[1];
				
				value = strtof( Str, &endPtr );

				if ( endPtr == Str ) {
					_port->println("!Erreur de format de nombre");
				} else {
					PRINT2(_port, char(1)+String(buf[0])+"=",value);
				}
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
				} // end switch
			} // end if 'A' -> 'K'
			buf_cnt=0;
		} // end if end of line
	} // end while
	// now output data for channel from 'K' to 'O' (10 to 14)
	if(millis()-t>50) {
		t=millis();
		for(uint8_t i=10;i<15;i++) {
			ch = 65 + i;
			if(variableBool[i]!=NULL)
				_port->println(char(1) + String(ch) + "=" + *variableBool[i]);
			if(variableUint8[i]!=NULL)
				_port->println(char(1) + String(ch) + "=" + *variableUint8[i]);	
			if(variableInt8[i]!=NULL)
				_port->println(char(1) + String(ch) + "=" + *variableInt8[i]);		
			if(variableUint16[i]!=NULL)
				_port->println(char(1) + String(ch) + "=" + *variableUint16[i]);		
			if(variableInt16[i]!=NULL)
				_port->println(char(1) + String(ch) + "=" + *variableInt16[i]);		
			if(variableUint32[i]!=NULL)
				_port->println(char(1) + String(ch) + "=" + *variableUint32[i]);		
			if(variableInt32[i]!=NULL)
				_port->println(char(1) + String(ch) + "=" + *variableInt32[i]);		
			if(variableFloat[i]!=NULL)
				_port->println(char(1) + String(ch) + "=" + *variableFloat[i]);		
			if(variableDouble[i]!=NULL)
				_port->println(char(1) + String(ch) + "=" + *variableDouble[i]);		
		}
	}
}
