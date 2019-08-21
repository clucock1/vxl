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


//:
// An executable that projects polygons into a list of images
// and writes to disk the pixel location within the polygon as well
// as the intensity at those pixels
int main(int argc, char** argv)
{
    //Get Inputs
    vul_arg<std::string> my_first_args("-cyndie_list", "this is not my name", "");
    vul_arg<std::string> my_next_args("-next_list", "learn to count", "");
    vul_arg<std::string> my_final_args("-my_list", "get help here", "");
    vul_arg_parse(argc, argv);

    if (argc==1)
        std::cout << "\nNo Extra Command Line Argument Passed Other Than Program Name" << std::endl;
    if (argc >= 2) {
        std::cout << "You have entered " << argc << " arguments:" << std::endl;
        for (size_t i = 0; i < argc; ++i)
            std::cout << argv[i] << std::endl;
    }

    std::cout << std::endl << my_first_args() << std::endl;
    std::cout << "Help: " << my_first_args.help() << std::endl << std::endl;
    std::cout << my_next_args() << std::endl;
    std::cout << "Help: " << my_next_args.help() << std::endl << std::endl;
    std::cout << my_final_args() << std::endl;
    std::cout << "Help: " << my_final_args.help() << std::endl << std::endl;

    return 0;
}