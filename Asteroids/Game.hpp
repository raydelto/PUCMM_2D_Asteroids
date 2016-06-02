#pragma once
#ifndef GAME_HPP
#define GAME_HPP

// C++ STL
#include <string>
#include <list>

// Asteroids
#include "SDLEvent.hpp"
#include "Player.hpp"
#include "Asteroid.hpp"

namespace Engine
{
	class Game : public SDLEvent
	{
	public:
		/* =============================================================
		* ENUMERATORS
		* ============================================================= */
		struct GameState
		{
			enum State
			{
				UNINITIALIZED = 0,
				INIT_FAILED = 1,
				INIT_SUCCESSFUL = 2,
				RUNNING = 4,
				PAUSED = 8,
				QUIT = 16
			};
		};

		/* =============================================================
		 * PUBLIC FUNCTIONS
		 * ============================================================= */
		Game				( const std::string& title, const int width, const int height );
		~Game				( );
		void OnExecute		( );
		bool OnInit			( );
		void OnUpdate		( );
		void OnRender		( );
		void OnKeyDown	    ( SDL_KeyboardEvent keyBoardEvent ) override;
		void OnKeyUp		( SDL_KeyboardEvent keyBoardEvent ) override;
	private:
		/* =============================================================
		 * PRIVATE FUNCTIONS
		 * ============================================================= */
		bool SDLInit		( );
		bool GlewInit		( );
		void SetupViewport	( );
		void CleanupSDL		( );
		void OnResize		( int width, int height ) override;
		void OnExit			( ) override;
		void CreateAsteroid(Asteroids::Asteroid::AsteroidSize::Size size, int amount, float x = 0.0f, float y = 0.0f);

		/* =============================================================
		 * MEMBERS
		 * ============================================================= */
		std::string			m_title;
		int					m_width;
		int					m_height;
		SDL_Window*			m_mainWindow;
		SDL_GLContext		m_context;
		GameState::State	m_state;
		int					m_nUpdates;
		Asteroids::Player*	m_player;
		std::list< Asteroids::Asteroid* > m_asteroids;
	};
}
#endif /* GAME_HPP */
