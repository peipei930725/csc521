#ifndef __COMMON_H__
#define __COMMON_H__

#include <errno.h>
#include <pcap/pcap.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/*=======================*
 ***** Control Flags *****
 ========================*/

#define FG_NATIVE_CYGWIN 1

#define FG_ARP_SEND_REQUEST 0
#define FG_ICMP_SEND_REQUEST 1

#define DEBUG_PACKET 1
#define DEBUG_PACKET_DUMP 0
#define DEBUG_ARP 1
#define DEBUG_ARP_REQUEST 1
#define DEBUG_ARP_REPLY 1
#define DEBUG_ARP_DUMP 1

#define DEBUG_ARPCACHE 1
#define DEBUG_IP 1
#define DEBUG_ICMP 1

#define DEBUG_CHECKSUM 1

/*
 * For libpcap that doesn't support WinPcap
 */
#ifndef PCAP_OPENFLAG_PROMISCUOUS
#define PCAP_OPENFLAG_PROMISCUOUS 1
#endif

/*===========================*
 ***** Common Parameters *****
 *===========================*/

/*
 * The buffer length of MAC address string
 */
#define BUFLEN_ETH 18

/*
 * The buffer length of IP address string
 */
#define BUFLEN_IP 16

/*
 * How many bytes should print_data() show
 */
#define MAX_DUMP_LEN 80

/*
 * How many bytes per row should print_data() show
 */
#define MAX_LINE_LEN 16

/*
 * The maximum length of a string buffer
 */
#define MAX_LINEBUF 256

/*=================================================*
 ***** Assigned Numbers and Protocol Prameters *****
 *=================================================*/
#define ETH_IP 0x0008
#define ETH_ARP 0x0608

#define ETH_ADDR_LEN 6
#define IPV4_ADDR_LEN 4

typedef uint32_t ipaddr_t;

#define COPY_ETH_ADDR(dst, src) (memcpy((dst), (src), ETH_ADDR_LEN))
#define COPY_IPV4_ADDR(dst, src) (memcpy((dst), (src), IPV4_ADDR_LEN))

typedef uint32_t ipaddr_t;

/*===============================*
 ***** Global Configurations *****
 *===============================*/
extern uint8_t myethaddr[ETH_ADDR_LEN];
extern uint8_t myipaddr[IPV4_ADDR_LEN];
extern uint8_t myrouterip[IPV4_ADDR_LEN];
extern uint8_t mynetmask[IPV4_ADDR_LEN];

extern uint8_t defarpip[IPV4_ADDR_LEN];
extern uint8_t defpingip[IPV4_ADDR_LEN];

/*===================*
 ***** Utilities *****
 *===================*/

extern int readready();
extern char *time2decstr(time_t t);
extern ipaddr_t retrieve_ip_addr(char *ip);
extern char *ip_addrstr(uint8_t *ip, char *buf);
extern char *eth_macaddr(const uint8_t *a, char *buf);

extern void print_ip(uint8_t *ip, char *msg);
extern void print_data(const uint8_t *data, int len);

extern uint16_t swap16(uint16_t s);
extern uint32_t swap32(uint32_t val);
extern uint16_t checksum(uint8_t *ptr, int len);

#define GET_IP(ipaddr) (*((ipaddr_t *)(ipaddr)))
#define SET_IP(dip, sip) (*((ipaddr_t *)(dip)) = *((ipaddr_t *)(sip)))
#define IS_MY_IP(ipaddr) ((GET_IP(ipaddr)) == GET_IP(myipaddr))

#define GET_NET_ID(ip) ((*((ipaddr_t *)(ip))) & (*((ipaddr_t *)mynetmask)))
#define IS_MY_NET(ip) ((GET_NET_ID(ip)) == GET_NET_ID(myipaddr))

#endif /* __COMMON_H__ */