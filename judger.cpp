#include"judger.h"

Judger judger;

string Judger::getfn(string fp)
{
    int backslashpos = fp.find('/');
    return fp.substr(backslashpos + 1, fp.size());
}

string Judger::ftos(string fp)
{
    ifstream ifs(fp, ios::in);
    if(!ifs) 
    {
        cout<<"ERROR OPEN IFS2!\n";
        return "";
    }
    string res;
    string tmp;
    while(!ifs.eof())
    {
        ifs>>tmp;
        res += tmp;
    }
    ifs.close();
    return res;
}

void Judger::rmexec(string fp)
{
    string cmd = "rm "+fp.substr(0, fp.size()-4);
    std::system(cmd.c_str());
}

void Judger::GetFileNames(std::string path, std::vector<std::string> &filenames)
{
    DIR* pDir;
    struct dirent* ptr;
    if(!(pDir = opendir(path.c_str()))){
        std::cout<<"File doesn't Exist!"<<std::endl;
        return;
    }
    while((ptr = readdir(pDir))!=0) {
        string tmp = ptr->d_name;
        if (tmp.find("cpp") != -1){
            filenames.push_back(path + "/" + ptr->d_name);
        }
    }
    closedir(pDir);
}

void Judger::GetFolderNames(std::string path, std::vector<std::string> &filenames)
{
    DIR* pDir;
    struct dirent* ptr;
    if(!(pDir = opendir(path.c_str()))){
        std::cout<<"Folder doesn't Exist!"<<std::endl;
        return ;
    }
    while((ptr = readdir(pDir))!=0) {
        string tmp = ptr->d_name;
        if (tmp.compare(".") != 0 && tmp.compare("..") != 0){
            filenames.push_back(path + "/" + ptr->d_name);
        }
    }
    closedir(pDir);
}

int main()
{
    vector<string> foldernames;
    vector<string> filenames;
    string format;
    judger.GetFolderNames(judger.rootfolder, foldernames);
    string folder;
    std::system("mkdir output");
    ofstream ofs1("output/equal.csv", ios::out);
    ofs1<<"file1,file2\n";
    ofstream ofs2("output/inequal.csv", ios::out);
    ofs2<<"file1,file2\n";
    ofs1.close();
    ofs2.close();
    ofs1.open("output/equal.csv", ios::app);
    ofs2.open("output/inequal.csv", ios::app);
    for(int i = 0; i != foldernames.size(); ++i)
    {
        folder = foldernames[i];
        judger.GetFileNames(folder, filenames);
        format = folder + "/stdin_format.txt";
        for(int i = 0; i < filenames.size(); ++i)
        {
            judger.geneexec(filenames[i]);
        }
        for(int i = 0; i < filenames.size() - 1; ++i)
        {
            for(int j = i + 1; j < filenames.size(); ++j)
            {
                bool flag = 1;
                for(int k = 0; k != testtimes; ++k)
                {
                    judger.generatecase(format, "testcases.txt", k);
                    judger.casetest(filenames[i], filenames[j], "testcases.txt",
                    "out1.txt", "out2.txt");
                    string str1 = judger.ftos("out1.txt");
                    string str2 = judger.ftos("out2.txt");
                    if(str1.compare(str2) != 0)
                        flag = 0;
                }
                if(flag == 1)
                {
                    ofs1<<filenames[i]<<","<<filenames[j]<<"\n";
                }
                else if(flag == 0)
                {
                    ofs2<<filenames[i]<<","<<filenames[j]<<"\n";
                }
            }
        }
        for(int i = 0; i != filenames.size(); ++i)
        {
            judger.rmexec(filenames[i]);
        }
        filenames.clear();//important
    }
    ofs1.close();
    ofs2.close();
    std::system("rm out1.txt");
    std::system("rm out2.txt");
    std::system("rm testcases.txt");

    return 0;
}
