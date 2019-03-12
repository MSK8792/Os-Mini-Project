#include <stdio.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include<stdlib.h>

int main() 
{
	char fname[50], buffer[1025],s1[100];
	int sd, source, size, file, n,num, arr[100],lower,upper,prime,i,j=0;
	struct sockaddr_in address;
		
	address.sin_family = AF_INET;	
	address.sin_port = htons(15000);	
	address.sin_addr.s_addr = INADDR_ANY;
	
	printf("Waiting for request... \n");
	
	sd = socket(AF_INET, SOCK_STREAM, 0);	
	bind(sd, (struct sockaddr*)&address, sizeof(address));
	listen(sd, 3);
	
	source = accept(sd, (struct sockaddr*)NULL, NULL);
	recv(source, fname, sizeof(fname), 0);
	printf("Received request for: %s \n", fname);
	FILE *fptr;
	fptr = fopen(fname,"r");
	  printf("\nPerforming Operations...\n");
 while ( (num = getw(fptr)) != EOF ) {
    lower=num;
    upper=lower;
  }
	lower=lower-40;  
      for(n=lower+1; n<upper; n++)
   {
     prime = 1;
     for(i=2; i<n/2; i++)
       if(n%i == 0)
       {
         prime = 0;
         break;
       }
     if(prime)
     {
     	arr[j]=n;
     	j++;
     }
   }
   
   
   for(i=0;i<11;i++){
   	s1[i]=arr[i];
  	send(source, buffer, s1[i], 0);
  }	
	fclose(fptr);				
	printf("\nResponse sent. \n");
	//close(file);
	return 0;
}


