CFLAGS = -g -O2 -c
LDFLAGS = 

TARGET = spiupdate

%.o:%.c
	$(GCC) $(CFLAGS) $< 

$(TARGET): $(TARGET).o
	$(GCC) $< -o $@ $(LDFLAGS)
