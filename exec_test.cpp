//#include<judger.h>
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<random>
#include<stdlib.h>
using namespace std;


string getfn(string fp)
{
    int backslashpos = fp.find('\\');
    return fp.substr(backslashpos + 1, fp.size());
}

void casetest(string fp1, string fp2, string testcasefp, string outp1, string outp2)
{
    string cmd = "";
    string fn1 = getfn(fp1);
    string fn2 = getfn(fp2);
    cmd = "g++ "+fn1+" -o "+fn1.substr(0, fn1.size()-4); 
    system(cmd.c_str());
    cmd = fn1.substr(0, fn1.size()-4)+" <"+testcasefp+" >"+outp1;
    system(cmd.c_str());
    cmd = "g++ "+fn2+" -o "+fn2.substr(0, fn2.size()-4); 
    system(cmd.c_str());
    cmd = fn2.substr(0, fn2.size()-4)+" <"+testcasefp+" >"+outp2;
    system(cmd.c_str());
}



/*int main()
{
    casetest("input/4A/48762087.cpp", "input/4A/84822638.cpp", "testcases.txt", "out1.txt", "out2.txt");
    return 0;
}*/