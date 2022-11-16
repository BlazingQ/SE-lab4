#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<random>
#include<stdlib.h>
using namespace std;

class Judger
{
private:
    string fp1;
    string fp2;
    string folder;
    string stdin_format;
    vector<string> testvalues;

public:
    Judger(string str);
    ~Judger();
    string getfn(string fp);
    void generatecase(string format, string outputfp);
    void casetest(string fp1, string fp2, string testcasefp, string outp1, string outp2);
};

Judger::Judger(string str)
{
    folder = str;

}

Judger::~Judger()
{
}



/*class JudgerInput
{
private:
    string fp1;
    string fp2;
public:
    JudgerInput(string str1, string str2);
    string getfp(int index);//getfilepath
    string getfn(int index);//getfilename
};

JudgerInput::JudgerInput(string str1, string str2)
{
    fp1 = str1;
    fp2 = str2;
}*/




