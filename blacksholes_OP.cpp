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