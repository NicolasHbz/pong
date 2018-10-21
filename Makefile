CC			=	g++
CFLAGS		=	-c -std=c++11 -Wno-unused-command-line-argument
LIBFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system
SOURCES		=	main.cpp			\
				AbstractEntity.cpp	\
				Paddle.cpp			\
				Ball.cpp			\
				game.cpp			\
				ScoreManager.cpp	\
				GameOver.cpp
OBJECTS		=	$(SOURCES:.cpp=.o)
EXECUTABLE	=	pong

all: $(SOURCES) $(EXECUTABLE)
        
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LIBFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(LIBFLAGS)

clean:
	rm *.o $(EXECUTABLE)