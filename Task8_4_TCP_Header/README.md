# TCP header

#### Parse header
Implement the following functions that each read and return one field from the TCP header. In order to parse the fields, you will need to find the respective bits in the TCP header, and leverage bitwise operations to represent the value as a single integer return parameter.

All functions get the pointer to the beginning of TCP header as a parameter.

* `getSourcePort` returns the source port. This is a 16-bit value, but you will need to process each byte separately. I.e.: if header[0] is 0xac, and header[1] is 0xde, you will need to return integer 0xacde. For this you will need to apply bitwise operations.

* `getDestinationPort` returns the destination port. The same note applies here as above regarding handling of 16-bit values.

* `getAckFlag` returns the value of ACK flag (either 0 or 1)

* `getDataOffset` returns the length of the header (i.e., the data offset)

#### Write header
Implement the following functions to produce parts of a TCP header. Each function gets an integer value as a parameter, that should be placed in right location in TCP header.

* `setSourcePort` that sets the source port field in TCP header as indicated in the port parameter. You will need to handle each byte separately: the most significant eight bits are placed at header[0], and least significant eight bits at header[1].

* `setDestinationPort` that sets the destination port field as indicated in the port parameter. The byte order is as described above.

* `setAckFlag` that sets the ACK bit on or off depending on whether the function argument is 0 (off) or non-zero (on).

* `setDataOffset` that sets the data offset field.

In each function, only the given TCP header field can change, and all other parts of the header must remain unchanged.
