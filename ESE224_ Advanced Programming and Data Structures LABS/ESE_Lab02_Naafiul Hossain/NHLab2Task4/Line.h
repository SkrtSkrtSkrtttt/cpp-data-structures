//Naafiul Hossain
//SBU ID: 115107623
#ifndef LINE_H
#define LINE_H

class Line {
private:
    double slope;     // slope of the line (k)
    double intercept; // y-intercept of the line (b)

public:
    // Constructors
    Line(double slope = 0.0, double intercept = 0.0);

    // Print function
    void print() const;

    // Overloaded operator ==
    bool operator==(const Line& other) const;

    // Overloaded operator *
    Line operator*(double multiplier) const;

    // Overloaded operator +
    Line operator+(double value) const;
};

#endif  // LINE_H
