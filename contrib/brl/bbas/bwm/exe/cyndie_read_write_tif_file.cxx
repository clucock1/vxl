//:
// \file

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <string>
#include <imesh/imesh_fileio.h>
#include <imesh/imesh_mesh.h>
#include <vnl/vnl_math.h>
#include <vgl/vgl_box_2d.h>

#ifdef _MSC_VER
#  include <vcl_msvc_warnings.h>
#endif
#include <vil/vil_open.h>
#include <vil/vil_new.h>
#include <vil/vil_load.h>
#include <vil/vil_file_format.h>
#include <vil/vil_stream.h>
#include <vpgl/vpgl_camera.h>
#include <vil/vil_image_view.h>
#include <vil/vil_image_resource.h>
#include <vil/vil_save.h>
#include <vpgl/vpgl_rational_camera.h>
#include <vpgl/vpgl_local_rational_camera.h>
#include <vul/vul_arg.h>
#include <vul/vul_awk.h>

size_t is = 0, js = 0, ie = 0, je = 0;

static void write_map_info_to_stream(std::ofstream& out_stream, std::string& filename)
{
    std::string strings_info = "    strings[\"";
    std::string end_info = "\"] = \"";
    out_stream << strings_info << filename << end_info;
}

static std::string get_filename_from_path(std::string& path)
{
    size_t found = path.find_last_of("/");
    return path.substr(found + 1);
}

static void store_image_section(vgl_box_2d<double>& bb_2d, vil_image_resource_sptr img, std::ofstream& ostr, std::string& filename) {

    filename = filename.substr(filename.find_last_of("-")+1, filename.find_first_of("_") - filename.find_last_of("-") - 1);
    is = bb_2d.min_x(), js = bb_2d.min_y();
    ie = bb_2d.max_x(), je = bb_2d.max_y();
    vil_image_view<float> view0 = img->get_view();
    std::stringstream ss;
    size_t nj = je - js + 1;
    std::string *out = new std::string[nj];
    size_t n = 0;
    //size_t size_of_string = 0;
    //bool string_to_outfile = false;
    ostr << "    std::string " << "TIF_file_" << filename << "[] = {";
    for (size_t j = js; j <= je; ++j){
        for (size_t i = is; i <= ie; ++i) {
            ss << view0(i, j) << ' ';
        }
        out[n] = ss.str();
        ostr << '"' << out[n];
        //ostr << "  TIF_file_" << filename << "[" << n << "] = \"" << out[n];
        ostr.seekp(-1, std::ios_base::end);
        ostr << '"' << ",\n      ";
        //ostr << '"' << ";\n";
        n += 1;
        ss.str(std::string());
    }
    ostr.seekp(-9, std::ios_base::end);
    ostr << "};\n";
#if 0
            size_of_string += out.size();
            if (size_of_string >= 16380) {
                ostr << "    strings[\"" << filename << "_" << n << ".tif\"] = \"" << out;
                std::cout << "n : " << n << " filename : " << filename << "_" << n << std::endl;
                std::cout << "size of " << out << " is " << out.size() << std::endl;
                ostr.seekp(-1, std::ios_base::end);
                ostr << '"' << ";\n";
                i += 1;
                n += 1;
                size_of_string = 0;
                ss.str(std::string());
                string_to_outfile = true;
            }
        }
    if (!string_to_outfile) {
        ostr << "    strings[\"" << filename << "_" << n << ".tif\"] = \"" << out;
        ostr.seekp(-1, std::ios_base::end);
        ostr << '"' << ";\n";
    }
#endif
    ss.seekp(-1, std::ios_base::end);
    ss << '"';
    //ostr << out << ";\n";
    return;
}

