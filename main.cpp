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
    
    double motorVoltage = 0;
    double highPowerInW = 0;
    double lowPowerInW = 0;
    double highPowerDurationInMin = 0;
    double lowPowerDurationInMin = 0;
    double highPowerDurationInHours = 0;
    double lowPowerDurationInHours = 0;
    double cRating = 0;
    double cellCapacityInAmpHours = 0;
    double cellVoltage = 0;
    double safetyPercentage = 0;
    //Calculated Values
    
    double highPowerCurrent = 0;
    double lowPowerCurrent = 0;
    double highPowerCapacity = 0;
    double lowPowerCapacity = 0;
    double rawCapacityReq = 0;
    double maxSafeCurrent = 0;
    double totalCapacity = 0;
    double seriesPacks = 0;
    double parallelPacks = 0;


    std::cout << "Enter motor voltage[V]: " << std::endl;
    std::cin >> motorVoltage;
    std::cout << "Enter cell voltage[V]: " << std::endl;
    std::cin >> cellVoltage;
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
    
    if(cRating > 40){ //Any C Rating over 40 C is total BS. You need to measure the internal resistance of the battery. To be actually sure.
        cRating = 40;
        std::cout << "C rating exceeded 40. Reseting to 40 C" << std::endl;
    }
    
    std::cout << "Enter cell capacity [Ah]: " << std::endl;
    std::cin >> cellCapacityInAmpHours;
    std::cout << "Enter safety percentage: " << std::endl;
    std::cin >> safetyPercentage;
    
    highPowerDurationInHours = highPowerDurationInMin/60;
    std::cout << "High power duration in hours: " << highPowerDurationInHours << std::endl;
    
    lowPowerDurationInHours = lowPowerDurationInMin/60;
    
    std::cout << "Low power duratio in hours: " << lowPowerDurationInHours << std::endl;
    
    highPowerCurrent = 8*(highPowerInW/motorVoltage);
    lowPowerCurrent = 8*(lowPowerInW/motorVoltage);
    
    maxSafeCurrent = cellCapacityInAmpHours * cRating;
    
    std::cout << "Maximum safe current:" << maxSafeCurrent << std::endl;
    
    if(highPowerCurrent > maxSafeCurrent) {
        std::cout << "Highpower current exceeds maximum safe current based on discharge" << std::endl;
    }
    
    highPowerCapacity = highPowerCurrent * highPowerDurationInHours;
    std::cout << "High power capacity [Ah]: " << highPowerCapacity << std::endl;
    
    lowPowerCapacity = lowPowerCurrent * lowPowerDurationInHours;
    std::cout << "Low power capacity [Ah]: " << lowPowerCapacity << std::endl;
    
    rawCapacityReq = lowPowerCapacity + highPowerCapacity;
    std::cout << "Combined power required [Ah]:" << rawCapacityReq << std::endl;
    
    totalCapacity = rawCapacityReq * ((safetyPercentage/100)+1);
    std::cout << "Total capacity required [Ah]: " << totalCapacity << std::endl;
    
    seriesPacks = motorVoltage / cellVoltage;
    parallelPacks = totalCapacity/cellCapacityInAmpHours;
    
    std::cout << "Number of series packs: " << seriesPacks <<std::endl;
    std::cout << "Number of parallel packs: " << parallelPacks << std::endl;
    
    return 0;
}
