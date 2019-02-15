#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main()
{
    std::ifstream fin;
    fin.open("poem.txt");
    if (!fin.is_open())
    {
        std::cout << "File isn't opened!\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        fin.seekg(0, fin.end);
        int length = fin.tellg();
        char * buffer = new char [length];
        fin.seekg (0, fin.beg);
        fin.read (buffer, length);
        fin.close();

        std::ofstream fout;
        fout.open("result.txt");
        if (!fout.is_open())
        {
            std::cout << "Can't open result.txt file! " << std::endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            int count =0;
            for (int i=0; i<length; i++)
            {
                if (buffer[i]=='a' || buffer[i]=='A' )
                {
                    buffer[i] = 'X';
                    count++;
                }
            }
           std::cout << "Content from file poem.txt copied to result.txt " << std::endl
                     <<  count << " \'A\' letters found and replaced with \'X\'" << std::endl;
           fout.write (buffer, length);
        }
        fout.close();
        
        delete [] buffer;
    }
return 0;

}