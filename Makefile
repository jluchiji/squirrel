ODIR    = obj
SDIR    = src
HDIR    = inc
TDIR    = tmp
DEBUG   = 3

OUT     = squirrel
CFLAGS  = -fPIC -g
LDFLAGS = -lpthread

CXX     = g++
ECHO    = /bin/echo
MKDIR   = mkdir -p

all: $(OUT)

.PHONY: force
force: clean $(OUT)
	@rm -rf $(TDIR)

# --------------------------------------------------------------------------- #
# Compilation and linking of the httpd executable.                            #
# --------------------------------------------------------------------------- #

SRCS    = $(shell find $(SDIR) -type f -name "*.cc")
OBJS    = $(patsubst $(SDIR)/%.cc, $(ODIR)/%.o,   $(SRCS))
DEPS    = $(patsubst $(SDIR)/%.cc, $(ODIR)/%.dep, $(SRCS))

.deps: $(DEPS)

$(ODIR)/%.dep: $(SDIR)/%.cc
	@printf "Analyzing  %-25s" $(notdir $<)...
	@$(CXX) $(CFLAGS) -I$(HDIR) -I$(patsubst $(ODIR)/%,$(HDIR)/%,$(@D)) -MM $^ >> .deps
	@printf "\033[1;32mDone!\033[0m\n"

-include .deps

$(OUT): $(OBJS)
	@printf "Linking    %-25s" $(@F)...
	@$(CXX) $(LDFLAGS) -o $(OUT) $(OBJS)
	@printf "\033[1;32mDone!\033[0m\n"

$(ODIR)/%.o: $(SDIR)/%.cc
	@printf "Compiling  %-25s" $(notdir $<)...
	@$(MKDIR) $(@D)
	@$(CXX) $(CFLAGS) -DDEBUG=$(DEBUG) -o $@ -c $< -I$(HDIR) -I$(patsubst $(ODIR)/%,$(HDIR)/%,$(@D))
	@printf "\033[1;32mDone!\033[0m\n"



# --------------------------------------------------------------------------- #
# Cleanup.                                                                    #
# --------------------------------------------------------------------------- #
.PHONY: clean clean-deps

clean-deps:
	@printf "Cleaning   %-25s" "dependencies"...
	@rm -f .deps
	@printf "\033[1;32mDone!\033[0m\n"

clean: clean-deps
	@printf "Cleaning   %-25s" "binaries"...
	@rm -rf obj tmp
	@rm -f httpd
	@printf "\033[1;32mDone!\033[0m\n"
