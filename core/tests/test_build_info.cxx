// vxl/core/tests/test_build_info.cxx

// Based on ITK, Testing/Code/Common/itkSystemInformationTest.cxx

#include "test_build_info.h"
#include <vcl_ios.h>
#include <vcl_iostream.h>
#include <vcl_fstream.h>
#include <vcl_string.h>
#include <vcl_map.h>
#include <vcl_ctime.h>
#include <testlib/testlib_test.h>

// Construct the name of the notes file.
#define vxl_BUILD_INFO_NOTES \
  vxl_BUILD_DIR "/Testing/HTML/TestingResults/Sites/" \
  vxl_SITE "/" vxl_BUILD_NAME "/BuildNameNotes.xml"

static vcl_string
get_current_date_time (const char * format)
{
  char buf[1024];
  vcl_time_t t;
  vcl_time (&t);
  vcl_strftime (buf, sizeof(buf), format, vcl_localtime(&t));
  return buf;
}

static void
system_information_print_file (const char * name, vcl_ostream & os,
                               bool note = false )
{
  if ( ! note)
    os << "================================\n";

  vcl_ifstream fin (name, vcl_ios::in);

  if (fin)
  {
      if ( ! note)
          os << "Contents of \"" << name << "\":\n"
             << "--------------------------------\n";

      // Writing out character by character is potentially slow, but
      // that's the easiest way to XMLize the output. This is not
      // performance critical code, so it's probably okay. Besides,
      // the output stream is buffered, which should help.

      vcl_string buffer;

      // Assume the string encoding is ASCII
      vcl_map<char, char const*> mapping;
      mapping['&'] = "&amp;";
      mapping['<'] = "&lt;";
      mapping['>'] = "&gt;";

      // Range of printable characters
      char const lo( 32 );
      char const hi( 126 );
      char const cr( '\r' );
      char const nl( '\n' );

      while( fin ) {
        vcl_getline( fin, buffer );
        for( unsigned i = 0; i < buffer.size(); ++i ) {
          char const& c = buffer[i];
          // Assume a \r at the end or a \n at the beginning is due to
          // mixed line-ending conversions not being handled by the
          // stream library, and so supress them.
          if( c == nl && i == 0 ||
              c == cr && i == buffer.size()-1 )
            ; // do nothing
          else if( mapping.find( c ) != mapping.end() )
            os << mapping[c];
          else if( buffer[i] < lo || buffer[i] > hi )
            os << "<strong>&lt;" << unsigned(buffer[i]) << "&gt;</strong>";
          else
            os << buffer[i];
        }
        os << "\n"; // the \n is not stored by vcl_getline
      }
      os.flush();
  }
  else
  {
      os << "Could not open \"" << name << "\" for reading.\n";
  }
}

static void test_build_info()
{
  const char* files[] =
    {
      // Note.txt is meant to be created by hand if desired for a build
      vxl_BUILD_DIR "/Note.txt",
      // files below all may be generated by CMake
      vxl_BUILD_DIR "/CMakeCache.txt",
      vxl_BUILD_DIR "/CMakeError.log",
      vxl_BUILD_DIR "/core/vxl_config.h",
      vxl_BUILD_DIR "/vcl/vcl_config_compiler.h",
      vxl_BUILD_DIR "/vcl/vcl_config_headers.h",
      vxl_BUILD_DIR "/vcl/vcl_config_manual.h",
      0
    };

  const char** f;
  for (f = files; *f; f++)
  {
      system_information_print_file (*f, vcl_cout);
  }

  vcl_ofstream outf (vxl_BUILD_INFO_NOTES, vcl_ios::out);
  if (outf)
  {
      vcl_cout << "Also writing this information to file "
               << vxl_BUILD_INFO_NOTES << '\n';

      outf << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
           << "<Site BuildName=\"" << vxl_BUILD_NAME
           << "\"  Name=\"" << vxl_SITE << "\">\n"
           << "<BuildNameNotes>\n";

      for (f = files; *f; ++f)
      {
          outf << "<Note Name=\"" << *f << "\">\n"
               << "<DateTime>"
               << get_current_date_time ("%a %b %d %Y %H:%M:%S %Z")
               << "</DateTime>\n"
               << "<Text>\n";

          system_information_print_file (*f, outf, true);

          outf << "</Text>\n"
               << "</Note>\n";
      }

      outf << "</BuildNameNotes>\n"
           << "</Site>\n";
  }
  else
  {
      vcl_cerr << "Error writing this information to file "
               << vxl_BUILD_INFO_NOTES << '\n';
      testlib_test_perform(false);
  }
}

TESTMAIN(test_build_info);
