//
// Created by vlad on 11/3/2024.
//
#include <Windows.h>
#include <thread>
#include <il2cpp_storm/api/GameAssembly.h>
#include <MinHook.h>

void* oSetFov = nullptr;
void* oRecoil = nullptr;
void IL2CPP_API_CALLING_CONVENTION SetFovOverride(void* pthis, float fov)
{

    return reinterpret_cast<void(IL2CPP_API_CALLING_CONVENTION*)(void*, float)>(oSetFov)(pthis, 110.f);
}

void IL2CPP_API_CALLING_CONVENTION CameraShaking_RecoilShake___ctor(
        void *pthis,
        void *settings,
        void *firearm,
        float scale)
{
}

void MainThread(HMODULE dllHandle)
{
    auto func = il2cpp_storm::api::GameAssembly::Get().ResolveICall("UnityEngine.Camera::set_fieldOfView");
    auto fun2 = reinterpret_cast<void *>(il2cpp_storm::api::GameAssembly::Get().GetImageBaseAddress() + 0x6145A0);

    if (!func || !fun2)
        MessageBox(nullptr, "Error!", "Error!", MB_OK);

    MH_Initialize();
    MH_CreateHook(func, &SetFovOverride, &oSetFov);
    if (MH_OK != MH_CreateHook(fun2, &CameraShaking_RecoilShake___ctor, &oRecoil))
        MessageBox(nullptr, "Error!", "Failed to hook recoil!", MB_OK);
    MH_EnableHook(MH_ALL_HOOKS);

    while (!GetAsyncKeyState(VK_END))
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    MH_DisableHook(MH_ALL_HOOKS);
    MH_Uninitialize();

    FreeLibrary(dllHandle);
}

extern "C" BOOL WINAPI DllMain(const HMODULE dllHandle, const DWORD callReason, LPVOID)
{
    if (callReason != DLL_PROCESS_ATTACH)
        return false;

    DisableThreadLibraryCalls(dllHandle);
    std::thread(MainThread, dllHandle).detach();

    return true;
}