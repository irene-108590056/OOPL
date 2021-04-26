#include "CEraser.h"
#include "CBall.h"
#include "CBouncingBall.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////

	enum AUDIO_ID {				// �w�q�U�ح��Ī��s��
		AUDIO_BLOCKBREAK,
		AUDIO_BLOCKHIT,
		AUDIO_BOOM,
		AUDIO_BOWSERFALL,
		AUDIO_BRIDGEBREAK,
		AUDIO_BULLETBILL,
		AUDIO_CASTLE,
		AUDIO_CASTLEEND,
		AUDIO_CASTLEFAST,
		AUDIO_COIN,
		AUDIO_DEATH,
		AUDIO_FIRE,
		AUDIO_FIREBALL,
		AUDIO_GAMEOVER,
		AUDIO_INTERMISSION,
		AUDIO_JUMP,
		AUDIO_JUMPBIG,
		AUDIO_LEVELEND,
		AUDIO_LOWTIME,
		AUDIO_MUSHROOMAPPEAR,
		AUDIO_MUSHROOMEAT,
		AUDIO_ONEUP,
		AUDIO_OVERWORLD,
		AUDIO_OVERWORLDFAST,
		AUDIO_PAUSE,
		AUDIO_PIPE,
		AUDIO_PRINCESSMUSIC,
		AUDIO_RAINBOOM,
		AUDIO_SCORERING,
		AUDIO_SHOT,
		AUDIO_SHRINK,
		AUDIO_STARMUSIC,
		AUDIO_STARMUSICFAST,
		AUDIO_STOMP,
		AUDIO_SWIM,
		AUDIO_UNDERGROUND,
		AUDIO_UNDERGROUNDFAST,
		AUDIO_UNDERWATER,
		AUDIO_UNDERWATERFAST,
		AUDIO_VINE,

		// TEST
		AUDIO_DING,				// 0
		AUDIO_LAKE,				// 1
		AUDIO_NTUT				// 2
	};

	enum class MENU {
		1_PLAYER_GAME,
		OPTIONS,
		ABOUT,
	};

	enum class OPTION {
		VOLUME,
		LEFT,
		DOWN,
		RIGHT,
		JUMP,
		SPACE,
		RUN,
		CAN_MOVE_BACKWARDTRUE,
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C���}�Y�e������
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnKeyDown(UINT, UINT, UINT);
	
	protected:
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
		void OnMove();
		
	private:
		int page;
		int current_select;
		int option_select;
		vector<int> option_sel;

		// INTRO ANIMATION
		CAnimation	intro;
		bool		intro_done;
		
		//BACKGROUND
		CMovingBitmap background1;

		// LOGO
		CAnimation logo;		// Logo animate
		CMovingBitmap logo1;	// 
		CMovingBitmap logo2;	// 

		// Menu
		CString stringHandler;
		vector<string> menu;

		// Option
		vector<string> option;
		vector<string> bin_select;
		vector<string> tri_select;

		// Test
		CInteger test_int = CInteger(2);
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();

		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);

	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��

	private:
		CString stringHandler;

		Level* level;
		int current_level;
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A(Game Over)
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame* g);
		void OnInit();
		void OnBeginState();	// �]�w�C�������һݪ��ܼ�

	protected:
		void OnMove();			// ���ʹC������
		void OnShow();			// ��ܳo�Ӫ��A���C���e��

	private:
		int counter;			// �˼Ƥ��p�ƾ�
	};

}