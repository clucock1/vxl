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

static void read_from_stream(std::ifstream& in_stream, std::ostringstream& out_stream)
{
    std::string line;

    while (getline(in_stream, line)) {
        std::stringstream s(line);
        std::string token;
        while (s >> token) {
            size_t pos = token.find('"');
            while (pos != std::string::npos) {
                token.insert(pos, "\\");
                pos = token.find('"', pos + 2);
            }
            out_stream << token << " ";
        }
        out_stream.seekp(-1, std::ios_base::end);

        out_stream << "\\n";
    }
}

#if 0
std::stringstream s(line); // create a sstream out of the line from the file
std::string token; // the token from line ( a token is a string separeted by either space or CR
while (s >> token) {

    out_stream << token << " ";
    std::string::size_type quote_location = token.find("\"");
    if (quote_location != std::string::npos) {
        token.replace(quote_location, 1, "\\");
    }
}
out_stream.seekp(-1, std::ios_base::end);

out_stream << line << "\\n";
#endif

static void write_map_info_to_stream(std::ofstream& out_stream, std::string& filename)
{
    std::string strings_info = "    strings[\"";
    std::string end_info = "\"] = ";
    out_stream << strings_info << filename << end_info;
}

static std::string get_filename_from_path(std::string& path)
{
    size_t found = path.find_last_of("/");
    return path.substr(found + 1);
}

int main(int argc, char** argv)
{
    //Get Inputs
    std::vector<std::string> path;
    path.push_back("C:/Users/cynthia.lucock/projects/vxl_fix_warnings/rpb_files/09DEC06145803-P1BS-052869858050_01_P002.imd");
    path.push_back("C:/Users/cynthia.lucock/projects/vxl_fix_warnings/rpb_files/09DEC06145803-P1BS-052869858050_01_P002_bin_2.rpb");
    path.push_back("C:/Users/cynthia.lucock/projects/vxl_fix_warnings/rpb_files/09DEC06145817-P1BS-052869840050_01_P002.imd");
    path.push_back("C:/Users/cynthia.lucock/projects/vxl_fix_warnings/rpb_files/09DEC06145817-P1BS-052869840050_01_P002_bin_2.rpb");
    path.push_back("C:/Users/cynthia.lucock/projects/vxl_fix_warnings/rpb_files/09DEC06145817-P1BS-500060999100_01_P002.imd");
    path.push_back("C:/Users/cynthia.lucock/projects/vxl_fix_warnings/rpb_files/09DEC06145817-P1BS-500060999100_01_P002_bin_2.rpb");

    //std::ifstream istr(path[0].c_str());
    std::string line;
    std::ostringstream ss;
    std::string opath = "C:/Users/cynthia.lucock/projects/vxl_fix_warnings/vxl/output_file.cxx";
    std::ofstream ostr(opath);
    std::string ipath = "C:/Users/cynthia.lucock/projects/vxl_fix_warnings/vxl/contrib/brl/bbas/brad/tests/test_belief_prop_utils.cxx";
    std::ifstream istr0(ipath);
    std::string file_string;

    if (!ostr)
        std::cout << "Not Open. Can't write to " << opath << std::endl;
    else if (!istr0)
        std::cout << "Couldn't Open " << ipath << std::endl;

    if (istr0) {
        std::string strOneLine;

        while (getline(istr0, strOneLine)) {
            size_t found = strOneLine.find("#include");
            if (found != std::string::npos)
                ostr << strOneLine << "\n";
            else if (found == std::string::npos)
                break;
        }

        std::string map_info = "\n std::string get_file_strings(std::string const& old_filename) {\n    std::map< std::string, std::string> strings;\n";
        ostr << map_info;

        for (auto vit = path.begin(); vit != path.end(); ++vit)
        {
            std::ifstream istr(*vit);
            if (!istr)
                std::cout << "couldn't open " << *vit << std::endl;
            else {
                read_from_stream(istr, ss);
                istr.close();
            }

            file_string = ss.str();
            std::cout << file_string << std::endl;
            ss.str(std::string());
            if (ostr) {
                std::string filename = get_filename_from_path(*vit);
                write_map_info_to_stream(ostr, filename);
                ostr << '"' << file_string << '"' << ";\n";
            }
        }

        ostr << "    return strings[old_filename];\n}\n";

        while (getline(istr0, strOneLine)) {
            //size_t found = strOneLine.find("#include");
            //if (found == std::string::npos)
                ostr << strOneLine << "\n";
        }

    }
    ostr.close();
    istr0.close();
 
    return 0;
}