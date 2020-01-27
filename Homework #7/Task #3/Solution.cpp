#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define min(a,b) ((a) < (b) ? (a) : (b))
struct Directory
{
    std::string name;
    std::string path = "/";
    Directory* parent = nullptr;
    std::vector<Directory*> subdirs;
    
    Directory() = default;
    Directory(const char* name)
    {
        this->name = name;
    }
    Directory(const Directory& rhs)
    {
        name = rhs.name;
        path = rhs.path;
        if (rhs.parent)
        {
            parent = new Directory(*rhs.parent);
        }
        subdirs = rhs.subdirs;
    }
    Directory& operator=(const Directory& rhs)
    {
        if (this != &rhs && &rhs != nullptr)
        {
            if (parent) delete[] parent;
            name = rhs.name;
            path = rhs.path;
            if (rhs.parent)
            {
                parent = new Directory(*rhs.parent);
            }
            subdirs = rhs.subdirs;
        }
        return *this;
    }
    
    int exists(char* name)
    {
        for (int i = 0; i < subdirs.size(); i++)
        {
            if (name == subdirs[i]->name)
            {
                return i;
            }
        }
        return -1;
    }
    void printdir()
    {
        printf("%s\n",path.c_str());
    }
    
    void listdirs()
    {
        std::vector<std::string> temp;
        for (int i = 0; i < subdirs.size(); i++)
        {
            temp.push_back(subdirs[i]->name);
        }
        std::sort(temp.begin(), temp.end());
        for (int i = 0; i < temp.size(); i++)
        {
            printf("%s ",temp[i].c_str());
        }
        std::cout<<std::endl;
    }
    
    void makeadir(char* name)
    {
        if (exists(name) >= 0)
        {
            printf("%s\n","Directory already exists");
            return;
        }
        
        Directory* temp = new Directory(name);
        temp->path = (path + name) + "/";
        temp->parent = this;
        subdirs.push_back(temp);
    }
};

class UbuntuTwoPointO
{
    Directory* root = new Directory;
    Directory* current = root;
    
    void mkdir(char* name)
    {
       if (current)
       {
           current->makeadir(name);
       }
    }
    void ls()
    {
       if (current)
       {
           current->listdirs();
       }
    }
    void pwd()
    {
        printf("%s\n", current->path.c_str());
    }
    void cd(char* name)
    {
        if (current)
        {
            int index = current->exists(name);
            if (index >= 0)
            {
                current = current->subdirs[index];
            }
            else if (!strcmp(name,".."))
            {
                if (current == root)
                {
                    printf("%s\n","No such directory");
                }
                else
                {
                    current = current->parent;
                }

            }
            else 
            {
                printf("%s\n","No such directory");
            }
        }
    }
    
public:
    UbuntuTwoPointO()
    {
        root->parent = nullptr;
    }
    ~UbuntuTwoPointO()
    {
        delete root;  
    }
    
    void getcommand(char* cmd)
    {
        if (!strcmp(cmd,"mkdir"))
        {
            char* dirname = new char[100];
            scanf("%s",dirname);
            mkdir(dirname);
        }
        else if (!strcmp(cmd,"cd"))
        {
            char* dirname = new char[100];
            scanf("%s", dirname);
            cd(dirname);
        }
        else if (!strcmp(cmd,"ls"))
        {
            ls();
        }
        else if (!strcmp(cmd,"pwd"))
        {
            pwd();
        }
    }
    
};

int main() {
    int N;
    char* command = new char[5];
    UbuntuTwoPointO sys;
    std::cin>>N;
    for (int i = 0; i < N; i++)
    {
        scanf("%s",command);
        sys.getcommand(command);
    }
    return 0;
}
