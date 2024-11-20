#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dlfcn.h>

// \\ []{}

void lexer(char (*str)[30], char newStr[]) {
  if (newStr[0] == 'c' && newStr[1] == 'a' &&  newStr[2] == 'l' && newStr[3] == 'l' && newStr[4] == ' '){ 
    strcpy(str[0], "call");


    int j = 0;
    for ( int k = 5 ; newStr[k] != '\0' && newStr[k] != '\r' && newStr[k] != '\n' && newStr[k] != ' ' ; k = k +1) {
      if (isalpha(newStr[k]) || newStr[k] == '.' || isdigit(newStr[k]) || newStr[k] == '_' ){
	str[1][j] = newStr[k];
      }
      j = j + 1;
    }

    // Sometimes in debugging it would add an inverted ? at the \0 index
    str[1][j] = '\0';

  } else if(newStr[0] == 'u' && newStr[1] == 's' &&  newStr[2] == 'e' && newStr[3] == ' ') {
    strcpy(str[0], "use");


    int j = 0;
    for ( int k = 4 ; newStr[k] != '\0' && newStr[k] != '\r' && newStr[k] != '\n' && newStr[k] != ' ' ; k = k +1) {
      if ( isalpha(newStr[k]) || newStr[k] == '.' || isdigit(newStr[k]) || newStr[k] == '_') {
	str[1][j] = newStr[k];
      }
      j = j + 1;
    }

    str[1][j] = '\0';

  } else {
    printf("Syntax Error: %s . Not a proper call.\n", newStr);
  } 
}

void use(void **sharedLib, char pathArgument[]) {
  char libraryPath[100] = "./";
  strcat(libraryPath, pathArgument);
  *sharedLib = dlopen(libraryPath, RTLD_NOW);
  if (!sharedLib) {
    fprintf(stderr, "The file is not found or a shared library: %s\n", dlerror());
  } else {
    printf("Library loaded properly\n"); 
  }
}

void call(void (**testFunction)(void), void *libArgument, char* functionArgument){
  *testFunction = (void (*)())dlsym(libArgument, functionArgument);
  if (!testFunction) {
    fprintf(stderr, "The function is not found. %s\n", dlerror());
    return;
  }
}

// ]}

int main(int argc, char *argv[]) {

  // script file var declarations
  FILE *scriptFile;
  scriptFile = fopen(argv[1], "r");
  char scriptArray[50];
  char commandString[2][30];

  // library declarations
  void *sharedLib;
  void (*testFileFunction)(void);

  int menu;
  char userInput[50];

    printf("Menu:  1-Run Script. 2-Enter command. Enter option: ");
    scanf("%d", &menu);

    //Menu 1 run script
  if (menu == 1){
      
      while (fgets(scriptArray, 50, scriptFile)) {
        lexer(commandString, scriptArray);
        if (strcmp(commandString[0],"call") == 0) {
          call(&testFileFunction, sharedLib, commandString[1]);
          testFileFunction();
        } else if (strcmp(commandString[0],"use") == 0) {
          use(&sharedLib, commandString[1]);
          if (!sharedLib) {
          printf("The library is not loaded. ");
         } 
       }
     }  
  } else {
    fgets(userInput, 50, stdin);
  }

  fclose(scriptFile);
  dlclose(sharedLib);

  return 0;
}
