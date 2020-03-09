#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <locale.h>

void printCommands()
{
	printf("\nAvailable command:\n");
	printf("pwd                => print working dir\n");
	printf("cd      path       => change dir\n");
	printf("mkdir   dir_name   => print working dir\n");
	printf("pfi     file_name  => print file info\n");
	printf("cp      file_name  => copy file\n");
	printf("rmf     path       => remove file \n");
	printf("rmd     path       => remove empty dir\n");
}

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

void create_dir() {
	char dir_name[MAX_PATH];
	printf("Input dir name or path:");
	scanf_s("%s", dir_name, MAX_PATH);
	if (CreateDirectoryA((LPCSTR)dir_name, NULL)) {
		printf("Directory was created\n");
	}else{
		print_problems();
	}
}

void print_working_directory() { 
	setlocale(LC_ALL, "Russian");
	WIN32_FIND_DATAA FindFileData;
	HANDLE hFind;
	char szDirName[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH, szDirName);
	hFind = FindFirstFileA(strcat(szDirName, "\\*"), &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE){
		print_problems();
	}else {
		do{
			printf("----------------------------------\n");
			SYSTEMTIME systemTime;
			FileTimeToSystemTime(&FindFileData.ftCreationTime, &systemTime);
			printf("Name          => %s\n",(char*)FindFileData.cFileName);
			printf("Creation time => %02d-%02d-%d %02d:%02d:%02d\n", 
				systemTime.wMonth, systemTime.wDay, systemTime.wYear,
				systemTime.wHour, systemTime.wMinute, systemTime.wSecond);
			printf("Size in bytes => %d\n",FindFileData.nFileSizeLow);
		}while (FindNextFileA(hFind, &FindFileData) != 0);
		FindClose(hFind);
	}
}

void print_file_info() {
	char file_path[MAX_PATH];
	BY_HANDLE_FILE_INFORMATION lpFileInformation;
	printf("Input file path:");
	scanf_s("%s", file_path, MAX_PATH);
	HANDLE file = CreateFileA(file_path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (GetFileInformationByHandle(file, &lpFileInformation)) {
		wprintf(L"File attributes: %d\n", lpFileInformation.dwFileAttributes);
		SYSTEMTIME systemTime;
		FileTimeToSystemTime(&(lpFileInformation.ftCreationTime), &systemTime);
		wprintf(L"Creation time: %02d-%02d-%d %02d:%02d:%02d\n", 
			systemTime.wMonth, systemTime.wDay, systemTime.wYear,
			systemTime.wHour, systemTime.wMinute, systemTime.wSecond);
		FileTimeToSystemTime(&(lpFileInformation.ftLastAccessTime), &systemTime);
		wprintf(L"Last access time: %02d-%02d-%d %02d:%02d:%02d\n",
			systemTime.wMonth, systemTime.wDay, systemTime.wYear,
			systemTime.wHour, systemTime.wMinute, systemTime.wSecond);
		FileTimeToSystemTime(&(lpFileInformation.ftLastWriteTime), &systemTime);
		wprintf(L"Last write time: %02d-%02d-%d %02d:%02d:%02d\n",
			systemTime.wMonth, systemTime.wDay, systemTime.wYear,
			systemTime.wHour, systemTime.wMinute, systemTime.wSecond);
		wprintf(L"Number of links: %d\n", lpFileInformation.nNumberOfLinks);
		wprintf(L"Volume serial number: %d\n", lpFileInformation.dwVolumeSerialNumber);
	}
	else {
		print_problems();
	}
	CloseHandle(file);
}

void remove_file() {
	char file_path[MAX_PATH];
	printf("Input file path:");
	scanf_s("%s", file_path, MAX_PATH);
	if (DeleteFileA(file_path)) {
		printf("File was deleted\n");
	}else {
		print_problems();
	}
}

void remove_dir() {
	char dir_path[MAX_PATH];
	printf("Input directory path:");
	scanf_s("%s", dir_path, MAX_PATH);
	if (RemoveDirectoryA(dir_path)) {
		printf("Directory was deleted\n");
	}else {
		print_problems();
	}
}

void copy_file() {
	char file_path_e[MAX_PATH];
	char file_path_n[MAX_PATH];
	printf("Input path to existing file:");
	scanf_s("%s", file_path_e, MAX_PATH);
	printf("Input path to new file:");
	scanf_s("%s", file_path_n, MAX_PATH);
	if (CopyFileA((LPCSTR)file_path_e, (LPCSTR)file_path_n, FALSE)) {
		printf("File was copied\n");
	}else {
		print_problems();
	}
}

void change_dir() {
	DWORD dwNumberOfChar;
	char szDirName[MAX_PATH];
	dwNumberOfChar = GetCurrentDirectoryA(MAX_PATH,szDirName);
	if (dwNumberOfChar != 0){
		printf("Current directory name => %s\n", szDirName);
	}else{
		print_problems();
	}
	DWORD dwNumberOfChar2;
	char dir_path[MAX_PATH];
	char szDirName2[MAX_PATH];
	printf("Input directory path:");
	scanf_s("%s", dir_path, MAX_PATH);
	if (SetCurrentDirectoryA((LPCSTR)dir_path))
	{
		dwNumberOfChar2 = GetCurrentDirectoryA(MAX_PATH, szDirName2);
		if (dwNumberOfChar2 != 0){
			printf("Current directory name => %s\n", szDirName2);
		}else {
			print_problems();
		}
	}else {
		print_problems();
	}
}

void main(int argc, char* argv[])
{
	begin:
	printCommands();
	char command[6]; 
	printf("Input command:");
	scanf_s("%s",command,6);
	if (strcmp(command, "cd")==0) {
		change_dir();
	}else if(strcmp(command, "pwd") == 0){
		print_working_directory();
	}else if (strcmp(command, "cp") == 0){
		copy_file();
	}else if (strcmp(command, "mkdir") == 0){
		create_dir();
	}else if (strcmp(command, "pfi") == 0){
		print_file_info();
	}else if (strcmp(command, "rmd") == 0){
		remove_dir();
	}else if (strcmp(command, "rmf") == 0){
		remove_file();
	}else{
		printf("\nIncorrect argument !!!");
		goto begin;
	}
	goto begin;
	exit(0);
}