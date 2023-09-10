DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "Il y a beaucoup à dire sur le fait\n"
	.string "de vivre sur une petite île comme\p"
	.string "celle-ci en harmonie avec POKéMON\n"
	.string "et la famille.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "J'ai quitté le port principal de\n"
	.string "POIVRESSEL lorsque j'ai épousé mon\p"
	.string "mari ici. La vie passe lentement\n"
	.string "sur cette petite île. Mais être\p"
	.string "entouré par la belle mer, c'est\n"
	.string "aussi du bonheur.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZAGOON : Guguuh !$"
