PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "Les gens disaient avoir vu un\n"
	.string "POKéMON voler au-dessus de HOENN.\p"
	.string "Est-ce qu'il vole tout le temps ?\n"
	.string "N'a-t-il pas besoin de se reposer\p"
	.string "quelque part ?$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "Un POKÉMON du ciel ! Un POKéMON\n"
	.string "ciel !$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.string "D'où viens-tu ?$"

PacifidlogTown_House4_Text_YesTown:
	.string "Oui? OUI VILLE ? Je n'ai jamais\n"
	.string "entendu parler d'un endroit comme\p"
	.string "celui-là.$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "Non? Cela n'a aucun sens. Il faut\n"
	.string "venir de quelque part. Oh!\p"
	.string "Attendez! Tu ne vas pas dire que tu\n"
	.string "es né au fond de la mer ?$"
