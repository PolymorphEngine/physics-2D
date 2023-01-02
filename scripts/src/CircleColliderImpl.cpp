/*
** EPITECH PROJECT, 2022
** Collider2dCircleComponent.cpp
** File description:
** Collider2dCircleComponent.cpp
*/

#include "polymorph/engine/types.hpp"
#include "colliders/CircleColliderImpl.hpp"
#include "colliders/RectColliderComponent.hpp"
#include "exceptions/UnknownColliderTypeException.hpp"

bool polymorph::engine::physics2D::CircleColliderImpl::checkCollision(Collider2d other)
{
    auto tmpPosition = engine::Vector2(transform->getPosition()) + offset;
    auto otherPosition = engine::Vector2(other->transform->getPosition()) + other->offset;
    auto circleShape = std::dynamic_pointer_cast<CircleColliderComponent>(*other);
    auto boxShape = std::dynamic_pointer_cast<RectColliderComponent>(*other);

    if (circleShape) {
        return engine::Circle::intersect(tmpPosition, radius, otherPosition, circleShape->radius);
    } else if (boxShape) {
        return engine::Circle::intersect(tmpPosition, radius, otherPosition, boxShape->size);
    }
    throw UnknownColliderTypeException("CircleCollider::checkCollision: unknown collider type");
}

polymorph::engine::physics2D::CircleColliderImpl::CircleColliderImpl(engine::GameObject gameObject, std::shared_ptr<myxmlpp::Node> node)
: CircleColliderComponent(node, gameObject)
{
}

void polymorph::engine::physics2D::CircleColliderImpl::debugDraw()
{
    //TODO: draw fallback texture
}

void polymorph::engine::physics2D::CircleColliderImpl::setColliderPosition()
{
    //TODO: is it needed ?
}

void polymorph::engine::physics2D::CircleColliderImpl::build()
{
    _setProperty("radius", radius);
    _setProperty("offset", offset);
}

void polymorph::engine::physics2D::CircleColliderImpl::saveAll()
{
    saveProperty("radius", radius);
    saveProperty("offset", offset);
}
