#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
using namespace std;


void read_command(){
    char* userinput;
    char delim[] = " ";
    cin.getline(userinput,256);
    char* cmd = strtok(userinput,delim);

    system(cmd);
}
int main(){
    while(1){
        if(system(NULL)){
            cout << "Command Processor is ready" << endl;
            cout << "#";
        }
        else   
            cout << "Command Processor is not ready\n";

        std::thread CreateThread(read_command);

        CreateThread.join();
    }   
}
   /*
    std::string userinput;
    std::string subCommand;
    std::string subString;

    getline(cin,userinput);

    string::iterator it = userinput.end();

    std::string first_token = userinput.substr(0, userinput.find(' '));
    std::string second_token = userinput.substr(userinput.find(' '));
    subCommand = first_token;
    subString = second_token;
    
    int commandSize = sizeof(subCommand)+ 1;
    char* charCommand[commandSize];


    system(first_token.c_str());
*/