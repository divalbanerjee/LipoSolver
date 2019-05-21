//
//  main.cpp
//  LipoSolver
// C++ Lipo Solver
//  Created by Dival Banerjee on 5/21/19.
//  Copyright © 2019 Dival Banerjee. All rights reserved.
//

#include <iostream>
#include <cmath>

int main(int argc, const char * argv[]) {
    //Inputs
    double motorVoltage;
    double highPowerInW;
    double lowPowerInW;
    double highPowerDurationInMin;
    double lowPowerDurationInMin;
    double highPowerDurationInHours;
    double lowPowerDurationInHours;
    double cRating;
    double cellCapacityInAmpHours;
    
    //Calculated Values
    
    double highPowerCurrent;
    double lowPowerCurrent;

    std::cout << "Enter motor voltage[V]: " << std::endl;
    std::cin >> motorVoltage;
    std::cout << "Enter high power level [W]: " << std::endl;
    std::cin >> highPowerInW;
    std::cout << "Enter high power duration [minutes]: " << std::endl;
    std::cin >> highPowerDurationInMin;
    std::cout << "Enter low power level [W]: " << std::endl;
    std::cin >> lowPowerInW;
    std::cout << "Enter low power duration [minutes]: " << std::endl;
    std::cin >> lowPowerDurationInMin;
    std::cout << "Enter C Rating | C ratings above 40 C will be set to 40 C" << std::endl;
    std::cin >> cRating;
    std::cout << "Enter cell capacity [Ah]: " << std::endl;
    std::cin >> cellCapacityInAmpHours;
    
    
    return 0;
}
