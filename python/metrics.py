import psutil
import time
import sys

while True:
    temp = 40 + (psutil.cpu_percent() / 5)
    cpu = psutil.cpu_percent()
    ram = psutil.virtual_memory().percent
    battery = psutil.sensors_battery().percent if psutil.sensors_battery() else 100

    print(temp, cpu, ram, battery)
    sys.stdout.flush()
    time.sleep(1)