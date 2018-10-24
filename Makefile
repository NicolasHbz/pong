CC			=	g++
CFLAGS		=	-c -std=c++11 -Wno-unused-command-line-argument
LIBFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SOURCES		=	main.cpp			\
				AbstractEntity.cpp	\
				AbstractScreen.cpp	\
				Paddle.cpp			\
				Ball.cpp			\
				Game.cpp			\
				ScoreManager.cpp	\
				GameOver.cpp		\
				Menu.cpp
OBJECTS		=	$(SOURCES:.cpp=.o)
EXECUTABLE	=	pong

all: $(SOURCES) $(EXECUTABLE)
        
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LIBFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(LIBFLAGS)

clean:
	rm *.o $(EXECUTABLE)