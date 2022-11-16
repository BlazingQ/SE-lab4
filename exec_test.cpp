#include"judger.h"
/*#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<random>
#include<stdlib.h>
using namespace std;*/

void Judger::geneexec(string fp)
{
    string cmd = "g++ "+fp+" -o "+fp.substr(0, fp.size()-4);
    system(cmd.c_str());  
}

void Judger::casetest(string fp1, string fp2, string testcasefp, string outp1, string outp2)
{
    string cmd = "";
    cmd = fp1.substr(0, fp1.size()-4)+" <"+testcasefp+" >"+outp1;
    system(cmd.c_str());
    cmd = fp2.substr(0, fp2.size()-4)+" <"+testcasefp+" >"+outp2;
    system(cmd.c_str());
}



/*int main()
{
    casetest("input/4A/48762087.cpp", "input/4A/84822638.cpp", "testcases.txt", "out1.txt", "out2.txt");
    return 0;
}*/