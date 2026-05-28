#pragma once

namespace pizda {
	class Game;
	class RaylibApp {
	public:
		bool init();
		void start();
		void terminate();

	private:
		Game* game;
	};
}