int main(int argc, char** argv)
{
    //Get Inputs
    std::vector<std::string> path;
    //path.push_back("C:/Users/cynthia.lucock/projects/vxl_fix_warnings/rpb_files/09DEC06145803-P1BS-052869858050_01_P002_bin_2.rpb");
    //path.push_back("C:/Users/cynthia.lucock/projects/vxl_fix_warnings/rpb_files/09DEC06145817-P1BS-052869840050_01_P002_bin_2.rpb");
    //path.push_back("C:/Users/cynthia.lucock/projects/vxl_fix_warnings/test_dem_appear_files/mesh_5.ply");
    //path.push_back("C:/Users/cynthia.lucock/projects/vxl_fix_warnings/test_dem_appear_files/CL_roi.tif");
    path.push_back("C:/Users/cynthia.lucock/projects/vxl_fix_warnings/test_dem_appear_files/09DEC06145803-P1BS-052869858050_01_P002_bin_2.tif");
    path.push_back("C:/Users/cynthia.lucock/projects/vxl_fix_warnings/test_dem_appear_files/09DEC06145817-P1BS-052869840050_01_P002_bin_2.tif");

    //std::ostringstream ss;
    //std::string opath = "C:/Users/cynthia.lucock/projects/vxl_fix_warnings/vxl/output_test_dem_appear.cxx";
    std::string opath = "C:/Users/cynthia.lucock/projects/vxl_fix_warnings/vxl/output_test_dem_appear_tif.cxx";
    std::ofstream ostr(opath);
    std::string file_string;

    if (!ostr)
        std::cout << "Not Open. Can't write to " << opath << std::endl;
#if 0
    else {
        std::string map_info = "std::string get_file_strings(std::string const& old_filename) {\n    std::map< std::string, std::string> strings;\n";
        ostr << map_info;
    }
#endif

    std::string img_dir = "C:/Users/cynthia.lucock/projects/vxl_fix_warnings/test_dem_appear_files/";
    std::string mesh_dir = "C:/Users/cynthia.lucock/projects/vxl_fix_warnings/test_dem_appear_files/";
    std::string i0p = "09DEC06145803-P1BS-052869858050_01_P002_bin_2.tif";
    std::string c0p = "09DEC06145803-P1BS-052869858050_01_P002_bin_2.rpb";
    std::string i1p = "09DEC06145817-P1BS-052869840050_01_P002_bin_2.tif";
    std::string c1p = "09DEC06145817-P1BS-052869840050_01_P002_bin_2.rpb";

    
    {
        vil_image_resource_sptr img0 = vil_load_image_resource((img_dir + i0p).c_str());
        vpgl_camera<double>* cam0 = read_local_rational_camera<double>(img_dir + c0p);
        vil_image_resource_sptr img1 = vil_load_image_resource((img_dir + i1p).c_str());
        vpgl_camera<double>* cam1 = read_local_rational_camera<double>(img_dir + c1p);

        if (!img0 || !img1 || !cam0 || !cam1)
            return 0;

        imesh_mesh mesh;
        bool good = imesh_read_ply(mesh_dir + "mesh_5.ply", mesh);
        imesh_vertex_array_base& verts = mesh.vertices();
        size_t nverts = verts.size();
        vgl_box_2d<double> bb_2d_0, bb_2d_1;
        std::vector<vgl_point_2d<double> > verts_2d_0, verts_2d_1;
        ostr << "    std::vector<vgl_point_2d<double> > verts_2d_0, verts_2d_1;\n";
        for (size_t i = 0; i < nverts; ++i) {
            double x = verts(i, 0), y = verts(i, 1), z = verts(i, 2);
            double u, v, u1, v1;
            cam0->project(x, y, z, u, v);
            vgl_point_2d<double> v2d(u, v);
            bb_2d_0.add(v2d);
            verts_2d_0.push_back(v2d);
            cam1->project(x, y, z, u1, v1);
            vgl_point_2d<double> v2d1(u1, v1);
            bb_2d_1.add(v2d1);
            verts_2d_1.push_back(v2d1);
            ostr << "    (" << u << ", " << v << ");\n";
            ostr << "    (" << u1 << ", " << v1 << ");\n";
        }
        ostr << "    std::vector<vgl_point_2d<double> > verts_2d_0, verts_2d_1;\n";
        for (size_t i=0; i < verts_2d_0.size(); ++i)
            ostr << "    verts_2d_0.push_back (" << verts_2d_0[i] << ");\n";
        for (size_t i=0; i < verts_2d_1.size(); ++i)
            ostr << "    verts_2d_1.push_back ( " << verts_2d_1[i] << ");\n";

        store_image_section(bb_2d_0, img0, ostr, i0p);
        is = bb_2d_0.min_x(), js = bb_2d_0.min_y();
        ie = bb_2d_0.max_x(), je = bb_2d_0.max_y();
        ostr << "    size_t i0s = " << is << ", j0s = " << js << ";\n";
        ostr << "    size_t i0e = " << ie << ", j0e = " << je << ";\n";
        ostr << "    bb_2d_0: " << bb_2d_0 << "\n";
        store_image_section(bb_2d_1, img1, ostr, i1p);
        is = bb_2d_1.min_x(), js = bb_2d_1.min_y();
        ie = bb_2d_1.max_x(), je = bb_2d_1.max_y();
        ostr << "    size_t i1s = " << is << ", j1s = " << js << ";\n";
        ostr << "    size_t i1e = " << ie << ", j1e = " << je << ";\n";
        ostr << "    bb_2d_1: " << bb_2d_1 << "\n";
    }
    ostr.close();
    return 0;
}