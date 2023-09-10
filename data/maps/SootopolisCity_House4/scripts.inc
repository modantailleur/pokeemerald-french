SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "Écoute-moi, je vais te dire quelque\n"
	.string "chose de bien. Il est censé y avoir\p"
	.string "une ancienne ruine dans la mer par\n"
	.string "ici. Il pourrait y avoir des\p"
	.string "trésors qui ne demandent qu'à être\n"
	.string "découverts là-bas.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "Trésors anciens… Ce serait bien\n"
	.string "s'ils existaient, mais même s'ils\p"
	.string "n'existaient pas, ce serait\n"
	.string "tellement beau de faire une\p"
	.string "promenade sous-marine avec mon\n"
	.string "POKéMON.$"

SootopolisCity_House4_Text_Azumarill:
	.string "AZUMARILL : Marurii.$"
