AR := ar rcs

NAME = philosophers.a

SRC := src


# SRC
SRCCFILES := input.c philo_start.c mutex_utils.c threads_utils.c log.c utils.c
SRCCFILES := $(addprefix $(SRC)/, $(SRCCFILES))


# LIBS
CFILES := $(SRCCFILES) philo.c
OFILES := $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(AR) $(NAME) $(OFILES)
	gcc $(NAME) -o philosophers

clean: 
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)
	rm -f philosophers

re: fclean all

