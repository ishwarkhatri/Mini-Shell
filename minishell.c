#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "fileio.h"
#include "process.h"

int main() {

	while(1) {
		printf("\nminish>");
		char *cmd = read_line_from_stdout();
		
		char **tokens = tokenize(cmd);

		int status = execute(tokens);
	}	

}


