#include <stdio.h>
#include <Windows.h>
#include <locale.h>

//F:\Desktop\SP_course\Lab2_SP\Lab2.1_SP\Debug\Lab2.1_SP.exe 6

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
	exit(0);
}

struct record {
	int record_number;
	_FILETIME creation;
	char text[80];
	int counter;
};

void incorrect_input() {
	printf("\nYou made a mistake !!!\n");
	printf("Only 1 arguments available:\n");
	printf("Number of records\n");
	exit(0);
}

void remove_record() {
	//TODO
}

void modify_record() {
	//TODO
}

void init_records(int init_num) {
	if (init_num > 0) {
		char file_name[51] = "F:\\Desktop\\SP_course\\Lab2_SP\\Lab2.1_SP\\records.txt";
		HANDLE hFile = CreateFileA(file_name, GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		record tst;
		SecureZeroMemory(&tst, sizeof(tst));
		if (hFile != INVALID_HANDLE_VALUE){
			SetFilePointer(hFile, 0, NULL, FILE_BEGIN);
			
		}else {
			print_problems();
		}
		
		//TODO
		CloseHandle(hFile);
	}
}


void main(int argc, char* argv[])
{
	if (argc != 2)
	{
		incorrect_input();
	}else{
		int num = atoi(argv[1]);
		char command[3];
		init_records(num);
		printf("Input command:\n");
		printf("rm  index => delete record\n");
		printf("mf  index => modify record\n");
		scanf_s("%s", command, 3);
		if (strcmp(command, "rm") == 0) {
			remove_record();
		}else if (strcmp(command, "mf") == 0) {
			modify_record();
		}else {
			printf("Incorrect command !!!\n");
			exit(0);
		}
	}
}