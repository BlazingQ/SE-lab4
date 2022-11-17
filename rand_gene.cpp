#include"judger.h"
/*#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<random>
using namespace std;*/

void Judger::generatecase(string format, string outputfp, int i)
{
    ifstream ifs(format, ios::in);
    ofstream ofs(outputfp, ios::out);
    string temp;
    vector<string> testvalues;
    if(!ifs) 
    {
        cout<<"ERROR OPEN IFS1!\n";
        return;
    }
    if(!ofs) 
    {
        cout<<"ERROR OPEN OFS!\n";
        return;
    }
    while(!ifs.eof())
    {
        ifs>>temp;
        testvalues.push_back(temp);
    }
    string tmp = "";
    srand(time(NULL) + i);
    for(int i = 0; i != testvalues.size(); ++i)
    {
        tmp = testvalues[i];
        
        if(tmp.compare("char") == 0)
        {
            //cout<<"flag1\n";
            int randint = rand()%52;
            char randchar = alphabet[randint];
            ofs<<randchar<<' ';
        }
        else if(tmp.find("int") != -1)
        {
            int floor, ceiling;
            int lbracket = tmp.find('(');
            int comma = tmp.find(',');
            int rbracket = tmp.find(')');
            floor = stoi(tmp.substr(lbracket+1,comma - lbracket - 1));
            ceiling = stoi(tmp.substr(comma+1,rbracket - comma - 1));
            int randint = floor + rand()%(ceiling - floor + 1);
            ofs<<randint<<' ';
        }
        else if(tmp.find("string") != -1)
        {
            int floor, ceiling;
            int lbracket = tmp.find('(');
            int comma = tmp.find(',');
            int rbracket = tmp.find(')');
            floor = stoi(tmp.substr(lbracket+1,comma - lbracket - 1));
            ceiling = stoi(tmp.substr(comma+1,rbracket - comma - 1));
            int randint = floor + rand()%(ceiling - floor + 1);
            string randstr = "";
            for(int i = 0; i != randint; ++i)
            {
                randstr += alphabet[rand()%52];
            }
            ofs<<randstr<<' ';
        }
    }
    ifs.close();
    ofs.close();
}

/*int main()
{
    Judger judger;
    judger.generatecase("format.txt", "testcases.txt", 0);
    return 0;
}*/