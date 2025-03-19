#include "Reel.h"
#define E 0.00001

Reel::Reel(std::vector<int> symbols, int x, int y, SDL_Renderer* renderer, float maxSpeed) {
	symbolValues = symbols; // Сохраняем последовательность чисел

	// Загружаем текстуры (ассоциируем числа с изображениями)
	std::vector<std::string> texturePaths = { "assets/circle.png", "assets/square.png", "assets/triangle.png", "assets/star.png" };
	for (int i = 0; i < 4; i++) {
		textures.push_back(TextureManager::LoadTexture(texturePaths[i].c_str(), renderer));
	}

	for (int i = 0; i < 4; i++) {
		slots[i] = { x, y + (i * 115), 100, 100 };
	}

	spinning = false;
	accelerating = false;
	decelerating = false;
	this->maxSpeed = maxSpeed;
	currentSpeed = 0;
	currentIndex = 0;
	offsetY = 0;
}

void Reel::update() {
	if (accelerating && currentSpeed >= maxSpeed) {
		currentSpeed = maxSpeed;
		accelerating = false;
	}

	if (decelerating && (fabs(currentSpeed) < E) || currentSpeed < 0) {
		currentSpeed = 0;
		decelerating = false;
		spinning = false;
		offsetY = 0; // Выравниваем на символе
	}

	if (spinning) {
		offsetY += currentSpeed;

		if (offsetY >= 100) {
			offsetY = 0;
			currentIndex = (currentIndex + 1) % symbolValues.size();
			if (accelerating) currentSpeed += maxSpeed * 0.1;  // Плавный разгон
			if (decelerating) currentSpeed -= maxSpeed * 0.1;  // Плавное торможение
		}
	}
}

void Reel::render(SDL_Renderer* renderer) {
	for (int i = 0; i < 4; i++) {
		int textureIndex = symbolValues[(currentIndex + i) % symbolValues.size()] - 1;
		SDL_Rect destRect = { slots[i].x, static_cast<int>(offsetY) + 400 - slots[i].y, 100, 100 };
		SDL_RenderCopy(renderer, textures[textureIndex], nullptr, &destRect);
	}
}

void Reel::startSpinning() {
	spinning = true;
	accelerating = true;
	decelerating = false;
	currentSpeed = 0.1;
}

void Reel::stopSpinning() {
	decelerating = true;
	accelerating = false;
}

bool Reel::isSpinning() const {
	return spinning || accelerating || decelerating;
}

int Reel::getVisibleSymbol(int row) const {
	return symbolValues[(currentIndex + row) % symbolValues.size()];
}