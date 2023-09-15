.set LOCALID_WOMAN_1, 19
.set LOCALID_MAN_1, 20

LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "FLORA : Oh, hé ? {PLAYER}{KUN}, tu\n"
	.string "fais du shopping aussi ? J'ai\p"
	.string "acheté tout un tas de POUPÉES et\n"
	.string "d'AFFICHES. Bien sûr, j'ai aussi\p"
	.string "attrapé beaucoup de POKéMON, et je\n"
	.string "les élève correctement aussi. En\p"
	.string "fait, je suis plus inquiet si vous\n"
	.string "relancez POKéMON correctement,\p"
	.string "{PLAYER}{KUN}. Je vais me battre\n"
	.string "avec toi pour que tu puisses me\p"
	.string "montrer ton POKéMON, {PLAYER}{KUN}.$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "MAI : Oh, pourquoi ? {PLAYER}{KUN},\n"
	.string "n'as-tu pas augmenté ton POKéMON ?\p"
	.string "Ce n'est pas une très bonne\n"
	.string "performance en tant qu'DRESSEUR…$"

LilycoveCity_Text_MayBattleMe:
	.string "FLORA : Allez, combattez avec moi\n"
	.string "pour que je puisse vérifier votre\p"
	.string "POKéMON !$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "MAI : Le POKéMON que j'ai élevé ne\n"
	.string "sera pas battu par votre POKéMON,\p"
	.string "{PLAYER}{KUN} !$"

LilycoveCity_Text_MayDefeat:
	.string "… … … … … … … … Je me souviens de\n"
	.string "la bataille que j'ai eue avec toi,\p"
	.string "{PLAYER}{KUN}, sur la ROUTE 103.\n"
	.string "Cette bataille t'a aidé à devenir\p"
	.string "aussi fort, {PLAYER}{KUN}, n'est-ce\n"
	.string "pas ?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "FLORA : Je pense retourner bientôt\n"
	.string "à LITTLEROOT. J'ai attrapé un bon\p"
	.string "groupe de POKéMON et mon POKéDEX\n"
	.string "arrive, alors je rentre à la maison\p"
	.string "pour le montrer à mon père.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{PLAYER}{KUN}, qu'est-ce que tu vas\n"
	.string "faire ? Récupérer tous les BADGES\p"
	.string "GYM et relever le défi POKéMON\n"
	.string "LEAGUE ? Eh bien, pendant que vous\p"
	.string "récupérez des BADGES, {PLAYER}{KUN},\n"
	.string "je vais travailler sur mon POKéDEX.\p"
	.string "Je vais le terminer avant vous ! À\n"
	.string "bientôt !$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{PLAYER}{KUN}, qu'est-ce que tu vas\n"
	.string "faire ? Relevez-vous le défi\p"
	.string "POKéMON LEAGUE ? Ou allez-vous\n"
	.string "terminer votre POKéDEX ? J'ai\p"
	.string "peut-être perdu contre toi au\n"
	.string "combat, mais je terminerai mon\p"
	.string "POKéDEX avant toi ! À bientôt !$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{PLAYER}{KUN}, qu'est-ce que tu vas\n"
	.string "faire ? Relevez-vous le défi ZONE\p"
	.string "DE COMBAT ? Ou allez-vous terminer\n"
	.string "votre POKéDEX ? J'ai peut-être\p"
	.string "perdu contre toi au combat, mais je\n"
	.string "terminerai mon POKéDEX avant toi !\p"
	.string "À bientôt !$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "BRICE : Oh, hé, c'est {PLAYER}. Je\n"
	.string "fais une course pour mon père. Non,\p"
	.string "je n'achète aucune POUPÉE. Quoi\n"
	.string "qu'il en soit, ça fait longtemps.\p"
	.string "Vous voulez vous battre pour voir\n"
	.string "qui a le mieux élevé POKéMON ?$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "BRICE : Oh, qu'est-ce qu'il y a ?\n"
	.string "Vous n'avez pas confiance ?$"

LilycoveCity_Text_BrendanBattleMe:
	.string "BRICE : Vous voulez vous battre\n"
	.string "pour voir qui a le mieux élevé\p"
	.string "POKéMON ?$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "BRICE : Aww, mais tu sais que je ne\n"
	.string "vais pas perdre contre aucun\p"
	.string "{PLAYER}.$"

