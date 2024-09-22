#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


int main() {
    double S = 100.0;    // Current stock price
    double K = 100.0;     // Option strike price
    double r = 0.05;     // Risk-free rate
    double T = 1.0;      // Time to maturity (in years)
    double sigma = 0.2;  // Volatility
    int N = 100;         // Number of time steps
    bool isCall = true; // False for Put option
    bool isAmerican = true; // True for American, False for European
    double q = 0.03;     // Dividend yield

    BinomialOptionPricing americanOption(S, K, r, T, sigma, N, isCall, isAmerican, q);
    double americanOptionPrice = americanOption.price();
    
    std::cout << "The American option price is: " << americanOptionPrice << std::endl;


    isAmerican = false; // True for American, False for European

    BinomialOptionPricing europeanOption(S, K, r, T, sigma, N, isCall, isAmerican, q);
    double europeanOptionPrice = europeanOption.price();

    std::cout << "The European option price is: " << europeanOptionPrice << std::endl;

    return 0;
}