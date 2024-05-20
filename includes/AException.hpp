/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** AException
*/
#ifndef AEXCEPTION_HPP_
#define AEXCEPTION_HPP_

#include <iostream>
#include <exception>
#include <string>

class AException : public std::exception {
    public:
        AException(const std::string &message);
        ~AException() override = default;
        const char *what() const noexcept override;

    protected:
    private:
        std::string _message;
};

//TODO: TO CHECK
class TypeofFile : public AException {
    public:
        TypeofFile(const std::string &message);
        ~TypeofFile() override = default;
};

class FileIsEmpty : public AException {
    public:
        FileIsEmpty(const std::string &message);
        ~FileIsEmpty() override = default;
};

class CannotOpenFile : public AException {
    public:
        CannotOpenFile(const std::string &message);
        ~CannotOpenFile() override = default;
};

class NoCameraInFile : public AException {
    public:
        NoCameraInFile(const std::string &message);
        ~NoCameraInFile() override = default;
};


#endif /* !AEXCEPTION_HPP_ */