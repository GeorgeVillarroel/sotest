#include <stdio.h>
#include <dlfcn.h>

// \\ []{}

// ]}

int main() {

  char userInput[50];

  while (userInput[0] != '3') {

    printf("Menu \n 1- \n 2- \n 3- \n Enter Option: ");
    fgets(userInput, 50, stdin );    
      if (userInput[0] == '1') {
        printf("inside the 1 if");    
      } 
    printf("%s", userInput );
  } 
}
