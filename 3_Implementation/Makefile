PROJ_NAME = Internet_Banking
SRC = src/main.c\
src/name.c\

TEST_SRC = src/pound.c\
src/usd.c\
test/test_conversion.c\
unity/unit.c\
  

#To check if the OS is windows or linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif
TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME).$(EXEC)
INC	= -Iinc\
-Iunity

all:$(SRC) $(BUILD)
	gcc $(SRC) $(INC) -o $(call FixPath,$(PROJ_NAME).$(EXEC)) -lm


run: all
	./$(call FixPath,$(PROJ_NAME).$(EXEC))

# Build and run of Unit test

build_test:
	gcc $(TEST_SRC) $(INC) $(INCLUDE_LIBS) -o $(call FixPath,$(PROJ_NAME).$(EXEC)) -lm

run_test: build_test
	./$(call FixPath,$(PROJ_NAME).$(EXEC))

analyze: test memcheck staticcheck coverage sanitize_check

staticcheck:
	cppcheck --enable=all -iunity .

memcheck:
	valgrind ./$(TEST_OUTPUT)

sanitize_check:
	gcc -fsanitize=address -fno-omit-frame-pointer $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) 
	./$(TEST_OUTPUT)

clean:
	$(RM) $(call FixPath,$(PROJ_NAME).$(EXEC))