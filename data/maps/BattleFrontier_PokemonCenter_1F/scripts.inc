.set LOCALID_NURSE, 1

BattleFrontier_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BattleFrontier_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST
	end

BattleFrontier_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_SchoolKid::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Man::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Picnicker::
	msgbox BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox BattleFrontier_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon:
	.string "Il y avait quelqu'un ici qui\n"
	.string "utilisait un POKéMON que je n'avais\p"
	.string "jamais vu auparavant. Je n'en ai\n"
	.string "jamais entendu parler à DRESSEUR'S\p"
	.string "SCHOOL, du moins. Je me demande où\n"
	.string "on peut attraper des POKéMON comme\p"
	.string "ça.$"

BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena:
	.string "D'accord! Prochain arrêt, la BATTLE\n"
	.string "ARENA ! Je ferais mieux d'obtenir\p"
	.string "le bon POKéMON sur le système de\n"
	.string "stockage PC.$"

BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge:
	.string "Riez… Je vais relever tous les\n"
	.string "défis avec juste ce bébé !$"

BattleFrontier_PokemonCenter_1F_Text_Skitty:
	.string "SKITTY : Mya myaaah !$"
