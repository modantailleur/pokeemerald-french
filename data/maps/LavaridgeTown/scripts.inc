.set LOCALID_RIVAL_ON_BIKE, 7
.set LOCALID_RIVAL, 8

LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_RIVAL, 11, 9
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "MAI : {PLAYER}{KUN} ! Cela fait\n"
	.string "longtemps qu'on ne s'est pas vu!\p"
	.string "Oh? Pendant que je visitais les\n"
	.string "sources chaudes, vous avez reçu le\p"
	.string "LAVARIDGE GYM BADGE. Vous avez dû\n"
	.string "collectionner de bons POKéMON… Non,\p"
	.string "je crois que vous en avez élevé. Je\n"
	.string "suppose que ce serait bien pour toi\p"
	.string "d'avoir ça.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "FLORA : Avec ces GO-GOGGLES, vous\n"
	.string "n'aurez aucun mal à traverser le\p"
	.string "désert près de la ROUTE 111. Mais,\n"
	.string "wow, {PLAYER}{KUN}… Des GYMS\p"
	.string "difficiles… Vous faites de gros\n"
	.string "efforts parce que vous ne voulez\p"
	.string "pas perdre contre moi, je parie !\n"
	.string "{PLAYER}{KUN}, je pense que je\p"
	.string "devrais défier ton père au\n"
	.string "PGUIDOALBURG GYM. A bientôt!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "BRICE : {PLAYER}, hé, ça fait un\n"
	.string "moment. Comment ça va? Hmm… C'est\p"
	.string "une bonne collection de BADGES.\n"
	.string "Très bien alors. Autant l'avoir.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "BRICE : Gardez-les avec vous si\n"
	.string "vous prévoyez d'aller dans ce\p"
	.string "désert près de la ROUTE 111. Il\n"
	.string "devrait y avoir des POKéMON qui\p"
	.string "sont exclusivement des habitants du\n"
	.string "désert. Vous pourriez les chercher.\p"
	.string "Quant à moi… j'envisage de défier\n"
	.string "NORMAN, le GYM LEADER de\p"
	.string "PGUIDOALBURG. Contrairement à toi,\n"
	.string "{PLAYER}, ton père a l'air vraiment\p"
	.string "dur. À bientôt !$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "J'ai ici un OEUF. J'avais espéré le\n"
	.string "faire éclore en le recouvrant de\p"
	.string "sable chaud près des sources\n"
	.string "chaudes. Mais cela ne semble pas\p"
	.string "suffire… J'ai entendu dire qu'il\n"
	.string "serait préférable de le conserver\p"
	.string "avec POKéMON et de le transporter\n"
	.string "partout. Vous êtes FORMATTHIEUEUR,\p"
	.string "n'est-ce pas ? Et votre POKéMON\n"
	.string "rayonne de vitalité. Alors, qu'en\p"
	.string "dis-tu ? Allez-vous faire éclore\n"
	.string "cet ŒUF ?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "Bien! J'espère que vous marcherez\n"
	.string "beaucoup avec cet EGG ici !$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{PLAYER} a reçu l'EGG.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "Oh? Vous avez trop de POKéMON. Il\n"
	.string "n'y a pas de place pour cet OEUF…$"

LavaridgeTown_Text_AsYouWishThen:
	.string "Comme vous le souhaitez, alors… Si\n"
	.string "vous changez d’avis à l’idée de\p"
	.string "faire éclore cet ŒUF, je serai là.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "De temps en temps, un ŒUF sera\n"
	.string "trouvé à la POKéMON DAY CARE. Ou du\p"
	.string "moins, c'est ainsi que circule la\n"
	.string "rumeur.$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "Nous puisons autant d’eau chaude\n"
	.string "que nécessaire, et pourtant les\p"
	.string "sources chaudes ne tarissent\n"
	.string "jamais. N'est-ce pas magique ? Ces\p"
	.string "sources chaudes apparaissent à\n"
	.string "proximité de volcans actifs. Les\p"
	.string "veines d'eau souterraines sont\n"
	.string "chauffées par le magma pour former\p"
	.string "des sources chaudes.$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "Être enterré dans ce sable chaud\n"
	.string "est… Soupir… Tellement chaud et\p"
	.string "paradisiaque… Hein ? Gyaah ! Aie!\n"
	.string "Un POKéMON m'a mordu les fesses !$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "Oh, tu aimes les sources chaudes,\n"
	.string "n'est-ce pas ? C'est surprenant\p"
	.string "pour quelqu'un d'aussi jeune que\n"
	.string "toi.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "Je me baigne dans les sources\n"
	.string "chaudes tous les jours. Je veux\p"
	.string "devenir un LEADER de GYM beau et\n"
	.string "fort comme ADRIANE.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "Si les gens mettent POKéMON dans\n"
	.string "des sources chaudes, cela pourrait\p"
	.string "être vraiment étrange. Eh bien, ça\n"
	.string "pourrait être un bain électrique,\p"
	.string "ou un bain moussant, ou même un\n"
	.string "bain de lave…$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "Ils prétendent que ces sources\n"
	.string "chaudes sont bonnes pour calmer les\p"
	.string "tensions nerveuses, soulager les\n"
	.string "muscles endoloris, résoudre les\p"
	.string "problèmes amoureux et attirer de\n"
	.string "l'argent…$"

LavaridgeTown_Text_TownSign:
	.string "VERMILAVA “ SOURCES CHAUDES DU\n"
	.string "CENTRE POKéMON Un excellent endroit\p"
	.string "pour se détendre ! ”$"

LavaridgeTown_Text_GymSign:
	.string "LEADER DU POKéMON GYM DE VERMILAVA\n"
	.string ": ADRIANE “ Un avec une passion\p"
	.string "ardente qui brûle ! ”$"

LavaridgeTown_Text_HerbShopSign:
	.string "POKéMON HERB SHOP “ Un goût amer,\n"
	.string "un meilleur remède ! ”$"
