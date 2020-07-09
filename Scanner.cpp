#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>
int main()
{
    HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    PROCESSENTRY32 ProcEntry;
    ProcEntry.dwSize = sizeof(ProcEntry);
    while (Process32Next(hPID, &ProcEntry))
    {
        std::cout << "process: " << ProcEntry.szExeFile <<" PID: " << ProcEntry.th32ProcessID << std::endl;            
    }
    CloseHandle(hPID);
}
