//
// Created by vlad on 11/3/2024.
//
#include "il2cpp_storm/api/GameAssembly.h"
#include <stdexcept>
#include <Windows.h>


namespace il2cpp_storm::api
{
    GameAssembly& GameAssembly::Get()
    {
        static GameAssembly instance;
        return instance;
    }

    GameAssembly::GameAssembly()
    {
        m_imageBaseAddress = reinterpret_cast<uintptr_t>(GetModuleHandle("GameAssembly.dll"));
    }

    void* GameAssembly::ResolveICall(const std::string_view &name) const
    {
        static auto func = GetProcAddress(reinterpret_cast<HMODULE>(m_imageBaseAddress), "il2cpp_resolve_icall");

        if (!func)
            throw std::runtime_error("Failed to resolve il2cpp_resolve_icall");

        return reinterpret_cast<void*(IL2CPP_API_CALLING_CONVENTION*)(const char*)>(func)(name.data());
    }

    uintptr_t GameAssembly::GetImageBaseAddress() const
    {
        return m_imageBaseAddress;
    }
}
