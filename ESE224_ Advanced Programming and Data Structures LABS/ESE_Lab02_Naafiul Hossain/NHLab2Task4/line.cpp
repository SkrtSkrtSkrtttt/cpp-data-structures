#include "line.h"
#include <iostream>

// Constructor definition
Line::Line(double slope, double intercept) : slope(slope), intercept(intercept) {}

// Print function definition
void Line::print() const {
    std::cout << "y = " << slope << "x + " << intercept << std::endl;
}

// Overloaded operator == definition
bool Line::operator==(const Line& other) const {
    return (slope == other.slope) && (intercept == other.intercept);
}

// Overloaded operator * definition
Line Line::operator*(double multiplier) const {
    return Line(slope * multiplier, intercept);
}

// Overloaded operator + definition
Line Line::operator+(double value) const {
    return Line(slope, intercept + value);
}
