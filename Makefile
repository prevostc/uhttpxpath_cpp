
CC = g++
INCLUDES = -I $${URBI_ROOT}/include `curlpp-config --libs` -I.$${TINYXPATH_ROOT}
CFLAGS = `curlpp-config --cflags` -DTIXML_USE_STL -shared -fPIC
TARGET = UHttpXPath.so
SOURCES = \
        UHttpXPath.cpp \
	HttpXPath.cpp \
	$${TINYXPATH_ROOT}/*.cpp

default: target 

target: $(SOURCES)
	$(CC) $(INCLUDES) $(CFLAGS) $(SOURCES) -o $(TARGET)

debug: $(SOURCES)
	$(CC) $(INCLUDES) $(CFLAGS) -DHTTPXPATH_DEBUG $(SOURCES) -o $(TARGET)

run: $(TARGET)
	 urbi-launch --start $(TARGET) -- --interactive

clean:
	rm *.o
	rm $(TARGET)




