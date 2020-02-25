#include <stdio.h>
#include <Windows.h>
#include <locale.h>

//F:\Desktop\SP_course\Lab1_SP\Lab1.1_SP\Debug\Lab1.1_SP.exe -e
//F:\Desktop\SP_course\Lab1_SP\Lab1.1_SP\Debug\Lab1.1_SP.exe -s
//F:\Desktop\SP_course\Lab1_SP\Lab1.1_SP\Debug\Lab1.1_SP.exe

void generate_error() {
    setlocale(LC_ALL, "Russian");
    //Contains information about the current state of both physical and virtual memory
    MEMORYSTATUS mem_info;
    //Retrieves information about the system's current usage of both physical and virtual memory.
    GlobalMemoryStatus(&mem_info);
    // Generate an error
    // If the function succeeds, the return value is a handle to the newly allocated memory object.
    // If the function fails, the return value is NULL.To get extended error information, call GetLastError.
    HLOCAL allocated_memory_object = LocalAlloc(LPTR, mem_info.dwTotalVirtual * 1000);
    if (allocated_memory_object == NULL) {
        LPVOID e_mess;
        DWORD e_code = GetLastError();
        FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, 
            e_code, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&e_mess, 0, NULL);
        char* err_mess = (char*)e_mess;
        wprintf(L"ERROR was generated: failed with 0x%x code\n", e_code);
        wprintf(L"ERROR formatted message: %s\n", err_mess);
    }
    exit(0);
}

void get_info() {
    //Contains information about the current computer system
    SYSTEM_INFO s_info;
    //Retrieves information about the current system.
    //Copy the hardware information to the SYSTEM_INFO structure. 
    GetSystemInfo(&s_info);
    // Display the contents of the SYSTEM_INFO structure. 
    printf("  Hardware information: \n");
    printf("  OEM ID: %u\n", s_info.dwOemId);
    printf("  Number of processors: %u\n", s_info.dwNumberOfProcessors);
    printf("  Page size: %u\n", s_info.dwPageSize);
    printf("  Processor type: %u\n", s_info.dwProcessorType);
    printf("  Minimum application address: %lx\n", s_info.lpMinimumApplicationAddress);
    printf("  Maximum application address: %lx\n", s_info.lpMaximumApplicationAddress);
    printf("  Active processor mask: %u\n", s_info.dwActiveProcessorMask);
    exit(0);
}

void incorrect_input() {
    printf("\nYou made a mistake !!!\n");
    printf("Only 2 arguments available:\n");
    printf("-e => generate error & print error\n");
    printf("-s => print system information\n");
    exit(0);
}

void main(int argc, char* argv[]) {
    (argc != 2 || ((strcmp(argv[1], "-e") != 0) && (strcmp(argv[1], "-s"))) != 0) ? incorrect_input() :
        (strcmp(argv[1], "-e") == 0) ? generate_error() : get_info();
}