### Basics of Networking

- [OSI Model Layers](https://www.youtube.com/watch?v=t-ai8JzhHuY)
    1. **Physical**: 
    - Deals with the physical medium. 
    - Coversion of digital bits to electrical(wired) / radio(wireless) and vice-versa for transmision.
    - Considers voltages, transmission, physical connectors, etc. 
    2. **Data Link**: 
    - Provides Node-Node connectivity.
    - Switches operate on L2.
    3. **Network**:
    - Provides connectivity between different hosts.
    - IP Addressing.
    - Path Selection.
    - Routers operate on L3.
    4. **Transport**:
    - Provides Host-Host communication.
    - Breaks and resassembles data so that it can be sent easily over the network.
    5. **Session**:
    - Controls the session by establishing, managing and terminating connection between applications (eg. Web Browser & Youtube, etc)
    6. **Presentation**:
    - It translates the data so that it can be used appropriately by the network.
    7. **Application**:
    - Closest to end user. Interacts with software applications.
    - HTTP & HTTPS are L7 protocols.
    - Syncing the communication.
    
    **Protocol Data Units**
    1. Data: The data received from the top 3 layers (Application, Presentation & Session)
    2. Segment: Data + L4 Header (from Transport Layer)
    3. Packet: Segment + L3 Header (from the Network Layer, it includes the IP Address)
    4. Frame: Packet + L2 Header & Trailer (from Data Link Layer)
    5. Raw Bits: the bits which are transmitted by L1.

- [Basic Device Security](https://www.youtube.com/watch?v=SDocmq1c05s&)
    1. **User Exec Mode (EM)**: Default mode
    
    2. **Privileged Exec Mode (PEM)**: Using `enable`
    
    3. **Global Configuration Mode (GCM)**: use `conf t`
    - To change Host name, use `hostname NewHostName`
    - To add a password, use `enable password`
    - To enable encrpytion on passwords, use `service password-encryption`
    - To encrypt password more securely, using MD5. use Use `enable secret Password`
    - To run **PEM** command on **GCM**, use `do PEMcommand`
    - To remove previously configured command, use `no PreviousCommand`
    - To view the active config file, use `show running-config`
    - To view startup config file, use `show startup-config`
    - To save config file, use either `write` `write memory` or `copy running-config startup-config`

- [Ethernet LAN Switching](https://youtu.be/5q1pqdmdPjo)
    - {L2 Header & Trailer}(https://youtu.be/u2n762WG0Vo?t=352)
        - Ethernet Header has 5 fields:
            - *Preamble*: 7bytes. Consists of alternating 1s & 0s. Allows devices to sync the receiver clocks.
            - *Start Frame Delimiter (SFD)*: 1byte. Similar to Preamble but the last bit is 1. Marks the ends of Preamble.
            - *Destination* & *Source*: Contains the destination MAC addr which is 6bytes long.
            - *Type / Length*: 2bytes. If value < 1500, it represents *length*, if value > 1536 it indicates the type. 
        - Eth. Trailer has only 1 field, *Frame Check Sequence (FCS)* which is 4bytes long. Detects corrupted data using CRC algo. 
        - Total Size = 26bytes.
        - Preamble and SFD aren't usually considered the part of the Eth. Header.
    - *OUI*: 3 bytes. Portion in a MAC assigned to identify the maker of the device.

    - Ethernet Frame Payload min. size = 46 bytes. (64 - 18). 18 bytes are taken by the Eth. header (without Preamble & SFD) & trailer. 
    - ARP is used to find L2 addr (MAC addr.) of a known L3 addr (IP addr) 
        - It has two msgs: *ARP Request* & *ARP Reply*
            - ARP Request is broadcast.
            - ARP Reply is unicast.
    - Ping is used to test reachablility to a specific device in a network.
        - It uses two msgs: *ICMB Echo Request* & *ICMP Echo Reply*
             
- [IPv4 Addressing](https://youtu.be/3ROdsfEUuhs)
    - Netmask: It is a term used to divide the IP address into subnets and tell the available hosts in the network.
    - IP Addresses are of two types:
        1. Network Address: the host portion of the addr is 0. It is the first addr of the network and cannot be assigned to a host.
        2. Broadcast Address: the host portion of the addr is 1 (For eg. 192.168.1.255). It the last addr of the network & can't be assigned to a network.
