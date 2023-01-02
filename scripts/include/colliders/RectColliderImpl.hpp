/*
** EPITECH PROJECT, 2020
** RectColliderImpl.hpp
** File description:
** header for RectColliderImpl.c
*/

#pragma once

#include "RectColliderComponent.hpp"

namespace polymorph::engine::physics2D
{
    class RectColliderImpl : public RectColliderComponent
    {
        public:
            explicit RectColliderImpl(polymorph::engine::GameObject gameObject, std::shared_ptr<myxmlpp::Node> node);

            ~RectColliderImpl() override = default;

            ////////////////////////////////// Methods /////////////////////////////////////
            void debugDraw() override;

            void setColliderPosition() override;

        void build() override;

        void saveAll() override;

    protected:
            bool checkCollision(Collider2d collider) override;
    };
}