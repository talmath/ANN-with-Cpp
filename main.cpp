


// little change ... 


#include <iostream>
#include <vector>
#include <fstream>

#include "neuron.h"
#include "network.h"
#include "data.h"






int main() {
    
    
    int x_size = 2;
    int y_size = 1;
    
    
    // DATA
    DATA data(x_size,y_size);    // construct
    data.printDATA();            // print
    
    
    /*
     the next step is to use DATA in order to feed our NET.
     what do you mean by feeding ? well, the answer is simple but
     the application might be rather technical as we have to learn
     how to differentiate a complex function. 
     
     
     
     */
    
    
    
    
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
