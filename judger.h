#ifndef JUDGER
#define JUDGER

#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<fstream>
#include<random>
#include<stdlib.h>
#include <dirent.h>
using namespace std;

const char alphabet[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const int testtimes = 10;
class Judger
{
public:
    string fp1;
    string fp2;
    string rootfolder;


    Judger(){rootfolder = "input";};
    string getfn(string fp);
    string ftos(string fp);
    void rmexec(string fp);
    void GetFileNames(std::string path, std::vector<std::string> &filenames);
    void GetFolderNames(std::string path, std::vector<std::string> &filenames);
    void generatecase(string format, string outputfp, int i);
    void geneexec(string fp);
    void casetest(string fp1, string fp2, string testcasefp, string outp1, string outp2);
    void cmpoutputs(string fp1, string fp2);
};

#endif



