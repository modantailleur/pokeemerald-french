MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "Toutes sortes d’êtres errent sur\n"
	.string "les pentes de MT. PYRE… On ne sait\p"
	.string "pas ce qui peut arriver. Prends ça.\n"
	.string "C'est pour votre bien.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Demandez à un POKéMON de tenir\n"
	.string "cette CLEANSE TAG. Cela aidera à\p"
	.string "repousser les POKéMON sauvages.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Êtes-vous venu rendre hommage aux\n"
	.string "esprits des disparus POKéMON ? Vous\p"
	.string "devez beaucoup prendre soin de\n"
	.string "votre POKéMON.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "C'est le dernier lieu de repos de\n"
	.string "mon ZIGZAGOON. Je l'ai chéri...$"
