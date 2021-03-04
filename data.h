

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
 


/* ********************************  PAIRS  ******************************** */
class PAIR{
public:
    vector<double>  x;
    vector<double>  y;
};


/* *********************************  DATA  ******************************** */
 

class DATA{
    
public:
    DATA(int size_1,int size_2);
    void printDATA();
    
private:
    vector<PAIR> data;
    unsigned x_size;
    unsigned y_size;
};




DATA::DATA(int size_1, int size_2){
    
    
    x_size = size_1;
    y_size = size_2;
    
    
    // EXTRACT file
    ifstream myFile;
    myFile.open("/Users/tal/Desktop/CODE/ANN/ANN/data.csv");
    
    // file into data
    int total = x_size + y_size;
    int index = 0;
    PAIR pair;
    
    while (myFile.good())
    {
        // STEP
        string line;
        getline(myFile, line, ',');
        int val = stoi(line);
        
        // STEP - construct pair
        int a = index % total;
        a < x_size ? pair.x.push_back(val) : pair.y.push_back(val);
        
        // STEP - pair COMPLETED
        if ( pair.x.size() + pair.y.size() == total )
        {
            data.push_back(pair);  // assign pair
            pair.x.clear();    // erase pair
            pair.y.clear();
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
            cout << data[i].x[j] << " ";
        }
        
        // right coordinate
        for (int j=0; j<y_size ; j++)
        {
            cout << data[i].y[j] << " ";
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
