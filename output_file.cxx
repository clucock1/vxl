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
    strings["09DEC06145803-P1BS-052869858050_01_P002.imd"] = "version = \"23.11\";\ngenerationTime = 2012-12-13T00:26:30.000000Z;\nproductOrderId = \"052869858050_01_P002\";\nproductCatalogId = \"20200100D8BF7900\";\nimageDescriptor = \"Basic1B\";\nbandId = \"P\";\npanSharpenAlgorithm = \"None\";\nnumRows = 33792;\nnumColumns = 35840;\nproductLevel = \"LV1B\";\nproductType = \"Basic\";\nnumberOfLooks = 1;\nradiometricLevel = \"Corrected\";\nbitsPerPixel = 16;\ncompressionType = \"JPEG2000\";\njpegProfileName = \"nga_npje_pan_vl\";\nBEGIN_GROUP = BAND_P\nULLon = -70.54873605;\nULLat = -33.51670435;\nULHAE = 725.41;\nURLon = -70.73776498;\nURLat = -33.51034403;\nURHAE = 525.79;\nLRLon = -70.73735471;\nLRLat = -33.35903054;\nLRHAE = 515.20;\nLLLon = -70.54962703;\nLLLat = -33.36468487;\nLLHAE = 905.05;\nabsCalFactor = 5.678345e-02;\neffectiveBandwidth = 2.846000e-01;\nTDILevel = 32;\nEND_GROUP = BAND_P\noutputFormat = \"NITF21NCDRD\";\nBEGIN_GROUP = IMAGE_1\nsatId = \"WV02\";\nmode = \"FullSwath\";\nscanDirection = \"Reverse\";\nCatId = \"10300100037CAF00\";\nTLCTime = 2009-12-06T14:58:03.358375Z;\nnumTLC = 2;\nTLCList = (\n(0, 0.000000),\n(33656, -1.695800) );\nfirstLineTime = 2009-12-06T14:58:03.358375Z;\navgLineRate = 19846.68;\nexposureDuration = 0.00161236;\nminCollectedRowGSD = 0.498;\nmaxCollectedRowGSD = 0.500;\nmeanCollectedRowGSD = 0.499;\nminCollectedColGSD = 0.498;\nmaxCollectedColGSD = 0.499;\nmeanCollectedColGSD = 0.499;\nmeanCollectedGSD = 0.499;\nmeanProductRowGSD = 0.502;\nmeanProductColGSD = 0.504;\nmeanProductGSD = 0.503;\nrowUncertainty = 29.08;\ncolUncertainty = 34.39;\nminSunAz = 69.0;\nmaxSunAz = 69.3;\nmeanSunAz = 69.2;\nminSunEl = 66.4;\nmaxSunEl = 66.4;\nmeanSunEl = 66.4;\nminSatAz = 311.4;\nmaxSatAz = 314.2;\nmeanSatAz = 312.9;\nminSatEl = 73.5;\nmaxSatEl = 73.9;\nmeanSatEl = 73.7;\nminInTrackViewAngle = 7.6;\nmaxInTrackViewAngle = 8.0;\nmeanInTrackViewAngle = 7.8;\nminCrossTrackViewAngle = -12.2;\nmaxCrossTrackViewAngle = -12.0;\nmeanCrossTrackViewAngle = -12.1;\nminOffNadirViewAngle = 14.4;\nmaxOffNadirViewAngle = 14.4;\nmeanOffNadirViewAngle = 14.4;\nPNIIRS = 5.0;\ncloudCover = 0.004;\nresamplingKernel = \"CC\";\npositionKnowledgeSrc = \"R\";\nattitudeKnowledgeSrc = \"R\";\nrevNumber = 844;\nEND_GROUP = IMAGE_1\nEND;\n";
    strings["09DEC06145803-P1BS-052869858050_01_P002_bin_2.rpb"] = "satId = \"????\";\nbandId = \"RGB\";\nSpecId = \"RPC00B\";\nBEGIN_GROUP = IMAGE\\\nlineOffset = 5109\nsampOffset = -8047\nlatOffset = -33.4374\nlongOffset = -70.6439\nheightOffset = 922\nlineScale = 16828\nsampScale = 17456\nlatScale = 0.08\nlongScale = 0.0959\nheightScale = 501\nlineNumCoef = (\n-0.00264594,\n0.04373632,\n1.05604,\n-0.01132939,\n-0.0004755171,\n1.047585e-005,\n8.342535e-005,\n-0.0003730049,\n0.001854732,\n-2.768628e-007,\n-2.919091e-007,\n3.89137e-007,\n4.417434e-006,\n3.622769e-007,\n4.40662e-006,\n3.690352e-005,\n8.724782e-006,\n-9.940829e-008,\n-4.703967e-007,\n-9.233629e-008);\nlineDenCoef = (\n1,\n0.0006341695,\n0.0008535553,\n-0.0001185298,\n-5.202248e-006,\n1.178422e-007,\n8.999336e-007,\n5.927408e-006,\n-2.176137e-005,\n8.245444e-006,\n-4.43691e-008,\n0,\n2.008929e-006,\n0,\n1.571993e-007,\n1.30458e-005,\n0,\n0,\n-4.168984e-007,\n0);\nsampNumCoef = (\n-0.002787494,\n-1.014879,\n-0.0001342559,\n-0.01222411,\n-0.001193823,\n-0.0003057016,\n0.000109006,\n0.002639235,\n-0.000115734,\n-4.360195e-006,\n-5.144666e-007,\n-4.510677e-008,\n1.077331e-005,\n2.743729e-006,\n-5.15557e-006,\n4.865478e-005,\n7.309242e-008,\n1.645469e-006,\n-1.411975e-006,\n3.371315e-008);\nsampDenCoef = (\n1,\n-0.0001543312,\n-0.001211336,\n-0.0003444029,\n-7.369097e-006,\n1.043191e-006,\n-1.026206e-006,\n1.776887e-006,\n7.241381e-006,\n-2.858965e-006,\n-1.091991e-008,\n-1.171952e-008,\n-1.790362e-007,\n0,\n8.741243e-008,\n-1.159687e-007,\n0,\n0,\n1.188762e-008,\n0);\nEND_GROUP = IMAGE\nEND;\nlvcs\n-70.692764\n-33.458862\n530\n";
    strings["09DEC06145817-P1BS-052869840050_01_P002.imd"] = "version = \"23.11\";\ngenerationTime = 2012-12-13T01:01:52.000000Z;\nproductOrderId = \"052869840050_01_P002\";\nproductCatalogId = \"20200100D8C1D000\";\nimageDescriptor = \"Basic1B\";\nbandId = \"P\";\npanSharpenAlgorithm = \"None\";\nnumRows = 33792;\nnumColumns = 34816;\nproductLevel = \"LV1B\";\nproductType = \"Basic\";\nnumberOfLooks = 1;\nradiometricLevel = \"Corrected\";\nbitsPerPixel = 16;\ncompressionType = \"JPEG2000\";\njpegProfileName = \"nga_npje_pan_vl\";\nBEGIN_GROUP = BAND_P\nULLon = -70.54845267;\nULLat = -33.51641899;\nULHAE = 726.77;\nURLon = -70.73698223;\nURLat = -33.51405506;\nURHAE = 527.89;\nLRLon = -70.73663249;\nLRLat = -33.36273680;\nLRHAE = 516.32;\nLLLon = -70.54931953;\nLLLat = -33.36469749;\nLLHAE = 902.10;\nabsCalFactor = 5.678345e-02;\neffectiveBandwidth = 2.846000e-01;\nTDILevel = 32;\nEND_GROUP = BAND_P\noutputFormat = \"NITF21NCDRD\";\nBEGIN_GROUP = IMAGE_1\nsatId = \"WV02\";\nmode = \"FullSwath\";\nscanDirection = \"Reverse\";\nCatId = \"1030010002BB6200\";\nTLCTime = 2009-12-06T14:58:17.839376Z;\nnumTLC = 2;\nTLCList = (\n(0, 0.000000),\n(33680, -1.739200) );\nfirstLineTime = 2009-12-06T14:58:17.839376Z;\navgLineRate = 19365.23;\nexposureDuration = 0.00165245;\nminCollectedRowGSD = 0.486;\nmaxCollectedRowGSD = 0.487;\nmeanCollectedRowGSD = 0.486;\nminCollectedColGSD = 0.497;\nmaxCollectedColGSD = 0.498;\nmeanCollectedColGSD = 0.497;\nmeanCollectedGSD = 0.492;\nmeanProductRowGSD = 0.502;\nmeanProductColGSD = 0.516;\nmeanProductGSD = 0.509;\nrowUncertainty = 24.44;\ncolUncertainty = 35.73;\nminSunAz = 68.9;\nmaxSunAz = 69.3;\nmeanSunAz = 69.1;\nminSunEl = 66.4;\nmaxSunEl = 66.5;\nmeanSunEl = 66.4;\nminSatAz = 282.3;\nmaxSatAz = 286.1;\nmeanSatAz = 284.3;\nminSatEl = 75.8;\nmaxSatEl = 75.8;\nmeanSatEl = 75.8;\nminInTrackViewAngle = 0.8;\nmaxInTrackViewAngle = 1.1;\nmeanInTrackViewAngle = 0.9;\nminCrossTrackViewAngle = -12.6;\nmaxCrossTrackViewAngle = -12.4;\nmeanCrossTrackViewAngle = -12.5;\nminOffNadirViewAngle = 12.6;\nmaxOffNadirViewAngle = 12.6;\nmeanOffNadirViewAngle = 12.6;\nPNIIRS = 5.0;\ncloudCover = 0.020;\nresamplingKernel = \"CC\";\npositionKnowledgeSrc = \"R\";\nattitudeKnowledgeSrc = \"R\";\nrevNumber = 844;\nEND_GROUP = IMAGE_1\nEND;\n";
    strings["09DEC06145817-P1BS-052869840050_01_P002_bin_2.rpb"] = "satId = \"????\";\nbandId = \"RGB\";\nSpecId = \"RPC00B\";\nBEGIN_GROUP = IMAGE\\\nlineOffset = 4451\nsampOffset = -7953\nlatOffset = -33.4395\nlongOffset = -70.6435\nheightOffset = 922\nlineScale = 16840\nsampScale = 17032\nlatScale = 0.0772\nlongScale = 0.0959\nheightScale = 501\nlineNumCoef = (\n-0.002365931,\n0.01557625,\n1.01921,\n-0.003474112,\n-0.0004825288,\n3.357694e-006,\n9.941763e-005,\n-0.0004544508,\n0.001607839,\n-1.909392e-007,\n-6.777044e-007,\n5.909931e-007,\n8.960757e-006,\n5.81189e-007,\n2.326514e-005,\n0.0001377724,\n3.791193e-005,\n-1.386158e-007,\n-5.742475e-007,\n-1.289108e-007);\nlineDenCoef = (\n1,\n0.0005352095,\n0.0007124099,\n-0.0001095409,\n-8.382742e-006,\n-3.638535e-007,\n1.130617e-006,\n2.490357e-005,\n-8.236239e-005,\n3.718215e-005,\n-5.232261e-008,\n3.283087e-008,\n7.0871e-006,\n3.914178e-008,\n3.633325e-007,\n0.0002244597,\n-1.535671e-008,\n0,\n-2.344788e-006,\n0);\nsampNumCoef = (\n-0.002756063,\n-1.016848,\n-0.0001003955,\n-0.01397387,\n-0.0009654424,\n-0.0003034329,\n0.0001058744,\n0.00280471,\n4.592958e-005,\n-4.012769e-006,\n-8.34248e-007,\n-1.581688e-006,\n6.31908e-006,\n1.808836e-006,\n-5.657072e-006,\n2.405801e-005,\n5.088772e-008,\n1.660197e-006,\n-1.096983e-007,\n2.585779e-008);\nsampDenCoef = (\n1,\n4.514118e-005,\n-0.0009805011,\n-0.0003470964,\n-7.501846e-006,\n1.068501e-006,\n-4.180832e-007,\n2.467518e-006,\n4.831575e-006,\n-1.935385e-006,\n-1.127505e-008,\n0,\n-1.297185e-007,\n0,\n9.024252e-008,\n-2.109139e-007,\n0,\n0,\n0,\n0);\nEND_GROUP = IMAGE\nEND;\nlvcs\n-70.692764\n-33.458862\n530\n";
    strings["09DEC06145817-P1BS-500060999100_01_P002.imd"] = "version = \"23.11\";\ngenerationTime = 2013-03-25T20:06:58.000000Z;\nproductOrderId = \"500060999100_01_P002\";\nproductCatalogId = \"2020011E5E2E3900\";\nimageDescriptor = \"Basic1B\";\nbandId = \"P\";\npanSharpenAlgorithm = \"None\";\nnumRows = 30720;\nnumColumns = 34816;\nproductLevel = \"LV1B\";\nproductType = \"Basic\";\nnumberOfLooks = 1;\nradiometricLevel = \"Corrected\";\nbitsPerPixel = 16;\ncompressionType = \"JPEG2000\";\njpegProfileName = \"nga_npje_pan_vl\";\nBEGIN_GROUP = BAND_P\nULLon = -70.54846912;\nULLat = -33.48181331;\nULHAE = 699.44;\nURLon = -70.73687673;\nURLat = -33.47951220;\nURHAE = 514.31;\nLRLon = -70.73657825;\nLRLat = -33.34312821;\nLRHAE = 512.15;\nLLLon = -70.54937875;\nLLLat = -33.34504727;\nLLHAE = 906.83;\nabsCalFactor = 5.678345e-02;\neffectiveBandwidth = 2.846000e-01;\nTDILevel = 32;\nEND_GROUP = BAND_P\noutputFormat = \"NITF21NCDRD\";\nBEGIN_GROUP = IMAGE_1\nsatId = \"WV02\";\nmode = \"FullSwath\";\nscanDirection = \"Reverse\";\nCatId = \"1030010002BB6200\";\nTLCTime = 2009-12-06T14:58:17.442576Z;\nnumTLC = 2;\nTLCList = (\n(0, 0.000000),\n(30356, -1.568000) );\nfirstLineTime = 2009-12-06T14:58:17.442576Z;\navgLineRate = 19359.69;\nexposureDuration = 0.00165292;\nminCollectedRowGSD = 0.486;\nmaxCollectedRowGSD = 0.487;\nmeanCollectedRowGSD = 0.486;\nminCollectedColGSD = 0.497;\nmaxCollectedColGSD = 0.498;\nmeanCollectedColGSD = 0.497;\nmeanCollectedGSD = 0.492;\nmeanProductRowGSD = 0.502;\nmeanProductColGSD = 0.516;\nmeanProductGSD = 0.509;\nrowUncertainty = 24.41;\ncolUncertainty = 35.69;\nminSunAz = 69.0;\nmaxSunAz = 69.3;\nmeanSunAz = 69.2;\nminSunEl = 66.4;\nmaxSunEl = 66.5;\nmeanSunEl = 66.4;\nminSatAz = 282.2;\nmaxSatAz = 285.7;\nmeanSatAz = 284.0;\nminSatEl = 75.9;\nmaxSatEl = 75.9;\nmeanSatEl = 75.9;\nminInTrackViewAngle = 0.7;\nmaxInTrackViewAngle = 1.0;\nmeanInTrackViewAngle = 0.9;\nminCrossTrackViewAngle = -12.6;\nmaxCrossTrackViewAngle = -12.4;\nmeanCrossTrackViewAngle = -12.5;\nminOffNadirViewAngle = 12.5;\nmaxOffNadirViewAngle = 12.5;\nmeanOffNadirViewAngle = 12.5;\nPNIIRS = 5.0;\ncloudCover = 0.013;\nresamplingKernel = \"CC\";\npositionKnowledgeSrc = \"R\";\nattitudeKnowledgeSrc = \"R\";\nrevNumber = 844;\nEND_GROUP = IMAGE_1\nEND;\n";
    strings["09DEC06145817-P1BS-500060999100_01_P002_bin_2.rpb"] = "satId = \"????\";\nbandId = \"RGB\";\nSpecId = \"RPC00B\";\nBEGIN_GROUP = IMAGE\\\nlineOffset = 10474\nsampOffset = -7951\nlatOffset = -33.4123\nlongOffset = -70.6436\nheightOffset = 979\nlineScale = 15178\nsampScale = 17028\nlatScale = 0.0697\nlongScale = 0.0958\nheightScale = 501\nlineNumCoef = (\n-0.001581208,\n0.01685885,\n1.021392,\n-0.003770469,\n-0.0004818991,\n3.615673e-006,\n0.0001008016,\n-0.000503781,\n0.001223366,\n-5.266555e-008,\n3.247754e-007,\n-1.642952e-007,\n2.041539e-006,\n-5.435146e-007,\n-2.56555e-005,\n-0.0001192393,\n-3.286015e-005,\n4.565219e-008,\n8.799491e-007,\n1.21594e-007);\nlineDenCoef = (\n1,\n0.0005276126,\n0.0002848843,\n-0.000108828,\n1.226855e-006,\n5.598811e-007,\n-1.075696e-006,\n-2.304797e-005,\n6.97758e-005,\n-3.217881e-005,\n-1.278391e-007,\n-1.783555e-008,\n1.662461e-005,\n-3.227639e-008,\n7.192261e-008,\n0.0002938649,\n3.181733e-008,\n0,\n-3.22235e-006,\n0);\nsampNumCoef = (\n-0.003333667,\n-1.016592,\n-3.861694e-005,\n-0.01394302,\n-0.0008684311,\n-0.0002976944,\n9.560289e-005,\n0.003093719,\n5.289319e-005,\n-3.968707e-006,\n-5.756276e-007,\n-2.597929e-006,\n5.956679e-006,\n2.445229e-006,\n-6.03211e-006,\n1.112038e-005,\n4.826943e-008,\n1.798884e-006,\n1.517848e-008,\n3.443181e-008);\nsampDenCoef = (\n1,\n-0.0002480899,\n-0.000881582,\n-0.0003491762,\n-5.422153e-006,\n1.10487e-006,\n-5.848807e-007,\n2.686398e-006,\n2.761704e-006,\n-2.558868e-006,\n-1.128691e-008,\n0,\n-9.362841e-008,\n0,\n8.781176e-008,\n3.281826e-008,\n0,\n0,\n0,\n0);\nEND_GROUP = IMAGE\nEND;\nlvcs\n-70.692764\n-33.458862\n530\n";
    return strings[old_filename];
}
#if 0
std::string get_file_strings(std::string const& old_filename) {
    std::map< std::string, std::string> strings;
    strings["09DEC06145803-P1BS-052869858050_01_P002.imd"] = "version = \"23.11\";\ngenerationTime = 2012-12-13T00:26:30.000000Z;\nproductOrderId = \"052869858050_01_P002\";\nproductCatalogId = \"20200100D8BF7900\";\nimageDescriptor = \"Basic1B\";\nbandId = \"P\";\npanSharpenAlgorithm = \"None\";\nnumRows = 33792;\nnumColumns = 35840;\nproductLevel = \"LV1B\";\nproductType = \"Basic\";\nnumberOfLooks = 1;\nradiometricLevel = \"Corrected\";\nbitsPerPixel = 16;\ncompressionType = \"JPEG2000\";\njpegProfileName = \"nga_npje_pan_vl\";\nBEGIN_GROUP = BAND_P\nULLon = -70.54873605;\nULLat = -33.51670435;\nULHAE = 725.41;\nURLon = -70.73776498;\nURLat = -33.51034403;\nURHAE = 525.79;\nLRLon = -70.73735471;\nLRLat = -33.35903054;\nLRHAE = 515.20;\nLLLon = -70.54962703;\nLLLat = -33.36468487;\nLLHAE = 905.05;\nabsCalFactor = 5.678345e-02;\neffectiveBandwidth = 2.846000e-01;\nTDILevel = 32;\nEND_GROUP = BAND_P\noutputFormat = \"NITF21NCDRD\";\nBEGIN_GROUP = IMAGE_1\nsatId = \"WV02\";\nmode = \"FullSwath\";\nscanDirection = \"Reverse\";\nCatId = \"10300100037CAF00\";\nTLCTime = 2009-12-06T14:58:03.358375Z;\nnumTLC = 2;\nTLCList = (\n(0, 0.000000),\n(33656, -1.695800) );\nfirstLineTime = 2009-12-06T14:58:03.358375Z;\navgLineRate = 19846.68;\nexposureDuration = 0.00161236;\nminCollectedRowGSD = 0.498;\nmaxCollectedRowGSD = 0.500;\nmeanCollectedRowGSD = 0.499;\nminCollectedColGSD = 0.498;\nmaxCollectedColGSD = 0.499;\nmeanCollectedColGSD = 0.499;\nmeanCollectedGSD = 0.499;\nmeanProductRowGSD = 0.502;\nmeanProductColGSD = 0.504;\nmeanProductGSD = 0.503;\nrowUncertainty = 29.08;\ncolUncertainty = 34.39;\nminSunAz = 69.0;\nmaxSunAz = 69.3;\nmeanSunAz = 69.2;\nminSunEl = 66.4;\nmaxSunEl = 66.4;\nmeanSunEl = 66.4;\nminSatAz = 311.4;\nmaxSatAz = 314.2;\nmeanSatAz = 312.9;\nminSatEl = 73.5;\nmaxSatEl = 73.9;\nmeanSatEl = 73.7;\nminInTrackViewAngle = 7.6;\nmaxInTrackViewAngle = 8.0;\nmeanInTrackViewAngle = 7.8;\nminCrossTrackViewAngle = -12.2;\nmaxCrossTrackViewAngle = -12.0;\nmeanCrossTrackViewAngle = -12.1;\nminOffNadirViewAngle = 14.4;\nmaxOffNadirViewAngle = 14.4;\nmeanOffNadirViewAngle = 14.4;\nPNIIRS = 5.0;\ncloudCover = 0.004;\nresamplingKernel = \"CC\";\npositionKnowledgeSrc = \"R\";\nattitudeKnowledgeSrc = \"R\";\nrevNumber = 844;\nEND_GROUP = IMAGE_1\nEND;\n";
    strings["09DEC06145803-P1BS-052869858050_01_P002_bin_2.rpb"] = "satId = \"????\";\nbandId = \"RGB\";\nSpecId = \"RPC00B\";\nBEGIN_GROUP = IMAGE\\\nlineOffset = 5109\nsampOffset = -8047\nlatOffset = -33.4374\nlongOffset = -70.6439\nheightOffset = 922\nlineScale = 16828\nsampScale = 17456\nlatScale = 0.08\nlongScale = 0.0959\nheightScale = 501\nlineNumCoef = (\n-0.00264594,\n0.04373632,\n1.05604,\n-0.01132939,\n-0.0004755171,\n1.047585e-005,\n8.342535e-005,\n-0.0003730049,\n0.001854732,\n-2.768628e-007,\n-2.919091e-007,\n3.89137e-007,\n4.417434e-006,\n3.622769e-007,\n4.40662e-006,\n3.690352e-005,\n8.724782e-006,\n-9.940829e-008,\n-4.703967e-007,\n-9.233629e-008);\nlineDenCoef = (\n1,\n0.0006341695,\n0.0008535553,\n-0.0001185298,\n-5.202248e-006,\n1.178422e-007,\n8.999336e-007,\n5.927408e-006,\n-2.176137e-005,\n8.245444e-006,\n-4.43691e-008,\n0,\n2.008929e-006,\n0,\n1.571993e-007,\n1.30458e-005,\n0,\n0,\n-4.168984e-007,\n0);\nsampNumCoef = (\n-0.002787494,\n-1.014879,\n-0.0001342559,\n-0.01222411,\n-0.001193823,\n-0.0003057016,\n0.000109006,\n0.002639235,\n-0.000115734,\n-4.360195e-006,\n-5.144666e-007,\n-4.510677e-008,\n1.077331e-005,\n2.743729e-006,\n-5.15557e-006,\n4.865478e-005,\n7.309242e-008,\n1.645469e-006,\n-1.411975e-006,\n3.371315e-008);\nsampDenCoef = (\n1,\n-0.0001543312,\n-0.001211336,\n-0.0003444029,\n-7.369097e-006,\n1.043191e-006,\n-1.026206e-006,\n1.776887e-006,\n7.241381e-006,\n-2.858965e-006,\n-1.091991e-008,\n-1.171952e-008,\n-1.790362e-007,\n0,\n8.741243e-008,\n-1.159687e-007,\n0,\n0,\n1.188762e-008,\n0);\nEND_GROUP = IMAGE\nEND;\nlvcs\n-70.692764\n-33.458862\n530\n";
    strings["09DEC06145817-P1BS-052869840050_01_P002.imd"] = "version = \"23.11\";\ngenerationTime = 2012-12-13T01:01:52.000000Z;\nproductOrderId = \"052869840050_01_P002\";\nproductCatalogId = \"20200100D8C1D000\";\nimageDescriptor = \"Basic1B\";\nbandId = \"P\";\npanSharpenAlgorithm = \"None\";\nnumRows = 33792;\nnumColumns = 34816;\nproductLevel = \"LV1B\";\nproductType = \"Basic\";\nnumberOfLooks = 1;\nradiometricLevel = \"Corrected\";\nbitsPerPixel = 16;\ncompressionType = \"JPEG2000\";\njpegProfileName = \"nga_npje_pan_vl\";\nBEGIN_GROUP = BAND_P\nULLon = -70.54845267;\nULLat = -33.51641899;\nULHAE = 726.77;\nURLon = -70.73698223;\nURLat = -33.51405506;\nURHAE = 527.89;\nLRLon = -70.73663249;\nLRLat = -33.36273680;\nLRHAE = 516.32;\nLLLon = -70.54931953;\nLLLat = -33.36469749;\nLLHAE = 902.10;\nabsCalFactor = 5.678345e-02;\neffectiveBandwidth = 2.846000e-01;\nTDILevel = 32;\nEND_GROUP = BAND_P\noutputFormat = \"NITF21NCDRD\";\nBEGIN_GROUP = IMAGE_1\nsatId = \"WV02\";\nmode = \"FullSwath\";\nscanDirection = \"Reverse\";\nCatId = \"1030010002BB6200\";\nTLCTime = 2009-12-06T14:58:17.839376Z;\nnumTLC = 2;\nTLCList = (\n(0, 0.000000),\n(33680, -1.739200) );\nfirstLineTime = 2009-12-06T14:58:17.839376Z;\navgLineRate = 19365.23;\nexposureDuration = 0.00165245;\nminCollectedRowGSD = 0.486;\nmaxCollectedRowGSD = 0.487;\nmeanCollectedRowGSD = 0.486;\nminCollectedColGSD = 0.497;\nmaxCollectedColGSD = 0.498;\nmeanCollectedColGSD = 0.497;\nmeanCollectedGSD = 0.492;\nmeanProductRowGSD = 0.502;\nmeanProductColGSD = 0.516;\nmeanProductGSD = 0.509;\nrowUncertainty = 24.44;\ncolUncertainty = 35.73;\nminSunAz = 68.9;\nmaxSunAz = 69.3;\nmeanSunAz = 69.1;\nminSunEl = 66.4;\nmaxSunEl = 66.5;\nmeanSunEl = 66.4;\nminSatAz = 282.3;\nmaxSatAz = 286.1;\nmeanSatAz = 284.3;\nminSatEl = 75.8;\nmaxSatEl = 75.8;\nmeanSatEl = 75.8;\nminInTrackViewAngle = 0.8;\nmaxInTrackViewAngle = 1.1;\nmeanInTrackViewAngle = 0.9;\nminCrossTrackViewAngle = -12.6;\nmaxCrossTrackViewAngle = -12.4;\nmeanCrossTrackViewAngle = -12.5;\nminOffNadirViewAngle = 12.6;\nmaxOffNadirViewAngle = 12.6;\nmeanOffNadirViewAngle = 12.6;\nPNIIRS = 5.0;\ncloudCover = 0.020;\nresamplingKernel = \"CC\";\npositionKnowledgeSrc = \"R\";\nattitudeKnowledgeSrc = \"R\";\nrevNumber = 844;\nEND_GROUP = IMAGE_1\nEND;\n";
    strings["09DEC06145817-P1BS-052869840050_01_P002_bin_2.rpb"] = "satId = \"????\";\nbandId = \"RGB\";\nSpecId = \"RPC00B\";\nBEGIN_GROUP = IMAGE\\\nlineOffset = 4451\nsampOffset = -7953\nlatOffset = -33.4395\nlongOffset = -70.6435\nheightOffset = 922\nlineScale = 16840\nsampScale = 17032\nlatScale = 0.0772\nlongScale = 0.0959\nheightScale = 501\nlineNumCoef = (\n-0.002365931,\n0.01557625,\n1.01921,\n-0.003474112,\n-0.0004825288,\n3.357694e-006,\n9.941763e-005,\n-0.0004544508,\n0.001607839,\n-1.909392e-007,\n-6.777044e-007,\n5.909931e-007,\n8.960757e-006,\n5.81189e-007,\n2.326514e-005,\n0.0001377724,\n3.791193e-005,\n-1.386158e-007,\n-5.742475e-007,\n-1.289108e-007);\nlineDenCoef = (\n1,\n0.0005352095,\n0.0007124099,\n-0.0001095409,\n-8.382742e-006,\n-3.638535e-007,\n1.130617e-006,\n2.490357e-005,\n-8.236239e-005,\n3.718215e-005,\n-5.232261e-008,\n3.283087e-008,\n7.0871e-006,\n3.914178e-008,\n3.633325e-007,\n0.0002244597,\n-1.535671e-008,\n0,\n-2.344788e-006,\n0);\nsampNumCoef = (\n-0.002756063,\n-1.016848,\n-0.0001003955,\n-0.01397387,\n-0.0009654424,\n-0.0003034329,\n0.0001058744,\n0.00280471,\n4.592958e-005,\n-4.012769e-006,\n-8.34248e-007,\n-1.581688e-006,\n6.31908e-006,\n1.808836e-006,\n-5.657072e-006,\n2.405801e-005,\n5.088772e-008,\n1.660197e-006,\n-1.096983e-007,\n2.585779e-008);\nsampDenCoef = (\n1,\n4.514118e-005,\n-0.0009805011,\n-0.0003470964,\n-7.501846e-006,\n1.068501e-006,\n-4.180832e-007,\n2.467518e-006,\n4.831575e-006,\n-1.935385e-006,\n-1.127505e-008,\n0,\n-1.297185e-007,\n0,\n9.024252e-008,\n-2.109139e-007,\n0,\n0,\n0,\n0);\nEND_GROUP = IMAGE\nEND;\nlvcs\n-70.692764\n-33.458862\n530\n";
    strings["09DEC06145817-P1BS-500060999100_01_P002.imd"] = "version = \"23.11\";\ngenerationTime = 2013-03-25T20:06:58.000000Z;\nproductOrderId = \"500060999100_01_P002\";\nproductCatalogId = \"2020011E5E2E3900\";\nimageDescriptor = \"Basic1B\";\nbandId = \"P\";\npanSharpenAlgorithm = \"None\";\nnumRows = 30720;\nnumColumns = 34816;\nproductLevel = \"LV1B\";\nproductType = \"Basic\";\nnumberOfLooks = 1;\nradiometricLevel = \"Corrected\";\nbitsPerPixel = 16;\ncompressionType = \"JPEG2000\";\njpegProfileName = \"nga_npje_pan_vl\";\nBEGIN_GROUP = BAND_P\nULLon = -70.54846912;\nULLat = -33.48181331;\nULHAE = 699.44;\nURLon = -70.73687673;\nURLat = -33.47951220;\nURHAE = 514.31;\nLRLon = -70.73657825;\nLRLat = -33.34312821;\nLRHAE = 512.15;\nLLLon = -70.54937875;\nLLLat = -33.34504727;\nLLHAE = 906.83;\nabsCalFactor = 5.678345e-02;\neffectiveBandwidth = 2.846000e-01;\nTDILevel = 32;\nEND_GROUP = BAND_P\noutputFormat = \"NITF21NCDRD\";\nBEGIN_GROUP = IMAGE_1\nsatId = \"WV02\";\nmode = \"FullSwath\";\nscanDirection = \"Reverse\";\nCatId = \"1030010002BB6200\";\nTLCTime = 2009-12-06T14:58:17.442576Z;\nnumTLC = 2;\nTLCList = (\n(0, 0.000000),\n(30356, -1.568000) );\nfirstLineTime = 2009-12-06T14:58:17.442576Z;\navgLineRate = 19359.69;\nexposureDuration = 0.00165292;\nminCollectedRowGSD = 0.486;\nmaxCollectedRowGSD = 0.487;\nmeanCollectedRowGSD = 0.486;\nminCollectedColGSD = 0.497;\nmaxCollectedColGSD = 0.498;\nmeanCollectedColGSD = 0.497;\nmeanCollectedGSD = 0.492;\nmeanProductRowGSD = 0.502;\nmeanProductColGSD = 0.516;\nmeanProductGSD = 0.509;\nrowUncertainty = 24.41;\ncolUncertainty = 35.69;\nminSunAz = 69.0;\nmaxSunAz = 69.3;\nmeanSunAz = 69.2;\nminSunEl = 66.4;\nmaxSunEl = 66.5;\nmeanSunEl = 66.4;\nminSatAz = 282.2;\nmaxSatAz = 285.7;\nmeanSatAz = 284.0;\nminSatEl = 75.9;\nmaxSatEl = 75.9;\nmeanSatEl = 75.9;\nminInTrackViewAngle = 0.7;\nmaxInTrackViewAngle = 1.0;\nmeanInTrackViewAngle = 0.9;\nminCrossTrackViewAngle = -12.6;\nmaxCrossTrackViewAngle = -12.4;\nmeanCrossTrackViewAngle = -12.5;\nminOffNadirViewAngle = 12.5;\nmaxOffNadirViewAngle = 12.5;\nmeanOffNadirViewAngle = 12.5;\nPNIIRS = 5.0;\ncloudCover = 0.013;\nresamplingKernel = \"CC\";\npositionKnowledgeSrc = \"R\";\nattitudeKnowledgeSrc = \"R\";\nrevNumber = 844;\nEND_GROUP = IMAGE_1\nEND;\n";
    strings["09DEC06145817-P1BS-500060999100_01_P002_bin_2.rpb"] = "satId = \"????\";\nbandId = \"RGB\";\nSpecId = \"RPC00B\";\nBEGIN_GROUP = IMAGE\\\nlineOffset = 10474\nsampOffset = -7951\nlatOffset = -33.4123\nlongOffset = -70.6436\nheightOffset = 979\nlineScale = 15178\nsampScale = 17028\nlatScale = 0.0697\nlongScale = 0.0958\nheightScale = 501\nlineNumCoef = (\n-0.001581208,\n0.01685885,\n1.021392,\n-0.003770469,\n-0.0004818991,\n3.615673e-006,\n0.0001008016,\n-0.000503781,\n0.001223366,\n-5.266555e-008,\n3.247754e-007,\n-1.642952e-007,\n2.041539e-006,\n-5.435146e-007,\n-2.56555e-005,\n-0.0001192393,\n-3.286015e-005,\n4.565219e-008,\n8.799491e-007,\n1.21594e-007);\nlineDenCoef = (\n1,\n0.0005276126,\n0.0002848843,\n-0.000108828,\n1.226855e-006,\n5.598811e-007,\n-1.075696e-006,\n-2.304797e-005,\n6.97758e-005,\n-3.217881e-005,\n-1.278391e-007,\n-1.783555e-008,\n1.662461e-005,\n-3.227639e-008,\n7.192261e-008,\n0.0002938649,\n3.181733e-008,\n0,\n-3.22235e-006,\n0);\nsampNumCoef = (\n-0.003333667,\n-1.016592,\n-3.861694e-005,\n-0.01394302,\n-0.0008684311,\n-0.0002976944,\n9.560289e-005,\n0.003093719,\n5.289319e-005,\n-3.968707e-006,\n-5.756276e-007,\n-2.597929e-006,\n5.956679e-006,\n2.445229e-006,\n-6.03211e-006,\n1.112038e-005,\n4.826943e-008,\n1.798884e-006,\n1.517848e-008,\n3.443181e-008);\nsampDenCoef = (\n1,\n-0.0002480899,\n-0.000881582,\n-0.0003491762,\n-5.422153e-006,\n1.10487e-006,\n-5.848807e-007,\n2.686398e-006,\n2.761704e-006,\n-2.558868e-006,\n-1.128691e-008,\n0,\n-9.362841e-008,\n0,\n8.781176e-008,\n3.281826e-008,\n0,\n0,\n0,\n0);\nEND_GROUP = IMAGE\nEND;\nlvcs\n-70.692764\n-33.458862\n530\n";
    return strings[old_filename];
}
#endif

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
    if (image_name == "09DEC06145803-P1BS-052869858050_01_P002")
        ni0 = 1103, nj0 = 1344;
    else if (image_name == "09DEC06145817-P1BS-052869840050_01_P002")
        ni0 = 1091, nj0 = 1263;
    else if (image_name == "09DEC06145817-P1BS-500060999100_01_P002")
        ni0 = 1091, nj0 = 1262;
    vil_image_view<float> img0(ni0, nj0);
    for (size_t j = 0; j < nj0; ++j)
        for (size_t i = 0; i < ni0; ++i) {
            img0(i, j) = static_cast<float>(j / 2000.0f + i / 2000.0f);
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
#if 0
  std::vector<unsigned> ref_views =utils.index(mnv);
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

  for (size_t i = 0; i < n; ++i) {
      std::string temp_imd = "./" + files[i] + ".imd";
      std::string temp_rpb = "./" + files[i] + post + ".rpb";
      std::string temp_tif = "./" + files[i] + ".tif";
      vpl_unlink(temp_imd.c_str());
      vpl_unlink(temp_rpb.c_str());
      vpl_unlink(temp_tif.c_str());
  }

#if 0
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
  std::string depth_path = "d:/tests/chiletest/depth.tif";
  utils.save_depth_map(depth_path);
#endif
#if 0
  utils.project_intensities(p);
  utils.print_intensities();
  utils.test_appearance_update();
#endif
}
TESTMAIN( test_belief_prop_utils );
