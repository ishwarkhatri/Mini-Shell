#include<unistd.h>

int execute(char **cmd) {
	pid_t pid;
	int status = 1, bg_process = 0;

	int i = 0;
	while(cmd[i] != NULL) {
		if(strcmp(cmd[i], "&") == 0) {
			cmd[i] = NULL;
			bg_process = 1;
			break;
		}
		i++;
	}

	pid = fork();

	//Child process (pid == 0)
	if(pid == 0) {
		execvp(cmd[0], cmd);
		perror("minish: Error to exec cmd");
		exit(-1); 
	} else if(pid < 0) {
		perror("minish: Error to fork new process");
		status = -1;
	}
	else { // parent process

		int i = 0;

		if(!bg_process) {
			pid_t wait_id;
			wait(&wait_id);
			
			if(wait_id < 0) {
				perror("minish: Error while waiting for child to exit");
			}

			status = -1;
		}
	}

	return status;
}

