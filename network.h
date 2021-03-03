


#include <iostream>
#include <vector>
using namespace std;


typedef vector<NEURON> LAYER;





class NET{
        
public:
    
    NET(vector<double> TOPOLOGY);
    void             FEEDforward (vector<double> input);
    void             printOUTPUT();
    
    void             BACKprop();
    
private:
    
    vector<LAYER>   LAYERs;
    vector<double>  output;
    vector<double>  topology;

};



void NET::BACKprop()
{
    /*
     this is the main step were our NET learns! in order to write this little
     piece of code we need to check the internet for mathematical background
     as it's totally impossible to escape the theoretical part. once we accumulate
     enough background we can surely apply it here. the first step is to understand the
     general picture. the idea is to modify the weights within the net in order to
     precise the NET with respect to some DATA. think of it as an adjuscment routine.
     So, accoding to that we need to verifty what is the DATA that we want to approximate.
     the DATA is just a finite set of the form {(x,y),...} that we want to approximate.
     
     step-1 : find the DATA
     
     once we have DATA then we would like to use it for the purpose modifying the NET's
     weights. the subsequent question is :
     
     question: how do we use the DATA to change the weights ?
     
     at this very point mathematics come into play. as mentioned above our DATA has the
     form D = {(x,y),...,} and the first step to use it for 'learning' is to define the
     corresponded ERROR function E = |f(x_1)-y_1| + |f(x_2)-y_2| + ... even though this
     function created by f(x), still it is not a function of x rather of W which represents
     all weights involved within our NET.
     
     step-2 : construct error function E(W) = |f(x_1)-y_1| + ...
     
     we think of E as a function of W, meaninig E = E(W). now we would like to find a minimum
     value for E. that is to say, to find an 'appropriate' W_0 for which E(W_0)<E(W) for any W.
     the only tool that enable to achieve such a thing called the GRADIENT. the latter is just
     a vector of all possible derivatives therefore its length is exactly the number of weights.
     this GRADIENT is calculated per vector W, which means different Ws give rise to different
     GRADIENTs. therefore we denote GRAD(W) the gradient at the point W.
     
     step-3 : construct the gradient GRAD(W)
     
     we claim that for some infitisimal positive lambda>0, E( W + lambda*(-GRAD(W)) ) < E(W)
     which basically means that the corresponded function f_W fits the DATA better then f. now,
     once we have the gradient at our disposal we literally define the next (better) weight
     W_0 as W + lambda*(-GRAD(W)).
     
     step-4 : defined the next weight  W_0 = W + lambda*(-GRAD(W))
     
     then, we take this new weight and push it into our NET. to be more specific, we change
     all the weights in our NET accoridng to the new weight W_0. as a consequence we get a
     modified NET that acts better than the previous one on the DATA. of course, we repeat
     this process several times in order to perfect our NET with respect to DATA. suppose
     we want to summerize all basic necessary steps described above and take into consideration
     that every single step has to be programmed very rigorly and carefully, then we would
     end up with the following :
     
     step: code a convenient structure to contain DATA
     step: use the latter to construct F(x)
     step: use the latter to find all derivatives - that is to find GRAD(W)
     step: define the new weights W_0 = W + lambda*(-GRAD(W)).
     step: modify all NET's weight according to W_0
     step: repeat the process all over again
     
     
     we cant think at this moment about a structure to contain DATA. the reason
     is quite obvious: we dont have any data so far so we cant think of how to
     catch it in terms of programming. we know that many types of DATA arrive in
     csv form, so maybe we should think in terms of csv-file which means to extract
     and construct DATA structure using a csv file.
     
     we would like to begin with the known XOR gate. this one suppose to be quite
     simple as it conatins only 4 lines of information. there're two variables x,y
     and only one outcome which can be either '0' or '1'. if both variables are
     identical then the result is '0' otherwise '1'. this little chat already implies
     which TOPOLOGY to choose. since there're two varibles then the first layer has
     consists of 2 neurons and since there's only one outcome then the last layer
     has to involve only one neuron. in between these two layers theoretically you
     can choose whatever you want which eventually implies that our TOPO is going to
     look like {2,...,1}. for simplicity we're going to choose only one middle layer
     of size three. therefore we're talking about TOPO = {2,3,1}.
     
     after we have created an appropriate CSV file which contains all of our DATA,
     the next step is to extract this information and put it inside a specific
     structure. the natural question we ask ourselves is: which structure to choose ?
     since we're dealing with numbers for both input and output then the most appropriate
     structure might be 'vector of doubles'. or maybe we should use classes and vectors
     together. for a moment I was thinking of a vector of a very specific class which
     contains two fields : input output. this way we'll have one unit one vector that
     contains all information.
     
     GRAD:
     since you want to diffrentiate functions for gradient purposes, the only way you
     can do that is through approximation, that is to approximate the desired derivative.
     therefore you have to follow the formula [f(x+h)-f(x)]/h for sufficiently small but
     possitive quantity h>0. this rises the question: which small quantitly should we use ?
     this particular question made us to browse the internet and after careful examination
     we have reached our desired candidate: DBL_EPSILON from cfloat library is the least
     positive double for which 1 != 1 + value which make it sufficiently tiny.
     
     
     
     */
    
    
    
    
}




NET::NET(vector<double> TOPOLOGY)
{
    // TOPOLOGY
    topology = TOPOLOGY;
    
    // LAYERs
    int num_of_layers = int(topology.size());
    for (unsigned layer_i = 0 ; layer_i < num_of_layers ; layer_i++)
    {
        // layer declaration
        LAYER layer;
        
        // number of neurons in current layer
        unsigned num_of_neurons = TOPOLOGY[layer_i];
    
        for (int i = 0 ; i<num_of_neurons ; i++)
        {
            
            if (layer_i == 0)
            {
                NEURON neuron(0);             // create weighless neuron
                layer.push_back(neuron);      // add it to layer
            }
            else
            {
                int num_neurons = TOPOLOGY[layer_i-1];
                NEURON neuron(num_neurons);
                layer.push_back(neuron);
            }
        }
        
        // assign layer to LAYERs (of NET)
        LAYERs.push_back(layer);
    }
}



void NET::FEEDforward (vector<double> input)
{
    // FIRST layer adjust
    for (int i=0 ; i<input.size() ; i++)
    {
        LAYERs[0][i].modifyOUTPUT(input[i]);    // modify each nuron's output
    }
    

    // OTHER layers
    int last_layer = int(topology.size());
    for (int i=1 ; i<last_layer ; i++)
    {
        
        // PREVIOUS layer (output)
        int            prev_layer      = i-1;
        int            prev_layer_size = topology[i-1];
        vector<double> prev_layer_output;
        
        for (int j=0 ; j<prev_layer_size ; j++)
        {
            prev_layer_output.push_back((LAYERs[prev_layer])[j].getOUTPUT());
        }
        
        
        // FEED next layer
        int next_layer      = i;
        int next_layer_size = topology[i];
        for (int j=0 ; j<next_layer_size ; j++ )
        {
            (LAYERs[next_layer])[j].calcOUTPUT(prev_layer_output);
        }
    }
}



void NET::printOUTPUT()
{
    // EXTRACT last layer
    LAYER layer       = LAYERs.back();              // last layer
    int   layer_size  = int(LAYERs.back().size());  // last layer size
    
    // PRINT
    for (int i=0 ; i<layer_size ; i++)              // extract values (to vector)
    {
        cout << layer[i].getOUTPUT() << endl;
    }
    
}


