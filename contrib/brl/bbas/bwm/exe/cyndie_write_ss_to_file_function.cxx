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
        while (s >> line) {
            size_t pos = line.find('"');
            while (pos != std::string::npos) {
                line.insert(pos, "\\");
                pos = line.find('"', pos + 2);
            }
            out_stream << line;
        }           
        out_stream << "\\n";
    }
}

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
    std::string path = "C:/Users/cynthia.lucock/projects/vxl_fix_warnings/rpb_files/09DEC06145803-P1BS-052869858050_01_P002.imd";
    std::ifstream istr(path.c_str());
    std::string line;
    std::ostringstream ss;
    if (!istr)
        std::cout << "couldn't open " << path << std::endl;
    else {
        read_from_stream(istr, ss);
        istr.close();
    }

    std::string file_string = ss.str();
    std::string opath = "C:/Users/cynthia.lucock/projects/vxl_fix_warnings/vxl/output.cxx";
    std::ofstream ostr(opath);
    if (!ostr)
        std::cout << "Not Open. Can't write to " << opath << std::endl;
    else {
        std::string map_info = "std::string get_file_strings(std::string const& old_filename) {\n    std::map< std::string, std::string> strings;\n";
        ostr << map_info;
        std::string filename = get_filename_from_path(path);
        write_map_info_to_stream(ostr, filename);
        ostr << '"' << file_string << '"' << ";\n    return strings[old_filename];\n}";
        ostr.close();
    }

    std::cout << file_string << std::endl;
 
    return 0;
}