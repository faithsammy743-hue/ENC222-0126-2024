#include <iostream>

// Define a Fraction structure
struct Fraction {
    int numerator;
    int denominator;

    // Function to compute decimal value
    double value() const {
        return static_cast<double>(numerator) / denominator;
    }
};

// Function to find largest fraction using pass-by-reference
Fraction& findLargest(Fraction& f1, Fraction& f2, Fraction& f3) {
    Fraction* largest = &f1; // pointer to track largest fraction

    if (f2.value() > largest->value()) {
        largest = &f2;
    }
    if (f3.value() > largest->value()) {
        largest = &f3;
    }

    return *largest; // return-by-reference
}

int main() {
    Fraction f1 = {1, 2};   // 0.5
    Fraction f2 = {3, 4};   // 0.75
    Fraction f3 = {5, 6};   // ~0.833

    Fraction& largest = findLargest(f1, f2, f3);

    std::cout << "Largest fraction is: "
              << largest.numerator << "/" << largest.denominator
              << " = " << largest.value() << '\n';

    return 0;
}