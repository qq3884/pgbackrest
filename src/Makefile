####################################################################################################################################
# pgBackRest Makefile
####################################################################################################################################

####################################################################################################################################
# Compile options
####################################################################################################################################
CC=gcc

# Compile using C99 standard
CSTD = -std=c99

# Compile optimizations
COPT = -O2

# Locations of header files
CINCLUDE = -I.

# Compile warnings
CWARN = -Wfatal-errors -Wall -Wextra -Wwrite-strings -Wswitch-enum -Wconversion -Wformat=2 -Wformat-nonliteral \
		-Wno-clobbered -Wno-missing-field-initializers

# Automatically generate Perl compile options for the local system
CPERL = `perl -MExtUtils::Embed -e ccopts`

# Debug options
CDEBUG = -DNDEBUG

# Extra compile options to be set by caller
CEXTRA =

# Concatenate options for easy usage
CFLAGS = $(CINCLUDE) $(CSTD) $(COPT) $(CWARN) $(CPERL) $(CDEBUG) $(CEXTRA)

####################################################################################################################################
# Link options
####################################################################################################################################
# Automatically generate Perl linker options for the local system
LDPERL = `perl -MExtUtils::Embed -e ldopts`

# Extra linker options to be set by caller
LDEXTRA =

# Concatenate options for easy usage
LDFLAGS = $(LDPERL) $(LDEXTRA)

####################################################################################################################################
# Install options
####################################################################################################################################
# Modify destination install directory
DESTDIR =

####################################################################################################################################
# List of required source files.  main.c should always be listed last and the rest in alpha order.
####################################################################################################################################
SRCS = \
	command/archive/push/push.c \
	command/help/help.c \
	command/command.c \
	common/fork.c \
	common/error.c \
	common/exit.c \
	common/io/handle.c \
	common/ini.c \
	common/lock.c \
	common/log.c \
	common/memContext.c \
	common/regExp.c \
	common/time.c \
	common/type/buffer.c \
	common/type/keyValue.c \
	common/type/list.c \
	common/type/string.c \
	common/type/stringList.c \
	common/type/variant.c \
	common/type/variantList.c \
	common/wait.c \
	config/config.c \
	config/define.c \
	config/load.c \
	config/parse.c \
	perl/config.c \
	perl/exec.c \
	storage/driver/posix/driver.c \
	storage/driver/posix/driverFile.c \
	storage/driver/posix/driverRead.c \
	storage/driver/posix/driverWrite.c \
	storage/fileRead.c \
	storage/fileWrite.c \
	storage/helper.c \
	storage/storage.c \
	main.c

# Create obj list from source list
OBJS=$(SRCS:.c=.o)

####################################################################################################################################
# Compile and link
####################################################################################################################################
pgbackrest: $(OBJS)
	$(CC) -o pgbackrest $(OBJS) $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

####################################################################################################################################
# Installation.  DESTDIR can be used to modify the install location.
####################################################################################################################################
install: pgbackrest
	install -d $(DESTDIR)/usr/bin
	install -m 755 pgbackrest $(DESTDIR)/usr/bin
