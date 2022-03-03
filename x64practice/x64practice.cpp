#include <iostream>
#include <vector>
#include <immintrin.h>
struct mnemonic
{
	std::string name;
	std::string set;
	std::string desc;
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
	{"ANDN",		"BMI1", "Logical And-Not"},
	{"TZCNT",		"BMI1", "Count Trailing Zeros"},
	{"BEXTR",		"BMI1", "Bit Field Extract"},
	{"RORX",		"BMI2", "Rotate Right Extended"},
	{"BLSI",		"BMI2", "Isolate Lowest Set Bit"},
	{"BLSMSK",		"BMI2", "Mask From Lowest Set Bit"},
	{"BZHI",		"BMI2", "Zero High Bits"},
	{"PDEP",		"BMI2", "Parallel Deposit Bits"},
	{"MULX",		"MBI2", "Multiply Unsigned"},
	{"PEXT",		"BMI2", "Parallel Extract Bits"},
	{"SARX",		"BMI2", "Shift Right Arithmetic Extended"},
	{"SHLX",		"BMI2", "Shift Left Logical Extended"},
	{"SHRX",		"BMI2", "Shift Right Logical Extended"},
	{"LZCNT",		"ABM",  "Count Leading Zeros"},
	{"POPCNT",		"ABM",  "Bit Population Count"},
	{"PACKSSDW",	"MMX",	"Pack with Saturation Signed Doubleword to Word"},
	{"PACKSSWB",	"MMX",	"Pack with Saturation Signed Word to Byte"},
	{"PACKUSWB",	"MMX",	"Pack with Saturation Signed Word to Unsigned Byte"},
	{"PUNPCKHBW",	"MMX",	"Unpack and Interleave High Bytes"},
	{"PUNPCKHDQ",	"MMX",	"Unpack and Interleave High Doublewords"},
	{"PUNPCKHWD",	"MMX",	"Unpack and Interleave High Words"},
	{"PUNPCKLBW",	"MMX",	"Unpack and Interleave Low Bytes"},
	{"PUNPCKLDQ",	"MMX",	"Unpack and Interleave Low Doublewords"},
	{"PUNPCKLWD",	"MMX",	"Unpack and Interleave Low Words"},
	{"MOVD",		"MMX",  "Move Doubleword"},
	{"MOVQ",		"MMX",  "Move Quadword"},
	{"SFENCE",		"SSE/EMMX", "Store Fence"},
	{"PREFETCHT0",	"SSE/EMMX", "Move data closer to the processor using the T0 reference"},
	{"PREFETCHT1",	"SSE/EMMX", "Move data closer to the processor using the T1 reference"},
	{"PREFETCHT2",	"SSE/EMMX", "Move data closer to the processor using the T2 reference"},
	{"PREFETCHNTA",	"SSE/EMMX", "Move data closer to the processor using the NTA reference"},
	{"MOVNTQ",		"SSE/EMMX", "Move Non-temporal Quadword"},
	{"MASKMOVQ",	"SSE/EMMX", "Mask Move Quadword"},
	{"PMOVMSKB",	"SSE/EMMX", "Packed Move Mask Byte"},
	{"PEXTRW",		"SSE/EMMX", "Extract Packed Word"},
	{"PINSRW",		"SSE/EMMX", "Packed Insert Word"},
	{"PSHUFW",		"SSE/EMMX", "Packed Shuffle Words"},
	{"PAVGB",		"SSE/EMMX", "Packed Average Unsigned Bytes"},
	{"PAVGW",		"SSE/EMMX", "Packed Average Unsigned Words"},
	{"PMAXSW",		"SSE/EMMX", "Packed Maximum Signed Words"},
	{"PMAXUB",		"SSE/EMMX", "Packed Maximum Unsigned Bytes"},
	{"PMINSW",		"SSE/EMMX", "Packed Minimum Signed Words"},
	{"PMINUB",		"SSE/EMMX", "Packed Minimum Unsigned Bytes"},
	{"PMULHUW",		"SSE/EMMX", "Packed Multiply High Unsigned Word"},
	{"PSADBW",		"SSE/EMMX", "Packed Sum of Absolute Differences of Bytes into a Word"},
	{"ADDPS",		"SSE", "Add Packed Single Precision Floating Point"},
	{"ADDSS",		"SSE", "Add Scalar Single Precision Floating Point"},
	{"SUBPS",		"SSE", "Subtract Packed Single Precision Floating Point"},
	{"SUBSS",		"SSE", "Subtract Scalar Single Precision Floating Point"},
	{"MULPS",		"SSE", "Multiply Packed Single Precision Floating Point"},
	{"MULSS",		"SSE", "Multiply Scalar Single Precision Floating Point"},
	{"DIVPS",		"SSE", "Multiply Scalar Single Precision Floating Point"},
	{"DIVSS",		"SSE", "Divide Scalar Single Precision Floating Point"},
	{"RCPPS",		"SSE", "Reciprocal Packed Single Precision Floating Point"},
	{"RCPSS",		"SSE", "Reciprocal Scalar Single Precision Floating Point"},
	{"SQRTPS",		"SSE", "Square Root Packed Single Precision Floating Point"},
	{"SQRTSS",		"SSE", "Square Root Scalar Single Precision Floating Point"},
	{"RSQRTPS",		"SSE", "Reciprocal Square Root Packed Single Precision Floating Point"},
	{"RSQRTSS",		"SSE", "Reciprocal Square Root Scalar Single Precision Floating Point"},
	{"MAXPS",		"SSE", "Maximum Packed Single Precision Floating Point"},
	{"MAXSS",		"SSE", "Maximum Scalar Single Precision Floating Point"},
	{"MINPS",		"SSE", "Minimum Packed Single Precision Floating Point"},
	{"MINSS",		"SSE", "Minimum Scalar Single Precision Floating Point"},
	{"MOVMSKPS",	"SSE", "Extract Packed Single Precision Floating Point Sign Mask"},
	{"ANDNPS",		"SSE", "AND NOT Packed Single Precision Floating Point"},
	{"ANDPS",		"SSE", "AND Packed Single Precision Floating Point"},
	{"ORPS",		"SSE", "OR Packed Single Precision Floating Point"},
	{"XORPS",		"SSE", "XOR Packed Single Precision Floating Point"},
	{"CMPxxPS",		"SSE", "Compare Packed Single Precision Floating Point"},
	{"CMPxxSS",		"SSE", "Compare Scalar Single Precision Floating Point"},
	{"COMISS",		"SSE", "Compare Ordered Scalar Single Precision Floating Point"},
	{"UCOMISS",		"SSE", "Unordered Compare Scalar Single Precision Floating Point"},
	{"CVTPI2PS",	"SSE", "Convert Packed Doubleword Integers to Packed Single Precision Floating Point"},
	{"CVTPS2PI",	"SSE", "Convert Packed Single Precision Floating Point to Packed Doubleword Integers"},
	{"CVTSI2SS",	"SSE", "Convert Signed Doubleword or Quadword Integer to Scalar Single Precision Floating Point"},
	{"CVTSS2SI",	"SSE", "Convert Scalar Single Precision Floating Point to Signed Doubleword or Quadword Integer"},
	{"CVTTPS2PI",	"SSE", "Convert Packed Single Precision Floating Point to Packed Doubleword Integers, Truncated"},
	{"CVTTSS2SI",	"SSE", "Convert Scalar Single Precision Floating Point to Signed Double or Quadword Integer, Truncated"},
	{"FXRSTOR",		"SSE", "Restore XMM, MMX, and x87 State"},
	{"FXSAVE",		"SSE", "Save XMM, MMX, and x87 State"},
	{"LDMXCSR",		"SSE", "Load MXCSR Control / Status Register"},
	{"STMXCSR",		"SSE", "Store MXCSR"},
	{"MOVAPS",		"SSE", "Move Aligned Packed Single Precision Floating Point"},
	{"MOVHLPS",		"SSE", "Move High to Low Packed Single Precision Floating Point"},
	{"MOVLHPS",		"SSE", "Move Low to High Packed Single Precision Floating Point"},
	{"MOVHPS",		"SSE", "Move High Packed Single Precision Floating Point"},
	{"MOVLPS",		"SSE", "Move Low Packed Single Precision Floating Point"},
	{"MOVSS",		"SSE", "Move Scalar Single Precision Floating Point"},
	{"MOVUPS",		"SSE", "Move Unaligned Packed Single Precision Floating Point"},
	{"MOVNTPS",		"SSE", "Move Nontemporal Packed Single Precision Floating Point"},
	{"SHUFPS",		"SSE", "Shuffle Packed Single Precision Floating Point"},
	{"UNPCKHPS",	"SSE", "Unpack High Single Precision Floating Point"},
	{"UNPCKLPS",	"SSE", "Unpack Low Single Precision Floating Point"},
	{"ADC",     	"8086", "Add with carry"},
	{"ADCX",		"8086", "Unsigned ADD with Carry Flag"},
	{"ADD",			"8086", "Signed or Unsigned Add"},
	{"ADOX",		"8086", "Unsigned ADD with Overflow Flag"},
	{"AND",			"8086", "Logical AND"},
	{"BLSR",		"8086", "Reset Lowest Set Bit"},
	{"BSF",			"8086", "Bit Scan Forward"},
	{"BSR",			"8086", "Bit Scan Reverse"},
	{"BSWAP",		"8086", "Byte Swap"},
	{"BT",			"8086", "Bit Test"},
	{"BTC",			"8086", "Bit Test and Complement"},
	{"BTR",			"8086", "Bit Test and Reset"},
	{"BTS",			"8086", "Bit Test and Set"},
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
	{"MCOMMIT",		"8086", "Commit Stores to Memory"},
	{"MFENCE",		"8086", "Memory Fence"},
	{"MONITORX",	"8086", "Setup Monitor Address"},
	{"MOV",			"8086", "Move"},
	{"MOVBE",		"8086", "Move Big Endian"},
	{"MOVMSKPD",	"8086", "Extract Packed Double-Precision Floating-Point Sign Mask"},
	{"MOVNTI",		"8086", "Move Non-Temporal Doubleword or Quadword"},
	{"MOVS",		"8086", "Move String"},
	{"MOVSX",		"8086", "Move with Sign-Extension"},
	{"MOVSXD",		"8086", "Move with Sign-Extend Doubleword"},
	{"MOVZX",		"8086", "Move with Zero-Extension"},
	{"MUL",			"8086", "Unsigned Multiply"},
	{"MWAITX",		"8086", "Monitor Wait with Timeout"},
	{"NEG",			"8086", "Two\'s Complement Negation"},
	{"NOP",			"8086", "No Operation"},
	{"NOT",			"8086", "One\'s Complement Negation"},
	{"OR",			"8086", "Logical OR"},
	{"OUT",			"8086", "Output to Port"},
	{"OUTS",		"8086", "Output String"},
	{"PAUSE",		"8086", "Pause"},
	{"POP",			"8086", "Pop Stack"},
	{"POPF",		"8086", "POP to rFLAGS"},
	{"PREFETCH",	"8086", "Prefetch L1 Data-Cache Line"},
	{"PREFETCHW",	"8086", "Prefetch L1 Data-Cache Line For Writing"},
	{"PREFETCH0",	"8086", "Prefetch Data to Cache Level level 0"},
	{"PUSH",		"8086", "Push onto Stack"},
	{"PUSHF",		"8086", "Push rFLAGS onto Stack"},
	{"RCL",			"8086", "Rotate Through Carry Left"},
	{"RCR",			"8086", "Rotate Through Carry Right"},
	{"RDFSBASE",	"8086", "Read FS.base"},
	{"RDGSBASE",	"8086", "Read GS.base"},
	{"RDPID",		"8086", "Read Processor ID"},
	{"RDRAND",		"8086", "Read Random"},
	{"RDSEED",		"8086", "Read Random Seed"},
	{"RET",			"8086", "Near Return from Called Procedure"},
	{"RET",			"8086", "Far Return from Called Procedure"},
	{"ROL",			"8086", "Rotate Left"},
	{"ROR",			"8086", "Rotate Right"},
	{"SAHF",		"8086", "Store AH into Flags"},
	{"SHL",			"8086", "Shift Left"},
	{"SAR",			"8086", "Shift Arithmetic Right"},
	{"SBB",			"8086", "Subtract with Borrow"},
	{"SCAS",		"8086", "Scan String"},
	{"SETcc",		"8086", "Set Byte on Condition"},
	{"SHLD",		"8086", "Shift Left Double"},
	{"SHR",			"8086", "Shift Right"},
	{"SHRD",		"8086", "Shift Right Double"},
	{"SLWPCB",		"8086", "Store Lightweight Profiling Control Block Address"},
	{"STC",			"8086", "Set Carry Flag"},
	{"STD",			"8086", "Set Direction Flag"},
	{"STOSQ",		"8086", "Store String"},
	{"SUB",			"8086", "Subtract"},
	{"TEST",		"8086", "Test Bits"},
	{"WRFSBASE",	"8086", "Write FS.base"},
	{"WRGSBASE",	"8086", "Write GS.base"},
	{"XADD",		"8086", "Exchange and Add"},
	{"XCHG",		"8086", "Exchange"},
	{"XLAT",		"8086", "Translate Table Index"},
};

int main()
{
#ifdef __clang__
	srand (time(0));//clang immintrin.h support workaround
#else
	uint64_t randomizerPtr = 0;
	_rdseed64_step(&randomizerPtr);
	srand(randomizerPtr);
#endif
	int points = 0;
	while (points < 100)
	{
		int random = rand() % mnemonics.size();
		std::cout << "[" << mnemonics[random].set << "]" << mnemonics[random].desc << '\n';
		std::string answer;
		std::cin >> answer;
		if (answer == mnemonics[random].name)
			std::cout << ++points << '\n';
		else
		{
			do
			{
				std::cout << "wrong: " << mnemonics[random].name << '\n';
				points--;

				std::string answer;
				std::cin >> answer;
				if (answer == mnemonics[random].name)
					break;

			} while (true);
		}
	}
}
