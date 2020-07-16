### Basics of Networking

##### Basics
- [Protocol Data Units](https://www.youtube.com/watch?v=t-ai8JzhHuY):
    1. Data: The data received from the top 3 layers (Application, Presentation & Session)
    2. Segment: Data + L4 Header (from Transport Layer)
    3. Packet: Segment + L3 Header (from the Network Layer, it includes the IP Address)
    4. Frame: Packet + L2 Header & Trailer (from Data Link Layer)

- Switch is a L2 device. It works on frames. 
    
- [Basic Device Security](https://www.youtube.com/watch?v=SDocmq1c05s&)
    
    1. **User Exec Mode (EM)**: Default mode
    
    2. **Privileged Exec Mode (PEM)**: Using `enable`
    
    3. **Global Configuration Mode (GCM)**: use `conf t`
    - To change Host name, use `hostname NewHostName`
    - To add a password, use `enable password`
    - To enable encrpytion on passwords, use `service password-encryption`
    - To encrypt password more securely, using MD5. use Use `enable secret Password`
    - To run **PEM** command on **GCM**, use `run PEMcommand`
    - To remove previously configured command, use `no PreviousCommand`
    - To view the active config file, use `show running-config`
    - To view startup config file, use `show startup-config`
    - To save config file, `write` write memory` `copy running-config startup-config`
            