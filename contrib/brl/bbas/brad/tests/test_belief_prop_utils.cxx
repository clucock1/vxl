#include <fstream>
#include <testlib/testlib_test.h>
#include <brad/brad_belief_prop_utils.h>
#include <vil/vil_load.h>
#include <vpgl/vpgl_camera.h>
#include <vil/vil_image_view.h>
#include <vil/vil_save.h>
#include <vpl/vpl.h>
#include <vpgl/vpgl_rational_camera.h>
#include <vpgl/vpgl_local_rational_camera.h>

std::string get_file_strings(std::string const& old_filename) {
    std::map< std::string, std::string> strings;
    strings["09DEC06145803-P1BS-052869858050_01_P002.imd"] = "version = \"23.11\";\ngenerationTime = 2012-12-13T00:26:30.000000Z;\nproductOrderId = \"052869858050_01_P002\";\nproductCatalogId = \"20200100D8BF7900\";\nimageDescriptor = \"Basic1B\";\nbandId = \"P\";\npanSharpenAlgorithm = \"None\";\nnumRows = 33792;\nnumColumns = 35840;\nproductLevel = \"LV1B\";\nproductType = \"Basic\";\nnumberOfLooks = 1;\nradiometricLevel = \"Corrected\";\nbitsPerPixel = 16;\ncompressionType = \"JPEG2000\";\njpegProfileName = \"nga_npje_pan_vl\";\nBEGIN_GROUP = BAND_P\n	ULLon =  -70.54873605;\n	ULLat =  -33.51670435;\n	ULHAE =   725.41;\n	URLon =  -70.73776498;\n	URLat =  -33.51034403;\n	URHAE =   525.79;\n	LRLon =  -70.73735471;\n	LRLat =  -33.35903054;\n	LRHAE =   515.20;\n	LLLon =  -70.54962703;\n	LLLat =  -33.36468487;\n	LLHAE =   905.05;\n	absCalFactor = 5.678345e-02;\n	effectiveBandwidth = 2.846000e-01;\n	TDILevel = 32;\nEND_GROUP = BAND_P\noutputFormat = \"NITF21NCDRD\";\nBEGIN_GROUP = IMAGE_1\n	satId = \"WV02\";\n	mode = \"FullSwath\";\n	scanDirection = \"Reverse\";\n	CatId = \"10300100037CAF00\";\n	TLCTime = 2009-12-06T14:58:03.358375Z;\n	numTLC = 2;\n	TLCList = (\n	(0,  0.000000),\n	(33656, -1.695800)	);\n	firstLineTime = 2009-12-06T14:58:03.358375Z;\n	avgLineRate = 19846.68;\n	exposureDuration = 0.00161236;\n	minCollectedRowGSD =   0.498;\n	maxCollectedRowGSD =   0.500;\n	meanCollectedRowGSD =   0.499;\n	minCollectedColGSD =   0.498;\n	maxCollectedColGSD =   0.499;\n	meanCollectedColGSD =   0.499;\n	meanCollectedGSD =   0.499;\n	meanProductRowGSD =   0.502;\n	meanProductColGSD =   0.504;\n	meanProductGSD =   0.503;\n	rowUncertainty =   29.08;\n	colUncertainty =   34.39;\n	minSunAz =  69.0;\n	maxSunAz =  69.3;\n	meanSunAz =  69.2;\n	minSunEl =  66.4;\n	maxSunEl =  66.4;\n	meanSunEl =  66.4;\n	minSatAz = 311.4;\n	maxSatAz = 314.2;\n	meanSatAz = 312.9;\n	minSatEl =  73.5;\n	maxSatEl =  73.9;\n	meanSatEl =  73.7;\n	minInTrackViewAngle =   7.6;\n	maxInTrackViewAngle =   8.0;\n	meanInTrackViewAngle =   7.8;\n	minCrossTrackViewAngle = -12.2;\n	maxCrossTrackViewAngle = -12.0;\n	meanCrossTrackViewAngle = -12.1;\n	minOffNadirViewAngle =  14.4;\n	maxOffNadirViewAngle =  14.4;\n	meanOffNadirViewAngle =  14.4;\n	PNIIRS = 5.0;\n	cloudCover = 0.004;\n	resamplingKernel = \"CC\";\n	positionKnowledgeSrc = \"R\";\n	attitudeKnowledgeSrc = \"R\";\n	revNumber = 844;\nEND_GROUP = IMAGE_1\nEND;\n";
    strings["09DEC06145803-P1BS-052869858050_01_P002_bin_2.rpb"] = "satId = \"????\";\nbandId = \"RGB\";\nSpecId = \"RPC00B\";\nBEGIN_GROUP = IMAGE\n\n\n  lineOffset = 5109\n  sampOffset = -8047\n  latOffset = -33.4374\n  longOffset = -70.6439\n  heightOffset = 922\n  lineScale = 16828\n  sampScale = 17456\n  latScale = 0.08\n  longScale = 0.0959\n  heightScale = 501\n  lineNumCoef = (\n    -0.00264594,\n    0.04373632,\n    1.05604,\n    -0.01132939,\n    -0.0004755171,\n    1.047585e-005,\n    8.342535e-005,\n    -0.0003730049,\n    0.001854732,\n    -2.768628e-007,\n    -2.919091e-007,\n    3.89137e-007,\n    4.417434e-006,\n    3.622769e-007,\n    4.40662e-006,\n    3.690352e-005,\n    8.724782e-006,\n    -9.940829e-008,\n    -4.703967e-007,\n    -9.233629e-008);\n  lineDenCoef = (\n    1,\n    0.0006341695,\n    0.0008535553,\n    -0.0001185298,\n    -5.202248e-006,\n    1.178422e-007,\n    8.999336e-007,\n    5.927408e-006,\n    -2.176137e-005,\n    8.245444e-006,\n    -4.43691e-008,\n    0,\n    2.008929e-006,\n    0,\n    1.571993e-007,\n    1.30458e-005,\n    0,\n    0,\n    -4.168984e-007,\n    0);\n  sampNumCoef = (\n    -0.002787494,\n    -1.014879,\n    -0.0001342559,\n    -0.01222411,\n    -0.001193823,\n    -0.0003057016,\n    0.000109006,\n    0.002639235,\n    -0.000115734,\n    -4.360195e-006,\n    -5.144666e-007,\n    -4.510677e-008,\n    1.077331e-005,\n    2.743729e-006,\n    -5.15557e-006,\n    4.865478e-005,\n    7.309242e-008,\n    1.645469e-006,\n    -1.411975e-006,\n    3.371315e-008);\n  sampDenCoef = (\n    1,\n    -0.0001543312,\n    -0.001211336,\n    -0.0003444029,\n    -7.369097e-006,\n    1.043191e-006,\n    -1.026206e-006,\n    1.776887e-006,\n    7.241381e-006,\n    -2.858965e-006,\n    -1.091991e-008,\n    -1.171952e-008,\n    -1.790362e-007,\n    0,\n    8.741243e-008,\n    -1.159687e-007,\n    0,\n    0,\n    1.188762e-008,\n    0);\nEND_GROUP = IMAGE\nEND;\nlvcs\n-70.692764\n-33.458862\n530\n";
    strings["09DEC06145817-P1BS-052869840050_01_P002.imd"] = "version = \"23.11\";\ngenerationTime = 2012-12-13T01:01:52.000000Z;\nproductOrderId = \"052869840050_01_P002\";\nproductCatalogId = \"20200100D8C1D000\";\nimageDescriptor = \"Basic1B\";\nbandId = \"P\";\npanSharpenAlgorithm = \"None\";\nnumRows = 33792;\nnumColumns = 34816;\nproductLevel = \"LV1B\";\nproductType = \"Basic\";\nnumberOfLooks = 1;\nradiometricLevel = \"Corrected\";\nbitsPerPixel = 16;\ncompressionType = \"JPEG2000\";\njpegProfileName = \"nga_npje_pan_vl\";\nBEGIN_GROUP = BAND_P\n	ULLon =  -70.54845267;\n	ULLat =  -33.51641899;\n	ULHAE =   726.77;\n	URLon =  -70.73698223;\n	URLat =  -33.51405506;\n	URHAE =   527.89;\n	LRLon =  -70.73663249;\n	LRLat =  -33.36273680;\n	LRHAE =   516.32;\n	LLLon =  -70.54931953;\n	LLLat =  -33.36469749;\n	LLHAE =   902.10;\n	absCalFactor = 5.678345e-02;\n	effectiveBandwidth = 2.846000e-01;\n	TDILevel = 32;\nEND_GROUP = BAND_P\noutputFormat = \"NITF21NCDRD\";\nBEGIN_GROUP = IMAGE_1\n	satId = \"WV02\";\n	mode = \"FullSwath\";\n	scanDirection = \"Reverse\";\n	CatId = \"1030010002BB6200\";\n	TLCTime = 2009-12-06T14:58:17.839376Z;\n	numTLC = 2;\n	TLCList = (\n	(0,  0.000000),\n	(33680, -1.739200)	);\n	firstLineTime = 2009-12-06T14:58:17.839376Z;\n	avgLineRate = 19365.23;\n	exposureDuration = 0.00165245;\n	minCollectedRowGSD =   0.486;\n	maxCollectedRowGSD =   0.487;\n	meanCollectedRowGSD =   0.486;\n	minCollectedColGSD =   0.497;\n	maxCollectedColGSD =   0.498;\n	meanCollectedColGSD =   0.497;\n	meanCollectedGSD =   0.492;\n	meanProductRowGSD =   0.502;\n	meanProductColGSD =   0.516;\n	meanProductGSD =   0.509;\n	rowUncertainty =   24.44;\n	colUncertainty =   35.73;\n	minSunAz =  68.9;\n	maxSunAz =  69.3;\n	meanSunAz =  69.1;\n	minSunEl =  66.4;\n	maxSunEl =  66.5;\n	meanSunEl =  66.4;\n	minSatAz = 282.3;\n	maxSatAz = 286.1;\n	meanSatAz = 284.3;\n	minSatEl =  75.8;\n	maxSatEl =  75.8;\n	meanSatEl =  75.8;\n	minInTrackViewAngle =   0.8;\n	maxInTrackViewAngle =   1.1;\n	meanInTrackViewAngle =   0.9;\n	minCrossTrackViewAngle = -12.6;\n	maxCrossTrackViewAngle = -12.4;\n	meanCrossTrackViewAngle = -12.5;\n	minOffNadirViewAngle =  12.6;\n	maxOffNadirViewAngle =  12.6;\n	meanOffNadirViewAngle =  12.6;\n	PNIIRS = 5.0;\n	cloudCover = 0.020;\n	resamplingKernel = \"CC\";\n	positionKnowledgeSrc = \"R\";\n	attitudeKnowledgeSrc = \"R\";\n	revNumber = 844;\nEND_GROUP = IMAGE_1\nEND;\n";
    strings["09DEC06145817-P1BS-052869840050_01_P002_bin_2.rpb"] = "satId = \"????\";\nbandId = \"RGB\";\nSpecId = \"RPC00B\";\nBEGIN_GROUP = IMAGE\n\n\n  lineOffset = 4451\n  sampOffset = -7953\n  latOffset = -33.4395\n  longOffset = -70.6435\n  heightOffset = 922\n  lineScale = 16840\n  sampScale = 17032\n  latScale = 0.0772\n  longScale = 0.0959\n  heightScale = 501\n  lineNumCoef = (\n    -0.002365931,\n    0.01557625,\n    1.01921,\n    -0.003474112,\n    -0.0004825288,\n    3.357694e-006,\n    9.941763e-005,\n    -0.0004544508,\n    0.001607839,\n    -1.909392e-007,\n    -6.777044e-007,\n    5.909931e-007,\n    8.960757e-006,\n    5.81189e-007,\n    2.326514e-005,\n    0.0001377724,\n    3.791193e-005,\n    -1.386158e-007,\n    -5.742475e-007,\n    -1.289108e-007);\n  lineDenCoef = (\n    1,\n    0.0005352095,\n    0.0007124099,\n    -0.0001095409,\n    -8.382742e-006,\n    -3.638535e-007,\n    1.130617e-006,\n    2.490357e-005,\n    -8.236239e-005,\n    3.718215e-005,\n    -5.232261e-008,\n    3.283087e-008,\n    7.0871e-006,\n    3.914178e-008,\n    3.633325e-007,\n    0.0002244597,\n    -1.535671e-008,\n    0,\n    -2.344788e-006,\n    0);\n  sampNumCoef = (\n    -0.002756063,\n    -1.016848,\n    -0.0001003955,\n    -0.01397387,\n    -0.0009654424,\n    -0.0003034329,\n    0.0001058744,\n    0.00280471,\n    4.592958e-005,\n    -4.012769e-006,\n    -8.34248e-007,\n    -1.581688e-006,\n    6.31908e-006,\n    1.808836e-006,\n    -5.657072e-006,\n    2.405801e-005,\n    5.088772e-008,\n    1.660197e-006,\n    -1.096983e-007,\n    2.585779e-008);\n  sampDenCoef = (\n    1,\n    4.514118e-005,\n    -0.0009805011,\n    -0.0003470964,\n    -7.501846e-006,\n    1.068501e-006,\n    -4.180832e-007,\n    2.467518e-006,\n    4.831575e-006,\n    -1.935385e-006,\n    -1.127505e-008,\n    0,\n    -1.297185e-007,\n    0,\n    9.024252e-008,\n    -2.109139e-007,\n    0,\n    0,\n    0,\n    0);\nEND_GROUP = IMAGE\nEND;\nlvcs\n-70.692764\n-33.458862\n530\n";
    strings["09DEC06145817-P1BS-500060999100_01_P002.imd"] = "version = \"23.11\";\ngenerationTime = 2013-03-25T20:06:58.000000Z;\nproductOrderId = \"500060999100_01_P002\";\nproductCatalogId = \"2020011E5E2E3900\";\nimageDescriptor = \"Basic1B\";\nbandId = \"P\";\npanSharpenAlgorithm = \"None\";\nnumRows = 30720;\nnumColumns = 34816;\nproductLevel = \"LV1B\";\nproductType = \"Basic\";\nnumberOfLooks = 1;\nradiometricLevel = \"Corrected\";\nbitsPerPixel = 16;\ncompressionType = \"JPEG2000\";\njpegProfileName = \"nga_npje_pan_vl\";\nBEGIN_GROUP = BAND_P\n	ULLon =  -70.54846912;\n	ULLat =  -33.48181331;\n	ULHAE =   699.44;\n	URLon =  -70.73687673;\n	URLat =  -33.47951220;\n	URHAE =   514.31;\n	LRLon =  -70.73657825;\n	LRLat =  -33.34312821;\n	LRHAE =   512.15;\n	LLLon =  -70.54937875;\n	LLLat =  -33.34504727;\n	LLHAE =   906.83;\n	absCalFactor = 5.678345e-02;\n	effectiveBandwidth = 2.846000e-01;\n	TDILevel = 32;\nEND_GROUP = BAND_P\noutputFormat = \"NITF21NCDRD\";\nBEGIN_GROUP = IMAGE_1\n	satId = \"WV02\";\n	mode = \"FullSwath\";\n	scanDirection = \"Reverse\";\n	CatId = \"1030010002BB6200\";\n	TLCTime = 2009-12-06T14:58:17.442576Z;\n	numTLC = 2;\n	TLCList = (\n	(0,  0.000000),\n	(30356, -1.568000)	);\n	firstLineTime = 2009-12-06T14:58:17.442576Z;\n	avgLineRate = 19359.69;\n	exposureDuration = 0.00165292;\n	minCollectedRowGSD =   0.486;\n	maxCollectedRowGSD =   0.487;\n	meanCollectedRowGSD =   0.486;\n	minCollectedColGSD =   0.497;\n	maxCollectedColGSD =   0.498;\n	meanCollectedColGSD =   0.497;\n	meanCollectedGSD =   0.492;\n	meanProductRowGSD =   0.502;\n	meanProductColGSD =   0.516;\n	meanProductGSD =   0.509;\n	rowUncertainty =   24.41;\n	colUncertainty =   35.69;\n	minSunAz =  69.0;\n	maxSunAz =  69.3;\n	meanSunAz =  69.2;\n	minSunEl =  66.4;\n	maxSunEl =  66.5;\n	meanSunEl =  66.4;\n	minSatAz = 282.2;\n	maxSatAz = 285.7;\n	meanSatAz = 284.0;\n	minSatEl =  75.9;\n	maxSatEl =  75.9;\n	meanSatEl =  75.9;\n	minInTrackViewAngle =   0.7;\n	maxInTrackViewAngle =   1.0;\n	meanInTrackViewAngle =   0.9;\n	minCrossTrackViewAngle = -12.6;\n	maxCrossTrackViewAngle = -12.4;\n	meanCrossTrackViewAngle = -12.5;\n	minOffNadirViewAngle =  12.5;\n	maxOffNadirViewAngle =  12.5;\n	meanOffNadirViewAngle =  12.5;\n	PNIIRS = 5.0;\n	cloudCover = 0.013;\n	resamplingKernel = \"CC\";\n	positionKnowledgeSrc = \"R\";\n	attitudeKnowledgeSrc = \"R\";\n	revNumber = 844;\nEND_GROUP = IMAGE_1\nEND;\n";
    strings["09DEC06145817-P1BS-500060999100_01_P002_bin_2.rpb"] = "satId = \"????\";\nbandId = \"RGB\";\nSpecId = \"RPC00B\";\nBEGIN_GROUP = IMAGE\n\n\n  lineOffset = 10474\n  sampOffset = -7951\n  latOffset = -33.4123\n  longOffset = -70.6436\n  heightOffset = 979\n  lineScale = 15178\n  sampScale = 17028\n  latScale = 0.0697\n  longScale = 0.0958\n  heightScale = 501\n  lineNumCoef = (\n    -0.001581208,\n    0.01685885,\n    1.021392,\n    -0.003770469,\n    -0.0004818991,\n    3.615673e-006,\n    0.0001008016,\n    -0.000503781,\n    0.001223366,\n    -5.266555e-008,\n    3.247754e-007,\n    -1.642952e-007,\n    2.041539e-006,\n    -5.435146e-007,\n    -2.56555e-005,\n    -0.0001192393,\n    -3.286015e-005,\n    4.565219e-008,\n    8.799491e-007,\n    1.21594e-007);\n  lineDenCoef = (\n    1,\n    0.0005276126,\n    0.0002848843,\n    -0.000108828,\n    1.226855e-006,\n    5.598811e-007,\n    -1.075696e-006,\n    -2.304797e-005,\n    6.97758e-005,\n    -3.217881e-005,\n    -1.278391e-007,\n    -1.783555e-008,\n    1.662461e-005,\n    -3.227639e-008,\n    7.192261e-008,\n    0.0002938649,\n    3.181733e-008,\n    0,\n    -3.22235e-006,\n    0);\n  sampNumCoef = (\n    -0.003333667,\n    -1.016592,\n    -3.861694e-005,\n    -0.01394302,\n    -0.0008684311,\n    -0.0002976944,\n    9.560289e-005,\n    0.003093719,\n    5.289319e-005,\n    -3.968707e-006,\n    -5.756276e-007,\n    -2.597929e-006,\n    5.956679e-006,\n    2.445229e-006,\n    -6.03211e-006,\n    1.112038e-005,\n    4.826943e-008,\n    1.798884e-006,\n    1.517848e-008,\n    3.443181e-008);\n  sampDenCoef = (\n    1,\n    -0.0002480899,\n    -0.000881582,\n    -0.0003491762,\n    -5.422153e-006,\n    1.10487e-006,\n    -5.848807e-007,\n    2.686398e-006,\n    2.761704e-006,\n    -2.558868e-006,\n    -1.128691e-008,\n    0,\n    -9.362841e-008,\n    0,\n    8.781176e-008,\n    3.281826e-008,\n    0,\n    0,\n    0,\n    0);\nEND_GROUP = IMAGE\nEND;\nlvcs\n-70.692764\n-33.458862\n530\n";
    return strings[old_filename];
}

