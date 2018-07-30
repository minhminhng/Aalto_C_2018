struct tcpHeader {
    unsigned short src_port;
    unsigned short dest_port;
    unsigned int seq_number;
    unsigned int acknowledgment;
    unsigned int offset;  // in bytes
    char ns;
    char cwr;
    char ece;
    char urg;
    char ack;
    char psh;
    char rst;
    char syn;
    char fin;
    unsigned int window;
    unsigned int checksum;
    unsigned int urg_ptr;
};


// Returns the 16-bit value of the source port
int getSourcePort(const unsigned char *tcp_hdr);

// Returns the 16-bit value of the destination port
int getDestinationPort(const unsigned char *tcp_hdr);

// Set the source port field in TCP header as indicated in the port parameter
void setSourcePort(unsigned char *tcp_hdr, int port);

// Set the destination port field in TCP header as indicated in the port parameter
void setDestinationPort(unsigned char *tcp_hdr, int port);

// Return the ACK flag which indicating the significance of the Acknowledge field
int getAckFlag(const unsigned char *tcp_hdr);

// Set the ACK flag as bit on or bit off
void setAckFlag(unsigned char *tcp_hdr, int flag);

// Return the length of the header
int getDataOffset(const unsigned char *tcp_hdr);

// Set the data offset field
void setDataOffset(unsigned char *tcp_hdr, int offset);
