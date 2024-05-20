/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include "Vector3D.hpp"
#include "AException.hpp"
#include "HittableList.hpp"
#include <libconfig.h++>
#include <iostream>
#include <regex>
#include "Factory.hpp"
#include <any>
#include <memory>
#include <fstream>
#include "Ray.hpp"

class Parser {
    public:
        Parser();
        ~Parser();
        bool checkFormat(const std::string &str);
        bool isEmpty(std::ifstream &pFile);
        bool isInFile(std::ifstream &pFile, const std::string &str);
        void getSpheres(const libconfig::Setting& spheres);
        void getPlanes(const libconfig::Setting& planes);
        void getCamera(const libconfig::Setting& camera);
        void parseFile(const std::string &filename);
        Factory &getFactory();

    private:
        libconfig::Config _cfg;
        Factory _factory;

};

#endif /* !PARSER_HPP_ */
