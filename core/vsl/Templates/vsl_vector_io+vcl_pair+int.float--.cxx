#include <vcl_compiler.h>
#include <utility>
#include <vsl/vsl_pair_io.h>
#include <vsl/vsl_vector_io.hxx>
typedef std::pair<int, float> pair_id;
VSL_VECTOR_IO_INSTANTIATE(pair_id);
