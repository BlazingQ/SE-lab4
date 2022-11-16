//#include<judger.h>
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<random>

using namespace std;

const char alphabet[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

void generatecase(string format)
{
    ifstream ifs(format, ios::in);
    const string outfp = "testcases.txt";
    ofstream ofs(outfp, ios::out);
    string temp;
    vector<string> testvalues;
    if(!ifs) 
    {
        cout<<"ERROR OPEN IFS!\n";
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
    /*while(!testvalues.empty())
    {
        cout<<testvalues.back()<<' ';
        testvalues.pop_back();
    }*/
    string tmp = "";
    srand(time(NULL));
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

int main()
{
    generatecase("stdin_format.txt");
    return 0;
}