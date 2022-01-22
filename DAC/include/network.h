#ifndef NETWORK_H
#define NETWORK_H


typedef struct
{
    char interface[50];
    char addr[50];
    char broadcast[50];
    char netmask[50];
    char network[50];
} network_info_t;




int getNetworks(network_info_t* networks_list[]);

#endif // NETWORK_H
