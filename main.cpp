
/* PACKAGEs*/
#include <iostream>
#include <vector>
#include <fstream>
#include "neuron.h"
#include "network.h"
#include "data.h"






int main() {
    
    // DATA
    DATA data(2,1);              // construct
    data.printDATA();            // print
    
    
    // TOPOLOGY
    vector<double> TOPOLOGY;
    TOPOLOGY.push_back(2);
    TOPOLOGY.push_back(3);
    TOPOLOGY.push_back(1);
    
    // NET create
    NET net(TOPOLOGY);
    
    // INPUT
    vector<double> input;
    input.push_back(1);
    input.push_back(1);
    
    // PUSH
    net.FEEDforward(input);
    
    // OUTPUT
    net.printOUTPUT();
    

    
    
    
    return 0;
}
