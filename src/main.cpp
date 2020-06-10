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

// > cl main.cpp /nologo /MD /GS- /GL /O1 /Os /GF /link /out:defense_fix.asi /DEBUG:NONE /EMITPOGOPHASEINFO

#define WIN32_LEAN_AND_MEAN

#include "windows.h"
#include "IHooker.h"

#pragma comment(lib, "kernel32.lib")

VOID PatchMain(IHooker* hooker)
{
	DWORD check1, check2, equal;
	if (hooker->ReadDWord(0x004F8194, &check1) && check1 == (WS_VISIBLE | WS_POPUP) &&
		hooker->ReadDWord(0x0060214A, &check2) && check2 == (WS_VISIBLE | WS_POPUP))
	{
		// Defense fix for HoMM SoD 3.2 (eng)
		hooker->PatchByte(0x0041E3A4, 0x4D); // fdiv -> fmul
		hooker->PatchByte(0x0041E4E0, 0x4D); // fdiv -> fmul
		hooker->PatchByte(0x00465944, 0x4D); // fdiv -> fmul
	}
}