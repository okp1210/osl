#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;
int main()
{
int pipefd[2], n;
char buffer[200];
pid_t p;
pipe(pipefd);
p = fork();
if (p > 0) {
close(pipefd[0]);
cout << "Parent passing value to child" << endl;
write(pipefd[1], "hello\n", 6);
close(pipefd[1]);
wait(0);
}
else if (p == 0) {
close(pipefd[1]);
cout << "Child printing received value" << endl;
n = read(pipefd[0], buffer, sizeof(buffer));
write(1, buffer, n);
close(pipefd[0]);
}
else {
cout<<"Error!";
return 1;
}
return 0;
}
