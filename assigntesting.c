#include <stdio.h>
#include <dlfcn.h>

// \\ []{}


void call(void (**testFunction)(void), void *libArgument, char* pathArgument) {
  *testFunction = (void (*)())dlsym(libArgument, pathArgument);
  if (!testFunction) {
    fprintf(stderr, "The function is not found. %s\n", dlerror());
    return;
  } 
}

// ]}

int main() {

  void *handle;
  void (*testFunction)(void);
  char* commandString = "createTestFile";

      
  handle = dlopen("./lib_test_filing.so", RTLD_NOW);
  if (!handle) {
    fprintf(stderr, "The file is not found or a shared library: %s\n", dlerror());
    return 1;
  }
  call(&testFunction, handle, commandString);
  
  testFunction();

  dlclose(handle);

  return 0;
}
