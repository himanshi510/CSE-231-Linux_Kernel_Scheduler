#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include<stdlib.h>
 #include <sched.h>
#define SYS_reduce_time 449

int main(void )
{


int r = syscall(SYS_reduce_time,getpid(), 100);
printf("returned val %d ",r);
// printf(sched_rr_getinterval());
}