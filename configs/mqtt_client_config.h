/******************************************************************************
* File Name:   mqtt_client_config.h
*
* Description: This file contains all the configuration macros used by the
*              MQTT client in this example.
*
* Related Document: See README.md
*
*
*******************************************************************************
* Copyright 2020-2022, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/

#ifndef MQTT_CLIENT_CONFIG_H_
#define MQTT_CLIENT_CONFIG_H_

#include "cy_mqtt_api.h"

/*******************************************************************************
* Macros
********************************************************************************/

/***************** MQTT CLIENT CONNECTION CONFIGURATION MACROS *****************/
/* MQTT Broker/Server address and port used for the MQTT connection. */
#define MQTT_BROKER_ADDRESS               "192.168.1.107"
#define MQTT_PORT                         8883

/* Set this macro to 1 if a secure (TLS) connection to the MQTT Broker is  
 * required to be established, else 0.
 */
#define MQTT_SECURE_CONNECTION            ( 1 )

/* Configure the user credentials to be sent as part of MQTT CONNECT packet */
#define MQTT_USERNAME                     ""
#define MQTT_PASSWORD                     ""


/********************* MQTT MESSAGE CONFIGURATION MACROS **********************/
/* The MQTT topics to be used by the publisher and subscriber. */
#define MQTT_PUB_TOPIC                    "ledstatus"
#define MQTT_SUB_TOPIC                    "ledstatus"

/* Set the QoS that is associated with the MQTT publish, and subscribe messages.
 * Valid choices are 0, 1, and 2. Other values should not be used in this macro.
 */
#define MQTT_MESSAGES_QOS                 ( 1 )

/* Configuration for the 'Last Will and Testament (LWT)'. It is an MQTT message 
 * that will be published by the MQTT broker if the MQTT connection is 
 * unexpectedly closed. This configuration is sent to the MQTT broker during 
 * MQTT connect operation and the MQTT broker will publish the Will message on 
 * the Will topic when it recognizes an unexpected disconnection from the client.
 * 
 * If you want to use the last will message, set this macro to 1 and configure
 * the topic and will message, else 0.
 */
#define ENABLE_LWT_MESSAGE                ( 0 )
#if ENABLE_LWT_MESSAGE
    #define MQTT_WILL_TOPIC_NAME          MQTT_PUB_TOPIC "/will"
    #define MQTT_WILL_MESSAGE             ("MQTT client unexpectedly disconnected!")
#endif

/* MQTT messages which are published on the MQTT_PUB_TOPIC that controls the
 * device (user LED in this example) state in this code example.
 */
#define MQTT_DEVICE_ON_MESSAGE            "TURN ON"
#define MQTT_DEVICE_OFF_MESSAGE           "TURN OFF"


/******************* OTHER MQTT CLIENT CONFIGURATION MACROS *******************/
/* A unique client identifier to be used for every MQTT connection. */
#define MQTT_CLIENT_IDENTIFIER            "psoc6-mqtt-client"

/* The timeout in milliseconds for MQTT operations in this example. */
#define MQTT_TIMEOUT_MS                   ( 5000 )

/* The keep-alive interval in seconds used for MQTT ping request. */
#define MQTT_KEEP_ALIVE_SECONDS           ( 60 )

/* Every active MQTT connection must have a unique client identifier. If you 
 * are using the above 'MQTT_CLIENT_IDENTIFIER' as client ID for multiple MQTT 
 * connections simultaneously, set this macro to 1. The device will then
 * generate a unique client identifier by appending a timestamp to the 
 * 'MQTT_CLIENT_IDENTIFIER' string. Example: 'psoc6-mqtt-client5927'
 */
#define GENERATE_UNIQUE_CLIENT_ID         ( 1 )

/* The longest client identifier that an MQTT server must accept (as defined
 * by the MQTT 3.1.1 spec) is 23 characters. However some MQTT brokers support 
 * longer client IDs. Configure this macro as per the MQTT broker specification. 
 */
#define MQTT_CLIENT_IDENTIFIER_MAX_LEN    ( 23 )

/* As per Internet Assigned Numbers Authority (IANA) the port numbers assigned 
 * for MQTT protocol are 1883 for non-secure connections and 8883 for secure
 * connections. In some cases there is a need to use other ports for MQTT like
 * port 443 (which is reserved for HTTPS). Application Layer Protocol 
 * Negotiation (ALPN) is an extension to TLS that allows many protocols to be 
 * used over a secure connection. The ALPN ProtocolNameList specifies the 
 * protocols that the client would like to use to communicate over TLS.
 * 
 * This macro specifies the ALPN Protocol Name to be used that is supported
 * by the MQTT broker in use.
 * Note: For AWS IoT, currently "x-amzn-mqtt-ca" is the only supported ALPN 
 *       ProtocolName and it is only supported on port 443.
 * 
 * Uncomment the below line and specify the ALPN Protocol Name to use this 
 * feature.
 */
