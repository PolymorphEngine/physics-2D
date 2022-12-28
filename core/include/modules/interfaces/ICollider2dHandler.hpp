/*
** EPITECH PROJECT, 2020
** IColliderHandler.hpp
** File description:
** header for IColliderHandler.c
*/

#pragma once

#include "polymorph/engine/core.hpp"

namespace polymorph::engine::physics2D
{
    class ACollider2dComponent;
    using Collider2d = engine::safe_ptr<ACollider2dComponent>;

    class ICollider2dHandler
    {
    public:
        virtual void onCollisionEnter(Collider2d &collider) = 0;

        virtual void onCollisionExit(Collider2d &collider) = 0;

        virtual void onCollisionStay(Collider2d &collider) = 0;
    };
}
