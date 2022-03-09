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
* 
* 
* tbd:
* what set is movq from?
* 
* popcnt is in both SSE4.2 and SSE4a
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
	{"ADDPD",		"SSE2", "Add Packed Double Precision Floating Point"},
	{"ADDSD",		"SSE2", "Add Scalar Double Precision Floating Point"},
	{"SUBPD",		"SSE2", "Subtract Packed Double Precision Floating Point"},
	{"SUBSD",		"SSE2", "Subtract Scalar Double Precision Floating Point"},
	{"MULPD",		"SSE2", "Multiply Packed Double Precision Floating Point"},
	{"MULSD",		"SSE2", "Multiply Scalar Double Precision Floating Point"},
	{"DIVPD",		"SSE2", "Divide Packed Double Precision Floating Point"},
	{"DIVSD",		"SSE2", "Divide Scalar Double Precision Floating Point"},
	{"MAXPD",		"SSE2", "Maximum Packed Double Precision Floating Point"},
	{"MAXSD",		"SSE2", "Maximum Scalar Double Precision Floating Point"},
	{"MINPD",		"SSE2", "Minimum Packed Double Precision Floating Point"},
	{"MINSD",		"SSE2", "Minimum Scalar Double Precision Floating Point"},
	{"PADDB",		"SSE2", "Packed Add Bytes"},
	{"PADDW",		"SSE2", "Packed Add Words"},
	{"PADDD",		"SSE2", "Packed Add Doublewords"},
	{"PADDQ",		"SSE2", "Packed Add Quadwords"},
	{"PADDUSB",		"SSE2", "Packed Add with Unsigned Saturation Bytes "},
	{"PADDUSW",		"SSE2", "Packed Add with Unsigned Saturation Words"},
	{"PSUBB",		"SSE2", "Packed Subtract Bytes"},
	{"PSUBW",		"SSE2", "Packed Subtract Words"},
	{"PSUBD",		"SSE2", "Packed Subtract Doublewords"},
	{"PSUBQ",		"SSE2", "Packed Subtract Quadword"},
	{"PSUBSB",		"SSE2", "Packed Subtract Signed With Saturation Bytes"},
	{"PSUBSW",		"SSE2", "Packed Subtract Signed With Saturation Words"},
	{"PSUBUSB",		"SSE2", "Packed Subtract Unsigned With Saturation Bytes"},
	{"PSUBUSW",		"SSE2", "Packed Subtract Unsigned With Saturation Words"},
	{"PMADDWD",		"SSE2", "Packed Multiply and Add Word to Doubleword"},
	{"PMULHW",		"SSE2", "Packed Multiply High Signed Word"},
	{"PMULLW",		"SSE2", "Packed Multiply Low Signed Word"},
	{"PMULUDQ",		"SSE2", "Packed Multiply Unsigned Doubleword to Quadword"},
	{"RCPPS",		"SSE2", "Reciprocal Packed Single Precision Floating Point"},
	{"RCPSS",		"SSE2", "Reciprocal Scalar Single Precision Floating Point"},
	{"SQRTPD",		"SSE2", "Square Root Packed Double Precision Floating Point"},
	{"SQRTSD",		"SSE2", "Square Root Scalar Double Precision Floating Point"},
	{"PADDSB",		"SSE2", "Packed Add with Signed Saturation Bytes"},
	{"PADDSW",		"SSE2", "Packed Add with Signed Saturation Words"},
	{"ANDNPD",		"SSE2",	"AND NOT Packed Double Precision Floating Point"},
	{"ANDNPS",		"SSE2",	"AND NOT Packed Single Precision Floating Point"},
	{"ANDPD",		"SSE2",	"AND Packed Double Precision Floating Point"},
	{"PAND",		"SSE2",	"Packed AND"},
	{"PANDN",		"SSE2",	"Packed AND NOT"},
	{"POR",			"SSE2",	"Packed OR"},
	{"PSLLDQ",		"SSE2",	"Packed Shift Left Logical Double Quadword"},
	{"PSLLQ",		"SSE2",	"Packed Shift Left Logical Quadwords"},
	{"PSLLD",		"SSE2",	"Packed Shift Left Logical Doublewords"},
	{"PSLLW",		"SSE2",	"Packed Shift Left Logical Words"},
	{"PSRAD",		"SSE2",	"Packed Shift Right Arithmetic Doublewords"},
	{"PSRAW",		"SSE2",	"Packed Shift Right Arithmetic Words"},
	{"PSRLDQ",		"SSE2",	"Packed Shift Right Logical Double Quadword"},
	{"PSRLQ",		"SSE2",	"Packed Shift Right Logical Quadwords"},
	{"PSRLD",		"SSE2",	"Packed Shift Right Logical Doublewords"},
	{"PSRLW",		"SSE2",	"Packed Shift Right Logical Words"},
	{"PXOR",		"SSE2",	"Packed Exclusive OR"},
	{"ORPD",		"SSE2",	"OR Packed Double Precision Floating Point"},
	{"XORPD",		"SSE2",	"XOR Packed Double Precision Floating Point"},
	{"CMPPD",		"SSE2",	"Compare Packed Double Precision Floating Point"},
	{"CMPSx",		"SSE2",	"Compare Strings"},
	{"COMISD",		"SSE2",	"Compare Ordered Scalar Double Precision Floating Point"},
	{"UCOMISD",		"SSE2",	"Unordered Compare Scalar Double Precision Floating Point"},
	{"PCMPxxB",		"SSE2",	"Packed Compare Bytes"},
	{"PCMPxxW",		"SSE2",	"Packed Compare Words"},
	{"PCMPxxD",		"SSE2",	"Packed Compare Doublewords"},
	{"CVTDQ2PD",	"SSE2",	"Convert Packed Doubleword Integers to Packed Double Precision Floating Point"},
	{"CVTDQ2PS",	"SSE2",	"Convert Packed Doubleword Integers to Packed Single Precision Floating Point"},
	{"CVTPD2PI",	"SSE2",	"Convert Packed Double Precision Floating Point to Packed Doubleword Integers"},
	{"CVTPD2DQ",	"SSE2",	"Convert Packed Double Precision Floating Point to Packed Doubleword Integer"},
	{"CVTPD2PS",	"SSE2",	"Convert Packed Double Precision Floating Point to Packed Single Precision Floating Point"},
	{"CVTPI2PD",	"SSE2",	"Convert Packed Doubleword Integers to Packed Double Precision Floating Point"},
	{"CVTPS2DQ",	"SSE2",	"Convert Packed Single Precision Floating Point to Packed Doubleword Integers"},
	{"CVTPS2PD",	"SSE2",	"Convert Packed Single Precision Floating Point to Packed Double Precision Floating Point"},
	{"CVTSD2SI",	"SSE2",	"Convert Scalar Double Precision Floating Point to Signed Doubleword or Quadword Integer"},
	{"CVTSD2SS",	"SSE2",	"Convert Scalar Double Precision Floating Point to Scalar Single Precision Floating Point"},
	{"CVTSI2SD",	"SSE2",	"Convert Signed Doubleword or Quadword Integer to Scalar Double Precision Floating Point"},
	{"CVTSI2SS",	"SSE2",	"Convert Signed Doubleword or Quadword Integer to Scalar Single Precision Floating Point"},
	{"CVTSS2SD",	"SSE2",	"Convert Scalar Single Precision Floating Point to Scalar Double Precision Floating Point"},
	{"CVTSS2SI",	"SSE2",	"Convert Scalar Single Precision Floating Point to Signed Doubleword or Quadword Integer"},
	{"CVTTPD2PI",	"SSE2",	"Convert Packed Double Precision Floating Point to Packed Doubleword Integers, Truncated"},
	{"CVTTPD2DQ",	"SSE2",	"Convert Packed Double Precision Floating Point to Packed Doubleword Integer, Truncated"},
	{"CVTTPS2DQ",	"SSE2",	"Convert Packed Single Precision Floating Point to Packed Doubleword Integers, Truncated"},
	{"CVTTPS2PI",	"SSE2",	"Convert Packed Single Precision Floating Point to Packed Doubleword Integers, Truncated"},
	{"CVTTSD2SI",	"SSE2",	"Convert Scalar Double Precision Floating Point to Signed Double or Quadword Integer, Truncated"},
	{"CVTTSS2SI",	"SSE2",	"Convert Scalar Single-Precision Floating Point to Signed Double or Quadword Integer, Truncated"},
	{"MOVSD",		"SSE2",	"Move String Doubleword"},//tbd
	{"MOVAPD",		"SSE2",	"Move Aligned Packed Double Precision Floating Point"},
	{"MOVUPD",		"SSE2",	"Move Unaligned Packed Double Precision Floating Point"},
	{"MOVHPD",		"SSE2",	"Move High Packed Double Precision Floating Point"},
	{"MOVLPD",		"SSE2",	"Move Low Packed Double Precision Floating Point"},
	//{"MOVDQ2Q",		"SSE2",	"Move Quadword to Quadword"}, //tbd
	//{"MOVQ2DQ",		"SSE2",	"Move Quadword to Quadword"}, //tbd
	{"MOVNTPD",		"SSE2",	"Move Non Temporal Packed Double Precision Floating Point"},
	{"MOVNTDQ",		"SSE2",	"Move Non Temporal Double Quadword"},
	{"MOVNTI",		"SSE2",	"Move Non Temporal Doubleword or Quadword"},
	{"MASKMOVDQU",	"SSE2",	"Masked Move Double Quadword Unaligned"},
	{"PMOVMSKB",	"SSE2",	"Packed Move Mask Byte"},
	{"PSHUFD",		"SSE2",	"Packed Shuffle Doublewords"},
	{"PSHUFHW",		"SSE2",	"Packed Shuffle High Words"},
	{"PSHUFLW",		"SSE2",	"Packed Shuffle Low Words"},
	{"UNPCKHPD",	"SSE2",	"Unpack High Double Precision Floating Point"},
	{"UNPCKLPD",	"SSE2",	"Unpack Low Double Precision Floating Point"},
	{"PUNPCKHBW",	"SSE2",	"Unpack and Interleave High Bytes"},
	{"PUNPCKHWD",	"SSE2",	"Unpack and Interleave High Words"},
	{"PUNPCKHDQ",	"SSE2",	"Unpack and Interleave High Doublewords"},
	{"PUNPCKHQDQ",	"SSE2",	"Unpack and Interleave High Quadwords"},
	{"PUNPCKLBW",	"SSE2",	"Unpack and Interleave Low Bytes"},
	{"PUNPCKLWD",	"SSE2",	"Unpack and Interleave Low Words"},
	{"PUNPCKLDQ",	"SSE2",	"Unpack and Interleave Low Doublewords"},
	{"PUNPCKLQDQ",	"SSE2",	"Unpack and Interleave Low Quadwords"},
	{"PACKSSDW",	"SSE2",	"Pack with Signed Saturation Doubleword to Word"},
	{"PACKSSWB",	"SSE2",	"Pack with Signed Saturation Word to Byte"},
	{"PACKUSWB",	"SSE2",	"Pack with Unsigned Saturation Word to Byte"},
	{"CLFLUSH",		"SSE2", "Cache Line Flush"},
	{"MFENCE",		"SSE2", "Memory Fence"},
	{"LFENCE",		"SSE2", "Load Fence"},
	{"PAUSE",		"SSE2", "Pause"},
	{"ADDSUBPD",	"SSE3", "Alternating Addition and Subtraction Packed Double Precision Floating Point"},
	{"ADDSUBPS",	"SSE3", "Alternating Addition and Subtraction Packed Single Precision Floating Point"},
	{"HADDPD",		"SSE3", "Horizontal Add Packed Double Precision Floating Point"},
	{"HADDPS",		"SSE3", "Horizontal Add Packed Single Precision"},
	{"HSUBPD",		"SSE3", "Horizontal Subtract Packed Double Precision"},
	{"HSUBPS",		"SSE3", "Horizontal Subtract Packed Single"},
	{"LDDQU",		"SSE3", "Load Unaligned Double Quadword"},
	{"MOVDDUP",		"SSE3", "Move and Duplicate Double Precision Floating Point"},
	{"MOVSHDUP",	"SSE3", "Move High and Duplicate Single Precision"},
	{"MOVSLDUP",	"SSE3", "Move Low and Duplicate Single Precisio"},
	{"FISTTP",		"SSE3", "Floating Point Integer Truncate and Store"},
	{"PSIGND",		"SSSE3", "Packed Sign Doubleword"},
	{"PSIGNW",		"SSSE3", "Packed Sign Word"},
	{"PSIGNB",		"SSSE3", "Packed Sign Byte"},
	{"PHADDD",		"SSSE3", "Packed Horizontal Add Doubleword"},
	{"PHADDW",		"SSSE3", "Packed Horizontal Add Word"},
	{"PHADDSW",		"SSSE3", "Packed Horizontal Add with Saturation Word"},
	{"PHSUBD",		"SSSE3", "Packed Horizontal Subtract Doubleword"},
	{"PHSUBW",		"SSSE3", "Packed Horizontal Subtract Word"},
	{"PHSUBSW",		"SSSE3", "Packed Horizontal Subtract with Saturation Word"},
	{"PMADDUBSW",	"SSSE3", "Packed Multiply and Add Unsigned Byte to Signed Word"},
	{"PABSD",		"SSSE3", "Packed Absolute Value Signed Doubleword"},
	{"PABSW",		"SSSE3", "Packed Absolute Value Signed Word"},
	{"PABSB",		"SSSE3", "Packed Absolute Value Signed Byte"},
	{"PMULHRSW",	"SSSE3", "Packed Multiply High with Round and Scale Words"},
	{"PSHUFB",		"SSSE3", "Packed Shuffle Byte"},
	{"PALIGNR",		"SSSE3", "Packed Align Right"},
	{"MPSADBW",		"SSE4.1", "Multiple Sum of Absolute Differences"},
	{"PHMINPOSUW",	"SSE4.1", "Horizontal Minimum and Position"},
	{"PMULDQ",		"SSE4.1", "Packed Multiply Signed Doubleword to Quadword"},
	{"PMULLD",		"SSE4.1", "Packed Multiply and Store Low Signed Doubleword"},
	{"DPPS",		"SSE4.1", "Dot Product Packed Single Precision Floating Point"},
	{"DPPD",		"SSE4.1", "Dot Product Packed Double Precision Floating Point"},
	{"BLENDPS",		"SSE4.1", "Blend Packed Single Precision Floating Point"},
	{"BLENDPD",		"SSE4.1", "Blend Packed Double Precision Floating Point"},
	{"BLENDVPS",	"SSE4.1", "Variable Blend Packed Single Precision Floating Point"},
	{"BLENDVPD",	"SSE4.1", "Variable Blend Packed Double Precision Floating Point"},
	{"PBLENDVB",	"SSE4.1", "Variable Blend Packed Bytes"},
	{"PBLENDW",		"SSE4.1", "Blend Packed Words"},
	{"PMINSB",		"SSE4.1", "Packed Minimum Signed Bytes"},
	{"PMAXSB",		"SSE4.1", "Packed Maximum Signed Bytes"},
	{"PMINUW",		"SSE4.1", "Packed Minimum Unsigned Words"},
	{"PMAXUW",		"SSE4.1", "Packed Maximum Unsigned Words"},
	{"PMINUD",		"SSE4.1", "Packed Minimum Unsigned Doublewords"},
	{"PMAXUD",		"SSE4.1", "Packed Maximum Unsigned Doublewords"},
	{"PMINSD",		"SSE4.1", "Packed Minimum Signed Doublewords"},
	{"PMAXSD",		"SSE4.1", "Packed Maximum Signed Doublewords"},
	{"ROUNDPS",		"SSE4.1", "Round Packed Single Precision Floating Point"},
	{"ROUNDSS",		"SSE4.1", "Round Scalar Single Precision"},
	{"ROUNDPD",		"SSE4.1", "Round Packed Double Precision Floating Point"},
	{"ROUNDSD",		"SSE4.1", "Round Scalar Double Precision"},
	{"INSERTPS",	"SSE4.1", "Insert Packed Single Precision Floating Point"},
	{"PINSRB",		"SSE4.1", "Packed Insert Byte"},
	{"PINSRD",		"SSE4.1", "Packed Insert Doubleword"},
	{"PINSRQ",		"SSE4.1", "Packed Insert Quadword"},
	{"EXTRACTPS",	"SSE4.1", "Extract Packed Single Precision Floating Point"},
	{"PEXTRB",		"SSE4.1", "Extract Packed Byte"},
	{"PEXTRW",		"SSE4.1", "Extract Packed Word"},
	{"PEXTRD",		"SSE4.1", "Extract Packed Doubleword"},
	{"PEXTRQ",		"SSE4.1", "Extract Packed Quadword"},
	{"PMOVSXBW",	"SSE4.1", "Packed Move with Sign Extension Byte to Word"},
	{"PMOVZXBW",	"SSE4.1", "Packed Move Byte to Word with Zero Extension"},
	{"PMOVSXBD",	"SSE4.1", "Packed Move with Sign Extension Byte to Doubleword"},
	{"PMOVZXBD",	"SSE4.1", "Packed Move with Zero Extension Byte to Doubleword"},
	{"PMOVSXBQ",	"SSE4.1", "Packed Move with Sign Extension Byte to Quadword"},
	{"PMOVZXBQ",	"SSE4.1", "Packed Move Byte to Quadword with Zero Extension"},
	{"PMOVSXWD",	"SSE4.1", "Packed Move with Sign Extension Word to Doubleword"},
	{"PMOVZXWD",	"SSE4.1", "Packed Move Word to Doubleword with Zero Extension"},
	{"PMOVSXWQ",	"SSE4.1", "Packed Move with Sign Extension Word to Quadword"},
	{"PMOVZXWQ",	"SSE4.1", "Packed Move with Zero Extension Word to Quadword"},
	{"PMOVSXDQ",	"SSE4.1", "Packed Move with Sign Extension Doubleword to Quadword"},
	{"PMOVZXDQ",	"SSE4.1", "Packed Move with Zero Extension Doubleword to Quadword"},
	{"PTEST",		"SSE4.1", "Packed Bit Test"},
	{"PCMPEQQ",		"SSE4.1", "Packed Compare Equal Quadwords"},
	{"PACKUSDW",	"SSE4.1", "Pack with Unsigned Saturation Doubleword to Word"},
	{"MOVNTDQA",	"SSE4.1", "Move Non Temporal Double Quadword Aligned"},
	{"CRC32",		"SSE4.2", "CRC32 Cyclical Redundancy Check"},
	{"PCMPESTRI",	"SSE4.2", "Packed Compare Explicit Length Strings Return Index"},
	{"PCMPESTRM",	"SSE4.2", "Packed Compare Explicit Length Strings Return Mask"},
	{"PCMPISTRI",	"SSE4.2", "Packed Compare Implicit Length Strings Return Index"},
	{"PCMPISTRM",	"SSE4.2", "Packed Compare Implicit Length Strings Return Mask"},
	{"PCMPGTQ",		"SSE4.2", "Packed Compare Greater Than Signed Quadwords"},
	{"POPCNT",		"SSE4.2", "Bit Population Count"},
	{"EXTRQ",		"SSE4a", "Extract Field From Register"},
	{"INSERTQ",		"SSE4a", "Insert Field"},
	{"MOVNTSD",		"SSE4a", "Move Non Temporal Scalar Double Precision Floating Point"},
	{"MOVNTSS",		"SSE4a", "Move Non Temporal Scalar Single Precision Floating Point"},
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
	//{"CRC32",		"8086", "CRC32 Cyclical Redundancy Check"},
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
	{"LODS",		"8086", "Load String"},
	{"LOOP",		"8086", "Loop"},
	{"MCOMMIT",		"8086", "Commit Stores to Memory"},
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
	srand (static_cast<uint32_t>(time(nullptr)));//clang immintrin.h support workaround
#else
	uint64_t randomizerPtr = 0;
	_rdseed64_step(&randomizerPtr);
	srand(randomizerPtr);
#endif
	int points = 0;
	while (points < 100)
	{
		uint64_t random = static_cast<uint64_t>(rand()) % mnemonics.size();
		//if (mnemonics[random].set != "SSE2")continue;
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

				std::cin >> answer;
				

			} while (answer != mnemonics[random].name);
		}
	}
}
