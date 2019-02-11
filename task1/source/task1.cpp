#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string.h>

void writeToFile();
void showFromFile();

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    std::ifstream fin;
    fin.open("text.txt");
    if (fin.is_open())
    {
        std::string line;
        cout << "Here is the content of text.txt file: " << endl << endl;
        while (std::getline (fin, line))
        {
            cout << line << endl;
        }
        fin.close();        
    }
    
    writeToFile();
    showFromFile();
    

    return 0;
}


void writeToFile ()
{
    std::ofstream fout;
    fout.open("text.txt");
    
    std::string line = "";
    std::vector<std::string> lines;
    do 
    {
       std::getline (std::cin, line);
       if (line.size()>0)
       {
          lines.push_back(line);
       }
    }while(line !="");
    
    for (int i=0; i<lines.size(); i++)
       {
           fout << lines[i] << std::endl;
       }
    fout.close();
}
void showFromFile()
{
    std::ifstream fin;
    std::string line;
    fin.open("text.txt");
    if (!fin.is_open())
    {
        std::cout << "Can't open file\n";
        exit (EXIT_FAILURE);
    }
    else
    {
        do
        {
            std::getline(fin, line);
            std::cout << line << std::endl;
        } while (line != "");
    }
    if (fin.eof())
    {
        fin.close();
    }
}