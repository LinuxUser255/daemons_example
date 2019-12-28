# sweet_daemons
This code demonstrates the workings and 7 step proces of a Linux daemon.
I wrote it in a CentOS VM and it's a bit buggy so couldn't complie it.

First:   Fork off the pattern process & let it terminate.
Second:  setsid. Create a new process.
Third:   catch signals. ignore/handle signals.
Fourth:  Fork again. This is to allow the pattern process to terminate.
Fifth:   chdir The working directory of the daemon must be changed.
Sixth:   umask. this must be change the file mode mask ccording to the daemons needs.
Seventh: close. Close all the open file descriptor that may be inherited from the parent process.
