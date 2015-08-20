#include <stdio.h>
#include <string.h> 
#include <unistd.h>

#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(){

FILE *fp;

char returnData[64];
const char s= "*";
char *token;

token = strtok(returnData, s);

fp = popen("/sbin/ifconfig eth0", "r");

while (fgets(returnData, 64, fp) token != NULL)
{
    printf("%s", token);
    
    token = strtok(NULL, s);
}

pclose(fp);
}
