TARGET_NAME = app
TARGET_DIR = ./bin

SUB_DIRS = ./sources
OBJ_DIR = obj

CXXFLAGS = -g -Wall
LDFRAGS = -lm -framework OpenGL -framework GLUT -framework Foundation

# サブディレクトリで出力したOBJを使ってビルドする。
all: $(SUB_DIRS)
	if [ ! -d $(TARGET_DIR) ]; then mkdir $(TARGET_DIR); fi
	g++ $(CXXFLAGS) $(LDFRAGS) -o $(TARGET_DIR)/$(TARGET_NAME) $(SUB_DIRS)/$(OBJ_DIR)/*.o

# サブディレクトリでmakeする
$(SUB_DIRS):: depend
	make -C $@

.PHONY: clean depend
clean:
	make -C $(SUB_DIRS) clean
	rm $(TARGET_DIR)/$(TARGET_NAME)

depend:
	make -C $(SUB_DIRS) depend
