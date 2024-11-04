//
// Created by vlad on 11/3/2024.
//
#pragma once


namespace il2cpp_storm::unity
{
    class Camera
    {
        public:
            [[nodiscard]] float GetFieldOfView() const;
            [[nodiscard]] float GetDepth() const;
            [[nodiscard]] static Camera* GetMain();

            void SetDepth(float depth);
            void SetFieldOfView(float fieldOfView);
    };
}