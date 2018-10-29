#include <stdio.h>
#include "tcpheader.h"

int getSourcePort(const unsigned char* tcp_hdr)
{
	int src_port;
	src_port = (tcp_hdr[0] << 8) | (tcp_hdr[1]);
	return src_port;
}

int getDestinationPort(const unsigned char* tcp_hdr)
{
	int dest_port;
	dest_port = (tcp_hdr[2] << 8) | (tcp_hdr[3]);
	return dest_port;
}

void setSourcePort(unsigned char* tcp_hdr, int port)
{
	tcp_hdr[0] = port >> 8;
	tcp_hdr[1] = port & 0x00FF;
}

void setDestinationPort(unsigned char* tcp_hdr, int port)
{
	tcp_hdr[2] = port >> 8;
	tcp_hdr[3] = port & 0x00FF;
}

int getAckFlag(const unsigned char* tcp_hdr)
{
	if (tcp_hdr[13] & 0x10)
	{
		return 1;
	}
	return 0;
}

void setAckFlag(unsigned char* tcp_hdr, int flag)
{
	if (flag){
		tcp_hdr[13] = tcp_hdr[13] | 0x10;
	}
	else {
		tcp_hdr[13] = tcp_hdr[13] & 0xEF;
	}
}

int getDataOffset(const unsigned char* tcp_hdr)
{
	unsigned int length = 0;
	length = (tcp_hdr[12] & 0xF0) >> 4;
	return length;
}

void setDataOffset(unsigned char* tcp_hdr, int offset)
{
	tcp_hdr[12] = (offset << 4) | (tcp_hdr[12] & 0x0F);
}
