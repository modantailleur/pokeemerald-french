FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "PROF. KOSMO : Oh… Je n'aurais\n"
	.string "jamais dû me laisser tromper en\p"
	.string "disant à l'ÉQUIPE MAGMA où vous\n"
	.string "pouvez trouver des MÉTÉORITES…\p"
	.string "Cette MÉTÉORITE de MGUIDOEOR FALLS…\n"
	.string "Elle ne sera jamais à moi\p"
	.string "maintenant…$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "Oh! Hein ? Cet objet… Serait-ce le\n"
	.string "cas ? Est-ce la MÉTÉORITE que TEAM\p"
	.string "MAGMA a prise à MGUIDOEOR FALLS ?\n"
	.string "S'il vous plaît, puis-je l'avoir ?\p"
	.string "Je ne le demande pas gratuitement.\n"
	.string "Que diriez-vous d'un échange contre\p"
	.string "cette MT ?$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "PROF. KOSMO : Cette MT, elle\n"
	.string "représente mon sentiment de\p"
	.string "gratitude. S'il vous plaît,\n"
	.string "utilisez-le !$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "PROF. KOSMO : Oh, je n'arrive pas à\n"
	.string "y croire. C'est vraiment, vraiment\p"
	.string "génial ! Cela va vraiment aider mes\n"
	.string "recherches !$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "PROF. KOSMO : Oh, mais… je suis\n"
	.string "écrasé de déception…$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "PROF. KOSMO : S'il vous plaît,\n"
	.string "puis-je avoir cette MÉTÉORITE ? Je\p"
	.string "ne le demande pas gratuitement. Que\n"
	.string "diriez-vous d'un échange contre\p"
	.string "cette MT ?$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "LE PROF. KOSMO s'est rendu à\n"
	.string "MGUIDOEOR FALLS sur la ROUTE 114\p"
	.string "avec quelques personnes de l'ÉQUIPE\n"
	.string "MAGMA.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "Pauvre PROF. KOSMO… Il est\n"
	.string "tellement déprimé… Je suis désolé\p"
	.string "pour lui.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "Regardez le PROF. KOSMO… Il est\n"
	.string "tellement heureux ! Je pense que\p"
	.string "c'est mignon.$"
