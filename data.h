

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
 


/* ***************************************  PAIRS  ******************************** */
class PAIRS{
public:
    vector<double>  input;
    vector<double>  output;
};


/* ***************************************  DATA  ******************************** */
 

class DATA{
    
public:
    DATA(int size_1,int size_2);
    void printDATA();
    
private:
    vector<PAIRS> data;
    unsigned x_size;
    unsigned y_size;
};




DATA::DATA(int size_1, int size_2){
    
    
    x_size = size_1;
    y_size = size_2;
    
    
    // EXTRACT file
    ifstream myFile;
    myFile.open("/Users/tal/Desktop/CODE/CODE_2/example.csv");
    
    // file into data
    int total = x_size + y_size;
    int index = 0;
    PAIRS pair;
    
    while (myFile.good())
    {
        // STEP
        string line;
        getline(myFile, line, ',');
        int val = stoi(line);
        
        // STEP - construct pair
        int a = index % total;
        a < x_size ? pair.input.push_back(val) : pair.output.push_back(val);
        
        // STEP - pair COMPLETED
        if ( pair.input.size() + pair.output.size() == total )
        {
            data.push_back(pair);  // assign pair
            pair.input.clear();    // erase pair
            pair.output.clear();
        }
        index++;
    }
}





// PRINT all DATA
void DATA::printDATA()
{
    
    for (int i=0 ; i<data.size() ; i++)
    {
        // left coordinate
        for (int j=0; j<x_size ; j++)
        {
            cout << data[i].input[j] << " ";
        }
        
        // right coordinate
        for (int j=0; j<y_size ; j++)
        {
            cout << data[i].output[j] << " ";
        }
        
        cout<<endl;
        
    }
}













// step-1 : CREATE csv file
//std::ofstream myfile;
//myfile.open("/Users/tal/Desktop/CODE/CODE_3/example.csv");
//myfile << "0,0,0,\n";
//myfile << "1,1,0,\n";
//myfile << "1,0,1,\n";
//myfile << "0,1,1\n";
//myfile.close();
