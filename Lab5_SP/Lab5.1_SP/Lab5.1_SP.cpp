#include <stdio.h>
#include <Windows.h>

int main()
{
	HANDLE myMutex = CreateMutex(
		0, //A pointer to a SECURITY_ATTRIBUTES structure.
		0, //The calling thread does not obtain ownership of the mutex. 
		TEXT("MutexName") //The name of the mutex object.
	);
	DWORD result = WaitForSingleObject(myMutex, 0);
	if (result != WAIT_OBJECT_0){
		printf("Application is already running !!!\n");
		return 0;
	} else {
		printf("Is Running");
		while (1) {}
	}
	return 0;
}
