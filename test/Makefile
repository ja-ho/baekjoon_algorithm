CC= g++
TARGET= test
OBJS= test.o

.SUFFIXES= .cpp .o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)