static void write_file_strings_to_tempfiles(std::string const& temp_filename, std::string const& image_name, std::string const& ext) {
    std::stringstream ss;
    std::string s0 = get_file_strings(image_name + ext);

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

    std::string ext[2] = { ".imd", "_bin_2.rpb" };
    for (size_t i = 0; i < 2; ++i) {
        std::string temp = "./" + image_name + ext[i];
        write_file_strings_to_tempfiles(temp, image_name, ext[i]);
    }

    size_t ni0 = 0, nj0 = 0;
    float i_den = 2000.0f, j_den = 2000.0f;
    if (image_name == "09DEC06145803-P1BS-052869858050_01_P002")
        ni0 = 1103, nj0 = 1344;
    else if (image_name == "09DEC06145817-P1BS-052869840050_01_P002") {
        ni0 = 1091, nj0 = 1263;
        i_den = 3500.0f, j_den = 4000.0f;
    }
    else if (image_name == "09DEC06145817-P1BS-500060999100_01_P002") {
        ni0 = 1091, nj0 = 1262;
        i_den = 1000.0f, j_den = 4000.0f;
    }
    vil_image_view<float> img0(ni0, nj0);
    for (size_t j = 0; j < nj0; ++j)
        for (size_t i = 0; i < ni0; ++i) {
            img0(i, j) = static_cast<float>(j / j_den + i / i_den);
        }
    std::string img0_path = "./" + image_name + ".tif";
    if (bool good_image_write = vil_save(img0, img0_path.c_str()))
        std::cout << "Good Image Write " << img0_path << std::endl;
    else if (!good_image_write)
        std::cout << "Not a Good Image Write " << img0_path << std::endl;
}

