/*
** EPITECH PROJECT, 2020
** CoreException.hpp
** File description:
** header for CoreException.c
*/

#pragma once

#include "polymorph/engine/debug/exception/ExceptionLogger.hpp"

namespace polymorph::engine::physics2D
{
    class ColliderException : public engine::debug::ExceptionLogger
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
    public:
        ColliderException(std::string message, debug::Logger::severity level = debug::Logger::severity::MAJOR);

        ~ColliderException() override = default;

//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
    public:


    private:

//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
    public:


    private:

//////////////////////--------------------------/////////////////////////

    };
}