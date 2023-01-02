#pragma once
#include "../ACollider2dComponent.hpp"
#include "CircleColliderComponent.hpp"

namespace polymorph::engine::physics2D
{

    class CircleColliderImpl : public CircleColliderComponent
    {
        public:
            explicit CircleColliderImpl(polymorph::engine::GameObject gameObject, std::shared_ptr<myxmlpp::Node> node);

            ~CircleColliderImpl() override = default;

            ////////////////////////////////// Methods /////////////////////////////////////
        public:
            bool checkCollision(Collider2d collider) override;

            void debugDraw() override;

            void setColliderPosition() override;

            void build() override;

            void saveAll() override;

        ///////////////////////////--------------------------///////////////////////////

    };
}
