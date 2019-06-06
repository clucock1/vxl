#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>
#include <testlib/testlib_test.h>
#include <vpl/vpl.h>
#include <brad/brad_synoptic_function_1d.h>
#ifdef _MSC_VER
#  include <vcl_msvc_warnings.h>
#endif

std::string get_file_string(std::string const& old_filename) {
    std::map< std::string, std::string> str;
    str["intensities_and_viewing_direction_e2.txt"] = "24\n0.500640153885 0.188846230507 0.195836216211\nf:/visdt/imgs24/gray00000.png 0.410751491785 0.0 0.917190015316 -1.81514453888\nf:/visdt/imgs24/gray00008.png 0.420796126127 0.0 0.936841130257 -2.00864839554\nf:/visdt/imgs24/gray00016.png 0.727476298809 0.0 0.949710190296 -2.18946027756\nf:/visdt/imgs24/gray00024.png 0.660150468349 0.0 0.935442686081 -2.36588954926\nf:/visdt/imgs24/gray00032.png 0.495411098003 1.0 0.926198244095 -2.55628561974\nf:/visdt/imgs24/gray00040.png 0.374299436808 0.0 0.915629267693 -2.76906490326\nf:/visdt/imgs24/gray00048.png 0.492439597845 0.0 0.916465461254 -3.01363134384\nf:/visdt/imgs24/gray00056.png 0.68290668726 0.0 0.937422037125 3.01445126534\nf:/visdt/imgs24/gray00064.png 0.459437161684 1.0 0.95524585247 2.75502920151\nf:/visdt/imgs24/gray00072.png 0.413786739111 0.0 0.955038130283 2.49440145493\nf:/visdt/imgs24/gray00080.png 0.327320516109 1.0 0.943713247776 2.22599315643\nf:/visdt/imgs24/gray00088.png 0.702314794064 1.0 0.928665816784 1.94778835773\nf:/visdt/imgs24/gray00096.png 0.421851783991 1.0 0.887159645557 1.66301167011\nf:/visdt/imgs24/gray00104.png 0.503881812096 1.0 0.830793678761 1.37333214283\nf:/visdt/imgs24/gray00112.png 0.245664387941 1.0 0.788625299931 1.04162573814\nf:/visdt/imgs24/gray00120.png 0.232401952147 1.0 0.762027144432 0.68328666687\nf:/visdt/imgs24/gray00128.png 0.43972876668 1.0 0.734198153019 0.335130751133\nf:/visdt/imgs24/gray00136.png 0.264066934586 1.0 0.70750939846 -0.0026384901721\nf:/visdt/imgs24/gray00144.png 0.661407053471 1.0 0.699641466141 -0.356669425964\nf:/visdt/imgs24/gray00152.png 0.657326459885 1.0 0.729472637177 -0.712199389935\nf:/visdt/imgs24/gray00160.png 0.629395127296 1.0 0.770127594471 -1.03422188759\nf:/visdt/imgs24/gray00168.png 0.628298282623 1.0 0.797587811947 -1.30552625656\nf:/visdt/imgs24/gray00176.png 0.559312999249 1.0 0.816478788853 -1.5184237957\nf:/visdt/imgs24/gray00180.png 0.58959710598 1.0 0.821681082249 -1.59775292873\n";
    return str[old_filename];
}

static void write_file_strings_to_tempfiles(std::string const& temp_filename, std::string const& image_name) {
    std::stringstream ss;
    std::string s0 = get_file_string(image_name);

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

static void test_synoptic_function()
{
  START("synoptic function test");
  std::string image_name = "intensities_and_viewing_direction_e2.txt"; // Name of image file
  write_image_to_files(image_name);
  brad_synoptic_function_1d sf;
  std::string temp_file = "./" + image_name;
  if(!sf.load_samples((temp_file).c_str()))
      return;
  //if(!sf.load_samples("E:/mundy/CVGroup/Nibbler/Notes/Experiments/intensities_and_viewing_direction_e2.txt"))
  
#if 1
  unsigned n = sf.size();
  for (unsigned i = 0; i<n; ++i){
    double s = sf.arc_length(i);

    std::cout << s << ' ' << sf.intensity(i)
             << ' ' << sf.cubic_interp_inten(s)<< ' ' << sf.vis(i) <<  '\n';
  }
  std::cout << "Fit Sigma " << sf.cubic_fit_sigma() <<'\n';
  std::cout << "Effective N obs " << sf.effective_n_obs() << '\n';
  std::cout << "Prob density " << sf.cubic_fit_prob_density() << '\n';
#endif

  sf.compute_auto_correlation();
  std::vector<double> corr = sf.auto_correlation();
  unsigned nc = corr.size();
  std::cout << "Autocorrelation function \n";
  for (unsigned i = 0; i<nc; ++i){
    double s = sf.arc_length(i);

    std::cout << s << ' ' << corr[i] <<  '\n';
  }
#if 1
  sf.fit_linear_const();
  std::cout << "tau_s " << sf.tau_s() << '\n';
  std::cout << "alpha " << sf.alpha() << '\n';
  std::cout << "mu " << sf.mu() << '\n';
  std::cout << "lin const sigma " << sf.lin_const_fit_sigma() << '\n';
  sf.set_inherent_data_sigma(0.348);
  std::cout << "lin const prob density " << sf.lin_const_fit_prob_density() << '\n';
#endif

#if 1
  std::cout << " Frequency Amplitudes\n";
  std::vector<double> freq_amps;
  sf.auto_corr_freq_amplitudes(freq_amps);
  for(unsigned i = 0; i<freq_amps.size(); ++i)
    std::cout << i << ' ' << freq_amps[i] << '\n';
  std::cout << "Max Frequency Prob. Density\n" << sf.max_frequency_prob_density() << '\n';
#endif

  vpl_unlink(temp_file.c_str());
}
TESTMAIN( test_synoptic_function );
