#pragma once
#include <SDL.h>
#include <iostream>

namespace SDLFramework {
	class Graphics {
	public:
		static const int SCREEN_WIDTH = 600;
		static const int SCREEN_HEIGHT = 800;

		static Graphics* Instance();
		//Handle releasing (uninitializing) memory. ONLY HANDLES OUR WINDOW AND RENDERER
		static void Release();
		static bool Initialized();

		//Cleanup that happens to the area in memory that draws the next frame
		void ClearBackBuffer();
		void Render();

		Graphics();
		~Graphics();

		bool Init();

	private:
		//This is going to hold the ONE instance of our Graphics class
		static Graphics* sInstance;
		static bool sInitialized;
		SDL_Window* mWindow = nullptr;
		SDL_Renderer* mRenderer = nullptr;
	};
}