SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
	special GetSeedotSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
	special GetLotadSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
	.string "Connaissez-vous le POKéMON SEEDOT ?\n"
	.string "On ne le voit presque jamais à\p"
	.string "SOOTOPOLIS. Quoi qu'il en soit,\n"
	.string "j'adore le gros SEEDOT. Le plus\p"
	.string "gros le meilleur. Mais mon jeune\n"
	.string "frère dit que LOTAD est plus gros.\p"
	.string "C'est bête. SEEDOT doit être plus\n"
	.string "gros que ça ! Hein? Avez-vous un\p"
	.string "SEEDOT avec vous ? P-p-s'il te\n"
	.string "plaît, montre-moi !$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
	.string "{STR_VAR_2} pouces ! Oh mon Dieu, c'est\n"
	.string "un gros problème ! Il pourrait même\p"
	.string "battre le gros LOTAD que mon jeune\n"
	.string "frère a vu ! Merci de me l'avoir\p"
	.string "montré. C'est mon remerciement !$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
	.string "{PLAYER} a reçu une POTION.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "Hein ? Votre SAC est plein à\n"
	.string "craquer.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
	.string "{STR_VAR_2} pouces, n'est-ce pas ? Hmm…\n"
	.string "J'ai vu un SEEDOT plus gros que\p"
	.string "celui-ci.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
	.string "Oh, maintenant, c'est quelque\n"
	.string "chose… Mais ce n'est pas un SEEDOT\p"
	.string "!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
	.string "Vous n'avez pas un gros SEEDOT ?\n"
	.string "C'est dommage… Si vous obtenez un\p"
	.string "gros SEEDOT, venez me le montrer.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
	.string "Le plus gros SEEDOT de l’histoire !\n"
	.string "Le géant de {STR_VAR_2} de {STR_VAR_3} pouces\p"
	.string "! Un SEEDOT plus gros qu'un LOTAD\n"
	.string "toujours voulu !$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
	.string "Connaissez-vous le POKéMON LOTAD ?\n"
	.string "On le voit rarement à SOOTOPOLIS.\p"
	.string "J'aime, je veux dire j'adore, gros\n"
	.string "LOTAD ! Mon grand frère dit que\p"
	.string "SEEDOT est plus gros. Mais c'est\n"
	.string "faux ! Tout le monde sait que LOTAD\p"
	.string "est bien plus gros. Hein ?\n"
	.string "Avez-vous un LOTAD? P-p-s'il te\p"
	.string "plaît, montre-moi !$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
	.string "{STR_VAR_2} pouces ! Wow, c'est gros !\n"
	.string "Il est peut-être encore plus gros\p"
	.string "que l'énorme SEEDOT que mon grand\n"
	.string "frère a vu. Merci de me l'avoir\p"
	.string "montré ! C'est mon remerciement !$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
	.string "{PLAYER} a reçu une POTION.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "Hein ? Votre SAC est plein à\n"
	.string "craquer.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
	.string "{STR_VAR_2} pouces ? Hmm… J'ai vu un\n"
	.string "LOTAD plus gros que celui-ci ici.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
	.string "Eh bien, n'est-ce pas quelque chose\n"
	.string "! Mais ce n'est pas LOTAD !$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
	.string "Vous n'avez pas un gros LOTAD ?\n"
	.string "Comme c'est décevant… Si vous\p"
	.string "obtenez un gros LOTAD, venez me le\n"
	.string "montrer !$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
	.string "Le plus gros LOTAD de l'histoire !\n"
	.string "Le colosse de {STR_VAR_2} de {STR_VAR_3}\p"
	.string "pouces ! UN LOTAD plus gros qu'un\n"
	.string "SEEDOT toujours voulu !$"
