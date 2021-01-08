#include<stdio.h>  
#include<windows.h>

int main(){
    HWND hWnd;
    DWORD pid;
    HANDLE hProcess = 0;
    DWORD addr = 0x00731c50;//0x00731cdc,0x00731d08,0x00731da0 same bull shit
    
    hWnd = FindWindow(NULL,"Plants vs. Zombies");
    if (hWnd){
        GetWindowThreadProcessId(hWnd, &pid);  
        hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
        if(!hProcess){
            printf("failed！\n");    
        }
        DWORD sbuf;
		int s;
		ReadProcessMemory(hProcess, (LPVOID)addr, &sbuf, 4, 0);
		ReadProcessMemory(hProcess, (LPVOID)(sbuf + 0x868), &sbuf, 4, 0);
		//ReadProcessMemory(hProcess, (LPVOID)(sbuf + 0x5578), &s, 4, 0);		
		s=9999; 
		WriteProcessMemory(hProcess,(LPVOID)(sbuf + 0x5578),&s,4,0);
    }
    return 0;
}
