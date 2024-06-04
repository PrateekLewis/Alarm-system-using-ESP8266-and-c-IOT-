import network
import time
import machine
import urequests

# WiFi credentials
ssid = 'YOUR_SSID'
password = 'YOUR_PASSWORD'

# Trigger and Echo pin setup
trig_pin = machine.Pin(5, machine.Pin.OUT)  # D1
echo_pin = machine.Pin(4, machine.Pin.IN)   # D2

# Connect to WiFi
def connect_wifi(ssid, password):
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(ssid, password)
    while not wlan.isconnected():
        print("Connecting to WiFi...")
        time.sleep(1)
    print("Connected to WiFi!")
    print("Network config:", wlan.ifconfig())

# Measure distance using the ultrasonic sensor
def measure_distance():
    trig_pin.off()
    time.sleep_us(2)
    trig_pin.on()
    time.sleep_us(10)
    trig_pin.off()
    
    while echo_pin.value() == 0:
        pulse_start = time.ticks_us()
    while echo_pin.value() == 1:
        pulse_end = time.ticks_us()
    
    pulse_duration = pulse_end - pulse_start
    distance = (pulse_duration / 2) / 29.1
    return distance

# Send alert via Telegram
def send_telegram_message():
    bot_token = 'YOUR_BOT_TOKEN'
    chat_id = 'YOUR_CHAT_ID'
    message = 'INTRUDER_ALERT'
    url = f'https://api.telegram.org/bot{bot_token}/sendMessage?chat_id={chat_id}&text={message}'
    response = urequests.get(url)
    print(response.status_code)
    response.close()

# Main loop
def main():
    connect_wifi(ssid, password)
    while True:
        distance = measure_distance()
        print(f"{distance:.2f} cm")
        if distance < 20:
            send_telegram_message()
            time.sleep(5)  # Delay for 5 seconds
        time.sleep(0.5)  # Delay for 0.5 seconds

if __name__ == "__main__":
    main()
