// This is brl/bseg/betr/tests/test_event_trigger.cxx
#include <iostream>
#include <fstream>
#include <testlib/testlib_test.h>
#include <betr/betr_geo_box_3d.h>
#include <betr/betr_geo_object_3d.h>
#include <vsol/vsol_spatial_object_3d.h>
#include <vsol/vsol_polygon_3d.h>
#include <vsol/vsol_box_3d.h>
#include <betr/betr_io.h>
#include <betr/vsol_mesh_3d.h>
#include <betr/vsol_mesh_3d_sptr.h>
#include <vsol/vsol_point_3d.h>
#include <vpgl/vpgl_lvcs.h>
#include <betr/betr_kml_utils.h>
#include <betr/betr_event_trigger.h>
#include <vpl/vpl.h>
#include <vpgl/vpgl_local_rational_camera.h>
#include <vpgl/vpgl_camera_double_sptr.h>
#include <vpgl/vpgl_camera.h>

std::string get_file_strings(std::string const& old_filename) {
    std::map< std::string, std::string> strings;
    strings["09DEC06145803-P1BS-052869858050_01_P002_bin_2.rpb"] = "satId = \"????\";\nbandId = \"RGB\";\nSpecId = \"RPC00B\";\nBEGIN_GROUP = IMAGE\n\n\n  lineOffset = 5109\n  sampOffset = -8047\n  latOffset = -33.4374\n  longOffset = -70.6439\n  heightOffset = 922\n  lineScale = 16828\n  sampScale = 17456\n  latScale = 0.08\n  longScale = 0.0959\n  heightScale = 501\n  lineNumCoef = (\n    -0.00264594,\n    0.04373632,\n    1.05604,\n    -0.01132939,\n    -0.0004755171,\n    1.047585e-005,\n    8.342535e-005,\n    -0.0003730049,\n    0.001854732,\n    -2.768628e-007,\n    -2.919091e-007,\n    3.89137e-007,\n    4.417434e-006,\n    3.622769e-007,\n    4.40662e-006,\n    3.690352e-005,\n    8.724782e-006,\n    -9.940829e-008,\n    -4.703967e-007,\n    -9.233629e-008);\n  lineDenCoef = (\n    1,\n    0.0006341695,\n    0.0008535553,\n    -0.0001185298,\n    -5.202248e-006,\n    1.178422e-007,\n    8.999336e-007,\n    5.927408e-006,\n    -2.176137e-005,\n    8.245444e-006,\n    -4.43691e-008,\n    0,\n    2.008929e-006,\n    0,\n    1.571993e-007,\n    1.30458e-005,\n    0,\n    0,\n    -4.168984e-007,\n    0);\n  sampNumCoef = (\n    -0.002787494,\n    -1.014879,\n    -0.0001342559,\n    -0.01222411,\n    -0.001193823,\n    -0.0003057016,\n    0.000109006,\n    0.002639235,\n    -0.000115734,\n    -4.360195e-006,\n    -5.144666e-007,\n    -4.510677e-008,\n    1.077331e-005,\n    2.743729e-006,\n    -5.15557e-006,\n    4.865478e-005,\n    7.309242e-008,\n    1.645469e-006,\n    -1.411975e-006,\n    3.371315e-008);\n  sampDenCoef = (\n    1,\n    -0.0001543312,\n    -0.001211336,\n    -0.0003444029,\n    -7.369097e-006,\n    1.043191e-006,\n    -1.026206e-006,\n    1.776887e-006,\n    7.241381e-006,\n    -2.858965e-006,\n    -1.091991e-008,\n    -1.171952e-008,\n    -1.790362e-007,\n    0,\n    8.741243e-008,\n    -1.159687e-007,\n    0,\n    0,\n    1.188762e-008,\n    0);\nEND_GROUP = IMAGE\nEND;\nlvcs\n-70.692764\n-33.458862\n530\n";
    strings["mesh_0.ply"] = "ply\nformat ascii 1.0\ncomment mesh-feature\nobj_info a bmsh3d_mesh object\nelement vertex 5\nproperty double x\nproperty double y\nproperty double z\nelement face 1\nproperty list uchar int vertex_indices\nend_header\n235.8696284389948200 406.1228461892747500 9.6798152424242456 \n223.5715434156161300 450.5470718703127800 9.6798152424242456 \n191.7069643406025800 444.0498655036974500 9.6798152424242456 \n196.8278478137980300 421.6872655445207600 9.6798152424242456 \n202.9746837489035700 396.9806647746743200 9.6798152424242456 \n5 0 4 3 2 1 \n";
    strings["mesh_1.ply"] = "ply\nformat ascii 1.0\ncomment mesh-feature\nobj_info a bmsh3d_mesh object\nelement vertex 5\nproperty double x\nproperty double y\nproperty double z\nelement face 1\nproperty list uchar int vertex_indices\nend_header\n146.1171943827043800 429.1333838455852300 3.8836995690295124 \n139.2825252680649700 449.8591446870622100 3.8836995690295124 \n91.3167515951369780 440.2827566788528800 3.8836995690295115 \n108.0650610929029900 394.7929440913377400 3.8836995690295120 \n146.7831158857193000 405.1760185076439000 3.8836995690295115 \n5 0 4 3 2 1 \n";
    strings["mesh_2.ply"] = "ply\nformat ascii 1.0\ncomment mesh-feature\nobj_info a bmsh3d_mesh object\nelement vertex 16\nproperty double x\nproperty double y\nproperty double z\nelement face 10\nproperty list uchar int vertex_indices\nend_header\n326.2725903279762200 502.9914457441568600 20.3883225176187860 \n320.4649557932071400 524.3666028204756900 20.3883225176187860 \n303.6748154362448400 519.9666438544760500 20.3883225176187860 \n300.5967163396496700 526.6657236635290900 20.3883225176187860 \n284.4927055041528100 523.2531142478948100 20.3883225176187820 \n286.5430187961817400 516.5698639010671500 20.3883225176187820 \n245.0820551945385000 504.8974165798779300 20.3883225176187710 \n250.2021435317453500 481.2046632366960900 20.3883225176187640 \n326.2725903279762200 502.9914457441568600 3.3783225176187841 \n320.4649557932071400 524.3666028204756900 3.3783225176187841 \n303.6748154362448400 519.9666438544760500 3.3783225176187841 \n300.5967163396496700 526.6657236635290900 3.3783225176187841 \n284.4927055041528100 523.2531142478948100 3.3783225176187841 \n286.5430187961817400 516.5698639010671500 3.3783225176187841 \n245.0820551945385000 504.8974165798779300 3.3783225176187699 \n250.2021435317453500 481.2046632366960900 3.3783225176187628 \n8 1 2 3 4 5 6 7 0 \n8 9 10 11 12 13 14 15 8 \n4 1 9 8 0 \n4 2 10 9 1 \n4 3 11 10 2 \n4 4 12 11 3 \n4 5 13 12 4 \n4 6 14 13 5 \n4 7 15 14 6 \n4 0 8 15 7 \n";
    return strings[old_filename];
}

