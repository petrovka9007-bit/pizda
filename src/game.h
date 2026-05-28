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
			hooiPosition = {screenWidth / 2.f, screenHeight / 2.f};
		}

		void processInput() {
			if (IsKeyDown(KEY_RIGHT)) hooiPosition.x += hooiRotation;
			if (IsKeyDown(KEY_LEFT))  hooiPosition.x -= hooiRotation;
			if (IsKeyDown(KEY_DOWN))  hooiPosition.y += hooiRotation;
			if (IsKeyDown(KEY_UP))    hooiPosition.y -= hooiRotation;
		}

		
		void update(int) {
		}
		void draw() {
			BeginMode2D(camera);
			DrawTextureV(hooi, hooiPosition, WHITE);
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
		Vector2 hooiPosition;
		float hooiRotation = 4.0f;
	};
}