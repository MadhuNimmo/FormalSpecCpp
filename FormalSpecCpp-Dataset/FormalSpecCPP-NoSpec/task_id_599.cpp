#include <cstddef>
#include <tuple>


std::tuple<int, double> SumAndAverage(int n) {

    int sum = 0;
    double average = 0.0;

    for (int i = 1; i <= n; ++i) {

        sum += i;
    }

    average = static_cast<double>(sum) / n;


    return std::make_tuple(sum, average);
}
