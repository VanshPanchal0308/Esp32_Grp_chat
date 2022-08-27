# ESP-WIFI-MESH Terminologies And Concepts:
## Here are some basic concepts that will be used further:

## What is Networking Protocol:
A communication protocol is a system of rules that allows two or more entities of a communications system to transmit information via any kind of variation of a physical quantity. The protocol defines the rules, syntax, semantics and synchronization of communication and possible error recovery methods. Protocols may be implemented by hardware, software, or a combination of both.

- Link for what is Networking Protocol:
[Click here for link](https://youtu.be/BnWn18qUYyA) 

---
## What is Wireless Networks:
A wireless network refers to a computer network that makes use of Radio Frequency (RF) connections between nodes in the network. Wireless networks are a popular solution for homes, businesses, and telecommunications networks.

- Types Of wireless networks:
1. **Wireless Local Area Network (LAN)**: Links two or more devices using a wireless distribution method, providing a connection through access points to the wider Internet.
2. **Wireless Metropolitan Area Networks (MAN)**: Connects several   wireless LANs.
3. **Wireless Wide Area Network (WAN)**: Covers large areas such as neighboring towns and cities.
4. **Wireless Personal Area Network (PAN)**: Interconnects devices in a short span, generally within a person’s reach. 

- Link for what is wireless networks:
[Click here for link](https://youtu.be/jLW_P12fZvQ)

---
## What is Wireless Networking Protocol:
The wireless communication protocol is a standard set of rules with reference to which various electronic devices communicate with each other wirelessly. 

- Different Types of Wireless Protocols:
1. WIFI
2. Bluetooth
3. ZigBee
4. Z-wave
5. RFID
6. LoRaWAN

- Link for how to select different Wireless protocols based of usage:
[Click here for link](https://youtu.be/7eNU4rvdTC0)

---

## What is Network Topology:
Network topology is used to describe the physical and logical structure of a network. It maps the way different nodes on a network--including switches and routers--are placed and interconnected, as well as how data flows.Network topology plays a major role in how a network functions. Namely, the topology has a direct effect on network functionality. Choosing the right topology can help increase performance, as a properly chosen and maintained network topology increases energy efficiency and
- Types Of Topologies:
1. **Bus Topology**
2. **Ring Topology**
3. **Tree Topology**
4. **Star Topology**
5. **Hybrid Topology**
6. **Mesh Topology:**

**Link for Terminologies of Tree topology**[Click here](https://youtu.be/1juJchA4yMI)

**Link for Network Topologies**
[click here for youtube video](https://youtu.be/LvX6S1rzNSQ)

---
## What is esp wifi mesh: 
- ESP-WIFI-MESH differs from traditional infrastructure Wi-Fi networks in that nodes are not required to connect to a central node. Instead, nodes are permitted to connect with neighboring nodes. Nodes are mutually responsible for relaying each others transmissions. This allows an ESP-WIFI-MESH network to have much greater coverage area as nodes can still achieve. ESP-WIFI-MESH is also less susceptible to overloading as the number of nodes permitted on the network is no longer limited by a single central node.
ESP-WIFI-MESH is **self-organizing** and **self-healing** meaning the network can be built and maintained autonomously. ESP-WIFI-MESH allows nodes to simultaneously act as a station and an AP. Therefore a node in ESP-WIFI-MESH can have multiple downstream connections using its softAP interface, whilst simultaneously having a single upstream connection using its station interface.The connections in a ESP MESH leads to a TREE topology.
---
## What is softAP:
 SoftAP is an abbreviated term for "software enabled access point". This is software enabling a computer which hasn't been specifically made to be a router into a wireless access point. It is often used interchangeably with the term "virtual router".
SoftAP is a common method of configuring Wi-Fi products without a display or input device, such as a Wi-Fi enabled appliance, home security camera, smart home product or any other IoT device. The process typically involves these steps:

- The headless device turns on a SoftAP Wi-Fi hotspot.

- The user downloads a product-specific app on a smartphone, and the app then either uses the underlying Android or iOS operating system to connect to the SoftAP hotspot, or directs the user to connect the phone manually.

- The app then asks the user for the user's private Wi-Fi network name (SSID) and passkey.
 
- The app sends the SSID and passkey to the headless device over the SoftAP connection.

- The headless device then falls off the SoftAP network and joins the user's private Wi-Fi network.

---
**Link for what is hub,subnet,router and basic networking terms**[Click here](https://youtu.be/_IOZ8_cPgu8)

---
## Now here is the Doc for entire concept of ESP-WIFI-MESH [Click here](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/esp-wifi-mesh.html#routing-tables)








