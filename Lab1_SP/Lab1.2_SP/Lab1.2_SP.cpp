#include <stdio.h>
#include <Windows.h>
#include <locale.h>

#define nNumberOfBytesToRead  2048

//F:\Desktop\SP_course\Lab1_SP\Lab1.2_SP\Debug\Lab1.2_SP.exe -a F:\Desktop\SP_course\Lab1_SP\Lab1.2_SP\from_ascii.txt F:\Desktop\SP_course\Lab1_SP\Lab1.2_SP\uni1.txt

void incorrect_input() {
	printf("\nYou made a mistake !!!\n"); 
	printf("Only 4 arguments available:\n");
	printf("-a => ASCII to UNICODE\n");
	printf("-u => UNICODE to ASCII\n");
	printf("file 1 => full path to source\n");
	printf("file 2 => full path to result\n");
	exit(0);
}

void problems_with_files() {
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

void from_ascii_to_unicode(HANDLE ascii_file, HANDLE new_file) {
	BYTE lpBuffer[nNumberOfBytesToRead];
	DWORD lpNumberOfBytesRead;
	while (ReadFile(ascii_file, lpBuffer, nNumberOfBytesToRead, (LPDWORD)&lpNumberOfBytesRead, NULL))
	{
		if (lpNumberOfBytesRead == 0) {
			break;
		} else {
			//сначала вы вызываете MultiByteToWideChar, чтобы получить размер конечной строки
			int str_length = MultiByteToWideChar(CP_UTF8, 0, (LPCCH)lpBuffer, lpNumberOfBytesRead, NULL, 0);
			//затем создаете некий строковый буфер с этим размером
			wchar_t* str = new wchar_t[str_length];
			//Наконец, функция MultiByteToWideChar вызывается во второй раз для выполнения преобразования кодировки, 
			//используя ранее созданный строковый буфер
			MultiByteToWideChar(CP_UTF8, 0, (LPCCH)lpBuffer, lpNumberOfBytesRead, str, str_length);
			wprintf(str);
			if (!WriteFile(new_file, str, str_length * sizeof(wchar_t), (LPDWORD)&lpNumberOfBytesRead, NULL)) {
				printf("\nSomething went wrong (\nWriting FAILED\n");
				exit(0);
			}
		}
	}
	CloseHandle(ascii_file);
	CloseHandle(new_file);
	exit(0);
}

void from_unicode_to_ascii(HANDLE unicode_file, HANDLE new_file) {
	//TODO
	CloseHandle(unicode_file);
	CloseHandle(new_file);
	exit(0);
}

void main(int argc, char* argv[]) {
	if (argc != 4 || ((strcmp(argv[1], "-a") != 0) && (strcmp(argv[1], "-u")) != 0)) {
		incorrect_input();
	}
	//Если функция завершается успешно, возвращаемое значение - открытый дескриптор заданного файла
	HANDLE file = CreateFileA(argv[2], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	HANDLE result_file = CreateFileA(argv[3], GENERIC_WRITE , FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file != INVALID_HANDLE_VALUE && result_file != INVALID_HANDLE_VALUE) {
		(strcmp(argv[1], "-a") == 0) ? from_ascii_to_unicode(file, result_file) : from_unicode_to_ascii(file, result_file);
	}
	else {
		problems_with_files();
	}
}
