/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser()
{
}

Parser::~Parser()
{
}

bool Parser::checkFormat(const std::string &str)
{
    std::regex reg(".+\\.cfg$");
    if (std::regex_match(str, reg))
        return true;
    return false;
}

bool Parser::isEmpty(std::ifstream &pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

bool Parser::isInFile(std::ifstream &pFile, const std::string &str)
{
    std::string line;
    while (std::getline(pFile, line)) {
        if (line.find(str) != std::string::npos) {
            return true;
        }
    }
    pFile.clear();
    pFile.seekg(0, std::ios::beg);
    return false;
}

void Parser::getSpheres(const libconfig::Setting& spheres)
{
    for (int i = 0; i < spheres.getLength(); ++i) {
        double sphereX = spheres[i]["x"];
        double sphereY = spheres[i]["y"];
        double sphereZ = spheres[i]["z"];
        double sphereRadius = spheres[i]["r"];
        int material = spheres[i]["material"];
        double colorX = spheres[i]["color_x"];
        double colorY = spheres[i]["color_y"];
        double colorZ = spheres[i]["color_z"];
        double fuzz = spheres[i]["fuzz"];
        std::any params;
        params = std::make_tuple(sphereX, sphereY, sphereZ, sphereRadius, material, colorX, colorY, colorZ, fuzz);
        _factory.createComponent("sphere", params);
    }
}

void Parser::getCamera(const libconfig::Setting& camera)
{
    int width = camera["width"];
    int samples = camera["samplePerPixel"];
    int maxDepth = camera["maxDepth"];
    double fov = camera["fov"];

    const libconfig::Setting& scaling = camera["scaling"];
    double scalingX = scaling["x"];
    double scalingY = scaling["y"];

    const libconfig::Setting& lookfrom = camera["lookfrom"];
    double lookfromX = lookfrom["x"];
    double lookfromY = lookfrom["y"];
    double lookfromZ = lookfrom["z"];

    const libconfig::Setting& lookat = camera["lookat"];
    double lookatX = lookat["x"];
    double lookatY = lookat["y"];
    double lookatZ = lookat["z"];

    const libconfig::Setting& vup = camera["vup"];
    double vupX = vup["x"];
    double vupY = vup["y"];
    double vupZ = vup["z"];

    Point3D lookfromPoint = Point3D(lookfromX, lookfromY, lookfromZ);
    Point3D lookatPoint = Point3D(lookatX, lookatY, lookatZ);
    Vector3D vupVec = Vector3D(vupX, vupY, vupZ);

    double scalingg = scalingX / scalingY;

    std::any params;
    params = std::make_tuple(width, scalingg, samples, maxDepth, fov, lookfromPoint, lookatPoint, vupVec);
    _factory.createComponent("camera", params);
}

void Parser::getPlanes(const libconfig::Setting& planes)
{
    for (int i = 0; i < planes.getLength(); ++i) {
        double planeX = planes[i]["x"];
        double planeY = planes[i]["y"];
        double planeZ = planes[i]["z"];
        double planeRadius = planes[i]["r"];
        int material = planes[i]["material"];
        double colorX = planes[i]["color_x"];
        double colorY = planes[i]["color_y"];
        double colorZ = planes[i]["color_z"];
        double fuzz = planes[i]["fuzz"];
        std::any params;
        params = std::make_tuple(planeX, planeY, planeZ, planeRadius, material, colorX, colorY, colorZ, fuzz);
        _factory.createComponent("plane", params);
    }
}

void Parser::parseFile(const std::string &filename)
{
    std::ifstream file(filename);
    int SphereisPresent = 0;
    int PlaneisPresent = 0;
    try {
        if (!file.is_open())
            throw CannotOpenFile("Error: cannot open file");
        if (isEmpty(file))
            throw FileIsEmpty("Error: file is empty");
        if (!checkFormat(filename))
            throw TypeofFile("Error: file is not a .cfg file");
        if (!isInFile(file, "camera"))
            throw NoCameraInFile("Error: no camera in file");
        SphereisPresent = isInFile(file, "spheres");
        PlaneisPresent = isInFile(file, "planes");

        _cfg.readFile(filename.c_str());

        const libconfig::Setting& primitives = _cfg.lookup("primitives");
        const libconfig::Setting& camera = _cfg.lookup("camera");

        getCamera(camera);
        if (SphereisPresent) {
            const libconfig::Setting& spheres = primitives["spheres"];
            getSpheres(spheres);
        }
        if (PlaneisPresent) {
            const libconfig::Setting& planes = primitives["planes"];
            getPlanes(planes);
        }
    } catch(const libconfig::FileIOException &fioex) {
        std::cerr << "Erreur lors de la lecture du fichier." << std::endl;
        exit(84);
    } catch(const libconfig::ParseException &pex) {
        std::cerr << "Erreur de syntaxe dans le fichier de configuration à la ligne " << pex.getLine() << ": " << pex.getError() << std::endl;
        exit(84);
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "Erreur: Paramètre manquant dans le fichier de configuration." << std::endl;
        exit(84);
    } catch (const libconfig::SettingTypeException &stex) {
        std::cerr << "Erreur: Type de paramètre incorrect dans le fichier de configuration." << std::endl;
        exit(84);
    } catch (const AException &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}

Factory &Parser::getFactory()
{
    return _factory;
}