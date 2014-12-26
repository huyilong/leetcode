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
		cout<<setw(3)<<vec[i][j]<<" ";//this is same as the insertion but not consistent with common sense
        //the common sense x,y will be the y,x in this 2d matrix
	}
	cout<<endl;
}

return 0;
}

/*
  0   9  18  27  36  45  54  63  72  81  90  99 108 117 126 135 144 153 162 171 
  0   8  16  24  32  40  48  56  64  72  80  88  96 104 112 120 128 136 144 152 
  0   7  14  21  28  35  42  49  56  63  70  77  84  91  98 105 112 119 126 133 
  0   6  12  18  24  30  36  42  48  54  60  66  72  78  84  90  96 102 108 114 
  0   5  10  15  20  25  30  35  40  45  50  55  60  65  70  75  80  85  90  95 
  0   4   8  12  16  20  24  28  32  36  40  44  48  52  56  60  64  68  72  76 
  0   3   6   9  12  15  18  21  24  27  30  33  36  39  42  45  48  51  54  57 
  0   2   4   6   8  10  12  14  16  18  20  22  24  26  28  30  32  34  36  38 
  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19 
  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 
  */