static void test_belief_prop_utils()
{
  //START("test_belief_prop_utils");
  // test belief prop functions
  brad_ray ray;
  ray.init_ray();
  ray.print();
  std:: cout << ' ';

  std::string files[] = {//"03JAN08145014-P1BS-052869788020_01_P006",
                         //"05DEC11150006-P1BS-052869812040_01_P002",
                         //"07JAN06150926-P1BS-052869817030_01_P004",
                         //"07NOV08144023-P1BS-052869842020_01_P002",
                         //"07NOV08144106-P1BS-052869785010_01_P001",
                         //"07NOV21144208-P1BS-052869820030_01_P004",
                         //"07NOV21144210-P1BS-052869820030_01_P005",
                         //"08OCT18145149-P1BS-052869833040_01_P001",
                         "09DEC06145803-P1BS-052869858050_01_P002",
                         "09DEC06145817-P1BS-052869840050_01_P002",
                         "09DEC06145817-P1BS-500060999100_01_P002"};
#if 0
                         "09DEC12143944-P1BS-052869847050_01_P001",
                         "09DEC12143956-P1BS-052869830010_01_P002",
                         "09DEC12143956-P1BS-500060996100_01_P002",
                         "09DEC12144010-P1BS-052869863040_01_P002",
                         "09DEC12144011-P1BS-500060998150_01_P003",
                         "09DEC14150530-P1BS-052869830020_01_P001",
                         "09DEC14150620-P1BS-052869824020_01_P002",
                         "09DEC17145621-P1BS-052869797010_01_P001",
                         "09DEC24145617-P1BS-052315343010_01_P002",
                         "09DEC24145617-P1BS-052869779040_01_P002",
                         "09DEC25150516-P1BS-052869797020_01_P002",
                         "09DEC25150516-P1BS-500060996010_01_P002",
                         "09DEC25150528-P1BS-052869818010_01_P001",
                         "09DEC25150635-P1BS-052869876020_01_P002",
                         "09DEC25150635-P1BS-500060999030_01_P002",
                         "09DEC28145609-P1BS-052869868010_01_P002",
                         "09DEC28145609-P1BS-500060997120_01_P002",
                         "09DEC28145718-P1BS-052869856040_01_P002",
                         "09DEC31144657-P1BS-052869840030_01_P001",
                         "09NOV30151513-P1BS-052869835030_01_P001",
                         "10DEC01145358-P1BS-052869866030_01_P001",
                         "10DEC09150358-P1BS-052869877050_01_P001",
                         "10DEC12145513-P1BS-052869863030_01_P001",
                         "10DEC14151413-P1BS-052869844040_01_P004",
                         "10FEB07150123-P1BS-052869803030_01_P001",
                         "10FEB10145223-P1BS-052869846010_01_P001",
                         "10FEB15150957-P1BS-052869823050_01_P001",
                         "10FEB21145127-P1BS-052869840020_01_P001",
                         "10FEB26150756-P1BS-052869871050_01_P001",
                         "10JAN05150316-P1BS-052869837030_01_P001",
                         "10JAN08145510-P1BS-052869801050_01_P001",
                         "10JAN08145916-P1BS-052869827030_01_P001",
                         "10JAN11144555-P1BS-052869873040_01_P001",
                         "10JAN16150318-P1BS-052869859050_01_P004",
                         "10JAN22144500-P1BS-052869870010_01_P001",
                         "10JAN27150215-P1BS-052869798020_01_P004",
                         "10JAN27150233-P1BS-052869859040_01_P001",
                         "10JAN30145319-P1BS-052869846050_01_P001",
                         "10MAR01145753-P1BS-052869824050_01_P002",
                         "10NOV06150113-P1BS-052869840010_01_P001",
                         "10NOV06150122-P1BS-052869878020_01_P001",
                         "10NOV06150605-P1BS-052869827040_01_P005",
                         "10NOV10151146-P1BS-052869785030_01_P004",
                         "10NOV10151231-P1BS-052869789020_01_P004",
                         "10NOV17150246-P1BS-052869796050_01_P001",
                         "10NOV23150719-P1BS-052869791010_01_P004",
                         "10NOV23150815-P1BS-052869854020_01_P001",
                         "10NOV28150228-P1BS-052869863010_01_P001",
                         "10OCT07145106-P1BS-052869786040_01_P001",
                         "10OCT07150831-P1BS-052869851020_01_P004",
                         "10OCT18145158-P1BS-052869872050_01_P001",
                         "10OCT24150848-P1BS-052869790040_01_P001",
                         "11DEC02151302-P1BS-052869829010_01_P001",
                         "11DEC10151810-P1BS-052869843050_01_P001",
                         "11DEC11145906-P1BS-052869854010_01_P001",
                         "11DEC13150801-P1BS-052869858020_01_P001",
                         "11DEC15150445-P1BS-052869834010_01_P001",
                         "11DEC16145749-P1BS-500060998010_01_P001",
                         "11DEC16145750-P1BS-052869803010_01_P001",
                         "11DEC19151049-P1BS-052869808030_01_P001",
                         "11DEC21151345-P1BS-052869865020_01_P001",
                         "11DEC24150332-P1BS-052869861020_01_P001",
                         "11FEB05145509-P1BS-052869823020_01_P001",
                         "11FEB05145509-P1BS-500060996060_01_P001",
                         "11FEB13150344-P1BS-052869823040_01_P001",
                         "11FEB13150344-P1BS-500060996080_01_P001",
                         "11JAN11150346-P1BS-052869814020_01_P001",
                         "11JAN13150655-P1BS-052869813020_01_P004",
                         "11JAN13150739-P1BS-052869826040_01_P004",
                         "11JAN14145545-P1BS-052869798050_01_P001",
                         "11JAN19151302-P1BS-052869824040_01_P001",
                         "11JAN22150346-P1BS-052869861050_01_P001",
                         "11JAN25145535-P1BS-052869836050_01_P001",
                         "11JAN30151239-P1BS-052869870040_01_P001",
                         "11MAR04151052-P1BS-052869786050_01_P001",
                         "11NOV02151428-P1BS-052869837010_01_P001",
                         "11NOV05150425-P1BS-052869823030_01_P001",
                         "11NOV05150425-P1BS-500060996070_01_P001",
                         "11NOV16150028-P1BS-052869818030_01_P001",
                         "11NOV19151531-P1BS-052869841030_01_P001",
                         "11NOV24145924-P1BS-052869791020_01_P001",
                         "11NOV29152235-P1BS-052869811010_01_P001",
                         "11OCT09145538-P1BS-052869792030_01_P002",
                         "11OCT09145550-P1BS-052869847020_01_P001",
                         "11OCT09145607-P1BS-052869829020_01_P004",
                         "11OCT12150843-P1BS-052869833020_01_P001",
                         "11OCT22151819-P1BS-052869847030_01_P001",
                         "11OCT22151819-P1BS-500060997040_01_P001",
                         "11OCT25150400-P1BS-052869815020_01_P001",
                         "11OCT25150817-P1BS-052869858030_01_P001",
                         "11OCT30152430-P1BS-052869836030_01_P001",
                         "12FEB03145527-P1BS-052869855050_01_P001",
                         "12FEB05152130-P1BS-052869859030_01_P001",
                         "12FEB05152130-P1BS-500060997090_01_P001",
                         "12FEB11150056-P1BS-052869836040_01_P001",
                         "12FEB17145944-P1BS-052869805040_01_P001",
                         "12FEB19150624-P1BS-052869877020_01_P001",
                         "12FEB22145607-P1BS-052869864020_01_P001",
                         "12FEB24152211-P1BS-052869823010_01_P001",
                         "12FEB24152211-P1BS-500060996050_01_P001",
                         "12JAN01150921-P1BS-500060999060_01_P001",
                         "12JAN05151109-P1BS-052869834030_01_P002",
                         "12JAN05151204-P1BS-052869841040_01_P002",
                         "12JAN12150444-P1BS-052869811020_01_P001",
                         "12JAN18150453-P1BS-052869825040_01_P001",
                         "12JAN28151600-P1BS-052869870050_01_P001",
                         "12JAN31145907-P1BS-052869827050_01_P002",
                         "12JAN31145948-P1BS-052869850030_01_P002",
                         "12MAR01150154-P1BS-052869800050_01_P001",
                         "12NOV03145829-P1BS-052894093070_01_P005",
                         "12NOV03145830-P1BS-052894093070_01_P006"
#endif

   unsigned n = 3; // Number of image files
   for (size_t i=0; i<n; ++i){
       write_image_to_files(files[i]);
       }

  //std::string meta_dir = "d:/tests/chiletest/metadata_files/";
  //std::string imgcam_dir = "d:/tests/chiletest/crop_dir/";
  std::string meta_dir = "./";
  std::string imgcam_dir = "./";
  std::string post = "_bin_2";

  std::vector<vbl_smart_ptr<brad_image_metadata> > metadata;
  for(unsigned i =0; i<n; ++i){
    vbl_smart_ptr<brad_image_metadata> meta_ptr = new brad_image_metadata();
    if(!meta_ptr->parse_from_meta_file(meta_dir + files[i]+".IMD"))
      continue;
    metadata.push_back(meta_ptr);
  }
  brad_belief_prop_utils utils;
  utils.set_metadata(metadata);

  unsigned mnv = utils.most_nadir_view();
  utils.force_single_index(mnv);
#if 1
  std::vector<unsigned> ref_views =utils.index(mnv);
  TEST("no ref views", ref_views.size(), 0);
  vgl_vector_3d<double> nview = utils.view_dir(mnv);
  for(std::vector<unsigned>::iterator vit = ref_views.begin();
      vit != ref_views.end(); ++vit){
    vgl_vector_3d<double> view = utils.view_dir(*vit);
    double dp = dot_product(nview, view);
    double angle = std::acos(dp)*180.0/3.14159;
    std::cout << "angle[" << *vit << "]: " << angle << '\n';
  }
#endif
  std::vector<vil_image_view<float> > imgs;
  std::vector<vpgl_camera_double_sptr> cams;
  for(unsigned i = 0; i<n; ++i){
    std::string img_file = imgcam_dir + files[i] + ".tif";
    //std::string cam_file = imgcam_dir + files[i] + ".rpb";

    //std::string img_file = imgcam_dir + files[i] + post + ".tif";
    std::string cam_file = imgcam_dir + files[i] + post + ".rpb";
    vil_image_view<float> img = vil_load(img_file.c_str());
    vpgl_camera_double_sptr ratcam = read_local_rational_camera<double>(cam_file);
        if(!img || !ratcam){
                std::cout << "null img or cam " << files[i] << '\n';
                continue;
        }
        imgs.push_back(img);
    cams.push_back(ratcam);
  }
  utils.set_images(imgs);
  utils.set_cams(cams);

#if 1
  vgl_point_3d<double>  p0(257.2, 107.9, 19.0);
  vgl_point_3d<double>  p1(334.3,244.5 , 13.6);
  vgl_point_3d<double>  p2(314.4,387.9 , 14.56);
  vgl_point_3d<double>  p2d(316.0, 388.0, 14.56);
  vgl_point_3d<double>  proad(228.7,342.7, 2.9);
  vgl_point_3d<double>  proof(291.9,431.7, 14.56);
  //vgl_point_3d<double>  proof(293,431.7, 14.56);
  float Iray =0.0f;
  vgl_point_3d<double> p = proof;
  utils.pixel_intensity(imgs[mnv], cams[mnv], p, Iray);
  std::cout << "Iray[" << mnv << "]: " << Iray << " RefInts[";
  std::vector<double> ref_intents = utils.ref_intensities(ref_views, p);
  for(std::vector<double>::iterator intit = ref_intents.begin();
      intit != ref_intents.end(); ++intit)
    std::cout << *intit << ' ';
  std::cout << "]\n";
  vnl_vector_fixed<unsigned char, 8> mog3(static_cast<unsigned char>(0));
  vnl_vector_fixed<float, 4> nobs(0.0f);
  utils.update_mog(ref_intents, mog3, nobs, true);
  double pray = utils.p_mog(Iray, mog3);
  std::cout << "P(Iray): " << pray << " mix-> ";
  utils.print_mog(mog3, nobs);
  ///
  for(double dy = 0.0; dy<10.0; dy+=1.0){
    vgl_point_3d<double> pi(p.x(), p.y()+dy, p.z());
    utils.init_zray(Iray, ref_views, pi, -10.0, true);
    utils.zray_pre();
    utils.zray_post();
    utils.update_PinS();
    utils.update_vis();
    utils.print_zray();
    double ed = utils.expected_depth();
    std::cout << "expected depth " << ed << '\n';
  }
#endif
#if 0
  //  double z0 = 9.36;
  double z0 = 15.0;
  vgl_point_2d<double> p0(399.13, 333.68);
  vgl_point_2d<double> p1(117.65, 330.03);
  vgl_point_2d<double> p2(113.3, 583.9);
  vgl_point_2d<double> p3(397.5, 583.98);
  vgl_box_2d<double> bb;
  bb.add(p0);  bb.add(p1);  bb.add(p2);  bb.add(p3);
  utils.compute_depth_map(bb, 1.0, z0);
  //std::string depth_path = "d:/tests/chiletest/depth.tif";
  std::string depth_path = "./depth.tif";
  utils.save_depth_map(depth_path);
#endif
#if 0
  utils.project_intensities(p);
  utils.print_intensities();
  utils.test_appearance_update();
#endif

  for (size_t i = 0; i < n; ++i) {
      std::string temp_imd = "./" + files[i] + ".imd";
      std::string temp_rpb = "./" + files[i] + post + ".rpb";
      std::string temp_tif = "./" + files[i] + ".tif";
      vpl_unlink(temp_imd.c_str());
      vpl_unlink(temp_rpb.c_str());
      vpl_unlink(temp_tif.c_str());
  }
#if 0
  vpl_unlink(depth_path.c_str());
#endif
}
TESTMAIN( test_belief_prop_utils );
