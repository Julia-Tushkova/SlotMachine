# Компилятор
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Ilibs/SDL2/include -Ilibs/SDL2_image -Ilibs/SDL2_ttf
LDFLAGS = -Llibs/SDL2/lib -Llibs/SDL2_image -Llibs/SDL2_ttf -lSDL2 -lSDL2_image -lSDL2_ttf

# Исходные файлы
SRCS = main.cpp Game.cpp Reel.cpp ReelManager.cpp SpinningState.cpp ScoreDisplay.cpp Button.cpp StateMachine.cpp TextureManager.cpp WaitingState.cpp WinState.cpp
OBJS = $(SRCS:.cpp=.o)

# Итоговый исполняемый файл
TARGET = slot_machine

# Сборка проекта
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Компиляция исходников
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка проекта
clean:
	rm -f $(OBJS) $(TARGET)
