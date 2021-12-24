#ifndef __TCP_H__
#define __TCP_H__

#include "ip.h"

/***
 ***	TCP
 ***/

/*============================*
 ***** Protocol Constants *****
 *============================*/
#define TCP_FG_URT 0x20
#define TCP_FG_ACK 0x10
#define TCP_FG_PSH 0x08
#define TCP_FG_RST 0x04
#define TCP_FG_SYN 0x02
#define TCP_FG_FIN 0x01

/*=========================*
 ***** Protocol Format *****
 *=========================*/
typedef struct {
  uint16_t srcport;
  uint16_t dstport;
  uint32_t seq;
  uint32_t ack;
  uint8_t hlen;
  uint8_t flags;
  uint16_t window;
  uint16_t chksum;
  uint16_t urgent;
  uint8_t data[1];
} mytcp_hdr_t;

typedef struct {
  uint16_t srcport;
  uint16_t dstport;
  myip_param_t ip;
} mytcp_param_t;

/*========================*
 ***** Public Methods *****
 *========================*/
extern void tcp_main(mypcap_t *p, uint8_t *pkt, int len);
extern void tcp_send(mypcap_t *p, mytcp_param_t tcp_param, uint8_t *payload,
                     int payload_len);

/*===========================*
 ***** Private Utilities *****
 *===========================*/
#define tcphlen(tcp) (((tcp)->tcp_hlen >> 4) << 2)
#define tcphlen_set(tcp, n) ((tcp)->tcp_hlen = (((n) >> 2) << 4))
#define tcpflag(tcp, flag) (((tcp)->tcp_flags & (flag)) != 0)
#define tcpflag_set(tcp, flag) ((tcp)->tcp_flags |= (flag))

#endif /* __TCP_H__ */
