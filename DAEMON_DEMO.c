
/*Daemons example*/

/* A daemon has 7 steps*/

/* First:   Fork off the pattern process & let it terminate*/
/* Second:  setsid. Create a new process*/
/* Third:   catch signals. ignore/handle signals.*/
/* Fourth:  Fork again. This is to allow the pattern process to terminate*/
/* Fifth:   chdir The working directory of the daemon must be changed*/
/* Sixth:   umask this must be change the file mode mask ccording to the daemons needs*/
/* Seventh: close Close all the open file descriptor that may be inherited from the parent process*/



/*needed libraries to get the function and process id*/
#include <stio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>

	
static void sructure_daemon()
{
	pid_t pid;
	pid = fork();

	if(pid < 0)
		exit(EXIT_FAILURE);

	if (pid > 0)
		exit(EXIT_SUCESS); 


	if(setsid() < 0)
	       exit(EXIT_FAILURE);

	signal(SIGCHLD, SIG_IGN);
	signal(SIGHUP, SIG_IGN);

	pid = fork(); 	
	
		if(pid < 0)
			exit(EXIT_FAILURE);

		if (pid > 0)
			exit(EXIT_SUCESS); 
		
		umask(0);

		chdir("/");

		int x;

		for(x = sysconf(_SC_OPEN_MASK); x>0; x--)
		{
			close(x);
		}

		openlog("DamenHere", LOG_PID, LOG_DAEMON);
	
}

int main()  /*call the main function*/

{ 
	structure_daemon();
	for(;;)
	
	{
		syslog (LOG_NOTICE, "DAEMON HAS STARTED");
		sleep(20);
		break;

	}

	syslog(LOG_NOTICE, "DAEMON has terminated") /*locate your syslog*/
	close /*your/syslogfile goes here*/
	
	return EXIT_SUCCESS;


}

int main()

{	


