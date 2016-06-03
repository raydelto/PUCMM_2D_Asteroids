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
#include "Bullet.hpp"

namespace Engine
{
	class App : public SDLEvent
	{
	public:
		/* =============================================================
		* ENUMERATORS
		* ============================================================= */
		struct AppState
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
		App									( const std::string& title, const int width, const int height );
		~App								( );
		void OnExecute						( );
		bool OnInit							( );
		void OnUpdate						( );
		void OnRender						( );
		void OnKeyDown						( SDL_KeyboardEvent keyBoardEvent ) override;
		void OnKeyUp						( SDL_KeyboardEvent keyBoardEvent ) override;
	private:
		/* =============================================================
		 * PRIVATE FUNCTIONS
		 * ============================================================= */
		bool SDLInit						( );
		bool GlewInit						( );
		void SetupViewport					( );
		void CleanupSDL						( );
		void OnResize						( int width, int height ) override;
		void OnExit							( ) override;
		void CreateAsteroid					( Asteroids::Asteroid::AsteroidSize::Size size, int amount, float x = 0.0f, float y = 0.0f );
		void CreateDebris					( Asteroids::Entity* entity );
		void CheckCollision					( );
		void CleanEntities					( );
		void CreateBullet					( );
		void DestroyEntity					( Asteroids::Entity* entity );
		void RespawnPlayer					( );

		/* =============================================================
		 * MEMBERS
		 * ============================================================= */
		std::string							m_title;
		int									m_width;
		int									m_height;
		SDL_Window*							m_mainWindow;
		SDL_GLContext						m_context;
		AppState::State						m_state;
		int									m_nUpdates;
		Asteroids::Player*					m_player;
		std::list< Asteroids::Asteroid* >	m_asteroids;
		std::list< Asteroids::Bullet* >		m_bullets;
		std::list< Asteroids::Entity* >     m_entities;
	};
}
#endif /* GAME_HPP */