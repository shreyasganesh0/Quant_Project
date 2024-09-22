#include <iostream>
#include <cmath>

struct Contract
{
    double premium;
    int dte;
    double delta;
    double gamma;
    double theta;
    double vega;
    double rho;
    double implied_volatility;
    double intrinsic_value;
};

// Error function approximation
double erf(double x) {
    const double A1 = 0.254829592;
    const double A2 = -0.284496736;
    const double A3 = 1.421413741;
    const double A4 = -1.453152027;
    const double A5 = 1.061405429;
    const double P = 0.3275911;

    // Save the sign of x
    int sign = (x >= 0) ? 1 : -1;
    x = fabs(x);

    // A&S formula 7.1.26
    double t = 1.0 / (1.0 + P * x);
    double y = 1.0 - (((((A5 * t + A4) * t) + A3) * t + A2) * t + A1) * t * exp(-x * x);

    return sign * y;
}

// Cumulative standard normal density function
double cumulativeStandardNormal(double x) {
    return 0.5 * (1.0 + erf(x / sqrt(2.0)));
}


int main() {
    // Option parameters
    double S0 = 100.0;   // Initial stock price
    double K = 100.0;    // Strike price
    double r = 0.05;     // Risk-free rate
    double sigma = 0.2;  // Volatility
    double T = 1;      // Time to maturity (in years)
    

    // Calculate option prices
    auto callContract = blackScholesOptionPricing(S0, K, r, sigma, T, true);
    auto putContract = blackScholesOptionPricing(S0, K, r, sigma, T, false);

    // Output the results
    std::cout << "European Call Option Price: " << callContract.premium << ", dte: " << callContract.dte << ", delta: " << callContract.delta << ", gamma: " << callContract.gamma << ", theta: " << callContract.theta << ", vega: " << callContract.vega  << ", rho: " << callContract.rho << ", implied volatility: " << callContract.implied_volatility  << ", intrinsic value: " << callContract.intrinsic_value << std::endl;
    std::cout << "European Put Option Price: " << putContract.premium << ", dte: " << putContract.dte << ", delta: " << putContract.delta << ", gamma: " << putContract.gamma << ", theta: " << putContract.theta << ", vega: " << putContract.vega << ", rho: " << putContract.rho << ", implied volatility: " << putContract.implied_volatility  << ", intrinsic value: " << putContract.intrinsic_value << std::endl;

    return 0;
}