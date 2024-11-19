#include <stdio.h>
#include <stdlib.h>

//
// \\ []{}

int main() {

  // int arraySize=0;

  FILE *scriptFile;
  scriptFile = fopen("test.sc", "r");

  char scriptArray[50];
  
  fgets(scriptArray, 50, scriptFile);
  
  // for (int i = 0; i < 50; i = i + 1){
  //   printf("(%c)",scriptArray[i]);
  // }

  printf("%s",scriptArray);

  fclose(scriptArray);

  return 0;
}
