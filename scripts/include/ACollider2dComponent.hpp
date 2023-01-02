/*
** EPITECH PROJECT, 2020
** Collider2d.hpp
** File description:
** header for Collider2d.c
*/

#pragma once

#include "polymorph/engine/types/vector/Vector2.hpp"
#include "polymorph/engine/core.hpp"
#include "modules/interfaces/ICollider2dHandler.hpp"
#include <map>
#include <utility>

namespace polymorph::engine::physics2D
{

    /**
     * @class Collider2dComponent
     * @details An abstract component that is used to make new collider shapes (box, circle ...)
     * @warning Do not try to use this as a component !(AddComponent)
     */
    class ACollider2dComponent : public polymorph::engine::AComponent
    {

    public:
        explicit ACollider2dComponent(std::shared_ptr<myxmlpp::Node> node, polymorph::engine::GameObject gameObject) :
                polymorph::engine::AComponent(std::move(node), std::move(gameObject)){};
        virtual ~ACollider2dComponent() = default;

///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////
            public:
            engine::Vector2 offset = {0, 0};

            private:
            std::map<std::string, bool> _encountered;

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////
            protected:
            virtual bool checkCollision(Collider2d collider) = 0;

            public:
            virtual void debugDraw() = 0;
            virtual void setColliderPosition() = 0;
            static inline void checkCollision(Collider2d &other, Collider2d &self)
            {
                auto collided = self->checkCollision(other);
                if (collided
                    && self->_encountered.contains(other->gameObject->getId())
                    && self->_encountered[other->gameObject->getId()])
                {
                    for (auto &c: self->gameObject->getComponents<ICollider2dHandler>())
                        c->onCollisionStay(other);
                }

                else if (collided
                         && (!self->_encountered.contains(other->gameObject->getId())
                             || !self->_encountered[other->gameObject->getId()]) )
                {
                    for (auto &c: self->gameObject->getComponents<ICollider2dHandler>())
                        c->onCollisionEnter(other);
                    self->_encountered[other->gameObject->getId()] = true;
                }

                else if (!collided &&
                         self->_encountered.contains(other->gameObject->getId())
                         && self->_encountered[other->gameObject->getId()])
                {
                    self->_encountered[other->gameObject->getId()] = false;
                    for (auto &c: self->gameObject->getComponents<ICollider2dHandler>())
                        c->onCollisionExit(other);
                }
            }
///////////////////////////--------------------------///////////////////////////

    };
}