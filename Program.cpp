#ifndef Program_H
#define Program_H
# include "CommandLine.cpp"
# define LSH_TOK_DELIM " \t\r\n\a"
# include<stdio.h>
# include <string.h>
# include <cstring>
# include <unistd.h>
# include <stdlib.h> 
#include <sys/types.h>
#include <sys/wait.h> 
class Program : public CommandLine
{
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
        tokens[pos] = NULL;

        pid_t pid, wpid;
        int child_status;
        pid = fork();
        if (pid == 0) {
        // Child process
            if (execvp(tokens[0], tokens) == -1) {
            perror("rshell error");
            }
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            // Error forking
            perror("rshell error");
        } else {
            // Parent process
            do {
            wpid = waitpid(pid, &child_status, WUNTRACED);
            } while (!WIFEXITED(child_status) && !WIFSIGNALED(child_status));
        }

    }    
};
#endif
/*int main(){
    CommandLine* test = new CommandLine("ls");
    Program* program = new Program;
    program->exe(test);
    
}*/