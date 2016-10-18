#include <fstream>
#include <dirent.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int fileNums(char * filename){
    DIR *dp;
    struct dirent *dirp;
    int n=0;
    if((dp=opendir(filename))==NULL)
        return 0;
    while (((dirp=readdir(dp))!=NULL))
    {
        cout<<dirp->d_name<<endl;
        n++;
    }
    closedir(dp);
    return (n-2);
}
void WriteFilename(string* _dir){
    string dir_name;

    DIR *dp;
    struct dirent *dirp;

    ofstream outfile;
    outfile.open("train.txt");


    for(int i=0;i<_dir->length();i++)
    {
        dir_name = _dir[i];

        int n = dir_name.find_last_of("/");
        string sub_dir_name1 = dir_name.substr(n,dir_name.size());
        string sub_dir_name = dir_name.substr(0,n);
        n = sub_dir_name.find_last_of("/");
        string sub_dir_name2 = sub_dir_name.substr(n+1,sub_dir_name.size());

        if((dp=opendir((char*)dir_name.c_str()))==NULL)
            return ;
        while (((dirp=readdir(dp))!=NULL))
        {

            if(strcmp(dirp->d_name,".")!=0 && strcmp(dirp->d_name,"..")!=0)
            {
               outfile<<sub_dir_name2<<sub_dir_name1<<"/"<<dirp->d_name<<" "<<i<<endl;

            }
            cout<<dirp->d_name<<endl;
        }
        closedir(dp);
    }
    outfile.close();


}


int main(int argc, char *argv[])
{
    string dir[] = {"/home/jason/workspace/opencv2.4/svm/build/2016_10_10/train/error","/home/jason/workspace/opencv2.4/svm/build/2016_10_10/train/brick","/home/jason/workspace/opencv2.4/svm/build/2016_10_10/train/stone","/home/jason/workspace/opencv2.4/svm/build/2016_10_10/train/wood"};
    WriteFilename(dir);
    return 0;
}
