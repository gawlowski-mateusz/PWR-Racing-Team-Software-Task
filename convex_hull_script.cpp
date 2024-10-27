//
// Created by mateusz on 27/10/2024.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Point {
    double x, y;

    // Overload comparison operator for sorting based on y coordinate,
    // and x coordinate if y values are the same
    bool operator<(const Point &other) const {
        return (y < other.y) || (y == other.y && x < other.x);
    }
};

// Calculate the orientation of the triplet (p, q, r)
// Positive value -> counterclockwise turn
// Negative value -> clockwise turn
// Zero -> collinear points
double orientation(const Point &p, const Point &q, const Point &r) {
    return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}

// Calculate the square of the Euclidean distance between two points
double distanceSquared(const Point &p1, const Point &p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Sort points by polar angle relative to a base point `p0`
// Uses orientation and distance to resolve ties in angle
void sortByPolarAngle(std::vector<Point> &points, const Point &p0) {
    std::sort(points.begin(), points.end(), [&p0](const Point &a, const Point &b) {
        double orient = orientation(p0, a, b);

        if (orient == 0) {
            // For collinear points with p0, prefer the closer one
            return distanceSquared(p0, a) < distanceSquared(p0, b);
        }

        return orient > 0; // Prefer counterclockwise points
    });
}

// Reads points from a file and returns them as a vector of Points
std::vector<Point> readInputFile() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;
    std::ifstream file("../" + filename);

    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return {};
    }

    int points_number;
    file >> points_number;
    std::vector<Point> points(points_number);

    // Read each point's x and y values from the file
    for (int i = 0; i < points_number; ++i) {
        file >> points[i].x >> points[i].y;
    }

    file.close();

    return points;
}

// Compute the convex hull of a set of points using Graham Scan algorithm
std::vector<Point> grahamScan(std::vector<Point> &points) {
    int n = points.size();
    if (n < 3) return {}; // Not enough points for a convex hull

    // Step 1: Find the starting point with the lowest y (or leftmost if tie)
    std::swap(points[0], *std::min_element(points.begin(), points.end()));

    // Step 2: Sort points by polar angle with respect to the starting point
    Point p0 = points[0];
    sortByPolarAngle(points, p0);

    // Step 3: Use a stack to build the convex hull
    std::vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);

    for (int i = 2; i < n; ++i) {
        // Check for a clockwise turn and remove the last point if found
        while (hull.size() > 1 && orientation(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
            hull.pop_back();
        }
        // Add the current point to the hull
        hull.push_back(points[i]);
    }

    return hull; // Final convex hull points
}

// Print the points in the convex hull
void printResult(const std::vector<Point> &hull) {
    std::cout << "[";

    for (size_t i = 0; i < hull.size(); ++i) {
        std::cout << "(" << std::fixed << std::setprecision(1) << hull[i].x << ", " << hull[i].y << ")";
        if (i != hull.size() - 1) {
            std::cout << ", ";
        }
    }

    std::cout << "]" << std::endl;
}

int main() {
    // Read points from a file
    std::vector<Point> points = readInputFile();

    // Compute the convex hull using the Graham Scan algorithm
    std::vector<Point> hull = grahamScan(points);

    // Display the result
    std::cout << "Convex Hull Points:\n";
    printResult(hull);

    return 0;
}
