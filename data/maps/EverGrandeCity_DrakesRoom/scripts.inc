EverGrandeCity_DrakesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_DrakesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 4, EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_Defeated::
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_IntroSpeech:
	.string "Je suis le dernier de la POKéMON\n"
	.string "LEAGUE ELITE FOUR, ARAGON le maître\p"
	.string "DRAGON ! Dans leur état naturel,\n"
	.string "les POKéMON sont des êtres vivants\p"
	.string "sauvages. Ils sont libres. Parfois,\n"
	.string "ils nous gênent. Parfois, ils nous\p"
	.string "aident. Pour que nous puissions\n"
	.string "combattre avec POKéMON comme\p"
	.string "partenaires, savez-vous ce qu'il\n"
	.string "faut ? Savez-vous ce qui est\p"
	.string "nécessaire ? Si vous ne le faites\n"
	.string "pas, vous ne m'emporterez jamais !$"

EverGrandeCity_DrakesRoom_Text_Defeat:
	.string "Superbe, il faut le dire.$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech:
	.string "Vous méritez tout le mérite d'être\n"
	.string "arrivé jusqu'ici en tant\p"
	.string "qu'DRESSEUR de POKéMON. Vous\n"
	.string "semblez savoir ce qui est\p"
	.string "nécessaire. Oui, ce dont un\n"
	.string "FORMATTHIEUEUR a besoin, c'est d'un\p"
	.string "cœur vertueux. POKéMON touche le\n"
	.string "bon cœur des dresseurs et apprend\p"
	.string "le bien du mal. Ils touchent le bon\n"
	.string "cœur des FORMATTHIEUEURS et\p"
	.string "deviennent forts. Aller! Allez-y !\n"
	.string "Le CHAMPION attend!$"
