AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
	.string "J'enquête sur ce vaisseau au nom du\n"
	.string "CAPT. POUPE. Il m'a aussi demandé\p"
	.string "de trouver un SCANNER, mais je n'ai\n"
	.string "pas réussi…$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
	.string "Oh! C'est un SCANNER ! Écoutez,\n"
	.string "puis-je vous demander de remettre\p"
	.string "ça au CAPT. POUPE ? Je veux\n"
	.string "enquêter un peu plus sur ce\p"
	.string "vaisseau.$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
	.string "Ce navire s'appelle S.S. CACTUS.\n"
	.string "Cela semble dater d'une époque\p"
	.string "antérieure.$"
