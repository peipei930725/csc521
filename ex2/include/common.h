#ifndef __COMMON_H__
#define __COMMON_H__

#include <errno.h>
#include <pcap/pcap.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

/*=======================*
 ***** Control Flags *****
 ========================*/

#define FG_NATIVE_CYGWIN 1
#define FG_ARP_SEND_REQUEST 1

#define DEBUG_PACKET 1
#define DEBUG_PACKET_DUMP 0
#define DEBUG_ARP 1
#define DEBUG_ARP_REQUEST 1
#define DEBUG_ARP_REPLY 1
#define DEBUG_ARP_DUMP 1

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

/*===============================*
 ***** Global Configurations *****
 *===============================*/
extern uint8_t myethaddr[ETH_ADDR_LEN];
extern uint8_t myipaddr[IPV4_ADDR_LEN];
extern uint8_t defarpip[IPV4_ADDR_LEN];

/*===================*
 ***** Utilities *****
 *===================*/
extern int readready();
extern char *time2decstr(time_t t);
extern ipaddr_t retrieve_ip_addr(char *ip);
extern char *ip_addrstr(unsigned char *ip, char *buf);
extern char *eth_macaddr(const unsigned char *a, char *buf);

extern void print_ip(unsigned char *ip, char *msg);
extern void print_data(const unsigned char *data, int len);
extern uint16_t swap16(uint16_t x);

#define COPY_ETH_ADDR(dst, src) (memcpy((dst), (src), ETH_ADDR_LEN))
#define COPY_IPV4_ADDR(dst, src) (memcpy((dst), (src), IPV4_ADDR_LEN))
#define GETIP(ipaddr) (*((ipaddr_t *)(ipaddr)))
#define ISMYIP(ipaddr) ((GETIP((ipaddr))) == GETIP(myipaddr))

#endif /* __COMMON_H__ */
