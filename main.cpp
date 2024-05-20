/**
 * @file main.cpp
 * @brief Main entry point for the Ray Tracer program
 */

#include "Parser.hpp"
#include "Ray.hpp"
#include "Vector3D.hpp"
#include "HittableList.hpp"
#include "Sphere.hpp"
#include "Planes.hpp"
#include "Camera.hpp"
#include <iostream>
#include <limits>
#include "IHittable.hpp"
#include "Factory.hpp"
#include <cstdlib>
#include <random>

/**
 * @brief Main function
 * 
 * @param ac Argument count
 * @param av Argument vector
 * @return int Exit status
 * 
 * The main function checks the command line arguments, parses the input file,
 * generates the world of hittable objects, sets up the camera, and generates
 * the final image.
 */
int main(int ac, char **av)
{
    // Check command line arguments
    if (ac != 2) {
        std::cerr << "Usage: ./raytracer [scene]" << std::endl;
        return 84;
    }
    if (ac == 2 && std::string(av[1]) == "-h") {
        std::cout << "Usage: ./raytracer [scene]" << std::endl;
        return 0;
    }

    // Parse the input file
    Parser parser;
    parser.parseFile(av[1]);

    // Generate the world of hittable objects
    Factory fact = parser.getFactory();
    HittableList world = fact.getWorld();

    // Set up the camera
    Camera cam = fact.getCamera();

    // Generate the final image
    cam.generatePPM("test", world);

    return 0;
}