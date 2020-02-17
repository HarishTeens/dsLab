// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include<time.h>
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include<stdbool.h>
#define PORT 8080 


void reverse(char str[], int length) 
{ 
    int start = 0; 
    int end = length -1; 
    int temp;
    while (start < end) 
    { 
        temp=*(str+start);
        *(str+start)=*(str+end);
        *(str+end)=temp;
        start++; 
        end--; 
    } 
} 
// Implementation of itoa() 
char* itoa(int num, char* str, int base) 
{ 
    int i = 0; 
    bool isNegative = false; 
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
  
    // In standard itoa(), negative numbers are handled only with  
    // base 10. Otherwise numbers are considered unsigned. 
    if (num < 0 && base == 10) 
    { 
        isNegative = true; 
        num = -num; 
    } 
  
    // Process individual digits 
    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
  
    // If number is negative, append '-' 
    if (isNegative) 
        str[i++] = '-'; 
  
    str[i] = '\0'; // Append string terminator 
  
    // Reverse the string 
    reverse(str, i); 
  
    return str; 
} 

void delay(){
    int c, d;
   
   for (c = 1; c <= 32767; c++)
       for (d = 1; d <= 32767; d++)
       {}
}

int main(int argc, char const *argv[]) 
{ 
    srand(time(0));
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0},b[1024]={0},b1[1024]={0}; 
    char *hello = "Hello from server"; 
       
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 

    clock_t rep,req;
    int cnt,temp;
    
    //request time
    valread = read( new_socket , buffer, 1024);
    cnt=atoi(buffer);
    printf("The request Time from client is  %d\n",cnt);
    req=time(NULL);
    //generate random number 
    int rnd=rand()%10+30;
    printf("random number is %d \n",rnd );
    char snum[20];

    // convert 123 to string [buf]
    itoa(rnd, snum, 10);

    //reply time stamp    
    send(new_socket, snum , strlen(snum) , 0 ); 
    rep=time(NULL);    
    printf("The Reply Time from server is  %d\n",rep);
    //read the acknowledgement timestamp
    valread = read( new_socket , b, 1024); 
    cnt=atoi(b);
    //read the number of prime numbers
    valread = read( new_socket , b1, 1024); 
    temp=atoi(b1);
    printf("Number of Prime numbers are %d\n",temp);
    printf("The acknowledgement time from client is %d\n",cnt);
    return 0; 
} 