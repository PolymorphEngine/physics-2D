/*
** EPITECH PROJECT, 2022
** Collider2dBoxComponent.cpp
** File description:
** Collider2dBoxComponent.cpp
*/

#include "polymorph/engine/types.hpp"
#include "colliders/RectColliderImpl.hpp"
#include "colliders/RectColliderComponent.hpp"
#include "colliders/CircleColliderComponent.hpp"
#include "exceptions/UnknownColliderTypeException.hpp"

bool polymorph::engine::physics2D::RectColliderImpl::checkCollision(
        polymorph::engine::physics2D::Collider2d other)
{
    auto tmpPosition = engine::Vector2(transform->getPosition()) + offset;
    auto otherPosition = engine::Vector2(other->transform->getPosition()) + other->offset;
    auto circleShape = std::dynamic_pointer_cast<CircleColliderComponent>(*other);
    auto boxShape = std::dynamic_pointer_cast<RectColliderComponent>(*other);

    if (circleShape) {
        return engine::Rect::intersect(tmpPosition, size, otherPosition, circleShape->radius);
    } else if (boxShape) {
        return engine::Rect::intersect(tmpPosition, size, otherPosition, boxShape->size);
    }
    throw UnknownColliderTypeException("ColliderBox2dImpl::checkCollision: unknown collider type");
}

polymorph::engine::physics2D::RectColliderImpl::RectColliderImpl(engine::GameObject entity, std::shared_ptr<myxmlpp::Node> node)
        : RectColliderComponent(node, entity)
{

}

void polymorph::engine::physics2D::RectColliderImpl::debugDraw()
{
    //TODO: draw fallback texture
}

void polymorph::engine::physics2D::RectColliderImpl::setColliderPosition()
{
    //TODO: is it needed ?
}

void polymorph::engine::physics2D::RectColliderImpl::build()
{
    _setProperty("size", size);
    _setProperty("offset", offset);
}

void polymorph::engine::physics2D::RectColliderImpl::saveAll()
{
    saveProperty("size", size);
    saveProperty("offset", offset);
}
