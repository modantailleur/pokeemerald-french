PacifidlogTown_House1_MapScripts::
	.byte 0

PacifidlogTown_House1_EventScript_Man::
	msgbox PacifidlogTown_House1_Text_RegiStory, MSGBOX_NPC
	end

PacifidlogTown_House1_EventScript_Woman::
	msgbox PacifidlogTown_House1_Text_SixDotsOpenThreeDoors, MSGBOX_NPC
	end

PacifidlogTown_House1_Text_RegiStory:
	.string "Dans la région HOENN, il existe\n"
	.string "trois POKéMON qui représentent le\p"
	.string "pouvoir de la roche, de la glace et\n"
	.string "de l'acier. On dit que chacun d’eux\p"
	.string "se cache au plus profond des\n"
	.string "grottes. C'est l'histoire que j'ai\p"
	.string "entendue quand j'étais petit.$"

PacifidlogTown_House1_Text_SixDotsOpenThreeDoors:
	.string "“Six points ouvrent trois portes.“\n"
	.string "Grand-père disait ça, mais je ne\p"
	.string "sais pas ce qu'il voulait dire.$"
