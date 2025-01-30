#include <cmath>


long CylinderSurfaceArea(double radius, double height) {

    // Calculation: Surface area of a cylinder is 2πr(r + h)
    long area = 2.0 * M_PI * radius * (radius + height);


    return area;
}
