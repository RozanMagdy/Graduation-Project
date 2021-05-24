# request control over SPI module in the Jetson Nano
import spidev

# to use Delay function, we import "time"
import time

# Make an instant from SpiDev (called "spi")
#---> to be able to use methods and variable needed
spi = spidev.SpiDev()

# Open SPI module in Jetson
# --> we select both channel & device 
# Jetson Nano has only one SPI module
spi.open(0,0)

# Select Mode (phase & polarity)
#--> compatible with the MCP module
spi.mode = 0b00

# specify the freq that the Jetson Nano 
#---> will produce as a master
spi.max_speed_hz = 500000


# Send initialization sequence
resp = spi.xfer2([0xC0])
resp = spi.xfer2([0x02, 0x0F, 0x8C])
resp = spi.xfer2([0x02, 0x28, 0x81, 0x91, 0x00])
resp = spi.xfer2([0x02, 0x0D, 0x01])
resp = spi.xfer2([0x02, 0x0F, 0x0C])

# This is the data to be sent. a = 97
data = 97

while True:
    #--------------(address, IDE,............, DLC, data to be sent )
    resp = spi.xfer2([0x40, 0x24, 0x60, 0x00, 0x01, data])
    
    # Send a RTS (request to send)
    resp = spi.xfer2([0x81])
    
    # indication that all is OK
    print('Done')
    data += 1
    
    if data == 103:
        data = 97
        
        # wait one second
        time.sleep(1)

