#include "opcode.h"
#include "fields.h"

typedef struct i68k {
	int opcode;
	union i68k_fields fields;
} i68k;
