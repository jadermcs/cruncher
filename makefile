CC	     := gcc
CFLAGS   := -std=c99 --pedantic -O3 -Wall -Wextra -Wpedantic

TARGETF  := bin
TARGET   := $(TARGETF)/cruncher_lang

SRCEXT   := c
SRCDIR   := src
BUILDDIR := build
INCLUDEDIR := build

SRCEXT   := c
SOURCES  := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS  := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
LIB      := -lm -lfl
INC      := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(TARGETF)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

lang:
	@echo " flex src/cruncher_lex.l "; flex src/cruncher_lex.l
	@echo " bison -d src/cruncher_syntax.y "; bison -d src/cruncher_syntax.y

test:
	@echo " Running tests..."
	@echo " Valid files:"
	@echo "------------------------------"
	@./$(TARGET) tests/test-valid1.hs
	@echo "------------------------------"
	@./$(TARGET) tests/test-valid2.hs
	@echo "\n\n Invalid files..."
	@echo "------------------------------"
	@./$(TARGET) tests/test-invalid1.hs
	@echo "------------------------------"
	@./$(TARGET) tests/test-invalid2.hs

.PHONY: clean_all
