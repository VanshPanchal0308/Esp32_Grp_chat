# **ESP32 GROUP CHAT USING MESH PROTOCOL**

![](https://i.imgur.com/sDASVSk.jpg[/img])


---

## **Table Of Contents :**

* [AIM OF THE PROJECT](#AIM-OF-THE-PROJECT)
* [About the Project](#about-the-project)
  * [Tech Stack](#tech-stack)
  * [File Structure](#file-structure)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installations](#installations)
  * [Execution](#execution)
* [Theory and Approach](#theory-and-approach)
* [Code Flow](#Code-Flow)
* [Results and Demo](#results-and-demo)
* [Future Work](#future-work)
* [Contributors](#contributors)
* [Acknowledgements](#acknowledgements)
* [License](#license)

---
## **AIM OF THE PROJECT :**

- The aim of the project is to establish a communication between 3 ESP's ,which is self healing and self repairing using ESP-MESH Protocol.
---
## **About the Project :**
- Objective of the project is to build a chat system between 3 ESP32's development boards.

- The chat system should be fast,secure and easy to use.

- Communication protocol used is ESP-MESH as :

    * It overcomes the drawbacks of traditional wifi.
    
    * It is self healing and self organizing in which if one of the decive losses power or gets disconnected then it automatically gets connected to its preferred device(node).
    
    * Only root node(root device) is need to be connected to router and all other devices are connected to each other by tree topology and hence range exceeds.
--- 

## **Tech Stack :**
- Embedded C
- [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html)
- [FreeRTOS](https://sravjti.in/embedded-systems-study-group/week6/week6.html#xtaskcreate)
- [ESP-WIFI-MESH](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/network/esp-wifi-mesh.html)


---
## **File Structure :**
 ```.
├── Components         # Contains files of specific library of functions or library used        
│    ├──mesh_main.c             # Contains the code to setup connection using ESP-NOW. 
      | -- data_transfer.h    #task and task handle defined. 
      |--mesh_new.h          #Functions used in mesh_main.c defined here.
│    ├──CMakeLists.txt      # To include this component in a esp-idf 
├── docs                    # Documentation files 
│   ├── report.pdf          # Project report
│              
├── main                    # Source files of project
│   ├──main.c               # Main Source code.
│   ├──kconfig.projbuild    # Shows the menu of project configuration
│   ├──CMakeLists.txt       # To include source code files in esp-idf        
     |--command.c            # To include commands of console to be used.
     |--esp_console_repl.c  #Functions to establish a basic REPl(Read-Evaluate-Print-Loop) environment.
     |--split_argv.c  
     |--linenoise.c        #Line editing, provided by linenoise.
     |--linenoise.h
     |--argtable3.h     #Argument parsing,provided by argtable3 library.This library include APIs used for parsing GNU style command line arguments.         
     |--argtable3.c     
├── CmakeLists.txt          # To include components and main folder while       executing
├── LICENSE
└── README.md 
```
 ---

## **Getting Started :**
---
### **Prerequisites :**
- **ESP-IDF v4.0 and above :**
 
     You can visit this site for [installation steps](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html#installation-step-by-step)

### **Installation :**

- **Clone the Repo :**
 
  ```
    git clone https://github.com/VanshPanchal0308/Esp32_Grp_chat
    ```  
    ---
## **Execution :**

- Open ESP-IDF terminal on Windows or terminal on Linux.
- Run get_idf command on terminal.
- Goto repository by typing the command 
```
     cd Esp32_Grp_chat
          
  ```
  - Run the following command for configuration:
```
idf.py menuconfig
```
- After running the above command go to example configuration and set your networks SSID and pasword to which your root node(ESP/device) will 
  get connected. 


- Connect 3 ESP32s through ports and run  the following commands on the the three terminals.

```
idf.py -p /dev/ttyUSB0 flash monitor
```
```
idf.py -p /dev/ttyUSB1 flash monitor
```
- Run this on 3rd terminal of another device :
```
idf.py flash monitor
```
- Let the ESPs boot and after all parents and childs are connected and network is established then start the communication.

---
## **Theory and Approach :**

ESP-WIFI-MESH differs from traditional infrastructure Wi-Fi networks in that nodes are not required to connect to a central node. Instead, nodes are permitted to connect with neighboring nodes. Nodes are mutually responsible for relaying each others transmissions. This allows an ESP-WIFI-MESH network to have much greater coverage area as nodes can still achieve .

![](https://i.imgur.com/feUofJS.jpg)

This naturally results in a tree network topology with a parent-child hierarchy consisting of multiple layers.

Every node in ESP-WIFI-MESH that is able to form downstream connections (i.e. has a softAP interface) will periodically transmit Wi-Fi beacon frames. A node uses beacon frames to allow other nodes to detect its presence and know of its status.

- **Beacon Frames & RSSI Thresholding:** Every node in ESP-WIFI-MESH that is able to form downstream connections (i.e. has a softAP interface) will periodically transmit Wi-Fi beacon frames. A node uses beacon frames to allow other nodes to detect its presence and know of its status.The signal strength of a potential upstream connection is represented by RSSI (Received Signal Strength Indication) of the beacon frames of the potential parent node. 

- **Preferred Parent Node:** When an idle node has multiple parent nodes candidates (potential parent nodes), the idle node will form an upstream connection with the preferred parent node. 

- **About Routing Table:** Each node w**ithin an ESP-WIFI-MESH network will maintain its individual routing table used to correctly route ESP-WIFI-MESH packets (see ESP-WIFI-MESH Packet) to the correct destination node. The routing table of a particular node will consist of the MAC addresses of all nodes within the particular node’s subnetwork (including the MAC address of the particular node itself). Each routing table is internally partitioned into multiple subtables with each subtable corresponding to the subnetwork of each child node.

 - **How Root Node Is Selected:** Each idle node will transmit their MAC addresses and router RSSI values via Wi-Fi beacon frames.  Each idle node will transmit their MAC addresses and router RSSI values via Wi-Fi beacon frames.After all iterations, each node will individually check for its vote percentage to determine if it should become the root node.

 - **Root Node Failure:** If the root node breaks down, the nodes connected with it (second layer nodes) will promptly detect the failure of the root node. The second layer nodes will initially attempt to reconnect with the root node. However after multiple failed attempts, the second layer nodes will initialize a new round of root node election. The second layer node with the strongest router RSSI will be elected as the new root node whilst the remaining second layer nodes will form an upstream connection with the new root node.

- **Intermediate Parent Node Failure:** If an intermediate parent node breaks down, the disconnected child nodes will initially attempt to reconnect with the parent node. After multiple failed attempts to reconnect, each child node will begin to scan for potential parent nodes.

- **ESP-WIFI-MESH Packet:** ESP-WIFI-MESH network data transmissions use ESP-WIFI-MESH packets. ESP-WIFI-MESH packets are entirely contained within the frame body of a Wi-Fi data frame. A multi-hop data transmission in an ESP-WIFI-MESH network will involve a single ESP-WIFI-MESH packet being carried over each wireless hop by a different Wi-Fi data frame.

- **Broadcasting:** Broadcasting is a feature that allows a single ESP-WIFI-MESH packet to be transmitted simultaneously to all nodes within the network. Each node essentially forwards a broadcast packet to all of its upstream and downstream connections such that the packet propagates throughout the network as quickly as possible


- ## **To Read and Learn the concepts in detail** [click here](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/esp-wifi-mesh.html#beacon-frames-rssi-thresholding)


- ## **To Go Through Basic Network Concepts** [click here](https://github.com/VanshPanchal0308/Esp32_Grp_chat/blob/dev_vansh/Resources/esp32_mesh_term.md)

---

## **Code Flow :**

![](https://i.imgur.com/vjsY8Kc.jpg)

---

## **Result And Demo :**

[Link to Demo Video](https://drive.google.com/drive/u/0/folders/1DhAgahlRMg8CsrKlBjflM9mjCFsvVGq0)


## **Future work :**
- Add http server chat interface.
- Add encryption to the chat communication.

---
## **Contributors :**

- Vansh Panchal
- Aryan Karawale
---

## **Acknowledgements :**

 - [SRA VJTI](https://sravjti.in/) Eklavya 2022
 - Special Thanks to our mentors :
      
      * Rishikesh Donadkar
      * Krishna
      * Viraj

## **License :**

- The [License](https://github.com/VanshPanchal0308/Esp32_Grp_chat/blob/working_code_1/LICENSE) used for this project.
 
---
---

    
        





 