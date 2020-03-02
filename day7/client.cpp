
// Client side C/C++ program to demonstrate Socket programming 
#include<time.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 8080 

using namespace std;

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

    int sock = 0, valread; 
    struct sockaddr_in serv_addr;     
    char buffer[1024] = {0}; 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
    srand(time(0));
    char snum[10];
    clock_t t1,t2;
    double lat=0;    
    int i;
    t1=clock();
    for(i=0;i<100;++i){
        int rnd=rand()%9+1;
        printf("The random number generated is %d \n",rnd );
        
        // convert 123 to string [buf]
        itoa(rnd, snum, 10);
        //send the random number
        
        send(sock , snum , strlen(snum) , 0 ); 
        
        valread = read( sock , buffer, 1024); 
        
        rnd=atoi(buffer);
        printf("The output is %d \n",rnd );
        
    }

    t2=clock();
    lat= ((double) (t2-t1)) / CLOCKS_PER_SEC;
    printf("The total latency is %f \n",lat );
    return 0; 
} 
