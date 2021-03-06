
# Linux Scheduler

We change the Linux Kernel Scheduler in the following ways. 

## System Call

For any process, there is a system call to reduce (and NOT increase) the chances that the process would be selected for being dispatched. More specifically, let us assume that a certain process is chosen by the scheduler. The system call passes on information, the additional delay (in msec) (that has been accepted from the userland) to the scheduler such that anytime the said process is chosen by the scheduler,
it adjusts the vruntime of the said process so as to delay its selection. 


## Time Stamp

For every process with the same nice value, it logs the timestamps corresponding to when each process is selected and dispatched to run. It reflect the additional delay specified by the user. You may need to have a fresh look at how vruntime is calculated. This would help you in figuring out how vruntime could be adjusted to reflects the additionally requested latency.