static void write_file_strings_to_tempfiles(std::string const& temp_filename, std::string const& image_name) {
  std::stringstream ss;
  std::string s0 = get_file_strings(image_name);

  std::ofstream ostr0(temp_filename.c_str());
  if (!ostr0)
    std::cout << "Not Open. Can't write to " << temp_filename << std::endl;
  if (ostr0) {
    ss << s0;
    ostr0 << ss.str();
    ostr0.close();
    ss.str(std::string()); // Empty stringstream
  }
}

static void write_image_to_files(std::string const& image_name) {
    std::string temp = "./" + image_name;
    write_file_strings_to_tempfiles(temp, image_name);
}


void test_event_trigger()
{
  std::string files[] = {"09DEC06145803-P1BS-052869858050_01_P002_bin_2.rpb",
                         "mesh_0.ply",
                         "mesh_1.ply",
                         "mesh_2.ply"};

  unsigned n = 4; // Number of image files
  for (size_t i = 0; i < n; ++i) {
      write_image_to_files(files[i]);
  }

  //create vsol_spatial_object_3d directly from polygon vertices
  vsol_point_3d_sptr p0 = new vsol_point_3d(235.8696284389948200, 406.1228461892747500, 9.6798152424242456);
  vsol_point_3d_sptr p1 = new vsol_point_3d(223.5715434156161300, 450.5470718703127800, 9.6798152424242456);
  vsol_point_3d_sptr p2 = new vsol_point_3d(191.7069643406025800, 444.0498655036974500, 9.6798152424242456);
  vsol_point_3d_sptr p3 = new vsol_point_3d(196.8278478137980300, 421.6872655445207600, 9.6798152424242456);
  vsol_point_3d_sptr p4 = new vsol_point_3d(202.9746837489035700, 396.9806647746743200, 9.6798152424242456);
  std::vector<vsol_point_3d_sptr> verts_ref;
  verts_ref.push_back(p0);   verts_ref.push_back(p1);   verts_ref.push_back(p2);
  verts_ref.push_back(p3);   verts_ref.push_back(p4);
  auto* poly_3d_ref = new vsol_polygon_3d(verts_ref);
  vsol_spatial_object_3d_sptr so_3d_ref = poly_3d_ref;
  vsol_point_3d_sptr pe0 = new vsol_point_3d(146.1171943827043800, 429.1333838455852300, 3.8836995690295124);
  vsol_point_3d_sptr pe1 = new vsol_point_3d(139.2825252680649700, 449.8591446870622100, 3.8836995690295124);
    vsol_point_3d_sptr pe2 = new vsol_point_3d(91.3167515951369780, 440.2827566788528800, 3.8836995690295115);
  vsol_point_3d_sptr pe3 = new vsol_point_3d(108.0650610929029900, 394.7929440913377400, 3.8836995690295120);
  vsol_point_3d_sptr pe4 = new vsol_point_3d(146.7831158857193000, 405.1760185076439000, 3.8836995690295115);

  std::vector<vsol_point_3d_sptr> verts_evt;
  verts_evt.push_back(pe0);   verts_evt.push_back(pe1);   verts_evt.push_back(pe2);
  verts_evt.push_back(pe3);   verts_evt.push_back(pe4);
  auto* poly_3d_evt = new vsol_polygon_3d(verts_evt);
  vsol_spatial_object_3d_sptr so_3d_evt = poly_3d_evt;
  //std::string img_dir = "D:/tests/chiletest/crop_dir/";
  std::string img_dir = "./";
  std::string image_name = "09DEC06145803-P1BS-052869858050_01_P002_bin_2";
  std::string cam_path = img_dir + image_name + ".rpb";
  vpgl_local_rational_camera<double>* lcam = read_local_rational_camera<double>(cam_path);
  vpgl_lvcs lvcs = lcam->lvcs();
  vpgl_camera_double_sptr camera = lcam;
  betr_event_trigger etr;
  etr.set_lvcs(lvcs);
  etr.set_ref_camera(camera);
  etr.set_evt_camera(camera);
  betr_geo_object_3d_sptr ref_obj = new betr_geo_object_3d(so_3d_ref, lvcs);
  betr_geo_object_3d_sptr evt_obj = new betr_geo_object_3d(so_3d_evt, lvcs);
  std::string ref_name = "ref_region", evt_name = "evt_region";
  etr.add_geo_object(ref_name, ref_obj, true);
  etr.add_geo_object(evt_name, evt_obj, false);
  vsol_polygon_2d_sptr ref_poly_2d, evt_poly_2d;
  bool good = etr.project_object(camera,ref_name, ref_poly_2d);
  good = good&& etr.project_object(camera,evt_name, evt_poly_2d);
  //load vsol_spatial_object_3d from ply files
  //std::string site_dir = "D:/tests/chiletest/site/chile-illum_objects/";
  std::string site_dir = "./";
  std::string obj0_path = site_dir + "mesh_0.ply";
  std::string obj1_path = site_dir + "mesh_1.ply";
  std::string obj2_path = site_dir + "mesh_2.ply";
  vsol_spatial_object_3d_sptr so_ply_ref, so_ply_evt, so_ply_3d;
  betr_io::read_so_ply(obj0_path, so_ply_ref);
  betr_io::read_so_ply(obj1_path, so_ply_evt);
  betr_io::read_so_ply(obj2_path, so_ply_3d);
  betr_geo_object_3d_sptr ply_ref_obj = new betr_geo_object_3d(so_ply_ref, lvcs);
  betr_geo_object_3d_sptr ply_evt_obj = new betr_geo_object_3d(so_ply_evt, lvcs);
  betr_geo_object_3d_sptr ply_3d_obj = new betr_geo_object_3d(so_ply_3d, lvcs);
  betr_event_trigger etr_ply;
  etr_ply.set_lvcs(lvcs);
  etr_ply.set_ref_camera(camera);
  etr_ply.set_evt_camera(camera);
  ref_name = "ply_ref_region"; evt_name = "ply_evt_region";
  std::string name_3d ="mesh_volume";
  etr_ply.add_geo_object(ref_name, ply_ref_obj, true);
  etr_ply.add_geo_object(evt_name, ply_evt_obj, false);
  etr_ply.add_geo_object(name_3d, ply_3d_obj, false);
  vsol_polygon_2d_sptr ply_ref_poly_2d, ply_evt_poly_2d, ply_mesh_poly_2d;
  good = etr_ply.project_object(camera,ref_name, ply_ref_poly_2d);
  good = good&& etr_ply.project_object(camera,evt_name, ply_evt_poly_2d);
  good = good&& etr_ply.project_object(camera,name_3d, ply_mesh_poly_2d);

  for (size_t i = 0; i < n; ++i) {
    std::string temp_file = "./" + files[i];
    vpl_unlink(temp_file.c_str());
  }
}
TESTMAIN(test_event_trigger);
