#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>


struct Contract
{
    double premium;
    double strike;
    int dte;
    double delta;
    double gamma;
    double theta;
    double vega;
    double rho;
    double implied_volatility;
    double intrinsic_value;
    double market_price; 
};

int main() {
    // Option parameters
    double S0 = 100.0;   // Initial stock price
    double K = 100.0;    // Strike price
    double r = 0.05;     // Risk-free rate
    double sigma = 0.2;  // Volatility
    double T = 1;        // Time to maturity (in years)

    // Calculate option prices
    auto callChain = blackScholesOptionPricing(S0, K, r, sigma, T, true);
    auto putChain = blackScholesOptionPricing(S0, K, r, sigma, T, false);

    // Output the results
    for (const auto& con : callChain) {
        std::cout << "Strike: " << con.strike << " European Call Option Price: " << con.premium
                  << ", Market Price: " << con.market_price << ", dte: " << con.dte
                  << ", delta: " << con.delta << ", gamma: " << con.gamma
                  << ", theta: " << con.theta << ", vega: " << con.vega
                  << ", rho: " << con.rho << ", implied volatility: " << con.implied_volatility
                  << ", intrinsic value: " << con.intrinsic_value << std::endl;
    }

    std::cout << "" << std::endl;

    for (const auto& con : putChain) {
        std::cout << "Strike: " << con.strike << " European Put Option Price: " << con.premium
                  << ", Market Price: " << con.market_price << ", dte: " << con.dte
                  << ", delta: " << con.delta << ", gamma: " << con.gamma
                  << ", theta: " << con.theta << ", vega: " << con.vega
                  << ", rho: " << con.rho << ", implied volatility: " << con.implied_volatility
                  << ", intrinsic value: " << con.intrinsic_value << std::endl;
    }

    return 0;
}