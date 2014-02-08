# brew/lib Makefile
#

TARGET=libbrew.a
ALT_TARGET=libbrew.so

OPT=0
DEBUG=dwarf-2

SUBDIRS= common backend frontend
OBJDIR=obj

#$($(SUBDIRS:%):
COMMON_SRC= bobject.cpp bfunc.cpp ast.cpp symtab.cpp
BACKEND_SRC= code.cpp
FRONTEND_SRC= brew_script.parser.cpp brew_script.lexer.cpp brew_asm.parser.cpp brew_asm.lexer.cpp

BREW_SCRIPT_PARSER_SRC= brew_script.parser.cpp
BREW_SCRIPT_LEXER_SRC= brew_script.lexer.cpp
BREW_ASM_PARSER_SRC= brew_asm.parser.cpp
BREW_ASM_LEXER_SRC= brew_asm.lexer.cpp

CPPSRC= $(COMMON_SRC) $(BACKEND_SRC) $(FRONTEND_SRC)

OBJ= $(CPPSRC:$(OBJDIR)/%.o=%.cpp)

CPPSTD= -std=c++11
CPPFLAGS= -O$(OPT) -g$(DEBUG)
CPPFLAGS += -fPIC
CPPFLAGS += $(CPPSTD)

ASFLAGS=
LDFLAGS=

TOOLCHAIN_DIR=/Dev-CPP/TDM-GCC-64/bin

CXX=g++
CC=gcc
AR=ar
ARFLAGS= rcs
BISON=win_bison
BISONARGS= -d -o
FLEX=win_flex
FLEXARGS= -o


all: begin prebuild build alt_build end

begin:
	@echo
	@echo Starting Brew Library build

end:
	@echo
	@echo Finished building Brew Library

delegate:
	for d in $(SUBDIRS); do
	cd $$d; $(MAKE) -C $$d; cd ..;

prebuild: $(BREW_SCRIPT_PARSER_SRC) $(BREW_SCRIPT_LEXER_SRC) $(BREW_ASM_PARSER_SRC) $(BREW_ASM_LEXER_SRC)

build: $(TARGET)

alt_build: $(ALT_TARGET)

$(TARGET): $(OBJ)
	$(AR) $(ARFLAGS) $@ $<

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(ALT_TARGET): $(OBJ)
	$(CXX) -shared $@ $<

$(BREW_SCRIPT_PARSER_SRC):
	$(BISON) $(BISONARGS) $@  frontend/brew.y

$(BREW_SCRIPT_LEXER_SRC): frontend/brew.l
	$(FLEX) $(FLEXARGS) $@ $<

$(BREW_ASM_PARSER_SRC): frontend/brewasm.y
	$(BISON) $(BISONARGS) $@ $<

$(BREW_ASM_LEXER_SRC): frontend/brewasm.l
	$(FLEX) $(FLEXARGS) $@ $<
