/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** AException
*/

#include "AException.hpp"

AException::AException(const std::string &message) : _message(message)
{
}

const char *AException::what() const noexcept
{
    return _message.c_str();
}

TypeofFile::TypeofFile(const std::string &message) : AException(message)
{
}

FileIsEmpty::FileIsEmpty(const std::string &message) : AException(message)
{
}

CannotOpenFile::CannotOpenFile(const std::string &message) : AException(message)
{
}

NoCameraInFile::NoCameraInFile(const std::string &message) : AException(message)
{
}