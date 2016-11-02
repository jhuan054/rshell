#ifndef Execute_H
#define Execute_H
#pragma GCC diagnostic ignored "-Wwrite-strings"
# define LSH_TOK_DELIM " \t\r\n\a"
# include<stdio.h>
# include <string.h>
# include <cstring>
# include <unistd.h>
# include <stdlib.h> 
# include <sys/types.h>
# include <sys/wait.h> 
# include "Program.cpp"
# include "BuiltIn.cpp"
class Execute : public CommandLine
{
    protected:
    bool cont;
    bool exitShell = 1;
    
    public:
    //Execute(string command):CommandLine(){this->commandNeed = command;};
    void exe(CommandLine* command){
        char* arg;
        char* token;
        char* tokens[100];
        int pos = 0;
        arg = new char [command->out().length() +1];
	    strcpy (arg, command->out().c_str());

        token = strtok(arg, LSH_TOK_DELIM);

        while (token != NULL) {
            tokens[pos] = token;
            pos++;
            token = strtok(NULL, LSH_TOK_DELIM);
        }
    
        char* builtinCommand[]={
            "exit",
            //"cd"
            //"help";
        };
        BuiltIn* builtin = new BuiltIn();
        Program* program = new Program();
        if(tokens[0] == NULL){
            this->cont = 0;
        }
        //cout<<builtin->num_evl()<<endl;
        for (unsigned i = 0; i < builtin->num_evl(); i++) {
            if (strcmp(tokens[0], builtinCommand[i]) == 0) {
                builtin->exe(command);
                if(builtin->out()=="f"){
                    this->exitShell = 0;
                }
                return;
            }
        }
        //cout<<command->out();
        program->exe(command);
        this->cont = 1;
        return;
    }  
    bool exitevl(){
        return this->exitShell;
    }
    
    bool contevl(){
        return this->cont;
    }

    
};
/*int main(){
    CommandLine* test = new CommandLine("ls -l");
    Execute* execute = new Execute;
    execute->exe(test);
    cout<<execute->exitevl()<<endl;
}*/
#endif
