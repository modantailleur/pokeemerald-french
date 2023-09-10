.set LOCALID_EXPERT_M, 4
.set LOCALID_TWIN, 5
.set LOCALID_SCHOOL_KID_M, 7
.set LOCALID_PSYCHIC_M, 8

DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "Qu'est-ce qui est à la mode ? Eh\n"
	.string "bien, ce doit être “ {STR_VAR_1} ” ! Je\p"
	.string "ne peux pas imaginer à quoi\n"
	.string "ressemblerait la vie sans “ {STR_VAR_1}\p"
	.string "” !$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "Qu'est-ce qui est à la mode ? Eh\n"
	.string "bien, ce doit être “ {STR_VAR_1} ” !\p"
	.string "Mais ça m'ennuie un peu. Je devrais\n"
	.string "chercher la prochaine grande\p"
	.string "chose.$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "J'enseigne à mon POKéMON “ {STR_VAR_1}\n"
	.string "”, mais ça ne se passe pas bien.\p"
	.string "C'est un peu trop, je pense.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "J'étudie actuellement le style\n"
	.string "branché et branché “ {STR_VAR_1} ”.\p"
	.string "Est-il vrai qu'il existe un lien\n"
	.string "profond entre “ {STR_VAR_1} ” et “\p"
	.string "{STR_VAR_2} ” ?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "Oh! Donc mon intuition était bonne\n"
	.string "! Je suis sur le point d'être\p"
	.string "branché et de réussir, yowza !$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "Quoi?! Est-ce ainsi?! Ce n'est pas\n"
	.string "facile pour un homme plus âgé comme\p"
	.string "moi de suivre les tendances !$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Toute cette histoire à propos de “\n"
	.string "{STR_VAR_1} ”… Il n'y a pas une émission\p"
	.string "de télévision dessus ?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "De l'autre côté de la mer… “ {STR_VAR_1}\n"
	.string "” est-il encore plus populaire ?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Je collectionne les produits\n"
	.string "officiels sous licence “ {STR_VAR_1} ”.\p"
	.string "J'ai des POUPÉES officielles “\n"
	.string "{STR_VAR_1} ”… Des vêtements officiels\p"
	.string "de la marque “ {STR_VAR_1} ”… Et des\n"
	.string "livres d'images sous licence\p"
	.string "officielle “ {STR_VAR_1} ”. Héhé, je\n"
	.string "possède ! Je ne partage rien avec\p"
	.string "toi !$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "IDENTIFIER LE BON “{STR_VAR_1}“ GUIDO LE\n"
	.string "MAUVAIS “{STR_VAR_1}“... LE LIEN ENTRE\p"
	.string "“{STR_VAR_1}“ GUIDO POKéMON... UTILE\n"
	.string "“{STR_VAR_1}“... Il est soigneusement\p"
	.string "rempli de livres sur “{STR_VAR_1}.“$"

DewfordTown_Hall_Text_TrendsScream:
	.string "“{STR_VAR_1}'S SCREAM“ est le titre.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "“Le sourire de {STR_VAR_1}“ est le\n"
	.string "titre.$"

DewfordTown_Hall_Text_LastTrend:
	.string "Il s'intitule “LE DERNIER {STR_VAR_1}“.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "Il s'intitule “LA NAISSANCE DE\n"
	.string "{STR_VAR_1}“.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "J'ai vu “{STR_VAR_1}“ ! Cool hein? C'est\n"
	.string "vraiment la chose la plus cool qui\p"
	.string "soit ! C'était génial! C'était la\n"
	.string "vraie chose, oh ouais !$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Oh non, non, non. Ce prétendu “\n"
	.string "{STR_VAR_1} ” que vous prétendez avoir\p"
	.string "vu n'est pas le cas. L'article\n"
	.string "authentique, c'est beaucoup…\p"
	.string "Comment le dire ? Plus pointu, mais\n"
	.string "plus doux ! Ah, peu importe. C'est\p"
	.string "étonnant!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Hé, écoute, j'ai composé une\n"
	.string "chanson thème pour “{STR_VAR_1}“. “\p"
	.string "{STR_VAR_1} ” est très populaire en ce\n"
	.string "moment. D'accord, écoute ! … … Oh!\p"
	.string "{STR_VAR_1} ! Merveilleux {STR_VAR_1} !$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "… … J'ose dire, mon gars, ça\n"
	.string "paierait pour toi de travailler ton\p"
	.string "chant avant de te jouer avec\n"
	.string "“{STR_VAR_1}.“$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "Quoi qu'il en soit, comme je le\n"
	.string "disais plus tôt, nous devrions nous\p"
	.string "réunir et organiser une fête “\n"
	.string "{STR_VAR_1} ” sur l'île.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "Oh, une très bonne idée ! Il sera\n"
	.string "décidé une fois pour toutes qui est\p"
	.string "le meilleur à “ {STR_VAR_1} ”. Génial,\n"
	.string "en effet ! À partir d'aujourd'hui,\p"
	.string "nos vies tourneront autour de “\n"
	.string "{STR_VAR_1} ” !$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "Je pensais cependant… Ne\n"
	.string "seriez-vous pas d'accord pour dire\p"
	.string "que “ {STR_VAR_1} ” est passé du statut\n"
	.string "de quelque chose de tendance à\p"
	.string "celui de notre vie quotidienne ?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Demander pardon? C'est autant, quoi\n"
	.string "? Cependant, il est vrai que “\p"
	.string "{STR_VAR_1} ” pèse lourdement sur votre\n"
	.string "esprit, que vous soyez éveillé ou\p"
	.string "endormi. Absolument, vous êtes le\n"
	.string "PROF. “ {STR_VAR_1} ”, vieux sport !$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Si vous et moi faisons équipe pour\n"
	.string "former un combo, nous serons\p"
	.string "invincibles lorsqu'il s'agira de\n"
	.string "tout ce qui concerne “ {STR_VAR_1} ” !$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Parfait, mon ami ! Nous serons le\n"
	.string "DUO “ {STR_VAR_1} ” ! N'est-ce pas une\p"
	.string "image mûre ? Hahahah !$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Pour moi, SLUDGE BOMB est au sommet\n"
	.string "de sa popularité. C'est celui-là.\p"
	.string "Hein ? Vous me dites que vous ne\n"
	.string "connaissez pas SLUDGE BOMB ? C'est\p"
	.string "carrément pitoyable. Je vais t'en\n"
	.string "donner un.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "J'adore la bombe à boue. Mais les\n"
	.string "POKéMON avec le mouvement “{STR_VAR_1}“\p"
	.string "sont également de la partie.$"
