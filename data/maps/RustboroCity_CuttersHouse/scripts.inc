RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Cette expression déterminée… Cette\n"
	.string "façon souple avec laquelle vous\p"
	.string "bougez… Et votre POKéMON bien\n"
	.string "entraîné… Vous êtes évidemment un\p"
	.string "DRESSEUR talentueux ! Non, attends,\n"
	.string "ne dis pas un mot. Je peux le dire\p"
	.string "rien qu'en te regardant. Je suis\n"
	.string "sûr que vous pouvez faire bon usage\p"
	.string "de cette MACHINE CACHÉE. Pas besoin\n"
	.string "d'être modeste ou timide. Allez,\p"
	.string "prends-le !$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "Cette MACHINE CACHÉE, ou HM en\n"
	.string "abrégé, est COUPÉE. Une attaque HM\p"
	.string "est une attaque qui peut être\n"
	.string "utilisée par POKéMON en dehors des\p"
	.string "combats. Tout POKéMON qui a appris\n"
	.string "CUT peut abattre des arbres minces\p"
	.string "si l'DRESSEUR a obtenu le BADGE DE\n"
	.string "PIERRE. Et contrairement à une MT,\p"
	.string "un HM peut être utilisé plus d’une\n"
	.string "fois.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Lorsqu’ils agrandissaient la ville\n"
	.string "de RUSTBORO, mon père les a aidés.\p"
	.string "Il a fait en sorte que son POKéMON\n"
	.string "utilise CUT pour débarrasser les\p"
	.string "terres des arbres.$"
