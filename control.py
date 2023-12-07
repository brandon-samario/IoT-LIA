import json
import paho.mqtt.client as mqtt

# Load configuration FROM Json file
with open('config.json', 'r') as file:
    config = json.load(file)

# Function that evaluates the conditions specified in config.json file
def evaluate_condition(condition, message):
    # Check if the condition is 'greater than' and compare accordingly
    if condition['comparison'] == '>':
        return float(message) > condition['value']
    # Check if the condition is 'less than or equal to' and compare
    elif condition['comparison'] == '<=':
        return float(message) <= condition['value']
    return False

# Called when the clients connects to the MQTT broker
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    # Subscribe to all MQTT topics based on conditions in the config
    for item in config:
        for condition in item['conditions']:
            client.subscribe(condition['topic'])

# Called when a message is received from the MQTT broker
def on_message(client, userdata, msg):
    # Prints the received message for troubleshooting
    print("Received message: '" + str(msg.payload.decode()) + "' on topic: '" + msg.topic)   
    for item in config:
        for condition in item['conditions']:
            # If the topic matches, evaluate the condition
            if msg.topic == condition['topic']:
                if evaluate_condition(condition, msg.payload.decode()):
                    # If condition is met, publish the result
                    for result in item['results']:
                        client.publish(result['topic'], result['value'])

# Set up MQTT client and define callback functions
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

# Connect to MQTT broker (ensure IP and port are correct for your setup)
client.connect("localhost", 1883, 60)
# Start the network loop forever
client.loop_forever()