LilycoveCity_Text_BrendanDefeat:
	.string "Humph… Vous avez fait beaucoup de\n"
	.string "relance. Ça pique un peu, j'avais\p"
	.string "une longueur d'avance sur toi en\n"
	.string "tant que DRESSEUR…$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "BRICE : Je… j'ai l'intention de\n"
	.string "rentrer chez moi à LITTLEROOT. Tu\p"
	.string "sais que j'aide mon père sur son\n"
	.string "POKéDEX. Tout se passe plutôt bien,\p"
	.string "alors je devrais aller lui\n"
	.string "montrer.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{PLAYER}, qu'allez-vous faire ?\n"
	.string "Récupérer tous les BADGES GYM et\p"
	.string "relever le défi POKéMON LEAGUE ?\n"
	.string "Peut-être que je ferai ça aussi…\p"
	.string "Bon, de toute façon, accrochez-vous\n"
	.string "!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{PLAYER}, qu'allez-vous faire ?\n"
	.string "Puisque vous êtes si fort, est-ce\p"
	.string "que vous relevez le défi POKéMON\n"
	.string "LEAGUE ? Hé, même moi : si\p"
	.string "j'entraînais un peu plus mon\n"
	.string "POKéMON, je devrais être plus fort\p"
	.string "que toi, {PLAYER}. Bon, de toute\n"
	.string "façon, accrochez-vous !$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{PLAYER}, qu'allez-vous faire ?\n"
	.string "Relevez-vous le défi ZONE DE COMBAT\p"
	.string "? Ou allez-vous terminer votre\n"
	.string "POKéDEX ? Puisque vous êtes si\p"
	.string "fort, vous devriez envisager le\n"
	.string "ZONE DE COMBAT. Hé, si j'entraîne\p"
	.string "un peu plus mon POKéMON, je\n"
	.string "deviendrai plus fort que toi,\p"
	.string "{PLAYER}. Peut-être que je devrais\n"
	.string "aller à ZONE DE COMBAT. Bon, de\p"
	.string "toute façon, accrochez-vous !$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Fufufu… Nous avons déplacé plus de\n"
	.string "butin dans notre CACHE secrète\p"
	.string "aujourd'hui… Qui-qui es-tu ?! Je\n"
	.string "parlais juste à moi-même !$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "Je ne suis qu'un GRUNT, donc je ne\n"
	.string "sais pas ce que pense le BOSS… Mais\p"
	.string "étant dans la TEAM AQUA, je sais\n"
	.string "que j'aurai la chance de faire de\p"
	.string "grandes choses ! Qui-qui es-tu ?!\n"
	.string "Je parlais juste à moi-même !$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "Hey vous! Ne vous approchez pas de\n"
	.string "la grotte dans la crique !\p"
	.string "Pourquoi? Vous n'avez pas besoin de\n"
	.string "raison ! Je suis un adulte, alors\p"
	.string "écoute-moi !$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "Si ce vaste monde devient le nôtre,\n"
	.string "celui de la TEAM AQUA, ce sera\p"
	.string "aussi un endroit plus heureux pour\n"
	.string "POKéMON.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "Là! WAILMER! Sortez de l'eau\n"
	.string "maintenant !$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "Hein ? Que veux-tu? Vous gâchez\n"
	.string "notre entraînement, alors\p"
	.string "pouvez-vous vous perdre ?$"

LilycoveCity_Text_ContestHallInTown:
	.string "Il y a une SALLE DE CONCOURS\n"
	.string "POKéMON dans cette ville. Cela\p"
	.string "signifie que des POKéMON bien\n"
	.string "élevés proviendront de tout le\p"
	.string "pays. Mon cœur se gonfle\n"
	.string "d’excitation !$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "Avez-vous vu cette étrange grotte\n"
	.string "dans la crique à la sortie de la\p"
	.string "ville ?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "Je vais apprendre à mon POKéMON de\n"
	.string "nouveaux mouvements pour participer\p"
	.string "à un CONCOURS. Donc, je vais voir\n"
	.string "le MOVE DELGUIDOER et lui faire\p"
	.string "oublier les mouvements HM.$"

LilycoveCity_Text_ImFromKanto:
	.string "Je viens de KANTO. La région HOENN\n"
	.string "est magnifique avec toute son eau\p"
	.string "et sa nature verdoyante. Hein ?\n"
	.string "Attendez une seconde… Pourrait-il y\p"
	.string "avoir des POKéMON rares qui vivent\n"
	.string "uniquement dans cette zone ?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "L'équipe AQUA entraîne son WAILMER\n"
	.string "dans la crique. Nous, LES MARINS,\p"
	.string "ne pouvons pas prendre la mer avec\n"
	.string "nos bateaux en travers du chemin !$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "Ohé, le saviez-vous ? Quelqu'un a\n"
	.string "écarté TEAM AQUA pour nous ! Cela a\p"
	.string "permis de sortir le WAILMER de\n"
	.string "l'anse, afin que nous puissions\p"
	.string "ressortir nos bateaux.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "Je faisais une sieste relaxante à\n"
	.string "l'auberge en bord de mer au son des\p"
	.string "vagues… Quand quelqu'un m'a volé\n"
	.string "mon POKéMON ! Qui est le ravisseur\p"
	.string "? L'ÉQUIPE AQUA ? Est-ce TEAM AQUA\n"
	.string "?$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "Mon POKéMON manquant… Il est revenu\n"
	.string "sans que je m'en aperçoive !$"

