#include <cmath>

double SphereVolume(double radius) {

    // Calculate the volume of the sphere using M_PI
    double volume = (4.0 / 3.0) * M_PI * radius * radius * radius;

    return volume;
}
