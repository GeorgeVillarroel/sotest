#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void createTestFile() {
  FILE *testFile = fopen("test_file.txt", "w");
  
  if (testFile == NULL) {
    perror("Need admin to create file here");
    exit(EXIT_FAILURE);
  } else {
    printf("File created\n");
  }

  pclose(testFile);
}

void checkTestFile() {
  FILE *testFile = fopen("test_file.txt", "r");
  
  if (testFile == NULL) {
    perror("File doesnt exists");
    exit(EXIT_FAILURE);
  } else {
    printf("File exists\n");
  } 

  pclose(testFile);
}

void deleteTestFile() {
  int removed = remove("test_file.txt");
  if (removed != 0) {
    printf("File doesnt exist\n");
  } else {
    printf("File deleted\n");
  }
}
