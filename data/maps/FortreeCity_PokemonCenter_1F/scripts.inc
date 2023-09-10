.set LOCALID_NURSE, 1

FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Écoute, gamin, tu travailles sur un\n"
	.string "POKéDEX ? Hmm… Allez dans la ZONE\p"
	.string "SAFARI. C'est ma suggestion.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Avez-vous fait quelque chose au\n"
	.string "RECORD CORNER ? C'est plutôt\p"
	.string "chouette. Il mélange et assortit\n"
	.string "les disques des DRESSEURS. Je ne\p"
	.string "sais pas trop comment ça marche,\n"
	.string "mais c'est cool. C'est excitant,\p"
	.string "même !$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Oh, wow, vous avez un POKéNAV ! Et\n"
	.string "c'est comme le mien !\p"
	.string "Connaissez-vous le système\n"
	.string "MATTHIEUCH CALL de POKéNAV ?\p"
	.string "Accédez-y et vous pourrez discuter\n"
	.string "avec les FORMATTHIEUEURS\p"
	.string "enregistrés à tout moment. Il vous\n"
	.string "montre également quels\p"
	.string "FORMATTHIEUEURS souhaitent une\n"
	.string "revanche avec vous. C'est vraiment\p"
	.string "chouette ! Ces gars du DEVON savent\n"
	.string "vraiment ce qu'ils font !$"
