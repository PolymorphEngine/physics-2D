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
    class CircleColliderComponent;
    using CircleCollider = polymorph::engine::safe_ptr<CircleColliderComponent>;

    class CircleColliderComponent : public ACollider2dComponent
    {
        public:
            explicit CircleColliderComponent(std::shared_ptr<myxmlpp::Node> node, polymorph::engine::GameObject gameObject):
                    ACollider2dComponent(node, gameObject){};
            virtual ~CircleColliderComponent() = default;
    ///////////////////////////--------------------------///////////////////////////

    ///////////////////////////////// Properties ///////////////////////////////////
        public:
            float radius = 0.0f;
    ///////////////////////////--------------------------///////////////////////////

    };
}
