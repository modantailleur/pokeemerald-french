SootopolisCity_House6_MapScripts::
	.byte 0

SootopolisCity_House6_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_ReceivedWailmerDoll
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, SootopolisCity_House6_EventScript_DeclineWailmerDoll
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	givedecoration DECOR_WAILMER_DOLL
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_House6_EventScript_NoRoomForWailmerDoll
	setflag FLAG_RECEIVED_WAILMER_DOLL
	release
	end

SootopolisCity_House6_EventScript_DeclineWailmerDoll::
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_ReceivedWailmerDoll::
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_NoRoomForWailmerDoll::
	bufferdecorationname STR_VAR_2, DECOR_WAILMER_DOLL
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll:
	.string "Bonjour! Vous êtes notre premier\n"
	.string "invité depuis un bon moment. Vous\p"
	.string "avez égayé ma journée, alors je\n"
	.string "vais vous offrir une grosse POUPÉE\p"
	.string "WAILMER.$"

SootopolisCity_House6_Text_TakeGoodCareOfIt:
	.string "Prenez-en bien soin!$"

SootopolisCity_House6_Text_IllHoldItForYou:
	.string "Oh, tu le veux, mais pas maintenant\n"
	.string "? D'accord, alors je le garde pour\p"
	.string "toi.$"

SootopolisCity_House6_Text_DontWantThisDoll:
	.string "Es-tu sûr? Tu ne veux pas de cette\n"
	.string "POUPÉE ?$"

SootopolisCity_House6_Text_LovePlushDolls:
	.string "J'adore les POUPÉES en peluche !$"
