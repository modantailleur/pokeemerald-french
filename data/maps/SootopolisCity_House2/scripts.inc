SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "MT. PYRE… À son sommet se trouvent\n"
	.string "deux orbes placés côte à côte. Le\p"
	.string "saviez-vous ?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "Oui, deux orbes côte à côte… Les\n"
	.string "voir ensemble… C'est en quelque\p"
	.string "sorte apaisant…$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "Est-ce ainsi? Peut-être\n"
	.string "devriez-vous visiter et voir…$"
