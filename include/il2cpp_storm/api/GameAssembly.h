//
// Created by vlad on 11/3/2024.
//
#pragma once
#include <cstdint>
#include <string_view>

#ifdef _WIN64
#   define IL2CPP_API_CALLING_CONVENTION __fastcall
#elif _WIN32
#   define IL2CPP_API_CALLING_CONVENTION __cdecl
#endif

namespace il2cpp_storm::api
{
    class GameAssembly
    {
    public:
        GameAssembly(const GameAssembly &) = delete;

        [[nodiscard]]
        static GameAssembly& Get();

        [[nodiscard]]
        void* ResolveICall(const std::string_view &name) const;

        [[nodiscard]]
        uintptr_t GetImageBaseAddress() const;
    private:
        GameAssembly();
        uintptr_t m_imageBaseAddress;
    };
}
