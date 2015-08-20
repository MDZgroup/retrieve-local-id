#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* fp;
	char returnData[64];
        
	fp = popen("/sbin/ifconfig eth0", "r");
	char x[100][100];
	int i = 0;
	
	while (fgets(returnData, 64, fp) != NULL)
	{
     char* token = strtok(returnData, ":");
		while(token != NULL)
		{			
			strcpy(x[i], token);
			i++;
    		token = strtok(NULL," ");
		}	      
	}
	printf("Local IP Address : %s \n", x[6]);
	pclose(fp);
}
