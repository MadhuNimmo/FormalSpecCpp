#include <climits>


int* AreaOfLargestTriangleInSemicircle(int radius) {
    // Calculate the area of the largest triangle in a semicircle
    int area = radius * radius;
    int* result = new int(area);
    if (radius < 0) {
        return nullptr;
    }else{
        return result;
    }
}
