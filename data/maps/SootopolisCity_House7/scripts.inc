SootopolisCity_House7_MapScripts::
	.byte 0

SootopolisCity_House7_EventScript_OldMan::
	msgbox SootopolisCity_House7_Text_CityFromEruptedVolcano, MSGBOX_NPC
	end

SootopolisCity_House7_EventScript_PokefanF::
	msgbox SootopolisCity_House7_Text_CaveMadeToKeepSomething, MSGBOX_NPC
	end

SootopolisCity_House7_Text_CityFromEruptedVolcano:
	.string "Un volcan sous-marin est entré en\n"
	.string "éruption et a surgi des\p"
	.string "profondeurs. Son cratère a émergé\n"
	.string "de la mer et s'est rempli d'eau de\p"
	.string "pluie. C'est ainsi qu'est née\n"
	.string "ATALANOPOLIS.$"

SootopolisCity_House7_Text_CaveMadeToKeepSomething:
	.string "La grotte qui relie SOOTOPOLIS au\n"
	.string "monde extérieur… On dirait que la\p"
	.string "grotte a été conçue pour empêcher\n"
	.string "quelque chose de sortir. Ou est-ce\p"
	.string "que j'imagine juste des choses ?$"
