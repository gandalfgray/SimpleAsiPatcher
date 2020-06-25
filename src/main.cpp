/*
	MIT License

	Copyright (c) 2020 Verok & Ben80

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

// VS 6.0
// > rc main.rc
// > cl main.cpp main.res /nologo /MD /W0 /O1 /GF /link /out:h3_fix.asi /debug:none /dll /merge:.text=.asi /merge:.rdata=.asi /section:.asi,re

// VS 2008
// > rc main.rc
// > cl main.cpp main.res /nologo /MD /GS- /GL /O1 /Os /GF /link /out:h3_fix.asi /debug:none /manifest:no /merge:.text=.asi /merge:.rdata=.asi /section:.asi,re

// VS 2019
// > rc main.rc
// > cl main.cpp main.res /nologo /MD /GS- /GL /O1 /Os /GF /link /out:h3_fix.asi /debug:none /emitpogophaseinfo /merge:.text=.rdata /merge:.rdata=.asi /section:.asi,re

#define WIN32_LEAN_AND_MEAN

#include "windows.h"
#include "hooker.h"
#include "H3Structures.h"
#include "H3Numerations.h"

#pragma comment(lib, "kernel32.lib")

#pragma pack(1)
const struct AddressSpace {
	DWORD pattern_check[2];
	DWORD armorer_fix[3];
	DWORD creatures_luck[2];
	struct {
		DWORD hook;
		BYTE type;
	} lighthouse_bonus;
	struct {
		DWORD hook;
		DWORD cast;
		DWORD skip;
		BYTE type;
	} ai_water_walk_fly;
	DWORD tavern_rumors;
	struct {
		DWORD hook;
		BYTE type;
	} refuge_camp;
	DWORD ghost_hero;
	struct {
		DWORD hook;
		DWORD offset[3];
	} double_cast;
	struct {
		DWORD hook;
		BYTE index;
	} harpy_binds;
	DWORD witch_huts;
} addressSpace[] = {
// === RUS ======================================================================================================================================
#pragma region RUS
	// Heroes III Erathia - v1.0 Buka
	0x004D4A5F, 0x0059308B,
	0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000,
	0x00000000, 0,
	0x00000000, 0x00000000, 0x00000000, 1,
	0x004B0570, 0x004E08F2, 4, 0x00547F89,
	0x00537746, 0x000050E0, 0x000051C4, 0x00013540,
	0x00000000, 0,
	0x00000000,

	// Heroes III Armageddon - v2.1 Buka
	0x004F2533, 0x005F9649,
	0x0041D5B3, 0x0041D6F1, 0x004640FD,
	0x00440545, 0x0043E686,
	0x004DFE30, 0,
	0x0042EDC8, 0x0042EDEB, 0x0042F10B, 0,
	0x004C8550, 0x004FFBB8, 3, 0x005A7F0A,
	0x00597358, 0x000053CC, 0x000054B4, 0x00013D74,
	0x004766A8, 176,
	0x0052D661,

	// Heroes III Armageddon - v2.2 Buka
	0x004F2863, 0x005F9609,
	0x0041D553, 0x0041D691, 0x00463D9D,
	0x00440045, 0x0043E186,
	0x004E02F0, 0,
	0x0042ED98, 0x0042EDBB, 0x0042F0DB, 0,
	0x004C87E0, 0x004FFEE8, 3, 0x005A7F3A,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00476368, 176,
	0x0052D971,

	// Heroes III Shadow - v3.1 Buka
	0x004F7EB3, 0x00602379,
	0x0041E2D3, 0x0041E40F, 0x00465EF3,
	0x00441DA4, 0x0043FEC2,
	0x004E4A20, 0,
	0x004300DE, 0x00430101, 0x00430410, 0,
	0x004CCD40, 0x00505B05, 0, 0x005AF9CA,
	0x0059EDB9, 0x000053CC, 0x000054B4, 0x00013D74,
	0x004789C0, 176,
	0x00534471,

	// Heroes III Complete - v4.0 Buka
	0x004F7EB3, 0x006021A9,
	0x0041E456, 0x0041E595, 0x0046592C,
	0x00441626, 0x0043F7B2,
	0x004E4ED0, 0,
	0x004301E6, 0x00430209, 0x00430519, 0,
	0x004CCFE0, 0x00505B6E, 3, 0x005AFA8A,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00478563, 177,
	0x00534031,

	// ----------------------------------------------------------------------------------------------------------------------------------------------

	// Heroes Chronicles Warlords & Underworld & Elements & Dragons - v1.0
	0x004EBA34, 0x005AF329,
	0x0041D5F3, 0x0041D731, 0x00461206,
	0x0043E0F6, 0x0043FFB5,
	0x004D9107, 0,
	0x0042ED78, 0x0042ED9B, 0x0042F0BB, 0,
	0x004C1150, 0x00000000, 3, 0x005650FA,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00473678, 176,
	0x00000000,

	// Heroes Chronicles Beastmaster & Sword - v1.0
	0x004EB494, 0x005AF2D9,
	0x0041D6A3, 0x0041D7E1, 0x00461126,
	0x0043FD05, 0x0043DE46,
	0x004D8EC7, 0,
	0x0042EE68, 0x0042EE8B, 0x0042F1AB, 0,
	0x004C1410, 0x00000000, 3, 0x005650EA,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00473638, 176,
	0x00000000,
#pragma endregion

// === ENG ======================================================================================================================================
#pragma region ENG
	// Heroes III Erathia - v1.0
	0x004D3363, 0x0058E558,
	0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000,
	0x00000000, 0,
	0x0042E079, 0x0042E09C, 0x0042E39B, 0,
	0x004AF690, 0x004DEE22, 2, 0x00544E55,
	0x00534EB8, 0x000050E0, 0x000051C4, 0x00013540,
	0x00000000, 0,
	0x00000000,

	// Heroes III Erathia - v1.1
	0x0041E573, 0x004210B8,
	0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000,
	0x00000000, 0,
	0x0044DA49, 0x0044DA6C, 0x0044DD6B, 0,
	0x004C11D0, 0x004ED982, 2, 0x0054D825,
	0x0053D9F8, 0x000050E0, 0x000051C4, 0x000013540,
	0x00000000, 0,
	0x00000000,

	// Heroes III Erathia - v1.2
	0x0041E523, 0x00421078,
	0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000,
	0x00000000, 0,
	0x0044D8E9, 0x0044D90C, 0x0044DC0B, 0,
	0x004C1410, 0x004EDDA2, 2, 0x0054DBF5,
	0x0053DC98, 0x000053CC, 0x000054B0, 0x0001382C,
	0x00000000, 0,
	0x00000000,

	// Heroes III Erathia - v1.3
	0x004F58F3, 0x005D9679,
	0x0041E003, 0x0041E13F, 0x00465203,
	0x00000000, 0x00000000,
	0x004E27A0, 0,
	0x0042FE4E, 0x0042FE71, 0x00430180, 0,
	0x004CAA90, 0x00502C65, 0, 0x0058CD4A,
	0x0057C149, 0x000053CC, 0x000054B4, 0x00013D74,
	0x00477CC0, 176,
	0x00000000,

	// Heroes III Erathia - v1.4
	0x004F5583, 0x005D8F69,
	0x0041E343, 0x0041E47F, 0x004653D3,
	0x00000000, 0x00000000,
	0x004E25F0, 0,
	0x0043017E, 0x004301A1, 0x004304B0, 0,
	0x004CA6C0, 0x00502925, 0, 0x0058C5FA,
	0x0057B9C9, 0x000053CC, 0x000054B4, 0x00013D74,
	0x004780C0, 176,
	0x00000000,

	// ----------------------------------------------------------------------------------------------------------------------------------------------

	// Heroes III Armageddon - v2.0
	0x004EB283, 0x005EEFD8,
	0x0041DDE3, 0x0041DF1F, 0x00460C59,
	0x00440850, 0x0043E992,
	0x004D91D0, 1,
	0x0042F8F9, 0x0042F91C, 0x0042FC1B, 0,
	0x004C3290, 0x004F88D6, 1, 0x0059D605,
	0x0058CEC8, 0x000053CC, 0x000054B0, 0x00013D70,
	0x00472AA1, 176,
	0x00526632,

	// Heroes III Armageddon - v2.1
	0x004F5C43, 0x00600299,
	0x0041E343, 0x0041E47F, 0x00465A23,
	0x004416D4, 0x0043F7F2,
	0x004E2D90, 0,
	0x0043015E, 0x00430181, 0x00430490, 0,
	0x004CAF80, 0x00503875, 0, 0x005ADC7A,
	0x0059D029, 0x000053CC, 0x000054B4, 0x00013D74,
	0x00478700, 176,
	0x00532341,

	// Heroes III Armageddon - v2.2
	0x004F5963, 0x005FFBF9,
	0x0041E033, 0x0041E16F, 0x00465A53,
	0x00441904, 0x0043FA22,
	0x004E2940, 0,
	0x0042FE6E, 0x0042FE91, 0x004301A0, 0,
	0x004CB020, 0x005035D5, 0, 0x005AD61A,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x004789D0, 176,
	0x00531DC1,

	// ----------------------------------------------------------------------------------------------------------------------------------------------

	// Heroes III Shadow - v3.0
	0x004F7D73, 0x006027E9,
	0x0041E4B3, 0x0041E5EF, 0x00465D63,
	0x00441A64, 0x0043FB82,
	0x004E4930, 0,
	0x004301CE, 0x004301F1, 0x00430500, 0,
	0x004CCC30, 0x00505995, 0, 0x005B020A,
	0x0059F589, 0x000053CC, 0x000054B4, 0x00013D74,
	0x004787C0, 176,
	0x00534751,

	// Heroes III Shadow - v3.1
	0x004F85B3, 0x006027E9,
	0x0041E203, 0x0041E33F, 0x00465B23,
	0x004414A4, 0x0043F5C2,
	0x004E5130, 0,
	0x0043001E, 0x00430041, 0x00430350, 0,
	0x00000000, 0x00506205, 0, 0x005B01DA,
	0x0059F5C9, 0x000053CC, 0x000054B4, 0x00013D74,
	0x004787B0, 176,
	0x00534EE1,

	// Heroes III Shadow - v3.2
	0x004F8193, 0x00602149,
	0x0041E3A3, 0x0041E4DF, 0x00465943,
	0x00441524, 0x0043F642,
	0x004E4D40, 0,
	0x0043020E, 0x00430231, 0x00430540, 0,
	0x004CCC40, 0x00505E15, 0, 0x005AF90A,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00478360, 176,
	0x00534621,

	// ----------------------------------------------------------------------------------------------------------------------------------------------

	// Heroes III Complete - v4.0
	0x004F7B03, 0x00601B89,
	0x0041E223, 0x0041E35F, 0x00465D63,
	0x00441804, 0x0043F922,
	0x004E4AD0, 0,
	0x0043020E, 0x00430231, 0x00430540, 0,
	0x004CCF80, 0x005057C5, 0, 0x005AF57A,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00478A30, 176,
	0x00534141,

	// ==============================================================================================================================================

	// Heroes Chronicles Warlords & Underworld - v1.0
	0x004F0033, 0x005B5129,
	0x0041E1A3, 0x0041E2DF, 0x0046364C,
	0x00441D34, 0x0043FE52,
	0x004DCB70, 1,
	0x0042FF0E, 0x0042FF31, 0x00430240, 0,
	0x004C5160, 0x00000000, 0, 0x00569F5A,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00476440, 176,
	0x00000000,

	// Heroes Chronicles Elements & Dragons - v1.0
	0x004EFE04, 0x005B5469,
	0x0041E1C3, 0x0041E2FF, 0x004632CC,
	0x00441744, 0x0043F862,
	0x004DCB30, 1,
	0x0042FFEE, 0x00430011, 0x00430320, 0,
	0x004C4B90, 0x00000000, 0, 0x0056A21A,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00475F00, 176,
	0x00000000,

	// Heroes Chronicles WorldTree - v1.0
	0x004EFA84, 0x005B51B9,
	0x0041E163, 0x0041E29F, 0x0046326C,
	0x004418F4, 0x0043FA12,
	0x004DC5E0, 1,
	0x0042FEBE, 0x0042FEE1, 0x004301F0, 0,
	0x004C4AF0, 0x00000000, 0, 0x00569F3A,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00475D90, 176,
	0x00000000,

	// Heroes Chronicles FieryMoon - v1.0
	0x004EF824, 0x005B5249,
	0x0041E183, 0x0041E2BF, 0x00462CDC,
	0x00441424, 0x0043F542,
	0x004DC760, 1,
	0x0042FEDE, 0x0042FF01, 0x00430210, 0,
	0x004C4810, 0x00000000, 0, 0x0056A1EA,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x004758A0, 176,
	0x00000000,

	// Heroes Chronicles Beastmaster & Sword - v1.0
	0x004EF874, 0x005B4C09,
	0x0041E213, 0x0041E34F, 0x00462E5C,
	0x00441514, 0x0043F632,
	0x004DC670, 1,
	0x0042FF46, 0x0042FF69, 0x00430279, 0,
	0x004C4520, 0x00000000, 3, 0x00569BDA,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00475B20, 176,
	0x00000000,
#pragma endregion

// === USA ======================================================================================================================================
#pragma region USA
	// Heroes Chronicles Beastmaster & Sword - v1.0
	0x004EF914, 0x005B51B9,
	0x0041E433, 0x0041E56F, 0x0046345C,
	0x004419E4, 0x0043FB02,
	0x004DC850, 1,
	0x0043018E, 0x004301B1, 0x004304C0, 0,
	0x004C4B40, 0x00000000, 0, 0x0056A16A,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00476030, 176,
	0x00000000,
#pragma endregion

// === GER ======================================================================================================================================
#pragma region GER
	// Heroes III Erathia - v1.2
	0x004D5253, 0x00591B29,
	0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000,
	0x00000000, 0,
	0x0042E5FB, 0x0042E61E, 0x0042E94D, 0,
	0x004B1500, 0x004E0C83, 2, 0x00547EFA,
	0x00537B99, 0x000053CC, 0x000054B0, 0x0001382C,
	0x00000000, 0,
	0x00000000,

	// ==============================================================================================================================================

	// Heroes Chronicles Dragons - GOG - v1.0
	0x004EFA04, 0x005B51C9,
	0x0041E0F3, 0x0041E22F, 0x00462C0C,
	0x00441354, 0x0043F472,
	0x004DC940, 1,
	0x0042FE4E, 0x0042FE71, 0x00430180, 0,
	0x004C43C0, 0x00000000, 0, 0x0056A16A,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00475790, 176,
	0x00000000,
#pragma endregion

// === FRA ======================================================================================================================================
#pragma region FRA
	// Heroes III Armageddon - v2.1
	0x004F61C3, 0x006003D9,
	0x0041E143, 0x0041E27F, 0x00465CB3,
	0x00441914, 0x0043FA32,
	0x004E3050, 0,
	0x0042FF5E, 0x0042FF81, 0x00430290, 0,
	0x004CB170, 0x00503DF5, 0, 0x005ADD3A,
	0x0059D0E9, 0x000053CC, 0x000054B4, 0x00013D74,
	0x00478990, 176,
	0x00532691,

	// Heroes III Shadow - v3.1
	0x004F8163, 0x006028F9,
	0x0041E413, 0x0041E54F, 0x004661B3,
	0x00441CF4, 0x0043FE12,
	0x004E4A20, 0,
	0x0043022E, 0x00430251, 0x00430560, 0,
	0x004CD040, 0x00505DB5, 0, 0x005B02EA,
	0x0059F6D9, 0x000053CC, 0x000054B4, 0x00013D74,
	0x00478BF0, 176,
	0x00534EA1,
#pragma endregion

// === POL ======================================================================================================================================
#pragma region POL
	// Heroes III Armageddon - v2.1
	0x004F5723, 0x005FED57,
	0x0041E383, 0x0041E4BF, 0x00465813,
	0x004414A4, 0x0043F5C2,
	0x004E2890, 0,
	0x004301BE, 0x004301E1, 0x004304F0, 0,
	0x004CA910, 0x00503355, 0, 0x005ADCFA,
	0x0059D0D9, 0x000053CC, 0x000054B4, 0x00013D74,
	0x00478270, 176,
	0x00531EF1,

	// Heroes III Shadow - v3.1
	0x004F7AF3, 0x00600ED7,
	0x0041E233, 0x0041E36F, 0x00465AE3,
	0x00441574, 0x0043F692,
	0x004E44D0, 0,
	0x00430026, 0x00430049, 0x00430359, 0,
	0x004CCA10, 0x0050361E, 3, 0x005AFD1A,
	0x0059EFF9, 0x000053CC, 0x000054B4, 0x00013D74,
	0x00478430, 176,
	0x00534041,

	// Heroes III Shadow - v3.2
	0x004F78D3, 0x00602179,
	0x0041E353, 0x0041E48F, 0x00465973,
	0x004414E4, 0x0043F602,
	0x004E4480, 0,
	0x00430136, 0x00430159, 0x00430469, 0,
	0x004CC630, 0x0050578E, 3, 0x005AF9BA,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00478210, 176,
	0x00533D71,

	// Heroes III Shadow - v3.2 / Armageddon - v2.2
	0x004F5993, 0x005FE337,
	0x0041E1A3, 0x0041E2DF, 0x00465903,
	0x00441764, 0x0043F883,
	0x004E2B20, 0,
	0x0042FF86, 0x0042FFA9, 0x004302B9, 0,
	0x004CAB10, 0x0050557E, 3, 0x005AD13A,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00478270, 176,
	0x005317A1
#pragma endregion
};
#pragma pack()

const AddressSpace* hookSpace;

#pragma region The Castles Lighthouse building bonus
DWORD __fastcall castleOwnerCheck(H3Town* town, H3Hero* hero)
{
	return hookSpace->lighthouse_bonus.hook + (hero->owner_id == town->owner_id ? 6 : 44);
}

VOID __declspec(naked) hook_castleOwnerCheck_v0()
{
	__asm
	{
		push ecx
		mov edx, [ebp - 0x4]
		call castleOwnerCheck
		pop ecx

		mov edx, eax
		mov eax, [ecx + 0x150]
		jmp edx
	}
}

VOID __declspec(naked) hook_castleOwnerCheck_v1()
{
	__asm
	{
		push edx
		mov ecx, [ebp - 0x4]
		xchg ecx, edx
		call castleOwnerCheck
		pop edx

		mov ecx, eax
		mov eax, [edx + 0x150]
		jmp ecx
	}
}
#pragma endregion

#pragma region Prevents AI from casting Fly if they dont have it.
DWORD __fastcall ai_water_walk_fly(H3Hero* hero, BOOL hasWingth, DWORD* res)
{
	if (!hasWingth && // no angel wings
		hero->learned_spell[SPL_FLY] == 0 && hero->available_spell[SPL_FLY] == 0 && // this AI hero does not have the means to cast fly (id = 6)
		(hero->learned_spell[SPL_WATER_WALK] != 0 || hero->available_spell[SPL_WATER_WALK] != 0)) // this AI hero has access to waterwalk (id = 7)
	{
		// waterwalk is not cast ~ waterwalk field is *(&hero + 0x116) (see 0x4E6040 Cast_waterwalk function)
		// try to cast waterwalk instead (code checks for Boots of Levitation first...)
		// skip procedure
		*res = hero->waterwalk_power == -1 ? hookSpace->ai_water_walk_fly.cast : hookSpace->ai_water_walk_fly.skip;
		return TRUE;
	}

	*res = hookSpace->ai_water_walk_fly.hook;
	return FALSE;
}

VOID __declspec(naked) hook_ai_water_walk_fly_v0()
{
	__asm {
		push eax
		push ecx

		push esp
		mov edx, eax
		mov ecx, esi
		call ai_water_walk_fly

		pop edx
		pop ecx

		test eax, eax
		jnz lbl_ret

		add edx, 7
		push ecx
		push 0x6
		mov ecx, [ebp-0x10]
		push ecx

		lbl_ret:
		jmp edx
	}
}

VOID __declspec(naked) hook_ai_water_walk_fly_v1()
{
	__asm {
		push eax
		push ecx

		push esp
		mov edx, eax
		mov ecx, esi
		call ai_water_walk_fly

		pop edx
		pop ecx

		test eax, eax
		mov eax, edx
		jnz lbl_ret

		add eax, 8
		push ecx
		push 6
		push ebx
		lea edx, [esp-0x1C]

		lbl_ret:
		jmp eax
	}
}
#pragma endregion

#pragma region fix ghost hero(without army)
DWORD sub_ghostHero;
DWORD __fastcall ghostHeroFix(H3Army* army, DWORD, INT cell, H3Army* destArmy, INT destCell, BOOL isHero, BOOL destIsHero)
{
	if (isHero && army != destArmy && destArmy->type[destCell] < 0)
	{
		INT creaturesCount = 0;
		for (DWORD i = 0; i < 7; i++)
			if (army->type[i] >= 0)
				creaturesCount += army->count[i];

		if (creaturesCount <= 1)
			return NULL;
	}
	
	return ((DWORD(__thiscall*)(H3Army*, INT, H3Army*, INT, BOOL, BOOL))sub_ghostHero)(army, cell, destArmy, destCell, isHero, destIsHero);
}
#pragma endregion

#pragma region RefugeCamp fix for random maps(it gave only 1 Pikeman each week)
VOID __declspec(naked) hook_fixRefugeCamp_v0()
{
	__asm {
		test al, al
		jz lbl_cont

		mov [edi+0x22], dx

		lbl_cont:
		test al, al
		retn
	}
}

VOID __declspec(naked) hook_fixRefugeCamp_v1()
{
	__asm {
		test al, al
		jz lbl_cont

		mov [ebx+0x22], dx

		lbl_cont:
		test al, al
		retn
	}
}

VOID __declspec(naked) hook_fixRefugeCamp_v2()
{
	__asm {
		mov cx, [edi+0x38]

		test al, al
		jz lbl_cont

		mov [ebx+0x22], cx

		lbl_cont:
		test al, al
		retn
	}
}

VOID __declspec(naked) hook_fixRefugeCamp_v3()
{
	__asm {
		test al, al
		jz lbl_cont

		mov [edi+0x22], cx

		lbl_cont:
		test al, al
		retn
	}
}

VOID __declspec(naked) hook_fixRefugeCamp_v4()
{
	__asm {
		mov cx, [edi+0x38]

		test al, al
		jz lbl_cont

		mov [ebp+0x22], cx

		lbl_cont:
		test al, al
		retn
	}
}

VOID __declspec(naked) hook_fixRefugeCamp_v5()
{
	__asm {
		test al, al
		jz lbl_cont

		mov [edi+0x22], cx

		lbl_cont:
		test al, al
		retn
	}
}
#pragma endregion

#pragma region fix double cast during 1 round in battle
DWORD __stdcall double_cast_offset(DWORD index)
{
	return hookSpace->double_cast.offset[index];
}

VOID __declspec(naked) hook_double_cast()
{
	__asm {
		push eax
		push 0
		call double_cast_offset
		pop edx

		lea ecx, [esi + edx * 4]
		mov ecx, [ecx + eax]
		test ecx, ecx
		jz lbl_null

		push edx
		push 1
		call double_cast_offset
		pop edx

		lea ecx, [esi + edx * 4]
		mov ecx, [ecx + eax]
		test ecx, ecx
		jz lbl_cont

		push 2
		call double_cast_offset

		mov al, [esi + eax]
		test al, al
		jz lbl_null

		lbl_cont:
		xor ecx, ecx
		inc ecx
		retn

		lbl_null:
		xor ecx, ecx
		retn
	}
}
#pragma endregion

#pragma region fix Harpy fly after Dendroid bind
DWORD sub_fixHarpyBinds;
DWORD __fastcall fixHarpyBinds(DWORD* obj, DWORD, DWORD a2, DWORD a3)
{
	return !obj[hookSpace->harpy_binds.index] ? ((DWORD(__thiscall*)(DWORD*, DWORD, DWORD))sub_fixHarpyBinds)(obj, a2, a3) : NULL;
}
#pragma endregion

VOID PatchSpace(HOOKER hooker)
{
	// Armorer fix
	if (hookSpace->armorer_fix[0])
		for (DWORD i = 0; i < sizeof(hookSpace->armorer_fix) / sizeof(DWORD); ++i)
			PatchByte(hooker, hookSpace->armorer_fix[i] + 1, 0x4D); // fdivr -> fmul

	// Neutral creatures luck
	if (hookSpace->creatures_luck[0])
		for (DWORD i = 0; i < sizeof(hookSpace->creatures_luck) / sizeof(DWORD); ++i)
			PatchNop(hooker, hookSpace->creatures_luck[i], 6);

	// Castle's Lighthouse building bonus
	if (hookSpace->lighthouse_bonus.hook)
		PatchHook(hooker, hookSpace->lighthouse_bonus.hook, !hookSpace->lighthouse_bonus.type ? hook_castleOwnerCheck_v0 : hook_castleOwnerCheck_v1);

	// Prevents AI from casting Fly if they don't have it.
	if (hookSpace->ai_water_walk_fly.hook)
		PatchHook(hooker, hookSpace->ai_water_walk_fly.hook, !hookSpace->ai_water_walk_fly.type ? hook_ai_water_walk_fly_v0 : hook_ai_water_walk_fly_v1);

	// Tavern rumors bug fix
	if (hookSpace->tavern_rumors)
	{
		DWORD arrList;
		if (ReadDWord(hooker, hookSpace->tavern_rumors + 3, &arrList))
			PatchDWord(hooker, hookSpace->tavern_rumors + 3, arrList - 4);
	}

	// RefugeCamp fix for random maps (it gave only 1 Pikeman each week)
	if (hookSpace->refuge_camp.hook)
	{
		switch (hookSpace->refuge_camp.type)
		{
		case 1:
			PatchCall(hooker, hookSpace->refuge_camp.hook, hook_fixRefugeCamp_v1, 1);
			break;
		case 2:
			PatchCall(hooker, hookSpace->refuge_camp.hook, hook_fixRefugeCamp_v2, 5);
			break;
		case 3:
			PatchCall(hooker, hookSpace->refuge_camp.hook, hook_fixRefugeCamp_v3, 1);
			break;
		case 4:
			PatchCall(hooker, hookSpace->refuge_camp.hook, hook_fixRefugeCamp_v3, 5);
			break;
		default:
			PatchCall(hooker, hookSpace->refuge_camp.hook, hook_fixRefugeCamp_v0, 1);
			break;
		}
	}

	// fix ghost hero (without army)
	if (hookSpace->ghost_hero && ReadDWord(hooker, hookSpace->ghost_hero + 1, &sub_ghostHero))
	{
		sub_ghostHero += hookSpace->ghost_hero + 5 + GetBaseOffset(hooker);
		PatchCall(hooker, hookSpace->ghost_hero, ghostHeroFix);
	}

	// fix double cast during 1 round in battle
	if (hookSpace->double_cast.hook)
		PatchCall(hooker, hookSpace->double_cast.hook, hook_double_cast, 2);

	// fix Harpy fly after Dendroid bind
	if (hookSpace->harpy_binds.hook && ReadDWord(hooker, hookSpace->harpy_binds.hook + 1, &sub_fixHarpyBinds))
	{
		sub_fixHarpyBinds += hookSpace->harpy_binds.hook + 5 + GetBaseOffset(hooker);
		PatchCall(hooker, hookSpace->harpy_binds.hook, fixHarpyBinds);
	}

	// fix Witch Huts for random maps (it gave only secondary skills with number 15 or lesser)
	if (hookSpace->witch_huts)
		PatchDWord(hooker, hookSpace->witch_huts + 3, 0x0FFFEFBF);
}

extern "C" VOID __stdcall PatchMain(HOOKER hooker)
{
	hookSpace = addressSpace;
	DWORD count = sizeof(addressSpace) / sizeof(AddressSpace);
	do
	{
		DWORD check;
		if ((ReadDWord(hooker, hookSpace->pattern_check[0] + 1, &check) && check == (WS_VISIBLE | WS_POPUP)) &&
			(ReadDWord(hooker, hookSpace->pattern_check[1] + 1, &check) && check == (WS_VISIBLE | WS_POPUP)))
		{
			PatchSpace(hooker);
			break;
		}

		++hookSpace;
	} while (--count);
}
