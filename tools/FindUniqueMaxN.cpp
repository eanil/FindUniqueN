#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

#include "../src/FindUniqueMax.h"

int main(int argc, char *argv[])
{
    const char *kInputFileOption{"inputFile"};
    const char *kNOption{"n"};

    // File to read if a file is specified
    boost::filesystem::path inputFile;
    // the number of top records to return
    unsigned int uniquen{1};

    namespace po = boost::program_options;
    po::options_description desc("Options");

    // clang-format off
    desc.add_options()
                    ("help,h", "Prints this help message.")
                    (kInputFileOption, po::value<boost::filesystem::path>(&inputFile), 
                     "Optional input file. Reads from stdin if not specified.")
                    (kNOption, po::value<unsigned int>(&uniquen)->default_value(uniquen), 
                     "Returns N largest values.");
    // clang-format on

    po::variables_map vm;
    po::store(parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        return EXIT_SUCCESS;
    }

    std::vector<std::string> p;

    if (vm.count(kInputFileOption))
    {
        // check if file exists
        if (!boost::filesystem::exists(inputFile))
        {
            std::cerr << inputFile << " does not exist." << std::endl;
            return EXIT_FAILURE;
        }

        std::ifstream stream(inputFile.string().c_str(), std::ios::in);
        try
        {
            p = FindUniqueMaxN(stream, uniquen);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }
    else
    {
        try
        {
            p = FindUniqueMaxN(std::cin, uniquen);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }

    std::for_each(p.begin(), p.end(), [](const auto &s) {
        std::cout << s << std::endl;
    });

    return EXIT_SUCCESS;
}
