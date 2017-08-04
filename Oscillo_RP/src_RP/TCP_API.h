#ifndef TCP_API_H
#define TCP_API_H

#include<stdio.h> //for printf
#include<stdlib.h> //for exit()
#include<stdint.h> //int16_t etc
#include<sys/socket.h> //for socket
#include<sys/types.h> //utile?
#include<arpa/inet.h> //for inet_addr
#include<errno.h> //for error
#include<unistd.h> //for close()
#include<netdb.h> //for gethostbyname
#include<pthread.h> //for thread

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADiDR;
typedef struct client client; //structure that contained client informations
typedef struct server_info server_info; //structure need to make thread with server routinr

void init_struct_client(client* client_list,unsigned int Nmax); //initialise client structure
void clear_struct_client(client* client_list); //free malloc on struct client
void add_client(client* client_list, SOCKET sock_server); //TCP server is initialised it add new client informations in structure client
void clear_client(client* client_list,unsigned int id); //clear client with id_client==id form structure client and reorganize the structure
int init_TCP_client(SOCKET* sock, const char* IP, int Port, bool &conn); //initialise TCP client
int int_converter(char x);
void get_RP_settings(SOCKET *sock);
void init_TCP_server(SOCKET* sock, int Port, client* client_list,unsigned int MaxClient); //initialise TCP server
void *TCP_server_routine(void* p_data); //server routine function for thread, server turn in parallel to main
void launch_server(SOCKET* sock, client* client_list); //function that launch the server in parallel to main
void close_TCP_server(SOCKET* sock, client* client_list); //close client connexion and TCP server (for server)
int close_TCP_client(SOCKET* sock, bool &conn); //close client connexion (for client)
int send_TCP_server(client* client_list, char* buffer, int buff_length, int target); // send buffer of size buff_length to client with id target, if target<0 buffer is sent to all clients for server
void send_TCP_client(SOCKET* sock, char* buffer, int buff_length); //send buffer of size buff_length to server for client
int receive_TCP_server(client* client_list, char* buffer, int buff_length, int target); //receive buffer of size buff_length from client with id target for server
int receive_TCP_client(SOCKET* sock, char* buffer, int buff_length); //receive buffer of size buff from server for client
int send_int16_TCP_server(client* client_list, int16_t *buffer, int buff_length, int target); //same as send_TCP_server but the variable sent are coded on 2 bytes (16 bits int) instead only one use with receive_int16_TCP_client
int receive_int16_TCP_client(SOCKET* sock, int16_t * buffer, int buff_length); //receive 16 bits buffer of size buff_length from server, use with send int16_TCP_server

#endif //TCP_API_H
