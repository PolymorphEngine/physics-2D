/*
** EPITECH PROJECT, 2022
** ComponentFactory.cpp
** File description:
** ComponentFactory.cpp
*/

#include "ComponentFactory.hpp"
#include <colliders/CircleColliderImpl.hpp>
#include <colliders/RectColliderImpl.hpp>

polymorph::engine::api::Phys2DFactory::Phys2DFactory() : AComponentFactory()
{
}

void polymorph::engine::api::Phys2DFactory::_registerBuildables(
        std::unordered_map<std::string, polymorph::engine::api::AComponentFactory::FactoryLambda> &buildables)
{
    buildables.emplace("CircleCollider", make<physics2D::CircleColliderImpl>());
    buildables.emplace("RectCollider", make<physics2D::RectColliderImpl>());
}