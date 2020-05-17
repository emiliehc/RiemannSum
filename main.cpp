#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream f;
    f.open("data.txt");
    if (!f)
    {
        std::cerr << "Unable to open file" << std::endl;
        exit(1);
    }

    std::vector<std::pair<double, double>> points;

    int num;
    f >> num;
    points.resize(num);
    for (int i = 0; i < num; ++i)
    {
        double number;
        f >> number;
        points[i] = {number, 0.0};
    }
    for (int i = 0; i < num; ++i)
    {
        double number;
        f >> number;
        points[i].second = number;
    }
    
    std::pair<double, double> previousPoint;

    double sum = 0;
    bool first = true;
    for (const auto& point : points)
    {
        if (first)
        {
            first = false;
            continue;
        }
        //std::cout << point.first << " " << point.second << std::endl;
        sum += (point.first - previousPoint.first) * previousPoint.second;

        previousPoint = point;
    }
    std::cout << sum << std::endl;

    return 0;
}
