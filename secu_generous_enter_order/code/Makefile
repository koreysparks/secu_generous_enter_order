CXX=g++   
OUT_NAME=secu_generous_enter_order

OUT_PATH=../lib/linux/
SRC_PATH=./
OBJ_PATH=./obj/

EES_LIB_INCLUDE_PATH=../include/
EES_LIB_LIB_PATH=../bin/linux/

COMMON_PATH=../../common_libs_pub/
COMMON_INC_PATH=$(COMMON_PATH)include/linux/
COMMON_LIB_PATH=$(COMMON_PATH)lib/linux/centos6.4/debug/

EES_QUOTE_DEMO_FILE=-lrt -ldl\
		$(COMMON_LIB_PATH)shengli_xml.a\
		$(COMMON_LIB_PATH)shengli_tool.a


SRC_FILE=$(wildcard $(SRC_PATH) *.cpp)
ALL_FILE=$(notdir $(SRC_FILE))
OBJ_FILE=$(patsubst %.cpp,%.o,$(ALL_FILE))

DEBUG_CXXFLAGS=-g -Wall -Wno-conversion-null -Wno-format-security -DDEBUG   


OUT_DEBUG_FILE=$(OUT_PATH)$(OUT_NAME)
OBJ_DEBUG_FILE=$(addprefix  $(OBJ_PATH),$(notdir $(OBJ_FILE)))


.PHONY: clean

debug : pre_debug $(OUT_DEBUG_FILE)

pre_debug :
	-$(shell mkdir $(OBJ_PATH) -p)
	-$(shell mkdir $(OUT_PATH) -p)
	
$(OUT_DEBUG_FILE) : $(OBJ_DEBUG_FILE)
	$(CXX) $(DEBUG_CXXFLAGS) $(addprefix  $(OBJ_PATH),$(notdir $^)) -o $@ $(EES_QUOTE_DEMO_FILE) 
	
$(OBJ_PATH)%.o : %.cpp
	$(CXX) -c $(DEBUG_CXXFLAGS)  -I $(EES_LIB_INCLUDE_PATH)  $(SRC_PATH)$< -o $@
	
	
clean :
	@echo  "make clean"
	$(shell rm $(OBJ_PATH) -rf)
	$(shell rm $(OUT_PATH)$(OUT_NAME) -f)

