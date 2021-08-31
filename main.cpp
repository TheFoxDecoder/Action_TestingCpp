#include <iostream>
#include "i_o_Benchmarks.hpp"

int main(int argc, char* argv[]){
    std::vector<std::string> args(argv, argv + argc);
    if (args.size() != 4)
    {
        std::cout << "Usage: " << args[0] << " copy_method (c, posix, c++) in_file number_of_times" << std::endl;
        return 1;
    }

    typedef std::map<std::string, std::function<void (const char*, const char*, std::vector<char>&)>> FuncMap;
    FuncMap funcMap { {"c", testCFileIO}, {"posix", testPosixIO}, {"c++", testCppIO}};

    auto it = funcMap.find(args[1]);
    if (it != funcMap.end())
    {       
        std::vector<char> inBuffer(1024 * 1024);
        
        auto dest = args[2] + ".copy";
        const auto times = std::stoul(args[3]);
        
        milliseconds::rep total = 0;
        for (unsigned int i = 0; i < times; ++i)
        {
            total += measure::ms(it->second, args[2].c_str(), dest.c_str(), inBuffer);
            ::unlink(dest.c_str());
        }
        std::cout << "Average " << args[1] << " I/O took: " << total / double(times) << "ms" << std::endl;
    }
    else
    {
        std::cout << "Not supported copy method: " << args[1] << std::endl;
    }    
}