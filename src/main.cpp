/*
	MIT License

	Copyright (c) 2020 Oleksiy Ryabchun

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

// VS 6.0  > cl main.cpp /nologo /MD /W0 /O1 /GF /link /out:defense_fix.asi /DEBUG:NONE /DLL
// VS 2008 > cl main.cpp /nologo /MD /GS- /GL /O1 /Os /GF /link /out:defense_fix.asi /DEBUG:NONE /MANIFEST:NO
// VS 2019 > cl main.cpp /nologo /MD /GS- /GL /O1 /Os /GF /link /out:defense_fix.asi /DEBUG:NONE /EMITPOGOPHASEINFO

#define WIN32_LEAN_AND_MEAN

#include "windows.h"
#include "hooker.h"

#pragma comment(lib, "kernel32.lib")

const struct AddressSpace {
	DWORD pattern_check[2];
	DWORD armorer_fix[3];
	DWORD creatures_luck[2];
} addressSpace[] = {
// === RUS ======================================================================================================================================
#pragma region RUS
	// Heroes III Erathia - v1.0 Buka
	0x004D4A5F, 0x0059308B,
	0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000,

	// Heroes III Armageddon - v2.1 Buka
	0x004F2533, 0x005F9649,
	0x0041D5B3, 0x0041D6F1, 0x004640FD,
	0x00000000, 0x00000000,

	// Heroes III Armageddon - v2.2 Buka
	0x004F2863, 0x005F9609,
	0x0041D553, 0x0041D691, 0x00463D9D,
	0x00000000, 0x00000000,

	// Heroes III Shadow - v3.1 Buka
	0x004F7EB3, 0x00602379,
	0x0041E2D3, 0x0041E40F, 0x00465EF3,
	0x00000000, 0x00000000,

	// Heroes III Complete - v4.0 Buka
	0x004F7EB3, 0x006021A9,
	0x0041E456, 0x0041E595, 0x0046592C,
	0x00441626, 0x0043F7B2,

	// ----------------------------------------------------------------------------------------------------------------------------------------------

	// Heroes Chronicles Warlords & Underworld & Elements & Dragons - v1.0
	0x004EBA34, 0x005AF329,
	0x0041D5F3, 0x0041D731, 0x00461206,
	0x0043E0F6, 0x0043FFB5,

	// Heroes Chronicles Beastmaster & Sword - v1.0
	0x004EB494, 0x005AF2D9,
	0x0041D6A3, 0x0041D7E1, 0x00461126,
	0x0043FD05, 0x0043DE46,
#pragma endregion

// === ENG ======================================================================================================================================
#pragma region ENG
	// Heroes III Erathia - v1.0
	0x004D3363, 0x0058E558,
	0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000,

	// Heroes III Erathia - v1.1
	0x0041E573, 0x004210B8,
	0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000,

	// Heroes III Erathia - v1.2
	0x0041E523, 0x00421078,
	0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000,

	// Heroes III Erathia - v1.3
	0x004F58F3, 0x005D9679,
	0x0041E003, 0x0041E13F, 0x00465203,
	0x00000000, 0x00000000,

	// Heroes III Erathia - v1.4
	0x004F5583, 0x005D8F69,
	0x0041E343, 0x0041E47F, 0x004653D3,
	0x00000000, 0x00000000,

	// ----------------------------------------------------------------------------------------------------------------------------------------------

	// Heroes III Armageddon - v2.0
	0x004EB283, 0x005EEFD8,
	0x0041DDE3, 0x0041DF1F, 0x00460C59,
	0x00000000, 0x00000000,

	// Heroes III Armageddon - v2.1
	0x004F5C43, 0x00600299,
	0x0041E343, 0x0041E47F, 0x00465A23,
	0x00000000, 0x00000000,

	// Heroes III Armageddon - v2.2
	0x004F5963, 0x005FFBF9,
	0x0041E033, 0x0041E16F, 0x00465A53,
	0x00000000, 0x00000000,

	// ----------------------------------------------------------------------------------------------------------------------------------------------

	// Heroes III Shadow - v3.0
	0x004F7D73, 0x006027E9,
	0x0041E4B3, 0x0041E5EF, 0x00465D63,
	0x00000000, 0x00000000,

	// Heroes III Shadow - v3.1
	0x004F85B3, 0x006027E9,
	0x0041E203, 0x0041E33F, 0x00465B23,
	0x00000000, 0x00000000,

	// Heroes III Shadow - v3.2
	0x004F8193, 0x00602149,
	0x0041E3A3, 0x0041E4DF, 0x00465943,
	0x00441524, 0x0043F642,

	// ----------------------------------------------------------------------------------------------------------------------------------------------

	// Heroes III Complete - v4.0
	0x004F7B03, 0x00601B89,
	0x0041E223, 0x0041E35F, 0x00465D63,
	0x00000000, 0x00000000,

	// ==============================================================================================================================================

	// Heroes Chronicles Warlords & Underworld - v1.0
	0x004F0033, 0x005B5129,
	0x0041E1A3, 0x0041E2DF, 0x0046364C,
	0x00000000, 0x00000000,

	// Heroes Chronicles Elements & Dragons - v1.0
	0x004EFE04, 0x005B5469,
	0x0041E1C3, 0x0041E2FF, 0x004632CC,
	0x00000000, 0x00000000,

	// Heroes Chronicles WorldTree - v1.0
	0x004EFA84, 0x005B51B9,
	0x0041E163, 0x0041E29F, 0x0046326C,
	0x00000000, 0x00000000,

	// Heroes Chronicles FieryMoon - v1.0
	0x004EF824, 0x005B5249,
	0x0041E183, 0x0041E2BF, 0x00462CDC,
	0x00000000, 0x00000000,

	// Heroes Chronicles Beastmaster & Sword - v1.0
	0x004EF874, 0x005B4C09,
	0x0041E213, 0x0041E34F, 0x00462E5C,
	0x00000000, 0x00000000,
#pragma endregion

// === USA ======================================================================================================================================
#pragma region USA
	// Heroes Chronicles Beastmaster & Sword - v1.0
	0x004EF914, 0x005B51B9,
	0x0041E433, 0x0041E56F, 0x0046345C,
	0x00000000, 0x00000000,
#pragma endregion

// === GER ======================================================================================================================================
#pragma region GER
	// Heroes III Erathia - v1.2
	0x004D5253, 0x00591B29,
	0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000,

	// ==============================================================================================================================================

	// Heroes Chronicles Dragons - GOG - v1.0
	0x004EFA04, 0x005B51C9,
	0x0041E0F3, 0x0041E22F, 0x00462C0C,
	0x00000000, 0x00000000,
#pragma endregion

// === FRA ======================================================================================================================================
#pragma region FRA
	// Heroes III Armageddon - v2.1
	0x004F61C3, 0x006003D9,
	0x0041E143, 0x0041E27F, 0x00465CB3,
	0x00000000, 0x00000000,

	// Heroes III Shadow - v3.1
	0x004F8163, 0x006028F9,
	0x0041E413, 0x0041E54F, 0x004661B3,
	0x00000000, 0x00000000,
#pragma endregion

// === POL ======================================================================================================================================
#pragma region POL
	// Heroes III Armageddon - v2.1
	0x004F5723, 0x005FED57,
	0x0041E383, 0x0041E4BF, 0x00465813,
	0x00000000, 0x00000000,

	// Heroes III Shadow - v3.1
	0x004F7AF3, 0x00600ED7,
	0x0041E233, 0x0041E36F, 0x00465AE3,
	0x00000000, 0x00000000,

	// Heroes III Shadow - v3.2
	0x004F78D3, 0x00602179,
	0x0041E353, 0x0041E48F, 0x00465973,
	0x00000000, 0x00000000,

	// Heroes III Shadow - v3.2 / Armageddon - v2.2
	0x004F5993, 0x005FE337,
	0x0041E1A3, 0x0041E2DF, 0x00465903,
	0x00000000, 0x00000000
#pragma endregion
};

VOID PatchSpace(HOOKER hooker, const AddressSpace* hookSpace)
{
	// Armorer fix
	if (hookSpace->armorer_fix[0])
		for (DWORD i = 0; i < sizeof(hookSpace->armorer_fix) / sizeof(DWORD); ++i)
			PatchByte(hooker, hookSpace->armorer_fix[i] + 1, 0x4D); // fdivr -> fmul

	// Neutral creatures luck
	if (hookSpace->creatures_luck[0])
		for (DWORD i = 0; i < sizeof(hookSpace->creatures_luck) / sizeof(DWORD); ++i)
			PatchNop(hooker, hookSpace->creatures_luck[i], 6);
}

extern "C" VOID __stdcall PatchMain(HOOKER hooker)
{
	const AddressSpace* hookSpace = addressSpace;
	DWORD count = sizeof(addressSpace) / sizeof(AddressSpace);
	do
	{
		DWORD check;
		if ((ReadDWord(hooker, hookSpace->pattern_check[0] + 1, &check) && check == (WS_VISIBLE | WS_POPUP)) &&
			(ReadDWord(hooker, hookSpace->pattern_check[1] + 1, &check) && check == (WS_VISIBLE | WS_POPUP)))
		{
			PatchSpace(hooker, hookSpace);
			break;
		}

		++hookSpace;
	} while (--count);
}