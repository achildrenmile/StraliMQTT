# 1 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino"
# 1 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino"
# 2 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino" 2
# 3 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino" 2
# 4 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino" 2
# 5 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino" 2
# 6 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino" 2

int status = WL_IDLE_STATUS;
int arrivedcount = 0;
bool hasWifi = false;
int messageCount=1;

const char* mqttServer = "mqtt.platformsolutions.eu";//"iot.eclipse.org";   //"m2m.eclipse.org";
int port = 1883;

void initWifi()
{
  Screen.print("Strali MQTT\r\n \r\nConnecting...\r\n");

  if (WiFi.begin() == WL_CONNECTED)
  {
    IPAddress ip = WiFi.localIP();
    Screen.print(1, ip.get_address());
    hasWifi = true;
    Screen.print(2," ");
    Screen.print(3, "Running... \r\n");
  }
  else
  {
    Screen.print(1, "No Wi-Fi\r\n ");
  }
}

void messageArrived(MQTT::MessageData& md)
{
    MQTT::Message &message = md.message;

    char msgInfo[60];
    sprintf(msgInfo, "Message arrived: qos %d, retained %d, dup %d, packetid %d", message.qos, message.retained, message.dup, message.id);
    Serial.println(msgInfo);

    sprintf(msgInfo, "Payload: %s", (char*)message.payload);
    Serial.println(msgInfo);
    ++arrivedcount;
}

int runMqttExample() {
  char* topic = "mxtest";
  MQTTNetwork mqttNetwork;
  MQTT::Client<MQTTNetwork, Countdown> client = MQTT::Client<MQTTNetwork, Countdown>(mqttNetwork);
  arrivedcount = 0;

  char msgBuf[100];
  sprintf(msgBuf, "Connecting to MQTT server %s:%d", mqttServer, port);
  Serial.println(msgBuf);

  int rc = mqttNetwork.connect(mqttServer, port);
  if (rc != 0) {
    Serial.println("Connected to MQTT server failed");
  } else {
    Serial.println("Connected to MQTT server successfully");
  }

  MQTTPacket_connectData data = { {'M', 'Q', 'T', 'C'}, 0, 4, {
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino" 3 4
                               __null
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino"
                               , {0, 
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino" 3 4
                               __null
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino"
                               }}, 60, 1, 0, { {'M', 'Q', 'T', 'W'}, 0, {
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino" 3 4
                               __null
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino"
                               , {0, 
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino" 3 4
                               __null
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino"
                               }}, {
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino" 3 4
                               __null
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino"
                               , {0, 
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino" 3 4
                               __null
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino"
                               }}, 0, 0 }, {
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino" 3 4
                               __null
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino"
                               , {0, 
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino" 3 4
                               __null
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino"
                               }}, {
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino" 3 4
                               __null
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino"
                               , {0, 
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino" 3 4
                               __null
# 63 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino"
                               }} };
  data.MQTTVersion = 3;
  data.clientID.cstring = "mxtest";
  data.username.cstring = "testuser";
  data.password.cstring = "testpassword";

  if ((rc = client.connect(data)) != 0) {
      Serial.println("MQTT client connect to server failed");
  }

  if ((rc = client.subscribe(topic, MQTT::QOS2, messageArrived)) != 0) {
      Serial.println("MQTT client subscribe from server failed");
  }

  MQTT::Message message;

  // QoS 0
  char buf[100];
  snprintf(buf, 100, "t: %.1fC\nh: %2.f%%", readTemperature(), readHumidity());
  //bool tempAlert=readMessage(messageCount++,buf);

  message.qos = MQTT::QOS0;
  message.retained = false;
  message.dup = false;
  message.payload = (void*)buf;
  message.payloadlen = strlen(buf)+1;
  rc = client.publish(topic, message);

/*   char str[100];



  strcat(str,"Temp: ");

  strcat(str,buf); */
# 96 "c:\\Users\\Michi\\OneDrive - Strali Solutions e.U\\02_Ideas\\04_AzureIoT\\projects\\Strali MQTT\\MQTTClient.ino"
  Screen.print(1, buf, true);

  while (arrivedcount < 1) {
      client.yield(100);
  }

  // QoS 1
  //sprintf(buf, "QoS 1 message from AZ3166!");
  // message.qos = MQTT::QOS1;
  // message.payloadlen = strlen(buf)+1;
  // rc = client.publish(topic, message);

  // while (arrivedcount < 2) {
  //     client.yield(100);
  // }

  // Screen.print("QoS 1 sent");


  if ((rc = client.unsubscribe(topic)) != 0) {
      Serial.println("MQTT client unsubscribe from server failed");
  }

  if ((rc = client.disconnect()) != 0) {
      Serial.println("MQTT client disconnect from server failed");
  }

  mqttNetwork.disconnect();
  Serial.print("Finish message count: ");
  Serial.println(arrivedcount);

  return 0;
}

void setup() {
  //Initialize serial and Wi-Fi:
  Serial.begin(115200);
  initWifi();


  if(!hasWifi)
  {
    return;
    // Microsoft collects data to operate effectively and provide you the best experiences with our products. 
    // We collect data about the features you use, how often you use them, and how you use them.
    //send_telemetry_data_async("", "MQTTClientSetup", "");
  }

  //Screen.print(3, " > Sensors");
  SensorInit();
}

void loop() {
  Serial.println("\r\n>>>Enter Loop");

  if (hasWifi) {
    runMqttExample();
  }

  delay(5000);
}
