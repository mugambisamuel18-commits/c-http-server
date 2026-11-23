#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")
#define PORT 8080
#define BUFFER_SIZE 4096
int main(){
    WSADATA wsa;
    SOCKET server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    int client_len= sizeof(client_addr);
char buffer[BUFFER_SIZE];
if(WSAStartup(MAKEWORD(2,2),&wsa)!=0){
    printf("WSAStartup failed.Error code:%d\n",WSAGetLastError());
     return 1;
}
server_fd=socket(AF_INET,SOCK_STREAM,0);
if(server_fd==INVALID_SOCKET){
printf("Could not create socket:%d\n",WSAGetLastError());
WSACleanup();
return 1;
}
server_addr.sin_family=AF_INET;
server_addr.sin_addr.s_addr=INADDR_ANY;
server_addr.sin_port=htons(PORT);
if(bind(server_fd,(struct sockaddr *)&server_addr,sizeof(server_addr))==SOCKET_ERROR){
    printf("Bind failed:%d\n",WSAGetLastError());
    closesocket(server_fd);
    WSACleanup();
    return 1;
}
listen(server_fd,5);
printf("HTTP Server running on http://localhost:%d\n",PORT);
while(1){
client_fd=accept(server_fd,(struct sockaddr *)&client_addr,&client_len);
if(client_fd==INVALID_SOCKET){
continue;
}
memset(buffer,0,BUFFER_SIZE);
recv(client_fd,buffer,BUFFER_SIZE - 1,0);
printf("---Incoming Reguest---\n%s\n",buffer);
const char *response=
"HTTP/1.1 200 OK\r\n"
"Content-Type: text/html\r\n"
"Content-Length: 110\r\n"
"Connection: close\r\n\r\n"
"<!DOCTYPE html><body>"
"<h1>C HTTP Server Running!</h1>"
"<p>Phase 1 Socket connection successful.</p>"
"</body></httml>";
int sent = send(client_fd,response,(int)strlen(response),0);
printf("send result:%d\n",sent);
printf("Respond sent.\n");
closesocket(client_fd);
}
closesocket(server_fd);
WSACleanup();
return 0;
}

