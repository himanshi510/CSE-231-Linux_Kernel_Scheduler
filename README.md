
#Linux Scheduler 

Change the Linux kernel scheduler in the following ways. For any process, there should be a system call to reduce (and NOT

increase) the chances that the process would be selected for being dispatched.

More specifically, let us assume that a certain process is chosen by the sched-
uler. The system call must pass on information, the additional delay (in msec)

(that has been accepted from the userland) to the scheduler such that anytime
the said process is chosen by the scheduler, it adjusts the vruntime of the said
process so as to delay its selection.
For every process with the same nice value, you must log the timestamps
corresponding to when each process is selected and dispatched to run. It must
reflect the additional delay specified by the user. You may need to have a fresh
look at how vruntime is calculated. This would help you in figuring out how
vruntime could be adjusted to reflect the additionally requested latency.
