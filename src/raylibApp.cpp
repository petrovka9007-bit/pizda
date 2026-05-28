#include "raylibApp.h"
#include "raylib.h"
// #include "backends/imgui_impl_glfw.h"
// #include "backends/imgui_impl_opengl3.h"
#include "GLFW/glfw3.h"
#include "game.h"

using namespace pizda;

bool RaylibApp::init() {
	const int screenWidth = 1024;
	const int screenHeight = 768;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	game = new Game(screenWidth, screenHeight);

	return true;
}

void RaylibApp::start() {

	// Setup Dear ImGui context
	// IMGUI_CHECKVERSION();
	// ImGui::CreateContext();

	// Setup Dear ImGui style
	// ImGui::StyleColorsDark();

	GLFWwindow* win = glfwGetCurrentContext();
	// ImGui_ImplGlfw_InitForOpenGL(win, true);

	// const char* glsl_version = "#version 130";
	// ImGui_ImplOpenGL3_Init(glsl_version);

	while (!WindowShouldClose()) {
		BeginDrawing();

		// Start the Dear ImGui frame
		//	ImGui_ImplOpenGL3_NewFrame();
		//	ImGui_ImplGlfw_NewFrame();
		//	ImGui::NewFrame();

		ClearBackground(BLACK);

		game->processInput();
		game->update(GetFrameTime());
		game->draw();

		// ImGui::Render();
		// ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		EndDrawing();

		if (game->finished()) {
			break;
		}
	}
	// ImGui_ImplOpenGL3_Shutdown();
	// ImGui_ImplGlfw_Shutdown();
	// ImGui::DestroyContext();

	CloseWindow();
}

void RaylibApp::terminate() {
	delete game;
}
