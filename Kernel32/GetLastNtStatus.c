#include <windows.h>
#include "TEB.h"

PTEB GetTeb(VOID)
{
#if defined(_WIN64)
	return (PTEB)__readgsqword(0x30);
#elif define(_WIN32)
	return (PTEB)__readfsdword(0x18);
#endif
}

NTSTATUS GetLastNtStatus(VOID)
{
	PTEB Teb = (PTEB)GetTeb();
	return Teb->LastStatusValue;
}

INT main(VOID)
{
	NTSTATUS Status;

	Status = GetLastNtStatus();

	return ERROR_SUCCESS;
}
