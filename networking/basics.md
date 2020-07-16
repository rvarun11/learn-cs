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
    
    2. **Privileged Exec Mode (PEM)**: Using __**enable**__
    
    3. **Global Configuration Mode (GCM)**: use __**conf t**__
            - To change Host name, use __**hostname** NewHostName__
            - To add a password, use __**enable** password__
            - To enable encrpytion on passwords, use __**service password-encryption**__
            - To encrypt password more securely, using MD5. use Use __**enable secret** Password__
            - To run **PEM** command on **GCM**, use __**run** PEMcommand__
            - To remove previously configured command, use __**no** PreviousCommand__
            - To view the active config file, use __**show running-config**__
            - To view startup config file, use __**show startup-config**__
            - To save config file, __**write**__ __**write memory**__ & __**copy running-config startup-config**__
            