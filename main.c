#if defined(_WIN32) || defined(_WIN64)
  #error "Windows is not supported by this software."
#else
  #include <sys/stat.h>
  #include <sys/types.h>
  #include <stdio.h>
#endif

int main(int argc, char* argv[]) {
  return 0;
}