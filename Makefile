CC = g++
CFLAGS = -c -g -Iinclude
LDFLAGS = -g
# FLAGS = 
SRCDIR = src
OBJDIR = obj
SRC = ${wildcard $(SRCDIR)/*.cpp}
HDR = ${wildcard include/*.hpp}
OBJS = ${SRC:.cpp=.o}
OBJDIRS = ${subst $(SRCDIR),$(OBJDIR),$(OBJS)}
EXEC = bpp

all: ${SRC} ${OBJDIRS} ${EXEC}

debug: all
debug: CFLAGS += -DDEBUG

${EXEC}: ${OBJDIRS}
	${CC} ${LDFLAGS} $^ -o $@

obj/%.o: src/%.cpp ${HDR}
	${CC} ${CFLAGS} $< -o $@

clean:
	del ${OBJDIR} ${EXEC}.exe 