.set LOCALID_NURSE, 1

VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
	.string "Vous ne pouvez pas vous considérer\n"
	.string "comme un véritable DRESSEUR si vous\p"
	.string "n'avez pas confiance en votre\n"
	.string "POKéMON. Seuls ceux qui peuvent\p"
	.string "croire en leur POKéMON en combat\n"
	.string "peuvent gagner jusqu'au bout.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent:
	.string "La raison pour laquelle tout le\n"
	.string "monde visiterait VERGUIDOTURF…\p"
	.string "C'est la TENTE DE BATAILLE. Il va\n"
	.string "sans dire. Ou y a-t-il quelqu'un\p"
	.string "ici que vous êtes venu voir ?$"
