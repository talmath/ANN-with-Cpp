

#include <iostream>
#include <vector>
using namespace std; 


class NEURON{
   
public:
    
    NEURON(unsigned num_of_weights);
    
    double          getOUTPUT()       {return OUTPUT;};
    vector<double>  printWEIGHT()     {return WEIGHT;};
    void            calcOUTPUT(vector<double> input);
    void            modifyOUTPUT(double val) {OUTPUT = val;}
    
private:
    
    double          SIGMOID(double x) {return (1/(1+exp(-x)));};
    double          OUTPUT;          // the OUTPUT val
    unsigned        weights_num;
    vector<double>  WEIGHT;          // the WEIGHTS
    
};




NEURON::NEURON(unsigned num_of_weights){
    
    // initialize OUTPUT
    OUTPUT = 0;
    
    weights_num = num_of_weights;
    
    // initialize WEIGHTs
    for (int i=0 ; i<num_of_weights ; i++)
    {
        WEIGHT.push_back(0.5);
    }
}



void NEURON::calcOUTPUT(vector<double> input)
{
    
    double sum = 0;
    for (int i=0 ; i<weights_num ; i++)
    {
        sum = sum + (WEIGHT[i] * input[i]);
    }
    
    OUTPUT = SIGMOID(sum);
}




