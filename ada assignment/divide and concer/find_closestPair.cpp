/*Ques: Implement a divide-and-conquer algorithm for finding the closest pair of points in 2D
space.*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

// A structure to represent a point in 2D space
struct Point {
    int x, y;
};

// A function to calculate the Euclidean distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// A helper function to compare two points based on their y-coordinates
bool compareY(Point p1, Point p2) {
    return p1.y < p2.y;
}

// A helper function to find the minimum of two doubles
double min(double x, double y) {
    return (x < y) ? x : y;
}

// A function to find the closest pair of points using divide and conquer
double closestPair(vector<Point>& points, int l, int r) {
    if (r - l <= 3) {
        // Base case: if there are only 3 or fewer points, calculate the distance directly
        double minDist = DBL_MAX;
        for (int i = l; i < r; i++) {
            for (int j = i + 1; j < r; j++) {
                double dist = distance(points[i], points[j]);
                if (dist < minDist) {
                    minDist = dist;
                }
            }
            
        }
        return minDist;
    }
    
    // Divide the points into two halves
    int mid = (l + r) / 2;
    double d1 = closestPair(points, l, mid);
    double d2 = closestPair(points, mid, r);
    double d = min(d1, d2);
    
    // Merge the two halves
    vector<Point> strip;
    for (int i = l; i < r; i++) {
        if (abs(points[i].x - points[mid].x) < d) {
            strip.push_back(points[i]);
        }
    }
    sort(strip.begin(), strip.end(), compareY);
    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && strip[j].y - strip[i].y < d; j++) {
            double dist = distance(strip[i], strip[j]);
            if (dist < d) {
                d = dist;
            }
        }
    }
    return d;
}

// A function to find the closest pair of points in 2D space
double closestPair(vector<Point>& points) {
    sort(points.begin(), points.end(), [](Point& a, Point& b) { return a.x < b.x; });
    return closestPair(points, 0, points.size());
}

// Driver code to test the implementation
int main() {
    vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    double minDist = closestPair(points);
    cout << "The minimum distance between any two points is " << minDist << endl;
    return 0;
}
