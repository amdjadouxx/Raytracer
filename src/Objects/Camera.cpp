/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-romain.nacaouele
** File description:
** Camera
*/

#include "Camera.hpp"

/**
 * @brief Construct a new Camera object
*/
Camera::Camera()
{
    _width = 800;
    _aspectRatio = 16.0 / 9.0;
    _height = int(_width / _aspectRatio);
    _height = (_height < 1) ? 1 : _height;

    _center = Point3D(0, 0, 0);;

    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(_width)/_height);

    auto viewport_u = Vector3D(viewport_width, 0, 0);
    auto viewport_v = Vector3D(0, -viewport_height, 0);

    _delta_u = viewport_u / _width;
    _delta_v = viewport_v / _height;

    auto viewport_upper_left = _center - Vector3D(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    _pixel00 = viewport_upper_left + 0.5 * (_delta_u + _delta_v);
}

/**
 * @brief Converts a linear color component to a gamma color component
 *
 * @param linear_component The linear color component
 * @return double The gamma color component
 */
double Camera::linearToGamma(double linear_component)
{
    if (linear_component > 0)
        return sqrt(linear_component);
    return 0;
}


/**
 * @brief Writes a color to a stream
 *
 * @param out The output stream
 * @param pixel_color The color to write
 */
void Camera::writeColor(std::ostream& out, const Color& pixel_color)
{
    auto r = pixel_color.getX();
    auto g = pixel_color.getY();
    auto b = pixel_color.getZ();
    r = linearToGamma(r);
    g = linearToGamma(g);
    b = linearToGamma(b);
    const Interval intensity(0.000, 0.999);
    int rbyte = int(256 * intensity.clmp(r));
    int gbyte = int(256 * intensity.clmp(g));
    int bbyte = int(256 * intensity.clmp(b));

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

/**
 * @brief Construct a new Camera object
 *
 * @param width The width of the camera
 * @param aspectRatio The aspect ratio of the camera
 * @param samplesPerPix The number of samples per pixel
 * @param maxDepth The maximum depth of the camera
 * @param vfov The vertical field of view of the camera
 * @param lookfrom The look from point of the camera
 * @param lookat The look at point of the camera
 * @param vup The view up vector of the camera
 */
Camera::Camera(int width, double aspectRatio, int samplesPerPix, int maxDepth, double vfov, Point3D lookfrom, Point3D lookat, Vector3D vup)
{
    init(width, aspectRatio, samplesPerPix, maxDepth, vfov, lookfrom, lookat, vup);
}

/**
 * @brief Destroy the Camera object
 */
Camera::~Camera()
{
}

/**
 * @brief Check if a ray hits the camera
 *
 * @param r The ray to check
 * @param ray_t The interval of the ray
 * @param rec The hit record
 * @return true If the ray hits the camera
 * @return false If the ray does not hit the camera
 */
bool Camera::hit(const Ray &r, Interval ray_t, HitRecord &rec) const
{
    if (!getIsHittable()) //TODO decorateur?
        return false;
    (void)r;
    (void)ray_t;
    (void)rec;
    return false;
}

/**
 * @brief Renders the camera
 *
 * @param world The world to render
 */
void Camera::render(const IHittable &world)
{

    std::cout << "P3\n" << _width << ' ' << _height << "\n255\n";
    for (int j = 0; j < _height; j++) {
        for (int i = 0; i < _width; i++) {
            auto pixel_center = _pixel00 + (i * _delta_u) + (j * _delta_v);
            auto ray_direction = pixel_center - _center;
            Ray r(_center, ray_direction);
            Color pixel_color = rayColorAttribute(r, world);
            writeColor(std::cout, pixel_color);
        }
    }
}

/**
 * @brief Get the color of a ray
 *
 * @param r The ray to get the color of
 * @param world The world to check for hits
 * @return Color The color of the ray
 */
Color Camera::rayColorAttribute(const Ray &r, const IHittable &world) const
{
    HitRecord rec;
    if (world.hit(r, Interval(0.0, std::numeric_limits<double>::infinity()), rec)) {
        return 0.5 * (rec.getNormal() + Color(1,1,1));
    }

    Vector3D unit_direction = unitVector(r.getDirection());
    auto t = 0.5 * (unit_direction.getY() + 1.0);
    return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

/**
 * @brief Generates a PPM file from the camera
 *
 * @param filename The name of the file to generate
 * @param world The world to render
 */
void Camera::generatePPM(const std::string& filename, const HittableList& world)
{
    std::ofstream file;
    file.open(filename + ".ppm");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    file << "P3\n" << _width << ' ' << _height << "\n255\n";
    for (int j = 0; j < _height; j++) {
        for (int i = 0; i < _width; i++) {
            Color pixelColor(0,0,0);
            for (int sample = 0; sample < _samplesPerPix; sample++) {
                Ray r = getRay(i, j);
                pixelColor += rayColor(r, _maxDepth ,world);
            }
            writeColor(file, _pixSampleScale * pixelColor);
        }
    }
    file.close();
}


/**
 * @brief Initialize the camera
 *
 * @param width The width of the camera
 * @param aspectRatio The aspect ratio of the camera
 * @param samplesPerPix The number of samples per pixel
 * @param maxDepth The maximum depth of the camera
 * @param vfov The vertical field of view of the camera
 * @param lookfrom The look from point of the camera
 * @param lookat The look at point of the camera
 * @param vup The view up vector of the camera
 */
void Camera::init(int width, double aspectRatio, int samplesPerPix, int maxDepth, double vfov, Point3D lookfrom, Point3D lookat, Vector3D vup)
{
    _samplesPerPix = samplesPerPix;
    _maxDepth = maxDepth;
    _width = width;
    _vfov = vfov;
    _lookfrom = lookfrom;
    _lookat = lookat;
    _vup = vup;
    _aspectRatio = aspectRatio;
    _height = int(_width / _aspectRatio);
    _height = (_height < 1) ? 1 : _height;

    _pixSampleScale = 1.0 / _samplesPerPix;
    _center = _lookfrom;

    Vector3D convert;
    auto theta = convert.degreesToRadians(_vfov);
    auto h = tan(theta/2);
    auto viewport_height = 2 * h * _focusDist;
    auto viewport_width = viewport_height * (double(_width)/_height);

    _w = unitVector(_lookfrom - _lookat);
    _u = unitVector(cross(_vup, _w));
    _v = cross(_w, _u);

    Vector3D viewport_u = viewport_width * _u;
    Vector3D viewport_v = viewport_height * -_v;


    _delta_u = viewport_u / _width;
    _delta_v = viewport_v / _height;

    auto viewport_upper_left = _center - (_focusDist * _w) - viewport_u/2 - viewport_v/2;
    _pixel00 = viewport_upper_left + 0.5 * (_delta_u + _delta_v);

    auto defocus_radius = _focusDist * tan(viewport_u.degreesToRadians(_defocusAngle / 2));
        _defocusDiskU = _u * defocus_radius;
        _defocusDiskV = _v * defocus_radius;
}

/**
 * @brief Samples a square
 *
 * @return Vector3D The sampled square
 */
Vector3D Camera::sampleSquare() const
{
    Random random;
    return Vector3D(random.randomDouble() - 0.5, random.randomDouble() - 0.5, 0);
}

/**
 * @brief Get a ray from the camera
 *
 * @param i The i value
 * @param j The j value
 * @return Ray The ray
 */
Ray Camera::getRay(int i, int j) const
{
    auto offset = sampleSquare();
    auto pixel_sample = _pixel00 + ((i + offset.getX()) * _delta_u)+ ((j + offset.getY()) * _delta_v);
    auto ray_origin = (_defocusAngle <= 0) ? _center : defocusDiskSample();
    auto ray_direction = pixel_sample - ray_origin;
    return Ray(ray_origin, ray_direction);
}

/**
 * @brief Get the color of a ray
 *
 * @param r The ray to get the color of
 * @param depth The depth of the ray
 * @param world The world to check for hits
 * @return Color The color of the ray
 */
Color Camera::rayColor(const Ray& r, int depth, const HittableList& world) const
{
    if (depth <= 0)
            return Color(0,0,0);
    HitRecord rec;
    if (world.hit(r, Interval(0.001, std::numeric_limits<double>::infinity()), rec)) {
        Ray scattered;
        Color attenuation;
        if (rec.getMat()->scatter(r, rec, attenuation, scattered))
            return attenuation * rayColor(scattered, depth-1, world);
        return Color(0,0,0);
    }

    Vector3D unit_direction = unitVector(r.getDirection());
    auto t = 0.5 * (unit_direction.getY() + 1.0);
    return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

/**
 * @brief Get the center of the camera
 *
 * @return Point3D The center of the camera
 */
Point3D Camera::getCenter() const
{
    return _center;
}

/**
 * @brief Get a sample from the defocus disk
 *
 * @return Point3D The sample from the defocus disk
 */
Point3D Camera::defocusDiskSample() const {
    Vector3D random;
    auto p = random.randomInUnitDisk();
    return _center + (p[0] * _defocusDiskU) + (p[1] * _defocusDiskV);
}