// #define MQTT_ALPN_PROTOCOL_NAME           "x-amzn-mqtt-ca"

/* Server Name Indication (SNI) is extension to the Transport Layer Security 
 * (TLS) protocol. As required by some MQTT Brokers, SNI typically includes the 
 * hostname in the Client Hello message sent during TLS handshake.
 * 
 * Uncomment the below line and specify the SNI Host Name to use this extension
 * as specified by the MQTT Broker.
 */
// #define MQTT_SNI_HOSTNAME                 "SNI_HOST_NAME"

/* A Network buffer is allocated for sending and receiving MQTT packets over 
 * the network. Specify the size of this buffer using this macro.
 * 
 * Note: The minimum buffer size is defined by 'CY_MQTT_MIN_NETWORK_BUFFER_SIZE' 
 * macro in the MQTT library. Please ensure this macro value is larger than 
 * 'CY_MQTT_MIN_NETWORK_BUFFER_SIZE'.
 */
#define MQTT_NETWORK_BUFFER_SIZE          ( 2 * CY_MQTT_MIN_NETWORK_BUFFER_SIZE )

/* Maximum MQTT connection re-connection limit. */
#define MAX_MQTT_CONN_RETRIES            (150u)

/* MQTT re-connection time interval in milliseconds. */
#define MQTT_CONN_RETRY_INTERVAL_MS      (2000)


/**************** MQTT CLIENT CERTIFICATE CONFIGURATION MACROS ****************/

/* Configure the below credentials in case of a secure MQTT connection. */
/* PEM-encoded client certificate */
/* Client's Certificate file is located at ../certs/client.crt */
#define CLIENT_CERTIFICATE      \
"-----BEGIN CERTIFICATE-----\n"\
"MIIDTzCCAjcCFGBJs2tIGGOq6DQhXD+ZyRCKqlbKMA0GCSqGSIb3DQEBCwUAMGMx\n"\
"CzAJBgNVBAYTAlRIMREwDwYDVQQIDAhDaG9uYnVyaTERMA8GA1UEBwwIQmFuZ3Nh\n"\
"ZW4xDDAKBgNVBAoMA0JVVTERMA8GA1UECwwIRUFTVFBhcmsxDTALBgNVBAMMBEJp\n"\
"aUwwHhcNMjMwMjE4MTIyNjM3WhcNMzMwMjE1MTIyNjM3WjBlMQswCQYDVQQGEwJU\n"\
"SDERMA8GA1UECAwIQ2hvbmJ1cmkxETAPBgNVBAcMCEJhbmdzYWVuMQwwCgYDVQQK\n"\
"DANCVVUxETAPBgNVBAsMCEVBU1RQYXJrMQ8wDQYDVQQDDAZjbGllbnQwggEiMA0G\n"\
"CSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQC8aTWPt4Vj2j4/6yK+RaNlEGpg0mM+\n"\
"O3vWLGPwyE2UWZZA+bnrSTXb8R3q28HczNhpdiocLnMh+kbIY9ZuFXBIYFa1Bdmm\n"\
"DPwI1wnp/LdPVgyXswEajhTa1cg57GI1H4z15LDhxl5MW5cyqRDd8LJ6M2HBZ8iu\n"\
"q0dqkb/m9OR3wUcmzdJMQ7l7i8gTnzF0T+OU3g7yAkEA/3hX6DHA2T4qwLpkbsx0\n"\
"PxkpWQRcsyNxXgN4H8ShjstJXBdqG27vddP5LDZYYhfidXBkn1qpR86vRZqdMkwH\n"\
"xNpaOW1kcfunQRQuicMy601o+7R7LSSpCGdEK7pq++vo2I2an41Gav7/AgMBAAEw\n"\
"DQYJKoZIhvcNAQELBQADggEBAHDvK+itjv9DIYfl1beePhmWdXiqAB49EahPnAQJ\n"\
"dujGEm0qQ347LSOsKjgUm6ttKiCSAgBLrFkOXFBTAkYnYWJMd6pkeyvwcbZAcABr\n"\
"iWProRZQREp/Lsw4icJ0WY8+QfAtgfmchJ92XAq2ZrArt6Wx+DJeMRVyMzNZ37gE\n"\
"3qI2HK1EVMgn/EFeW/GGAJycnv+lM5DU1bW84zJ+nwf7GM4bkPWMp5/j9sZJStgr\n"\
"OL2zG1m2imc+6Y1JIhRbeyCjw1yx5199tOx2SkUaoYjbX7rjK6B1IECDOF2A0bGM\n"\
"naNk2qZltnt7Ung/gLiIDSDOq3swzhQdvGn66f9DfznSKfI=\n"\
"-----END CERTIFICATE-----\n"

