AR := ar rcs

NAME = philosophers.a

SRC := src


# SRC
SRCCFILES := input.c mutex_utils.c log.c utils.c philo_create.c philo_runtime.c philo_init.c time.c philo_checker.c
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

