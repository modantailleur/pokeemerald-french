Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_RestUpHere:
	.string "Oh, chérie, chérie. Votre POKéMON\n"
	.string "n'est pas épuisé ? Si vous le\p"
	.string "souhaitez, reposez-vous ici. C'est\n"
	.string "une bonne idée ! Tu devrais faire\p"
	.string "ça.$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "C'est exact. Prenez votre temps et\n"
	.string "reposez-vous !$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
	.string "Oh, chérie, chérie. Votre POKéMON\n"
	.string "est toujours fatigué ? Tu devrais\p"
	.string "prendre un autre repos ici. C'est\n"
	.string "une bonne idée. Tu devrais faire\p"
	.string "ça.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "Est-ce ainsi? Vous n'avez pas\n"
	.string "besoin d'être timide.$"
