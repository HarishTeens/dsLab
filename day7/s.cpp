
// Client side C/C++ program to demonstrate Socket programming 
#include<time.h>
#include<bits/stdc++.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 8080 

using namespace std;

/* A utility function to reverse a string  */
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

bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 
// Function to print primes 
int printPrime(int n) 
{ 
    int cnt=0;
    for (int i = 2; i <= n; i++) { 
        if (isPrime(i)) {
            cnt++;
            printf("%d ",i);
        }
    } 
    return cnt;
} 



int readFile(int x){
    int ret;
    static const char filename[] = "map.txt";
    FILE *file = fopen(filename, "r");
    int count = 0;
    if ( file != NULL )
    {
        char line[256]; /* or other suitable maximum line size */
        while (fgets(line, sizeof line, file) != NULL) /* read a line */
        {
            if (count == x-1)
            {
                //use line or in a function return it
                //in case of a return first close the file with "fclose(file);"
     
                ret=atoi(line);
                break;
            }
            else
            {
                count++;
            }
        }
        fclose(file);
    }
    else
    {
        //file doesn't exist
    }

    return ret;
}


int checkHit(queue<pair<int,int> > g,int x){

    int ret=-1;

 
    while (!g.empty()) 
    { 
        if(g.front().first==x){
          
            ret=g.front().second;
            break;
        }
        g.pop(); 
    }     
    return ret;
}

int manageFault(queue<pair<int,int> > &q,int x){
    int ret=readFile(x);
    if(q.size()==5){
        q.pop();        
    }
    q.push(make_pair(x,ret));
    
    return ret;
}

   
int main(int argc, char const *argv[]) 
{     
    srand(time(0));
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0};     
       
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

    char snum[10];
    time_t t;
    int i;
    queue<pair<int,int> > fcfs;
    for(i=0;i<100;++i){
        valread = read( new_socket , buffer, 1024); 
        int rnd=atoi(buffer);
        int output=checkHit(fcfs,rnd);
        
        if(output==-1){
            output=manageFault(fcfs,rnd);
        }

        itoa(output, snum, 10);
        send(new_socket , snum , strlen(snum) , 0 );     
    }    
    
    return 0; 
} 