LilycoveCity_Text_ImArtDealer:
	.string "Je suis marchand d'art. Je suis\n"
	.string "acheteur et vendeur d'objets d'art,\p"
	.string "notamment de peintures. J'ai\n"
	.string "entendu dire que le MUSÉE ici\p"
	.string "expose de magnifiques œuvres…$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "Même si nous vieillissons et\n"
	.string "ridons, la mer reste toujours jeune\p"
	.string "avec l'éclat éclatant de la vie…\n"
	.string "Fwohoho fwohohohoho…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "Il y a soixante ans, mon mari m'a\n"
	.string "proposé ici. La mer reste toujours\p"
	.string "aussi belle. Mufufufu\n"
	.string "mufufufufufu…$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Hm, vous connaissez la caverne\n"
	.string "particulière de cette crique ? Cela\p"
	.string "avait été une formation naturelle,\n"
	.string "mais ensuite le groupe TEAM AQUA\p"
	.string "est arrivé et a fait ses\n"
	.string "rénovations. Ils se font appeler la\p"
	.string "“ TEAM AQUA amoureuse de la nature\n"
	.string "” ! Mais ce qu'ils font et ce\p"
	.string "qu'ils disent ne correspondent pas\n"
	.string "du tout !$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "Cette grotte dans la crique… Je ne\n"
	.string "l'ai pas remarqué tout de suite,\p"
	.string "mais elle est complètement vide\n"
	.string "maintenant. Ces TEAM AQUA, ils ont\p"
	.string "dû partir pour de bon.$"

LilycoveCity_Text_CitySign:
	.string "NENUCRIQUE “ Là où la terre se\n"
	.string "termine et où commence la mer. ”$"

LilycoveCity_Text_ContestHallSign:
	.string "SALLE CONCOURS POKéMON “ Le lieu de\n"
	.string "rassemblement des dresseurs ! ”$"

LilycoveCity_Text_MotelSign:
	.string "COVE LILY MOTEL “ Souviens-toi de\n"
	.string "nous en tant que COVE LILY de\p"
	.string "LILYCOVE. ”$"

LilycoveCity_Text_MuseumSign:
	.string "MUSÉE LILYCOVE “ Collection de\n"
	.string "chefs-d'œuvre POKéMON exposée ! ”$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "LILYCOVE MUSEUM “ La collection\n"
	.string "POKéMON de {PLAYER} exposée ! ” $"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "NENUCRIQUE HARBOUR “ Le ferry S.S.\n"
	.string "TIDAL est en construction à\p"
	.string "POIVRESSEL. “Le service devrait\n"
	.string "commencer sous peu.”$"

LilycoveCity_Text_HarborSign:
	.string "NENUCRIQUE HARBOUR “ Profitez d'une\n"
	.string "charmante croisière sur le ferry\p"
	.string "S.S. TIDAL. ” $"

LilycoveCity_Text_TrainerFanClubSign:
	.string "POKéMON DRESSEUR FAN CLUB Les noms\n"
	.string "des dresseurs sont griffonnés\p"
	.string "partout sur le panneau…$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "GRAND MAGASIN LILYCOVE “ Débordant\n"
	.string "de superbes marchandises et\p"
	.string "d'enthousiasme ! “ Un endroit idéal\n"
	.string "pour trouver ce dont vous avez\p"
	.string "besoin ! ”$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "DÉPLACER LA MAISON DU SUPPRESSEUR “\n"
	.string "Déplacements POKéMON indésirables\p"
	.string "supprimés. ”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "Connaissez-vous la machine BERRY\n"
	.string "BLENDER?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "Les gens doivent travailler\n"
	.string "ensemble pour que tout aille plus\p"
	.string "vite. Plus vous pouvez le faire\n"
	.string "tourner vite, meilleurs sont vos\p"
	.string "{POKEBLOCK}S, j'ai entendu dire.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "Il est utilisé pour fabriquer une\n"
	.string "sorte de bonbon appelé {POKEBLOCK}. Si\p"
	.string "vous donnez un bon {POKEBLOCK} à un\n"
	.string "POKéMON, sa condition s'améliorera\p"
	.string "considérablement.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "J'ai entendu dire qu'il y avait une\n"
	.string "tour quelque part sur les routes\p"
	.string "maritimes. C'est ce qu'on appelle\n"
	.string "le PILIER CELESTE, j'ai entendu\p"
	.string "dire.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "J'ai vu cette haute tour quelque\n"
	.string "part autour de la ROUTE 131.\p"
	.string "Serait-ce possible…?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "Nous venons d'arriver ici pour nos\n"
	.string "vacances de lune de miel. Nous\p"
	.string "avons vu par hasard un POKéMON de\n"
	.string "type DRAGON voler très haut dans le\p"
	.string "ciel. Est-ce que des POKéMON sympas\n"
	.string "comme celui-là vivent dans la\p"
	.string "région HOENN ?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "Lors de notre lune de miel, nous\n"
	.string "avons juré de voir autant de\p"
	.string "POKéMON rares que possible. Nous\n"
	.string "avons donc été ravis de voir un\p"
	.string "POKéMON rare dès notre arrivée. Je\n"
	.string "veux dire, nous sommes totalement\p"
	.string "heureux !$"
