/*
** EPITECH PROJECT, 2020
** UnknownColliderTypeException.cpp
** File description:
** header for UnknownColliderTypeException.c
*/

#include "exceptions/UnknownColliderTypeException.hpp"

polymorph::engine::physics2D::UnknownColliderTypeException::UnknownColliderTypeException(std::string type, debug::Logger::severity level)
        : ColliderException("'"+type + "' is unknown.", level)
{

}