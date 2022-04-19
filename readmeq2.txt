to compile
make compile2
to run 
make run2
.....................
in qq2.c 
for message queue; one structure is made to store indices of strings that are passed ; ohter is for storing strings
in st1 struc, it is used to get value of highestindex;
it has one field as long which stores mesaage type;
in my_msgbuf , there is mtype and array of structure st;
so thta we can send array of 5 strings 10 times;
ftok uses the identity of the file give by its pathname and id which generates key_t type key which we can use with msgget    
msgget is used to get the message queue identifier associated with key and make conection
there are 2 msg queues; each of which have a diff. id
since we have to recieve all the arrays of structure;
we have a loop of 10 

the indices of strings and corresponding string are printed
also for return msg type is set to 2.
int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
in ours we have msqid already set which we got by msgget,structure address, its size,flg as 0
msgsnd is used ot send msg.
ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp,
               int msgflg); used to recieve msg 
here msgtype is 1 or 2 accordingly as written in program.

in qq1.c
similar structures are declared
here we are using rand() to generate randome generate strigns of length 4;
and then we copy these into our char_array which is 2d array
then we copy values of this char_arr into structure st's mtext array;
we copy 5 strings at a time into mtext and similar for index array as well;
so in 10 structure array we have copied all the 50 elements in grps of 5
ftok and msgget have same functionality as earlier
we send the 10 structures throigh msgsnd
and recieve the returned structure to get val of highest index if it matched we 
continue with loop else we break

client.c.............
in syscall socket()
0 is backlog parameter
AF_UNIX is domain oscket
SOCK_STREAMis to specify byte oriented protocol
stucture st is send through socket and st is same as earlier
we swrite the structure whose size is 400
and read integer which is highest index
server.c
we unlink to delete the l so that no ther process sees it
we bind socket to socket address which is file path
we use
listen which sets the socket state to listen
accept blocks as long oas there no incoming requests
socket type , lenth of sock_addr which is populated 
loop runs till we have reached eof or error

p1.c
structure as before
two fifo ff1 which is used to write only nad ff2 which is used to read only
we open them fd is file descriptor and wrote the structure array to fifo size 400 iof arrstructure passed
if write returns -1 or read returns -1 it is error 
we write in ff1 and read form ff2 the index hiighest returned
in p2.c we declare mkfifo ff1 and ff2
mkfifo() makes FIFO a special file with pathname and mode that reads/writes or both
and open fifo ff1 as read only and ff2 as write inly 
we read the structure and print values of string and indices and then write highest index to fifo with fd2 
if reader gets 0 return value that indicated that we have reached end of file