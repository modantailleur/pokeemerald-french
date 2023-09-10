.set LOCALID_ATTENDANT, 1

VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 6, 5
	waitstate
	releaseall
	end

VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end


@ Leftover text from when this was a Contest Hall in R/S
@ Unused
VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
	.string "À quel CONCOURS participez-vous ?\n"
	.string "Envie d'un conseil ? Dans n'importe\p"
	.string "quel CONCOURS, par exemple un\n"
	.string "CONCOURS MIGNON, je ne pense pas\p"
	.string "qu'ils vous jugent uniquement sur\n"
	.string "votre gentillesse au premier tour.\p"
	.string "Vous devez trouver des moyens de\n"
	.string "mieux élever POKéMON.$"

@ Unused
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
	.string "J'ai élevé mon POKéMON pour qu'il\n"
	.string "soit mignon. J'ai découvert que\p"
	.string "vous pouvez mettre POKéMON dans un\n"
	.string "CONCOURS de gentillesse ! Je suis\p"
	.string "tellement contente d'avoir élevé\n"
	.string "mon POKéMON avec soin et amour…$"

@ Unused
VerdanturfTown_ContestHall_Text_MyMonRules:
	.string "Mes règles POKéMON ! C'est cool,\n"
	.string "résistant mais beau, mignon et\p"
	.string "intelligent. C'est complet ! Autant\n"
	.string "viser des victoires dans chaque\p"
	.string "CONCOURS.$"

@ Unused
VerdanturfTown_ContestHall_Text_NormalRankStage:
	.string "CONCOURS POKéMON ÉTAPE DE RANG\n"
	.string "NORMAL !$"