/* PEM-encoded client private key */
/* Client's Primary Key file is located at ../certs/client.key  */
/* But it 's not used for the application */
#define CLIENT_PRIVATE_KEY          \
"-----BEGIN RSA PRIVATE KEY-----\n"\
"MIIEpAIBAAKCAQEAvGk1j7eFY9o+P+sivkWjZRBqYNJjPjt71ixj8MhNlFmWQPm5\n"\
"60k12/Ed6tvB3MzYaXYqHC5zIfpGyGPWbhVwSGBWtQXZpgz8CNcJ6fy3T1YMl7MB\n"\
"Go4U2tXIOexiNR+M9eSw4cZeTFuXMqkQ3fCyejNhwWfIrqtHapG/5vTkd8FHJs3S\n"\
"TEO5e4vIE58xdE/jlN4O8gJBAP94V+gxwNk+KsC6ZG7MdD8ZKVkEXLMjcV4DeB/E\n"\
"oY7LSVwXahtu73XT+Sw2WGIX4nVwZJ9aqUfOr0WanTJMB8TaWjltZHH7p0EULonD\n"\
"MutNaPu0ey0kqQhnRCu6avvr6NiNmp+NRmr+/wIDAQABAoIBAQCVH3R8NpYGDTOd\n"\
"5Z6PGJEVqaN41KwmEnCWeHX1mqQEmc+Zx84GUuClHzc9rwfGmf9joVn9CiqoJu4l\n"\
"JxgN8zv2nQGjr2ivy7Ej0gePwizYR1QaMVzbRr9s4S3j4ptsTneEG6iAWkBCkW+f\n"\
"cj7eWub4X3is2lb1IK2axJct1oCJ4v1ciPU9tB/kMNEvpdc74lO6MiEogEIuQDf+\n"\
"1b91CV3gEkdeUJXfgVUhnl+W3/wfcOyLkq+4W0+TymUT9wsntZ1TbHlTR/iumFHy\n"\
"rey6Hhtpa/rR1vmgGThtqyWiy2FOJiHHUOv0mTw7nCfamx/c/K09i8pzaKN5Mr6K\n"\
"V+OE0eahAoGBAOSumlXs5F/S0J+Xgj0J9n41PzjFcOaHUo895/x3ndFcZ9JT/JTh\n"\
"bB8mW/YeXPhTHKZchZO5z2rrsgwqv96nr6djEqYvIN+1Lg+MbhI4UYYC8cw4lcNq\n"\
"JDoZFb+RorHnv1Ho812vBAnv2k2ZtxOZ0P3yHh+GCh28yv+rO1Bll8/PAoGBANLr\n"\
"EG5tUBypc/0s0nYr2biesxHWyPEGVIDA+pDNgmuH02OctAiZRMWnMakCTO84lcSC\n"\
"nHW33WxIv5ynsdZbsvsECkAEh5KW0hUyJ3bxDyFvS5Z0/OS7retNLcAfugLschv9\n"\
"Ii7nQqMNJMzOXdY62NHnXwDY4JOlGbimXxI6hvnRAoGAJF6cjyPg4liN84POI9UM\n"\
"zd+8EVRdc1x8RenLlnyTrfNrU6kl16vOXVnlcEw97wSQ3uiCGg+ILHIV3BeEcm3q\n"\
"4s0/7ww5xzpye+iSrPUmChE30YoCT5T29AJ/Uftgi7jW1bkd0319P/NUndjfpA9n\n"\
"jKvQHKVdwIMBKg5anZu6vEMCgYB+A0je4NpzNV6CDWx0g8BhiBduege10NVd024g\n"\
"Y1gfTJgkNHRvirrG6BxIYIJ8ji8UqAA4aLCWyGQKgTpD2qd1RzWkh9BD6W38kel4\n"\
"K4+hpy/e5WhOdD71jTffSFVG9+M5C6SHp01twyWQY1825hOyXOyqwehy7boPUv8M\n"\
"EgGgcQKBgQCJbXOcHaJ7/udx/2dRYgVquNBp+1pthNwDhwpDN2jAJmSGLbDbKrze\n"\
"H9TcgJe40uXwuPzPk2sZ/FkQGB3+JoFEF/bVGpuz2C3pEBFqHksGhdPwOx2+T6Ue\n"\
"55fn6DiUAKG8Hz87P/0fj1n3D+z0gjY4txhOLmazMo9Hzq9cZRDCVg==\n"\
"-----END RSA PRIVATE KEY-----\n"

