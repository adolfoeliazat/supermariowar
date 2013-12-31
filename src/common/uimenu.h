#ifndef __UIMENU_H_
#define __UIMENU_H_

enum MenuCodeEnum {
	MENU_CODE_NEIGHBOR_UP = 0,
	MENU_CODE_NEIGHBOR_DOWN = 1,
	MENU_CODE_NEIGHBOR_LEFT = 2,
	MENU_CODE_NEIGHBOR_RIGHT = 3,
	MENU_CODE_NONE, 
	MENU_CODE_CLICKED,
	MENU_CODE_UNSELECT_ITEM, 
	MENU_CODE_INPUT_TYPE_CHANGED, 
	MENU_CODE_INPUT_DEVICE_CHANGED, 
	MENU_CODE_CANCEL_INPUT, 
	MENU_CODE_START_GAME, 
	MENU_CODE_MODIFY_ACCEPTED,
	MENU_CODE_BONUS_DONE, 
	MENU_CODE_EXIT_APPLICATION, 
	MENU_CODE_TO_OPTIONS_MENU, 
	MENU_CODE_TO_CONTROLS_MENU, 
	MENU_CODE_BACK_TO_CONTROLS_MENU, 
	MENU_CODE_TO_PLAYER_1_CONTROLS, 
	MENU_CODE_TO_PLAYER_2_CONTROLS, 
	MENU_CODE_TO_PLAYER_3_CONTROLS, 
	MENU_CODE_TO_PLAYER_4_CONTROLS, 
	MENU_CODE_TO_MAIN_MENU, 
	MENU_CODE_TOGGLE_FULLSCREEN, 
	MENU_CODE_TO_SCREEN_SETTINGS, 
	MENU_CODE_TO_SCREEN_RESIZE, 
	MENU_CODE_MODE_CHANGED, 
	MENU_CODE_TO_GAME_SETUP_MENU, 
	MENU_CODE_TO_TEAM_SELECT_MENU, 
	MENU_CODE_BACK_TEAM_SELECT_MENU, 
	MENU_CODE_SOUND_VOLUME_CHANGED, 
	MENU_CODE_MUSIC_VOLUME_CHANGED, 
	MENU_CODE_TO_MODE_SETTINGS_MENU, 
	MENU_CODE_BACK_TO_GAME_SETUP_MENU, 
	MENU_CODE_BACK_TO_GAME_SETUP_MENU_FROM_MODE_SETTINGS, 
	MENU_CODE_EXIT_TOURNAMENT_YES, 
	MENU_CODE_EXIT_TOURNAMENT_NO, 
	MENU_CODE_TO_POWERUP_SELECTION_MENU, 
	MENU_CODE_BACK_TO_OPTIONS_MENU, 
	MENU_CODE_RESTORE_DEFAULT_POWERUP_WEIGHTS,
	MENU_CODE_CLEAR_POWERUP_WEIGHTS,
	MENU_CODE_TO_GRAPHICS_OPTIONS_MENU, 
	MENU_CODE_TO_EYECANDY_OPTIONS_MENU,
	MENU_CODE_TO_SOUND_OPTIONS_MENU, 
	MENU_CODE_TO_GAMEPLAY_OPTIONS_MENU, 
	MENU_CODE_TO_TEAM_OPTIONS_MENU, 
	MENU_CODE_BACK_TO_GRAPHIC_OPTIONS_MENU, 
	MENU_CODE_MENU_GRAPHICS_PACK_CHANGED,
	MENU_CODE_WORLD_GRAPHICS_PACK_CHANGED,
	MENU_CODE_GAME_GRAPHICS_PACK_CHANGED, 
	MENU_CODE_SOUND_PACK_CHANGED, 
	MENU_CODE_TO_PROJECTILES_OPTIONS_MENU,
	MENU_CODE_TO_PROJECTILES_LIMITS_MENU,
	MENU_CODE_TO_POWERUP_SETTINGS_MENU,
	MENU_CODE_POWERUP_RESET_YES,
	MENU_CODE_POWERUP_CLEAR_YES,
	MENU_CODE_POWERUP_RESET_NO,
	MENU_CODE_TOUR_STOP_CONTINUE, 
	MENU_CODE_EXIT_TOUR_YES, 
	MENU_CODE_EXIT_TOUR_NO, 
	MENU_CODE_RESET_STORED_POWERUPS,
	MENU_CODE_MAP_CHANGED,
	MENU_CODE_MAP_FILTER_EXIT,
	MENU_CODE_TO_MAP_FILTERS,
	MENU_CODE_TO_MAP_FILTER_EDIT,
	MENU_CODE_MAP_BROWSER_EXIT,
	MENU_CODE_TO_MAP_BROWSER_THUMBNAILS,
	MENU_CODE_SAVE_ALL_MAP_THUMBNAILS,
	MENU_CODE_BACK_TO_SCREEN_SETTINGS_MENU,
	MENU_CODE_SCREEN_FILTER_CHANGED,
	MENU_CODE_SCREEN_SETTINGS_CHANGED,
	MENU_CODE_GENERATE_THUMBS_RESET_YES,
	MENU_CODE_GENERATE_THUMBS_RESET_NO,
	MENU_CODE_MATCH_SELECTION_START,
	MENU_CODE_MATCH_SELECTION_MATCH_CHANGED,
	MENU_CODE_TO_MATCH_SELECTION_MENU,
	MENU_CODE_BACK_TO_MATCH_SELECTION_MENU,
	MENU_CODE_EXIT_WORLD_YES,
	MENU_CODE_EXIT_WORLD_NO,
	MENU_CODE_WORLD_STAGE_START,
	MENU_CODE_WORLD_STAGE_NO_START,
	MENU_CODE_TOUR_STOP_CONTINUE_FORCED,
	MENU_CODE_WORLD_MUSIC_CHANGED,
	MENU_CODE_WORLD_MAP_CHANGED,
	MENU_CODE_POWERUP_OVERRIDE_CHANGED,
	MENU_CODE_HEALTH_MODE_START_LIFE_CHANGED,
	MENU_CODE_HEALTH_MODE_MAX_LIFE_CHANGED,
	MENU_CODE_POWERUP_PRESET_CHANGED,
	MENU_CODE_POWERUP_SETTING_CHANGED,
	MENU_CODE_QUICK_GAME_START,
	MENU_CODE_TO_BONUS_PICKER_MENU,
	MENU_CODE_DELETE_STAGE_BUTTON,
	MENU_CODE_DELETE_STAGE_YES,
	MENU_CODE_DELETE_STAGE_NO,
	MENU_CODE_VEHICLE_MIN_MOVES_CHANGED,
	MENU_CODE_VEHICLE_MAX_MOVES_CHANGED,
	MENU_CODE_CREATE_VEHICLE,
	MENU_CODE_TO_NET_SERVERS_MENU,
	MENU_CODE_TO_NET_SERVERLIST,
	MENU_CODE_NET_SERVERLIST_EXIT,
	MENU_CODE_TO_NET_ADDREMOVE_SERVER_MENU,
	MENU_CODE_NET_CONNECT
};

