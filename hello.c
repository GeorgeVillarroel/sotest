#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void parser(char (*str)[30], char newStr[]) {
  if (newStr[0] == 'c' && newStr[1] == 'a' &&  newStr[2] == 'l' && newStr[3] == 'l' && newStr[4] == ' '){ 
    strcpy(str[0], "call");
  } else if(newStr[0] == 'u' && newStr[1] == 's' &&  newStr[2] == 'e' && newStr[3] == ' ') {
    strcpy(str[0], "use");
  } else {
    printf("Syntax Error: %s . Not a proper call.\n", newStr);
  }
  printf("%s\n", str[0]);
}

// ]}

int main(int argc, char *argv[]) {

  // use function to calculate the amount of lines in the file script
  int arraySize = sizeCalculator(argv[1]);

  FILE *scriptFile;
  scriptFile = fopen(argv[1], "r");

  char scriptArray[arraySize];
  char commandString[2][30];

  while (fgets(scriptArray, arraySize, scriptFile)) {;
    // printf("%s",scriptArray);
    parser(commandString, scriptArray);
    printf("%s",commandString[0]);
  }

  fclose(scriptFile);

  return 0;
}
