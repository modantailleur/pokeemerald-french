.set LOCALID_NURSE, 1
.set LOCALID_LANETTE, 4

FallarborTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

FallarborTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl::
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Lanette::
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_LanetteGreeting, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth::
	applymovement LOCALID_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest::
	applymovement LOCALID_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExited::
	playse SE_SLIDING_DOOR
	removeobject LOCALID_LANETTE
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Text_LanetteGreeting:
	.string "Oh salut. Tu es? D'accord, votre\n"
	.string "nom est {PLAYER}{KUN}. Je vois que\p"
	.string "vous êtes un FORMATTHIEUEUR. Cela\n"
	.string "signifie donc que vous utilisez le\p"
	.string "système de stockage POKéMON que\n"
	.string "j'ai développé. La façon dont je\p"
	.string "suis arrivé à cette conclusion est\n"
	.string "un simple processus déductif. Vous\p"
	.string "m'avez parlé parce que vous vouliez\n"
	.string "accéder à quelque chose sur ce PC.\p"
	.string "Oh je suis désolé. Je m'appelle\n"
	.string "ANNGUIDOTE. Honnêtement, je suis\p"
	.string "heureux de vous rencontrer. C'est\n"
	.string "génial que vous utilisiez le\p"
	.string "système de stockage. Si vous le\n"
	.string "pouvez, rendez-moi visite à la\p"
	.string "maison. Ma maison est sur la ROUTE\n"
	.string "114.$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown:
	.string "Je me demande à quoi ressemblait\n"
	.string "POKéMON il y a très, très longtemps\p"
	.string "? Peut-être que le FOSSIL MANIAC à\n"
	.string "la périphérie de la ville le\p"
	.string "saura.$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees:
	.string "Dans les champs de FALLARBOR, nous\n"
	.string "plantons des plants d'arbres\p"
	.string "robustes qui prospèrent même dans\n"
	.string "les cendres volcaniques.$"
