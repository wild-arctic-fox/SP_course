#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define amountOfNumbers 5

CRITICAL_SECTION criticalSection;
HANDLE* threadHandles;
int dwTlsIndex;

//F:\Desktop\SP_course\Lab4_SP\Lab4.2_SP\Debug\Lab4.2_SP.exe 4

void incorrect_input() {
	printf("\nYou made a mistake !!!\n");
	printf("Only 1 arguments available:\n");
	printf("Number of threads => more then 1\n");
	exit(0);
}

int countLargestDivisor(int number)
{
	int n = number / 2;
	for (int i = n; i >= 2; i--) {
		if (number% i == 0) 
			return i;
	}
}

void fillLargestDivisors(int* initArr, int* resArr)
{
	for (int i = 0; i < amountOfNumbers; i++){
		resArr[i] = countLargestDivisor(initArr[i]);
	}
}

void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++){
		printf(" %d", arr[i]);
	}
}

int countSum(int* arr, int size)
{
	int result = 0;
	for (int i = 0; i < size; i++) {
		result += arr[i];
	}
	return result;
}

DWORD WINAPI executedByThread(LPVOID arr)
{
	EnterCriticalSection(&criticalSection);
	printf("Id => %u\n", GetCurrentThreadId());
	int* array = (int*)arr;
	TlsSetValue(dwTlsIndex, (LPVOID)(new int[amountOfNumbers]));
	int sum = 0;
	// Print init array
	printf("Generated array => ");
	printArr(array, amountOfNumbers);
	// Count largest divisors
	fillLargestDivisors(array, (int*)TlsGetValue(dwTlsIndex));
	// Print new array
	printf("\nModyfied array => ");
	printArr((int*)TlsGetValue(dwTlsIndex), amountOfNumbers);
	// Count sum
	sum = countSum((int*)TlsGetValue(dwTlsIndex), amountOfNumbers);
	printf("\nSum => %d\n\n", sum);
	LeaveCriticalSection(&criticalSection);
	return 0;
}

void runThreads(int threadsCount)
{
	printf("Number of threads => %d\n\n", threadsCount);
	// Initializes a critical section object.
	InitializeCriticalSection(&criticalSection);
	// Init thread
	threadHandles = new HANDLE[threadsCount];
	DWORD* ids = new DWORD[threadsCount];
	int** arrays = new int* [threadsCount];
	time_t t;
	srand((unsigned)time(&t));
	// Allocates a thread local storage (TLS) index
	dwTlsIndex = TlsAlloc();
	for (int i = 0; i < threadsCount; i++)
	{
		arrays[i] = new int[amountOfNumbers];
		for (int j = 0; j < amountOfNumbers; j++){
			arrays[i][j] = rand() % 90 + 10;
		}
		threadHandles[i] = CreateThread(
			NULL,			  //A pointer to a SECURITY_ATTRIBUTES
			0,				  //The initial size of the stack, in bytes.
			executedByThread, //A pointer to the application-defined function to be executed by the thread.
			arrays[i],		  //A pointer to a variable to be passed to the thread.
			NULL,			  //The flags that control the creation of the thread.
			&ids[i]);		  //A pointer to a variable that receives the thread identifier
	}
}

int main(int argc, char* argv[])
{
	if (argc != 2) {
	  incorrect_input();
	} else {
		int threadsCount = atoi(argv[1]);
		runThreads(threadsCount);
		WaitForMultipleObjects(threadsCount, threadHandles, TRUE, INFINITE);
		DeleteCriticalSection(&criticalSection);
	}
	return 0;
}