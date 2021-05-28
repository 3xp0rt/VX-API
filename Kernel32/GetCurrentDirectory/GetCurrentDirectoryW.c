#include <windows.h>

/*
DEFINITIONS FOR PEB AND RTL_USER_PROCESS_PARAMETERS MUST BE PRESENT
*/

PPEB GetPeb(VOID)
{
#if defined(_WIN64)
	return (PPEB)__readgsqword(0x60);
#elif define(_WIN32)
	return (PPEB)__readfsdword(0x30);
#endif
}

PWCHAR StringCopyW(PWCHAR String1, PWCHAR String2)
{
	PWCHAR p = String1;

	while ((*p++ = *String2++) != 0);

	return String1;
}

INT main(VOID)
{
	PPEB Peb;
	PRTL_USER_PROCESS_PARAMETERS ProcessParameters;
	WCHAR CurrentDirectory[WT_MAX_PATH] = { 0 };

	Peb = (PPEB)GetPeb();
	ProcessParameters = Peb->ProcessParameters;

	StringCopyW(CurrentDirectory, ProcessParameters->CurrentDirectory.DosPath.Buffer);

	return ERROR_SUCCESS;
}

