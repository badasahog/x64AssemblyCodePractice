#include <iostream>
#include <vector>
#include <immintrin.h>
#pragma intrinsic(__rdtsc)
struct mnemonic
{
	std::string name;
	std::string desc;
	std::string set;
};
/*
* instruction sets (acording to msdn):
* ABM
* ADX
* AES
* AVX
* AVX2
* BMI1
* BMI2
* CLFSH
* CMPXCHG16B
* CX8
* F16C
* FMA
* FSGBASE
* FXSR
* LAHF
* MMX
* MMXEXT
* MONITOR
* MOVBE
* MSR
* OSXSAVE
* PCLMULQDQ
* POPCNT
* RDRAND
* RDSEED
* SEP
* SHA
* SSE
* SSE2
* SSE3
* SSE4.1
* SSE4.2
* SSE4a
* SSSE3
* XSAVE
* 
* instruction sets (acording to wikichip)
* MMX
* EMMX
* SSE
* SSE2
* SSE3
* SSSE3
* SSE4.1
* SSE4.2
* SSE4a
* AVX
* AVX2
* ABM
* BMI1
* BMI2
* FMA3
* AES
* RdRand
* SHA
* ADX
* CLMUL
* F16C
* 
* 
* not supported:
* 3DNOW
* 3DNOWEXT
* AVX512CD
* AVX512ER
* AVX512F
* AVX512PF
* ERMS
* INVPCID
* LZCNT
* PREFETCHWT1
* RDTSCP
* RTM
* SYSCALL
* TBM
* XOP
*/
std::vector<mnemonic> mnemonics = 
{
	{"ADC",     	"8086", "Add with carry"},
	{"ADCX",		"8086", "Unsigned ADD with Carry Flag"},
	{"ADD",			"8086", "Signed or Unsigned Add"},
	{"ADOX",		"8086", "Unsigned ADD with Overflow Flag"},
	{"AND",			"8086", "Logical AND"},
	{"ANDN",		"BMI1", "Logical And-Not"},
	{"BEXTR",		"BMI1", "Bit Field Extract"},
	{"BLSI",		"BMI2", "Isolate Lowest Set Bit"},
	{"BLSMSK",		"BMI2", "Mask From Lowest Set Bit"},
	{"BLSR",		"8086", "Reset Lowest Set Bit"},
	{"BSF",			"8086", "Bit Scan Forward"},
	{"BSR",			"8086", "Bit Scan Reverse"},
	{"BSWAP",		"8086", "Byte Swap"},
	{"BT",			"8086", "Bit Test"},
	{"BTC",			"8086", "Bit Test and Complement"},
	{"BTR",			"8086", "Bit Test and Reset"},
	{"BTS",			"8086", "Bit Test and Set"},
	{"BZHI",		"BMI2", "Zero High Bits"},
	{"CALL",		"8086", "Near Procedure Call"},
	{"CBW",			"8086", "Convert to Sign-Extended"},
	{"CLC",			"8086", "Clear Carry Flag"},
	{"CLD",			"8086", "Clear Direction Flag"},
	{"CLFLUSH",     "8086", "Cache Line Flush"},
	{"CLFLUSHOPT",  "8086", "Optimized Cache Line Flush"},
	{"CLZERO",		"8086", "Zero Cache Line"},
	{"CMC",			"8086", "Complement Carry Flag"},
	{"CMOVcc",		"8086", "Conditional Move"},
	{"CMP",			"8086", "Compare"},
	{"CMPS",		"8086", "Compare Strings"},
	{"CMPXCHG",     "8086", "Compare and Exchange"},
	{"CMPXCHG8B",   "8086", "Compare and Exchange Eight Bytes"},
	{"CMPXCHG16B",  "8086", "Compare and Exchange Sixteen Bytes"},
	{"CPUID",		"8086", "Processor Identification"},
	{"CRC32",		"8086", "CRC32 Cyclical Redundancy Check"},
	{"DEC",			"8086", "Decrement by 1"},
	{"DIV",			"8086", "Unsigned Divide"},
	{"ENTER",		"8086", "Create Procedure Stack Frame"},
	{"IDIV",		"8086", "Signed Divide"},
	{"IMUL",		"8086", "Signed Multiply"},
	{"IN",			"8086", "Input from Port"},
	{"INC",			"8086", "Increment by 1"},
	{"INS",			"8086", "Input String"},
	{"INT",			"8086", "Interrupt to Vector"},
	{"jcc",			"8086", "Jump on Condition"},
	{"JCXZ",		"8086", "Jump if rCX Zero"},
	{"JMP",			"8086", "Near Jump"},
	{"LAHF",		"8086", "Load Status Flags into AH Register"},
	{"LDS",			"8086", "Load Far Pointer"},
	{"LEA",			"8086", "Load Effective Address"},
	{"LEAVE",		"8086", "Delete Procedure Stack Frame"},
	{"LFENCE",		"8086", "Load Fence"},
	{"LLWPCB",		"8086", "Load Lightweight Profiling Control Block Address"},
	{"LODS",		"8086", "Load String"},
	{"LOOP",		"8086", "Loop"},
	{"LWPINS",		"8086", "Lightweight Profiling Insert Record"},
	{"LWPVAL",		"8086", "Lightweight Profiling Insert Value"},
	{"LZCNT",		"ABM", "Count Leading Zeros"},
	{"MCOMMIT",     "8086", "Commit Stores to Memory"},
	{"MFENCE",		"8086", "Memory Fence"},
	{"MONITORX",    "8086", "Setup Monitor Address"},
	{"MOV",			"8086", "Move"},
	{"MOVBE",		"8086", "Move Big Endian"},
	{"MOVD",		"8086", "Move Doubleword or Quadword"},
	{"MOVMSKPD",    "8086", "Extract Packed Double-Precision Floating-Point Sign Mask"},
	{"MOVMSKPS",    "8086", "Extract Packed Single-Precision Floating-Point Sign Mask"},
	{"MOVNTI",		"8086", "Move Non-Temporal Doubleword or Quadword"},
	{"MOVS",		"8086", "Move String"},
	{"MOVSX",		"8086", "Move with Sign-Extension"},
	{"MOVSXD",		"8086", "Move with Sign-Extend Doubleword"},
	{"MOVZX",		"8086", "Move with Zero-Extension"},
	{"MUL",			"8086", "Unsigned Multiply"},
	{"MULX",		"MBI2", "Multiply Unsigned"},
	{"MWAITX",		"8086", "Monitor Wait with Timeout"},
	{"NEG",			"8086", "Two’s Complement Negation"},
	{"NOP",			"8086", "No Operation"},
	{"NOT",			"8086", "One’s Complement Negation"},
	{"OR",			"8086", "Logical OR"},
	{"OUT",			"8086", "Output to Port"},
	{"OUTS",		"8086", "Output String"},
	{"PAUSE",		"8086", "Pause"},
	{"PDEP",		"BMI2", "Parallel Deposit Bits"},
	{"PEXT",		"BMI2", "Parallel Extract Bits"},
	{"POP",			"8086", "Pop Stack"},
	{"POPCNT",		"ABM", "Bit Population Count"},
	{"POPF",		"8086", "POP to rFLAGS"},
	{"PREFETCH",    "8086", "Prefetch L1 Data-Cache Line"},
	{"PREFETCHW",   "8086", "Prefetch L1 Data-Cache Line For Writing"},
	{"PREFETCH0",   "8086", "Prefetch Data to Cache Level level 0"},
	{"PUSH",		"8086", "Push onto Stack"},
	{"PUSHF",		"8086", "Push rFLAGS onto Stack"},
	{"RCL",			"8086", "Rotate Through Carry Left"},
	{"RCR",			"8086", "Rotate Through Carry Right"},
	{"RDFSBASE",    "8086", "Read FS.base"},
	{"RDGSBASE",    "8086", "Read GS.base"},
	{"RDPID",		"8086", "Read Processor ID"},
	{"RDPRU",		"8086", "Read Processor Register"},
	{"RDRAND",		"8086", "Read Random"},
	{"RDSEED",		"8086", "Read Random Seed"},
	{"RET",			"8086", "Near Return from Called Procedure"},
	{"RET",			"8086", "Far Return from Called Procedure"},
	{"ROL",			"8086", "Rotate Left"},
	{"ROR",			"8086", "Rotate Right"},
	{"RORX",		"BMI2", "Rotate Right Extended"},
	{"SAHF",		"8086", "Store AH into Flags"},
	{"SHL",			"8086", "Shift Left"},
	{"SAR",			"8086", "Shift Arithmetic Right"},
	{"SARX",		"BMI2", "Shift Right Arithmetic Extended"},
	{"SBB",			"8086", "Subtract with Borrow"},
	{"SCAS",		"8086", "Scan String"},
	{"SETcc",		"8086", "Set Byte on Condition"},
	{"SFENCE",		"8086", "Store Fence"},
	{"SHLD",		"8086", "Shift Left Double"},
	{"SHLX",		"BMI2", "Shift Left Logical Extended"},
	{"SHR",			"8086", "Shift Right"},
	{"SHRD",		"8086", "Shift Right Double"},
	{"SHRX",		"BMI2", "Shift Right Logical Extended"},
	{"SLWPCB",		"8086", "Store Lightweight Profiling Control Block Address"},
	{"STC",			"8086", "Set Carry Flag"},
	{"STD",			"8086", "Set Direction Flag"},
	{"STOSQ",		"8086", "Store String"},
	{"SUB",			"8086", "Subtract"},
	{"TEST",		"8086", "Test Bits"},
	{"TZCNT",		"BMI1", "Count Trailing Zeros"},
	{"WRFSBASE",    "8086", "Write FS.base"},
	{"WRGSBASE",    "8086", "Write GS.base"},
	{"XADD",		"8086", "Exchange and Add"},
	{"XCHG",		"8086", "Exchange"},
	{"XLAT",		"8086", "Translate Table Index"},
	{"XOR",			"8086", "Logical Exclusive OR"}
};

int main()
{
	uint64_t randomizerPtr = 0;
	int points = 0;
	while (points < 100)
	{
		_rdseed64_step(&randomizerPtr);
		randomizerPtr %= mnemonics.size();
		std::cout << mnemonics[randomizerPtr].desc << '\n';
		std::string answer;
		std::cin >> answer;
		if (answer == mnemonics[randomizerPtr].name)
			std::cout << ++points << '\n';
		else
		{
			std::cout << "wrong: " << mnemonics[randomizerPtr].name << '\n';
			points--;
		}
	}
}