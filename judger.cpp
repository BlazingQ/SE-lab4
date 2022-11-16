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
    system(cmd.c_str());
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
    for(int i = 0; i != foldernames.size(); ++i)
    {
        folder = foldernames[i];
        judger.GetFileNames(folder, filenames);
        format = folder + "/stdin_format.txt";
        cout<<"format= "<<format<<endl;
        judger.generatecase(format, "testcases.txt");
        for(int i = 0; i < filenames.size(); ++i)
        {
            judger.geneexec(filenames[i]);
        }
        for(int i = 0; i < filenames.size() - 1; ++i)
        {
            for(int j = i + 1; j < filenames.size(); ++j)
            {
                judger.casetest(filenames[i], filenames[j], "testcases.txt",
                "out1.txt", "out2.txt");
                cout<<"i = "<<i<<"  out:"<<judger.ftos("out1.txt")<<endl;
                cout<<"j = "<<j<<"  out:"<<judger.ftos("out2.txt")<<endl;
            }
        }
        for(int i = 0; i != filenames.size(); ++i)
        {
            judger.rmexec(filenames[i]);
        }
        filenames.clear();//important
    }
    system("rm out1.txt");
    system("rm out2.txt");
    system("rm testcases.txt");

    return 0;
}
