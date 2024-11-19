#include <stdio.h>
#include <stdlib.h>

// \\ []{}

int sizeCalculator(char nameFile[]) {
  FILE *testFile;
  testFile = fopen(nameFile, "r");
  int lines = 0;
  char lineString[50];

  while (fgets(lineString, 50, testFile)) {
    lines = lines + 1;
  }

  fclose(testFile);

  return lines;
}

int main(int argc, char *argv[]) {

  // use function to calculate the amount of lines in the file script
  int arraySize = sizeCalculator(argv[1]);

  FILE *scriptFile;
  scriptFile = fopen(argv[1], "r");

  char scriptArray[arraySize];
   
  while (fgets(scriptArray, arraySize, scriptFile)) {;
    printf("%s",scriptArray);
  }

  fclose(scriptFile);

  return 0;
}
