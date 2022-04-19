a new syscall reduce_time was initialized in syscall table
also it is defined in sys.c
we get the pid of the process from the argument. from this pid
we get the task and update its delay to passed value in syscall. 
when we fork() a new structure task_struct is created for the new process 
we are defining delay in it. declared delay in linux/sched.h in sched_entity structure.
vruntime is updated in sched/fair.c in update_curr function where this delay is added in current vruntime
delay is intialised to 0 in sched_fork in core.c
in our syscall definition;
we find the pid of task by using pid_task(find_vpid(pid),PIDTYPE_PID) 
using this task we get the sched entity assigned to task and update its delay variable to passed value;
in test.c we pass process id to syscall using getpid() and delay 100 which is in u64 which sends pid of current process and we can check the
logs to see if syscall works and vruntime is increased.

