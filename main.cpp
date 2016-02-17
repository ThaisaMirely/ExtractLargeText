#include <sys/stat.h>
#include <vector>
#include <fstream>
#include <iostream>


using namespace std;


void show_usage()
{
    cerr << "\t --- extract text from the input file --- \n"
    << "Enter the input text, the name of the output file, "
    << "and the size in kilobytes of text you want to extract the input file\n"
    << "\t Example: $glf input.txt output.txt 1024"
    << std::endl;
}

size_t GetSizeFile(const char* file_name)
{
    ifstream file(file_name);
    size_t length = 0;
    file.seekg(0, ios::end);
    length = file.tellg();
    file.seekg(0, ios::beg);
    return length;
}


bool is_file(const char* name)
{
    struct stat buffer;
    return (stat (name, &buffer) == 0);
}


void create_file(vector<string> data)
{
    if(data.size() == 3 && is_file(data[0].c_str()))
    {
        size_t position = stoi(data[2]);

        if(GetSizeFile(data[0].c_str()) > position)
        {
            
            ifstream input_file(data[0].c_str());
            ofstream output_file(data[1].c_str(), ios::app);
            output_file.clear();
            string line;
            
            long long  tll = input_file.tellg();
            
            while (tll < position)
            {
                getline(input_file, line);
                output_file << line;
                tll = input_file.tellg();
            }
            
            input_file.close();
            output_file.close();
            
            cout << "Successfully generated file \n";

        }
        else
        {
            cerr << " --- FILE INPUT LOWER THAN SIZE FOR EXTRACTION DATA --- \n"
            << std::endl;
        }
    }
    else
    {
        show_usage();
    }
}


int main(int argc, char* argv[])
{
    vector<string> data;
    for (int i = 1; i < argc; ++i)
    {
        string arg = argv[i];
        if ((arg == "-h") || (arg == "--help"))
        {
            show_usage();
        }
        else
        {
            data.push_back(argv[i]);
        }
    }
    
    if (!data.empty()) {
        create_file(data);
    }
    return 0;
}
