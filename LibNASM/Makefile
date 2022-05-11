##	START_MAKEFILE	##

#===============================>COLORS<===============================#

_RED		=	\e[31m
_YELLOW		=	\e[33m
_GREEN		=	\e[32m
_END		=	\e[0m

# ===================================================================== #

#==============================>ASM_FILES<=============================#

SRCS	= ft_strcmp.s \
		  ft_write.s \
		  ft_read.s \
		  ft_strcpy.s \
		  ft_strdup.s \
		  ft_strlen.s

#=============================>TEST_FILE<==============================#

TEST	= test_lib.c

#=============================START_FILE===============================#

REZ		= start_test

# ===================================================================== #

#============================>COMPILATIONS<============================#

GCC		= gcc

CFLAGS	= -Wall -Werror -Wextra

NASM	= nasm

NFLAGS	= -f macho64

AR		= ar -rc

#==============================>DELETE<===============================#

RM		= rm -rf

#==========================>COMPILING_SOURCE<=========================#

OBJS	= ${SRCS:%.s=%.o}

NAME	= libasm.a

#==========================>COMPILING_RULES<==========================#

all:	${NAME}

${NAME}:	${OBJS}
			@${AR} ${NAME} $?
			@printf "\033[2K\r${_GREEN} Library create: '${NAME}'. ${_END}✅\n"

%.o:		%.s
			@printf "\033[2K\r${_YELLOW} ⌛ Compilling $< ${_END}\n"
			@${NASM} ${NFLAGS} $< -o $@

#============================>TEST_RULES<============================#

test:		${NAME}
			@${GCC} ${CFLAGS} ${TEST} ${NAME} -o ${REZ}
			@printf "\033[2K\r${_GREEN}'${REZ}' create. ✅ ${_END}\n"

#============================>CLEAN_RULES<===========================#

clean:
			@${RM} ${OBJS}
			@printf "\033[2K\r${_RED} '".o"' has been deleted. ${_END}🗑️\n"

fclean:		clean
			@${RM} ${NAME}
			@${RM} ${REZ}
			@printf "\033[2K\r${_RED} '"${NAME}"' and '"${REZ}"' has been deleted. ${_END}🗑️\n"

re:			fclean all

.PHONY: all test clean fclean re
