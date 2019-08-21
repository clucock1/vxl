//:
// \file

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <string>

#ifdef _MSC_VER
#  include <vcl_msvc_warnings.h>
#endif
#include <vul/vul_arg.h>
#include <vul/vul_awk.h>


int main(int argc, char** argv)
{
    //Get Inputs
    //std::string path = "C:/Users/cynthia.lucock/projects/vxl_fix_warnings/rpb_files/09DEC06145803-P1BS-052869858050_01_P002.imd";
    std::string path = "C:/Users/cynthia.lucock/projects/vxl_fix_warnings/test_dem_appear_files/CL_roi.tif";
    std::ifstream istr(path.c_str());
    std::string line;
    //std::stringstream ss(line);
    std::ostringstream ss;
    if (!istr)
        std::cout << "couldn't open " << path << std::endl;
    else {
        if (istr) {
            ss << istr.rdbuf();
            line = ss.str();
        }
    } 
    std::cout << line << std::endl;

    std::string file_string = ss.str();
    std::string opath = "C:/Users/cynthia.lucock/projects/vxl_fix_warnings/vxl/output.cxx";
    std::ofstream ostr(opath);
    if (!ostr)
        std::cout << "Not Open. Can't write to " << opath << std::endl;
    else {
        ostr << file_string;
    }
    std::cout << file_string << std::endl;

      
#if 0
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
#endif
    return 0;
}