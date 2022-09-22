#ifndef __ESP_MESH_H__
#define __ESP_MESH_H__

#include <stdbool.h>
#include "esp_err.h"
#include "esp_wifi_types.h"

#ifdef __cplusplus
extern "C" {
#endif
void esp_mesh_p2p_tx_main(void *arg);




 void espmesh_start();


 void esp_mesh_p2p_rx_main(void *arg);


 

 esp_err_t esp_mesh_comm_p2p_start(void);


 void mesh_event_handler( void *arg, esp_event_base_t  event_base,  int32_t event_id, void *event_data);


 void ip_event_handler(void *arg, esp_event_base_t event_base,int32_t event_id, void *event_data);


void esp_main() ;





#ifdef __cplusplus
}
#endif

#endif 
