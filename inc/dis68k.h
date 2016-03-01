#include "opcode.h"
#include "op.h"

typedef struct i68k {
	int opcode;
	union op operation;
} i68k;
