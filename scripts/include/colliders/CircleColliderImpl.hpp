#pragma once
#include "../ACollider2dComponent.hpp"
#include "CircleColliderComponent.hpp"

namespace polymorph::engine::physics2D
{

    class CircleColliderImpl : public CircleColliderComponent
    {
        public:
            explicit CircleColliderImpl(std::shared_ptr<myxmlpp::Node> node, polymorph::engine::GameObject gameObject);

            ~CircleColliderImpl() override = default;

            ////////////////////////////////// Methods /////////////////////////////////////
        public:
            bool checkCollision(Collider2d collider) override;

            void debugDraw() override;

            void setColliderPosition() override;

            ///////////////////////////--------------------------///////////////////////////

    };
}
