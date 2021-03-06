#include <stdio.h>
#include <unistd.h>
#include <string.h> /* for strncpy */


#include <stdio.h>
#include <net/if.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "include/network.h"


#define INT_TO_ADDR(_addr) \
(_addr & 0xFF), \
(_addr >> 8 & 0xFF), \
(_addr >> 16 & 0xFF), \
(_addr >> 24 & 0xFF)


#define MAX_NETWORKS 3

//TODO assess this buffer. Maybe make into an Alloc ...
network_info_t networks[MAX_NETWORKS] = {0};

int getNetworks(network_info_t* networks_list[])
{

    // grab the addr of the network data.
    *networks_list = networks;


    struct ifconf ifc;
    struct ifreq ifr[10];
    int sd, ifc_num = 0, addr, bcast, mask, network, i;

    /* Create a socket so we can use ioctl on the file
     * descriptor to retrieve the interface info.
     */

    sd = socket(PF_INET, SOCK_DGRAM, 0);

    if (sd < 1)
    {
        return 0;
    }


    ifc.ifc_len = sizeof(ifr);
    ifc.ifc_ifcu.ifcu_buf = (caddr_t)ifr;

    if (ioctl(sd, SIOCGIFCONF, &ifc) == 0)
    {
        ifc_num = ifc.ifc_len / sizeof(struct ifreq);
        //printf("%d interfaces found\n", ifc_num);

        for (i = 0; i < ifc_num; ++i)
        {

            if (ifr[i].ifr_addr.sa_family != AF_INET)
            {
                continue;
            }

            /* display the interface name */
            //printf("%d) interface: %s\n", i+1, ifr[i].ifr_name);
            if (i < MAX_NETWORKS)
            {
                snprintf(networks[i].interface, 50, "%s", ifr[i].ifr_name);
            }

            /* Retrieve the IP address, broadcast address, and subnet mask. */
            if (ioctl(sd, SIOCGIFADDR, &ifr[i]) == 0)
            {
                addr = ((struct sockaddr_in *)(&ifr[i].ifr_addr))->sin_addr.s_addr;
                //printf("%d) address: %d.%d.%d.%d\n", i+1, INT_TO_ADDR(addr));

                if (i < MAX_NETWORKS)
                {
                    snprintf(networks[i].addr, 50, "%d.%d.%d.%d\n", INT_TO_ADDR(addr));
                }
            }

            if (ioctl(sd, SIOCGIFBRDADDR, &ifr[i]) == 0)
            {
                bcast = ((struct sockaddr_in *)(&ifr[i].ifr_broadaddr))->sin_addr.s_addr;
                //printf("%d) broadcast: %d.%d.%d.%d\n", i+1, INT_TO_ADDR(bcast));

                if (i < MAX_NETWORKS)
                {
                    snprintf(networks[i].broadcast, 50, "%d.%d.%d.%d\n", INT_TO_ADDR(bcast));
                }
            }

            if (ioctl(sd, SIOCGIFNETMASK, &ifr[i]) == 0)
            {
                mask = ((struct sockaddr_in *)(&ifr[i].ifr_netmask))->sin_addr.s_addr;
                //printf("%d) netmask: %d.%d.%d.%d\n", i+1, INT_TO_ADDR(mask));
                if (i < MAX_NETWORKS)
                {
                    snprintf(networks[i].netmask, 50, "%d.%d.%d.%d\n", INT_TO_ADDR(mask));
                }
            }

            /* Compute the current network value from the address and netmask. */
            network = addr & mask;
            //printf("%d) network: %d.%d.%d.%d\n", i+1, INT_TO_ADDR(network));
            if (i < MAX_NETWORKS)
            {
                snprintf(networks[i].network, 50, "%d.%d.%d.%d\n", INT_TO_ADDR(network));
            }
        }
    }

    close(sd);

    return ifc_num;
}



/* scan of networks from above code ...
1) interface: lo
1) address: 127.0.0.1
1) broadcast: 0.0.0.0
1) netmask: 255.0.0.0
1) network: 127.0.0.0

2) interface: enp40s0
2) address: 192.168.1.22
2) broadcast: 192.168.1.255
2) netmask: 255.255.255.0
2) network: 192.168.1.0
*/



