/*
** EPITECH PROJECT, 2022
** Collider2d.hpp
** File description:
** header for Collider2d.c
*/

#pragma once

#include "ACollider2dComponent.hpp"

namespace polymorph::engine::physics2D
{
    class RectColliderComponent;
    using RectCollider = polymorph::engine::safe_ptr<RectColliderComponent>;

    class RectColliderComponent : public ACollider2dComponent
    {
    public:
        explicit RectColliderComponent(std::shared_ptr<myxmlpp::Node> node, polymorph::engine::GameObject gameObject):
                ACollider2dComponent(node, gameObject){};
        virtual ~RectColliderComponent() = default;
        ///////////////////////////--------------------------///////////////////////////

        ///////////////////////////////// Properties ///////////////////////////////////

    public:
        engine::Vector2 size;
        ///////////////////////////--------------------------///////////////////////////

    };
}
