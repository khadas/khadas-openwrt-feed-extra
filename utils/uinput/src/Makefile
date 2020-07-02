CFLAGS = -g -O2 -c
LDFLAGS = 

TARGET = uinput

%.o:%.c
	$(GCC) $(CFLAGS) $< 

$(TARGET): $(TARGET).o
	$(GCC) $< -o $@ $(LDFLAGS)
