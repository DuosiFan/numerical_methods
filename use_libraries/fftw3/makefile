CC := clang

FFTW3_ROOT := /home/duosifan/thirdparty/install/fftw3-clang
FFTW3_INC := $(FFTW3_ROOT)/include
FFTW3_LIB := $(FFTW3_ROOT)/lib

CFLAGS := -Wall -Wextra -Werror -std=c17
CPPFLAGS := -I$(FFTW3_INC)
LDFLAGS := -L$(FFTW3_LIB)
LDLIBS := -lfftw3 -lm

srcs := $(wildcard src/*.c)
apps := $(srcs:%.c=%.app)

all: $(apps)

%.app: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $< $(LDLIBS) -o $@
