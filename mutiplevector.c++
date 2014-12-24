#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){

vector< vector<int> > vec;

for (int i = 0; i < 10; i++) {
    vector<int> row; // Create an empty row
    for (int j = 0; j < 20; j++) {
        row.push_back( i*j); // Add an element (column) to the row
    }
    //push the vector into the vector 
    vec.push_back(row); // Add the row to the main vector
}
//this is a 10*20 2d matrix   
// create the 1d row will be used as the rows in the final 2d
//i.e. they are corresponding

//small detail  -> we should print out the y from up to down, rather than from down to up
for(int i = 9; i >= 0; i--)
{
	for (int j = 0; j < 20; j++)
	{
		cout<<setw(3)<<vec[i][j]<<" ";
	}
	cout<<endl;
}

return 0;
}