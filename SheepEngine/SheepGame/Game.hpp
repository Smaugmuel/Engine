#ifndef GAME_HPP
#define GAME_HPP
#include "../SheepEngine/Core/Engine.hpp"
#include "../SheepEngine/Misc/StateMachines/StateMachineV2.hpp"
#include "../SheepEngine/Events/EventReceiver.hpp"
#include <chrono>

//enum RenderMode
//{
//	NORMAL_MODE,
//	DEFERRED_MODE,
//	DEFERRED_CHUNK_MODE,
//	DEFERRED_SPLIT_MODE,
//	DEFERRED_MULTIPLE_LIGHTS_MODE,
//	DEFERRED_MULTIPLE_SHADOW_LIGHTS_MODE,
//	DEPTH_MODE,
//	NR_OF_RENDER_MODES
//};
//enum HUDMode
//{
//	HUD_OFF,
//	TORGUE_HUD,
//	DEFERRED_POSITIONS,
//	DEFERRED_NORMALS,
//	DEFERRED_COLORS,
//	NR_OF_HUD_MODES
//};
//enum OrthogonalMode
//{
//	ORTHOGONAL_OFF,
//	ORTHOGONAL_ON
//};

class Game final : public EventReceiver
{
public:
	Game();
	~Game();

	bool Initialize();
	void Run();

private:
	/*Used To Calculate deltatime between updates/render*/
	typedef std::chrono::high_resolution_clock Clock;
	typedef std::chrono::time_point<std::chrono::steady_clock> Time;

	Time m_t1;
	Time m_t2;

	void ReceiveEvent(const Event& e) final override;
	void CheckFPSRelatedInput(float dt);
	void CheckNonFPSRelatedInput(float dt);


	/*void RenderNormal();
	void RenderDeferredFirstPass();
	void RenderDeferredFirstPassChunks();
	void RenderDepth();
	void RenderShadowPass();
	void RenderShadowPassChunks();
	void RenderMultipleShadowsPass();
	void RenderDeferredLightShadowPass();
	void RenderDeferredLightSplitPass();
	void RenderDeferredLightMultiplePass();
	void RenderDeferredLightMultipleShadowsPass();
	void RenderHUD();
	void RenderHUDText();*/

	/*StateMachineV2<GameState> m_gameStateMachine;
	bool m_pop_game_state_flag;
	bool m_shutdown_flag;*/

	
	Engine m_engine;

	int m_cameraIndex;
	int m_GUIhelloWorldIndex;

	std::vector<ObjectV4*> m_objects;

	/*
	If true, Map input to move the Camera in the editor, else use input for something else.
	For exemple, have a condition, if ScrollWheel is down, m_UseFPSControles = true.
	*/
	bool m_UseFPSControls;

	/*RenderMode m_renderMode;
	HUDMode m_HUDMode;
	OrthogonalMode m_orthogonal;*/
};

#endif