/* PEM-encoded Root CA certificate */
/* Root CA's Certificate file is located at ../certs/root_ca.crt */
#define ROOT_CA_CERTIFICATE     \
"-----BEGIN CERTIFICATE-----\n"\
"MIIDpzCCAo+gAwIBAgIURYf7v9HbMdWG8NEdW8K6eNgmrdMwDQYJKoZIhvcNAQEL\n"\
"BQAwYzELMAkGA1UEBhMCVEgxETAPBgNVBAgMCENob25idXJpMREwDwYDVQQHDAhC\n"\
"YW5nc2FlbjEMMAoGA1UECgwDQlVVMREwDwYDVQQLDAhFQVNUUGFyazENMAsGA1UE\n"\
"AwwEQmlpTDAeFw0yMzAyMTgxMjI2MzdaFw0zMzAyMTUxMjI2MzdaMGMxCzAJBgNV\n"\
"BAYTAlRIMREwDwYDVQQIDAhDaG9uYnVyaTERMA8GA1UEBwwIQmFuZ3NhZW4xDDAK\n"\
"BgNVBAoMA0JVVTERMA8GA1UECwwIRUFTVFBhcmsxDTALBgNVBAMMBEJpaUwwggEi\n"\
"MA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDL36OgmmB1lFDx0K8rcSqG2aIZ\n"\
"IaNLgdJM9u5HL2NKo6hrQK7QFzv3occfCO8FPhGejQ6Nag8w85KjSt1o+JZYC+E0\n"\
"FkUNuT/k7SGVRCuoNFDDrTbkX/3dXD/RmtKLWNfL07UAfWoOpUbHpSefiCzfhuPA\n"\
"F8azszkN0YOK42yloPckecREX8oJGGS7r3O0YPfoZgnjr3CCDgEFtdYb7YuTguhR\n"\
"L+UlNpGPtgcn3oCejTnT0zTXvX2PflRJiv+GcAMsxnQ3CgxxvjErppSnfnn/av9z\n"\
"zrF9xBi53/DbTlpVVltSW1Odyo7vAUjF5Pa/YBcjrKpIhvOWVLnd9fvafIT9AgMB\n"\
"AAGjUzBRMB0GA1UdDgQWBBSZukO2HRLYGlqfA6FWwBlYXpoJTjAfBgNVHSMEGDAW\n"\
"gBSZukO2HRLYGlqfA6FWwBlYXpoJTjAPBgNVHRMBAf8EBTADAQH/MA0GCSqGSIb3\n"\
"DQEBCwUAA4IBAQBdoI0gXmx6jFRIhFVgOO9zAg8Ie7V3sm+/m9KSdSVKSkj8NXfw\n"\
"f8k4hIW3dkVjAMDdFbJuDNlOMWN9h27xpy87skY8ZBZvwpB+pFjCwOKC2pTRx+IS\n"\
"0qElwSuceGVFdVMC0pYu0gYxniZXeSYQAnqmxpfPhtcmf07SagzJ5Pn3SWGO9Y5K\n"\
"jBpb/YQCTujcnaTbA85MTHSF/UYo1o/CULO6Tvl66HNuFcOlB6nkRMav+y1aAbWC\n"\
"ZJt/7/KiOOlYTfLsw/4OmxCfskrSIJDjmr9mBKlw3bhTnUmMBjLxOaRBN818Xmvt\n"\
"+HSSQ5ax50usV04xazEpZtT6J0AI+s+ilaEh\n"\
"-----END CERTIFICATE-----\n"

/******************************************************************************
* Global Variables
*******************************************************************************/
extern cy_mqtt_broker_info_t broker_info;
extern cy_awsport_ssl_credentials_t  *security_info;
extern cy_mqtt_connect_info_t connection_info;


#endif /* MQTT_CLIENT_CONFIG_H_ */
