CFLAGS = -g -O2 -c
LDFLAGS = 

TARGET = i2c

%.o:%.c
	$(GCC) $(CFLAGS) $< 

$(TARGET): $(TARGET).o
	$(GCC) $< -o $@ $(LDFLAGS)
