SRC = $(wildcard *.cpp)

OBJ_PATH = obj
OBJ = $(SRC:%.cpp=$(OBJ_PATH)/%.o)

INCLUDE_PATH = 

.PHONY: all
all: $(OBJ)

# *.oが必要なときのサフィックスルール
$(OBJ_PATH)/%.o :: %.cpp Makefile
#	if [ ! -d $(OBJ_PATH) ]; then mkdir $(OBJ_PATH); fi
	g++ -c $< $(INCLUDE_PATH) -o $@


.PHONY: clean depend

clean:
	rm -f $(OBJ)
	rm -f Makefile.depend

# 依存関係まわり
depend:
	g++ -MM -MG $(SRC) >Makefile.depend

-include Makefile.depend