#include "uicontrol.h"
#include "eyecandy.h"

class UI_Menu
{
	public:

		UI_Menu();
		~UI_Menu();

		void AddControl(UI_Control * control, UI_Control * up, UI_Control * down, UI_Control * left, UI_Control * right);
		void AddNonControl(UI_Control * control);
    UI_Control * GetHeadControl() {
        return headControl;
    }
		void SetHeadControl(UI_Control * control);
		void ResetMenu();

    void SetCancelCode(MenuCodeEnum code) {
        cancelCode = code;
    }

		void Update();
		void Draw();
		
    void ClearEyeCandy() {
        eyeCandy.clean();
    }

		void ResetCurrentControl();
		MenuCodeEnum SendInput(CPlayerInput * playerInput);

    void AddEyeCandy(CEyecandy * ec) {
        eyeCandy.add(ec);
    }

		void RememberCurrent();
		void RestoreCurrent();

    UI_Control * GetCurrentControl() {
        return current;
    }

    void SetControllingTeam(short teamid) {
        iControllingTeam = teamid;
    }
    void SetAllowExit(bool allowExit) {
        fAllowExitButton = allowExit;
    }

		MenuCodeEnum MouseClick(short iMouseX, short iMouseY);
    bool IsModifying() {
        return fModifyingItem;
    }

		void Refresh();

	protected:

		MenuCodeEnum MoveNextControl(MenuCodeEnum iDirection);

		std::list<UI_Control*> controls;
		
		UI_Control * current;
		UI_Control * savedCurrent;

		MenuCodeEnum cancelCode;
		bool fModifyingItem;

		UI_Control * headControl;

		CEyecandyContainer eyeCandy;

		short iControllingTeam;
		bool fAllowExitButton;
};

#endif //__UIMENU_H_

