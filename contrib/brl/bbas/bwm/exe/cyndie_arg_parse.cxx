//:
// \file

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#ifdef _MSC_VER
#  include <vcl_msvc_warnings.h>
#endif
#include <vul/vul_arg.h>
#include <vul/vul_awk.h>


int main(int argc, char** argv)
{
    //Get Inputs
    vul_arg<std::string> my_args("-external_list", "import this file", "");
    vul_arg_parse(argc, argv);

    if (argc==1)
        std::cout << "\nNo Extra Command Line Argument Passed Other Than Program Name" << std::endl;
    if (argc >= 2) {
        std::cout << "You have entered " << argc << " arguments:" << std::endl;
        for (size_t i = 0; i < argc; ++i)
            std::cout << argv[i] << std::endl;
    }

    std::cout << std::endl << my_args() << std::endl;
    std::cout << "Help: " << my_args.help() << std::endl << std::endl;
    return 0;
}