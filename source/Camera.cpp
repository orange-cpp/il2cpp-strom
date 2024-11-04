//
// Created by vlad on 11/3/2024.
//
#include "il2cpp_storm/unity/Camera.hpp"

#include <stdexcept>

#include "il2cpp_storm/api/GameAssembly.h"

#include <MinHook.h>

namespace il2cpp_storm::unity
{
    Camera* Camera::GetMain()
    {
        static auto func = api::GameAssembly::Get().ResolveICall("UnityEngine.Camera::get_main");

        if (!func)
            throw std::runtime_error("UnityEngine.Camera::get_main is not found!");

        return reinterpret_cast<Camera*(IL2CPP_API_CALLING_CONVENTION*)()>(func)();
    }

    void Camera::SetFieldOfView(const float fieldOfView)
    {
        static auto func = api::GameAssembly::Get().ResolveICall("UnityEngine.Camera::set_fieldOfView");

        if (!func)
            throw std::runtime_error("UnityEngine.Camera::set_fieldOfView is not found!");

        return reinterpret_cast<void(IL2CPP_API_CALLING_CONVENTION*)(Camera*, float)>(func)(this, fieldOfView);
    }
}
