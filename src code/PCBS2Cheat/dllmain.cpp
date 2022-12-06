// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <memory>
#include "IL2CppResolver/Main.hpp" //Main Il2Cpp Resolver :D
#include "IL2CppResolver/Defines.hpp" //Defines!!! :D
#include "GetOffsets.hpp"

void OpenConsole() 
{
    AllocConsole(); //Allocating Console To Printing Anyone String :D
    FILE* fp_cons;
    freopen_s(&fp_cons, "CONOUT$", "w", stdout); //Please, Use CONOUT$ only for Windows and Write Mode... Thanks :D
}
bool IlToCppDetect() //IL2CPP Detection :D
{
    if (IL2CPP::Initialize(true) && IL2CPP::Thread::Attach(IL2CPP::Domain::Get())) {
        return true;
    }
    else {
        return false;
    }
}
bool FetchCarrerStatusState() {
    Unity::CGameObject* game_carrer = Unity::GameObject::Find("CarrerStatus");
    Unity::CComponent* component = game_carrer->GetMemberValue<Unity::CComponent*>("CarrerStatus::State");
    if (!component) {
        return false;
    }
    std::vector<Unity::il2cppMethodInfo*> methods; //Methods :D
    std::vector<Unity::il2cppFieldInfo*> fields; //Fields!!! 
    component->FetchMethods(&methods);
    component->FetchFields(&fields);
    Sleep(5000);
    for (Unity::il2cppMethodInfo* method : methods) {
        printf("--> %s\n", method->m_pName);
        Sleep(5000);
    }
    printf("\n\n\n");
    for (Unity::il2cppFieldInfo* field : fields) {
        printf("--> %s\n", field->m_pName); //Name of Current Classes :D
        Sleep(5000);
    }
    Sleep(5000);
    return true;
}
void SetMoneyTo1000000() 
{
    Unity::CGameObject* game = Unity::GameObject::Find("CarrerStatus"); //CarrerStatus.cs :D
    Unity::CComponent* compon = game->GetMemberValue<Unity::CComponent*>("m_state"); //It's and Component, and Offset :D
    compon->SetMemberValue<int>("m_cash", 1000000);
    printf("[+] Cash is Successfully Added"); //Money!!! :D
}

void HideGUIPCBS2() {
    Unity::CGameObject* hide_guigame = Unity::GameObject::Find("State");
    if (hide_guigame->CallMethod<void*>("HideGUI", true)) //If Game Crashing, GUI is Not Detected or GUI Just Hided as Default :D 
    {
        printf("\n[+] GUI Is Hided Successfull");
    }
    else 
    {
        printf("\n[-] GUI Is Not Hided Successfull");
    }
}
DWORD WINAPI MainThread(HMODULE m) 
{
    HWND hwnd_pcbs2 = FindWindowA(0, "PCBS2");
    if (hwnd_pcbs2) {
        MessageBoxA(hwnd_pcbs2, "PCBS2 Is Founded Successfull", "PCBS2Cheat by HardBuzzer", MB_OK || MB_SETFOREGROUND);
    }
    OpenConsole();
    SetConsoleTitleA("PCBS2Cheat By HardBuzzer");
    Sleep(5000);
    if (IlToCppDetect()) 
    {
        printf("[+] Il2Cpp Is Detected Successfull");
        Sleep(5000);
        printf("\nWelcome To My New Cheat for PCBS2... Made by HardBuzzer"); //New Cheat Console :D
        if (GetAsyncKeyState(VK_F2)) 
        {
            HideGUIPCBS2();
            Sleep(5000);
        }
        if (GetAsyncKeyState(VK_F3)) 
        {
            SetMoneyTo1000000(); //Money :D
            Sleep(5000);
        }
        if (GetAsyncKeyState(VK_F4)) {
            system("cls"); //Clear Console :D
            if (FetchCarrerStatusState()) {
                printf("[+] Successfull Fetched");
            }
            else {
                printf("[-] Failed Fetched...");
            }
        }
        if (GetAsyncKeyState(VK_INSERT)) 
        {
            GlobalPCBS2Offsets::GetOffsets(); //Getting Offsets :D
        }
        return TRUE;
    }
    else {
        printf("[-] Il2Cpp Is Not Detected...");
        Sleep(25000);
        FreeConsole();
        return FALSE;
    }
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

