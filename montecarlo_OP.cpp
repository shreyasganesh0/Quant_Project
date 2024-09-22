#include <iostream>
#include <cmath>
#include <random>
#include <vector>

// Function to generate normally distributed random numbers
double generateGaussianNoise(double mean, double stddev) {
    static std::mt19937 generator(std::random_device{}());
    std::normal_distribution<double> distribution(mean, stddev);
    return distribution(generator);
}

int main() {
    // Option parameters
    double S0 = 100.0;   // Initial stock price
    double K = 100.0;    // Strike price
    double r = 0.05;     // Risk-free rate
    double sigma = 0.2;  // Volatility
    double T = 1;      // Time to maturity (1 year)
    int simulations = 100000; // Number of simulations

   
    return 0;
}