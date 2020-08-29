#ifndef VARIABLEASSIGNER
#define VARIABLEASSIGNER

#include "Arduino.h"
#include "HardwareSerial.h"


#ifdef __cplusplus
// #include <functional>
// using callback_function_t = std::function<void(void)>;
#define CHANNEL_MAX 15
#define BUF_SIZE 100
/* Class --------------------------------------------------------*/
class Assign {
	public:
		enum varType {
			BOOL,
			INT8,
			UINT8,
			INT16,
			UINT16,
			INT32,
			UINT32,
			FLOAT,
			DOUBLE,
			UNDEF
		};
		Assign(HardwareSerial *port);
		Assign(void);
		void AssignToVariable(uint8_t channel, bool *value);
		void AssignToVariable(uint8_t channel, uint8_t *value);
		void AssignToVariable(uint8_t channel, int8_t *value);
		void AssignToVariable(uint8_t channel, uint16_t *value);
		void AssignToVariable(uint8_t channel, int16_t *value);
		void AssignToVariable(uint8_t channel, uint32_t *value);
		void AssignToVariable(uint8_t channel, int32_t *value);
		void AssignToVariable(uint8_t channel, float *value);
		void AssignToVariable(uint8_t channel, double *value);

		void ReadCommand(void);
	private:
		bool *variableBool[CHANNEL_MAX];
		uint8_t *variableUint8[CHANNEL_MAX];
		int8_t *variableInt8[CHANNEL_MAX];
		uint16_t *variableUint16[CHANNEL_MAX];
		int16_t *variableInt16[CHANNEL_MAX];
		uint32_t *variableUint32[CHANNEL_MAX];
		int32_t *variableInt32[CHANNEL_MAX];
		float *variableFloat[CHANNEL_MAX];
		double *variableDouble[CHANNEL_MAX];
		varType type[CHANNEL_MAX];
		HardwareSerial *_port;
		char buf[BUF_SIZE];
		uint8_t buf_cnt=0;
		unsigned long t=0;
		String out="";
};

#endif
#endif
