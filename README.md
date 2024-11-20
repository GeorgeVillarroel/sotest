# Test: SO
scripting language interpreter for shared function libraries.

### Compilation & execution
gcc -finput-charset=utf-9 hello.c -ldl -o sotest <br />
./sotest test.sc <br />

## Test Shared Libraries
### lib_test_filing
functions for handling files <br />
createTestFile(): create a test_file.txt empty <br />
checkTestFile(): check if theres a test_file.txt in the root dir of the project <br />
deleteTestFile(): delete the test_file.txt if is in the directory <br />

### lib_test_output
functions for printf in console <br />
helloWorld(): prints "Hello World!" <br />
goobyeWorld(): prints "Goobye World!" <br />

### test_output
![clear console](image-runtime-0.png)
![program commands on the console](image-runtime-1.png)

## Machine

Oracle VirtualBox <br />
Xubuntu 18.04.5 <br />
32bit i686 <br />
![xubuntu](i686.png)