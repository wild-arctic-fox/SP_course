#include <stdio.h>
#include <Windows.h>
#include <locale.h>

void incorrect_input() {
	printf("\nYou made a mistake !!!\n");
	printf("Only 3 arguments available:\n");
	printf("-a => ASCII to UNICODE\n");
	printf("-u => UNICODE to ASCII\n");
	printf("file => full path to file\n");
	exit(0);
}

void problems_with_files() {
	printf("\nSomething went wrong(\n");
	printf("Check path or existing files\n");
	exit(0);
}

void from_ascii_to_unicode(HANDLE ascii_file) {
	//TODO
	exit(0);
}

void from_unicode_to_ascii(HANDLE unicode_file) {
	//TODO
	exit(0);
}

void main(int argc, char* argv[]) {
	if (argc != 3 || ((strcmp(argv[1], "-a") != 0) && (strcmp(argv[1], "-u"))) != 0) {
		incorrect_input();
	}
	//Если функция завершается успешно, возвращаемое значение - открытый дескриптор заданного файла
	HANDLE file = CreateFileA(argv[2], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file != INVALID_HANDLE_VALUE) {
		(strcmp(argv[1], "-a") == 0) ? from_ascii_to_unicode(file) : from_unicode_to_ascii(file);
	}
	else {
		problems_with_files();
	}
	CloseHandle(file);
	exit(0);
}
