include_directories( ${VXLCORE_INCLUDE_DIR} )

set(bsgm_sources
    bsgm_census.h                          bsgm_census.cxx
    bsgm_disparity_estimator.h             bsgm_disparity_estimator.cxx
    bsgm_multiscale_disparity_estimator.h  bsgm_multiscale_disparity_estimator.cxx
    bsgm_align_pointsets_3d.h              bsgm_align_pointsets_3d.hxx
    bsgm_prob_align_pointsets_3d.h         bsgm_prob_align_pointsets_3d.hxx
    bsgm_pairwise_dsm.h                    bsgm_pairwise_dsm.cxx
    bsgm_prob_pairwise_dsm.h               bsgm_prob_pairwise_dsm.cxx
   )

aux_source_directory(Templates bsgm_sources)

vxl_add_library(LIBRARY_NAME bsgm LIBRARY_SOURCES ${bsgm_sources})

target_link_libraries( bsgm vidl_pro ${VXL_LIB_PREFIX}vgl_io ${VXL_LIB_PREFIX}vgl_algo ${VXL_LIB_PREFIX}vil_algo ${VXL_LIB_PREFIX}vnl_algo ${VXL_LIB_PREFIX}vnl ${VXL_LIB_PREFIX}vgl ${VXL_LIB_PREFIX}vil ${VXL_LIB_PREFIX}vul ${VXL_LIB_PREFIX}vcl)

add_subdirectory( app )

add_subdirectory( pro )

#if( BUILD_TESTING )
#  add_subdirectory(tests)
#endif()
