string str,sub; // str is string to search, sub is the substring to search for

vector<size_t> positions; // holds all the positions that sub occurs within str


//try to use the string method API
//here is .substring()  and also .find()  methods could save you tons of time
size_t pos = str.find(sub, 0);
while(pos != string::npos)
{
    positions.push_back(pos);
    pos = str.find(sub,pos+1);
}