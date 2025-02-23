.set LOCALID_MOVE_DELETER, 1

LilycoveCity_MoveDeletersHouse_MapScripts::
	.byte 0

LilycoveCity_MoveDeletersHouse_EventScript_MoveDeleter::
	lockall
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget::
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove::
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves::
	msgbox LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain::
	msgbox LilycoveCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove:
	.string "Euh… Oh, oui, je suis le MOVE\n"
	.string "DELGUIDOER. Je peux faire oublier à\p"
	.string "POKéMON ses mouvements. Voudrais-tu\n"
	.string "que je fasse ça ?$"

LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget:
	.string "Quel POKéMON devrait oublier un\n"
	.string "mouvement ?$"

LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten:
	.string "Quel mouvement faut-il oublier ?$"

LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove:
	.string "{STR_VAR_1} ne connaît qu'un seul\n"
	.string "mouvement, il ne peut donc pas être\p"
	.string "oublié…$"

LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten:
	.string "Hum ! Le {STR_VAR_1} de {STR_VAR_2} ? Ce\n"
	.string "mouvement devrait être oublié ?$"

LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove:
	.string "Cela a fonctionné à la perfection !\n"
	.string "{STR_VAR_1} a complètement oublié\p"
	.string "{STR_VAR_2}.$"

LilycoveCity_MoveDeletersHouse_Text_ComeAgain:
	.string "Revenez s'il y a des mouvements à\n"
	.string "oublier.$"

LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves:
	.string "Quoi? Aucun EGG ne devrait\n"
	.string "connaître de mouvements.$"

LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf:
	.string "Hum ! Votre {STR_VAR_1} ne semble pas\n"
	.string "prêt à oublier SURF.$"
