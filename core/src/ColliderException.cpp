/*
** EPITECH PROJECT, 2020
** ConfigurationException.cpp
** File description:
** header for ConfigurationException.c
*/

#include "ColliderException.hpp"

polymorph::engine::physics2D::ColliderException::ColliderException(std::string message, polymorph::engine::debug::Logger::severity level)
        : ExceptionLogger("[ColliderException] " + message, level)
{

}