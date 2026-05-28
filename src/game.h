#pragma once
#include "raylib.h"
namespace pizda {
	class Game {
	public:
		Game(int screenWidth, int screenHeight) {
			hooi = loadTexture("assets/hooi.png");
			camera.zoom = 1.f;
			camera.rotation = 0.f;
			camera.offset = {0, 0};
			camera.target = {0, 0};
		}
		void processInput() {
		}
		void update(int) {
		}
		void draw() {
			BeginMode2D(camera);
			DrawTexture(hooi, 0, 0, WHITE);
			EndMode2D();
		}
		bool finished() {
			//	return true if gameover etc
			return false;
		}

	private:
		Camera2D camera;

		Texture loadTexture(const char* path) {
			Texture result = LoadTexture(path);
			GenTextureMipmaps(&result);
			SetTextureFilter(result, TEXTURE_FILTER_TRILINEAR);
			return result;
		}

		Texture hooi;
	};
}