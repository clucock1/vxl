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
    std::string path = "C:/Users/cynthia.lucock/projects/vxl_fix_warnings/rpb_files/09DEC06145803-P1BS-052869858050_01_P002.imd";
    std::ifstream istr(path.c_str());
    std::string line;
    std::ostringstream ss;
    if (!istr)
        std::cout << "couldn't open " << path << std::endl;
    else {
#if 0
        while (istr >> line) {
            ss << line;
        }
#endif

        //size_t pos;
        while (getline(istr, line)) {
            std::stringstream s(line);
            while (s >> line)
                ss << line;
            //while ((pos = line.rfind(' ')) != std::string::npos || (pos = line.rfind('\t')) != std::string::npos)
                //line.erase(pos, 1);

            ss << "\\n";
        }
    }
    istr.close();

    std::string file_string = ss.str();
    std::string opath = "C:/Users/cynthia.lucock/projects/vxl_fix_warnings/vxl/output.cxx";
    std::ofstream ostr(opath);
    if (!ostr)
        std::cout << "Not Open. Can't write to " << opath << std::endl;
    else {
        ostr << file_string;
    }
    std::cout << file_string << std::endl;
    ostr.close();
        
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