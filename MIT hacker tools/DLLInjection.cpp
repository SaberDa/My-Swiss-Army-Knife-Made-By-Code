#include <Windows.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    HANDLE ProcessHandle;
    LPVOID remotebuffer;
    BOOL write;

    wchar_t dllpath[] = TEXT("C:\\user\\root\\desktop\\inject.dll");

    if (argc < 2) {
        cout << "Useage inject.exe Pid;" << endl;
        cout << "such as inject.exe 258" << endl;
        exit(0);
    }

    cout << "Injecting DLL to PID: " << atoi(argv[1]) << endl;

    ProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, DWORD(atoi(argv[1])));

    if (ProcessHandle == NULL) {
        cout << "OpenProcess Fail !!!" << endl;
        exit(0);
    } else cout << "OpenProcess " << atoi(argv[1]) << " successful !!!" << endl;
        
    remotebuffer = VirtualAllocEx(ProcessHandle, NULL, sizeof dllpath, MEM_COMMIT, PAGE_READWRITE);
	write = WriteProcessMemory(ProcessHandle, remotebuffer, (LPVOID)dllpath, sizeof dllpath, NULL);
	
    if (write == 0) {
        cout << "WriteProcessMemory Fail !!!" << GetLastError() << endl;
        exit(0);
    } else cout << "WriteProcessMemory successful !!!" << endl;

    PTHREAD_START_ROUTINE threatStartRoutineAddress = (PTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle(TEXT("Kernel32")), "LoadLibraryW");

    CreateRemoteThread(ProcessHandle, NULL, 0, threatStartRoutineAddress, remotebuffer, 0, NULL);
    CloseHandle(ProcessHandle);
    
    return 0;
}