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
    std::string st;
    std::stringstream ss;
    std::istringstream sstr;
    if (!istr)
        std::cout << "couldn't open " << path << std::endl;
    else {
  //      st.assign((std::istreambuf_iterator<char>(istr)),
  //                 std::istreambuf_iterator<char>());

        while (getline(istr, line)) {
            ss << line;
            ss << "\\n";
            //sstr.str(line);
            //st += line + "\\n";
        }
        //sstr.str(st);
    } 

    std::string file_string = ss.str();
    std::cout << file_string << std::endl;

    std::string opath = "C:/Users/cynthia.lucock/projects/vxl_fix_warnings/vxl/output.cxx";
    std::ofstream ostr(opath);
    if (!ostr)
        std::cout << "Not Open. Can't write to " << opath << std::endl;
    else {
#if 0
        for (size_t i = 0; i < st.length(); ++i) {
            if (st[i] == '\n') {
                st.replace(i, 1, "\\n");
            }
        }
#endif
        //ostr << st;
        ostr << file_string;
    }
        
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
//    std::cout << st << std::endl;
    return 0;
}