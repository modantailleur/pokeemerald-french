.set LOCALID_ATTENDANT, 1

FallarborTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentCorridor_OnFrame
	.byte 0

FallarborTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

FallarborTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	releaseall
	end

FallarborTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
FallarborTown_ContestHall_Text_DoAllRightInPreliminary:
	.string "Nous nous en sortons bien au tour\n"
	.string "préliminaire, mais nous ne pourrons\p"
	.string "jamais gagner les appels… Peut-être\n"
	.string "que cela signifie que je dois\p"
	.string "surveiller ce que font les autres\n"
	.string "candidats…$"

@ Unused
FallarborTown_ContestHall_Text_MonAllTheseRibbons:
	.string "Voir! Mon POKéMON a gagné tous ces\n"
	.string "RUBANS ! Votre POKéMON a-t-il gagné\p"
	.string "des RUBANS ? Vous pouvez les\n"
	.string "consulter sur votre POKéNAV.$"

@ Unused
FallarborTown_ContestHall_Text_CantWinEverywhere:
	.string "Je ne peux pas battre les GYM\n"
	.string "LEADERS… Je ne peux gagner aucun\p"
	.string "CONCOURS… J'ai été ici, là et\n"
	.string "partout, et tout cela pour rien…$"

@ Unused
FallarborTown_ContestHall_Text_SuperRankStage:
	.string "CONCOURS POKéMON SUPER RANK STAGE\n"
	.string "!$"
