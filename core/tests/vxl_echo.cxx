#include <vxl_copyright.h>
#include <vxl_version.h>
#include <vcl_compiler.h>
#include <iostream>

int main (int argc, char * argv[])
{
  for (int i = 1; i < argc; ++i)
  {
    if (argv[i][0] == 'n' && argv[i][1] == 'l' && argv[i][2] == 0)
      std::cout << std::endl;
    else
      std::cout << argv[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
