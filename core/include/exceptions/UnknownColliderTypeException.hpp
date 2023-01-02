/*
** EPITECH PROJECT, 2020
** CorruptedFileException.hpp
** File description:
** header for CorruptedFileException.c
*/


#pragma once

#include "ColliderException.hpp"

namespace polymorph::engine::physics2D
{

    class UnknownColliderTypeException final : public ColliderException
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
    public:
        UnknownColliderTypeException(std::string type, debug::Logger::severity level = debug::Logger::MAJOR);

        ~UnknownColliderTypeException() final = default;

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