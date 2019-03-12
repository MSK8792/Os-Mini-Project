#include <stdio.h>
#include<stdlib.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) 
{
	char fname[50], buffer[1025];
	int sd, n , low, high,arr[100],prime,i,j,m;
	struct sockaddr_in address;
	
	address.sin_family = AF_INET;
	address.sin_port = htons(15000);
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	if((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
			perror("socket"); 
	connect(sd, (struct sockaddr*)&address, sizeof(address));
	
	printf("Enter lower limit :");
	scanf("%d",&low);
	
	printf("Enter upper limit :");
	scanf("%d",&high);
	
	
	FILE *f = fopen("data.txt", "w");
	printf("Enter a filename: ");
	scanf("%s", fname);
	
	printf("Sending request... \n");
	send(sd, fname, sizeof(fname), 0);	// send a message on a socket
	
	printf("Received response: \n");
	while((m = recv(sd, buffer, sizeof(buffer), 0)) > 0) ;	// receive a message from a socket

	for(n=low+1; n<high; n++)
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
   
   
   for(i=0;i<11;i++)
   	printf("%d\n",arr[i]);
	
	
	return 0;
}
