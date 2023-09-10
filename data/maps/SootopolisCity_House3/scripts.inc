SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "Vous êtes un DRESSEUR DE POKéMON,\n"
	.string "n'est-ce pas ? JUAN de SOOTOPOLIS a\p"
	.string "de nombreux fans. Encore plus que\n"
	.string "son élève MARC ! En avez-vous ?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Oh, alors tu dois être plutôt\n"
	.string "fort.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Oh, chérie… C'est un peu solitaire.\n"
	.string "Essayez de travailler un peu plus\p"
	.string "dur pour qu'un fan vous suive.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Des fans dévoués viennent même de\n"
	.string "l’extérieur de HOENN. C'était\p"
	.string "vraiment fou quand je suis allé au\n"
	.string "DRESSEUR FAN CLUB à LILYCOVE.$"
