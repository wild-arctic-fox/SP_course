#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <locale.h>

#define numberOfThreads 10

HANDLE semaphore;

void print_problems() {
	setlocale(LC_ALL, "Russian");
	printf("\nSomething went wrong(\n");
	LPVOID e_mess;
	DWORD e_code = GetLastError();
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL,
		e_code, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&e_mess, 0, NULL);
	char* err_mess = (char*)e_mess;
	wprintf(L"ERROR was generated: failed with 0x%x code\n", e_code);
	wprintf(L"ERROR formatted message: %s\n", err_mess);
}


DWORD WINAPI ExecutedByThread(LPVOID lpParam)
{
	// Todo
	return 0;
}

int main()
{
	HANDLE threads[numberOfThreads];
	DWORD id;

	semaphore = CreateSemaphore(
		NULL, // A pointer to a SECURITY_ATTRIBUTES structure.
		3,	  // The initial count for the semaphore object. 
		3,	  // The maximum count for the semaphore object.
		NULL  // The name of the semaphore object.
	);

	if (semaphore == NULL){
		print_problems();
		return 1;
	}

	for (int i = 0; i < numberOfThreads; i++)
	{
		threads[i] = CreateThread(NULL, 0, ExecutedByThread, NULL, 0, &id);

		if (threads[i] == NULL){
			print_problems();
			return 1;
		}
	}

	WaitForMultipleObjects(numberOfThreads, threads, TRUE, INFINITE);

	for (int i = 0; i < numberOfThreads; i++)
		CloseHandle(threads[i]);

	CloseHandle(semaphore);

	return 0;
}
