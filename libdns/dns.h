#pragma once

#include <stdint.h>

#include <liblog/log.h>

typedef struct {
    int v;
    union {
       unsigned char v4[4];
       unsigned char v6[16];
    } data;
} addr_t;

typedef struct {
  int port;
  int datattl;
  int nsttl;
  const char *host;
  const char *ns;
  const char *mbox;
  int (*cb)(void *opt, addr_t *addr, int max, int ipv4, int ipv6);
  // stats
  uint64_t nRequests;
} dns_opt_t;

extern int dnsserver(dns_opt_t *opt);
