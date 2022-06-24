AR := ar rcs

NAME = philosophers.a

SRC := src


# SRC
SRCCFILES := philosopher_start.c utils.c log.c time.c
SRCCFILES := $(addprefix $(SRC)/, $(SRCCFILES))


# LIBS
CFILES := $(SRCCFILES) philosophers.c
OFILES := $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(AR) $(NAME) $(OFILES)
	gcc $(NAME) -o philosophers

clean: 
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

