.set LOCALID_GRUNT_1, 1
.set LOCALID_GRUNT_2, 2
.set LOCALID_SHELLY, 3
.set LOCALID_SCIENTIST, 5
.set LOCALID_GRUNT_3, 7
.set LOCALID_GRUNT_4, 8

Route119_WeatherInstitute_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	.byte 0

Route119_WeatherInstitute_2F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
	end

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere::
	setobjectxyperm LOCALID_SCIENTIST, 1, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone::
	setobjectxyperm LOCALID_SCIENTIST, 4, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear::
	setobjectxyperm LOCALID_SCIENTIST, 2, 2
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_UP
	return

Route119_WeatherInstitute_2F_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_5, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_2, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_3, Route119_WeatherInstitute_2F_Text_Grunt3Intro, Route119_WeatherInstitute_2F_Text_Grunt3Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_WEATHER_INSTITUTE, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_EventScript_ShellyDefeated
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_ShellyDefeated::
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_GRUNT_3
	applymovement LOCALID_GRUNT_3, Route119_WeatherInstitute_2F_Movement_GruntApproachShelly
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SHELLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SHELLY, Common_Movement_Delay48
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_SHELLY
	removeobject LOCALID_GRUNT_4
	removeobject LOCALID_GRUNT_3
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_SCIENTIST, Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_SCIENTIST
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastform::
	msgbox Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CASTFORM
	givemon SPECIES_CASTFORM, 25, ITEM_MYSTIC_WATER
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	end

Route119_WeatherInstitute_2F_EventScript_SendCastformToPC::
	call Common_EventScript_TransferredToPC
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM
	return

Route119_WeatherInstitute_2F_EventScript_ExplainCastform::
	msgbox Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_CASTFORM
	release
	end

Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather::
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather::
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather  @ Both defeated
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
	goto_if_eq VAR_RESULT, 1, Route119_WeatherInstitute_2F_EventScript_KyogreWeather
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_KyogreWeather::
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather::
	special CreateAbnormalWeatherEvent
	setflag FLAG_TEMP_2
	return

Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather::
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_Movement_GruntApproachShelly:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_up
	walk_in_place_faster_down
	step_end

Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition:
	slide_down
	walk_in_place_faster_left
	step_end

Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer:
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_WeatherScientist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_Text_Grunt2Intro:
	.string "L'INSTITUT a créé un type de\n"
	.string "POKéMON qui a quelque chose à voir\p"
	.string "avec la météo. Nous sommes là pour\n"
	.string "les prendre !$"

Route119_WeatherInstitute_2F_Text_Grunt2Defeat:
	.string "Notre plan est gâché par un enfant\n"
	.string "?$"

Route119_WeatherInstitute_2F_Text_Grunt2PostBattle:
	.string "Si le POKéMON qu'ils ont créé ici\n"
	.string "peut contrôler librement la météo,\p"
	.string "alors nous, de la TEAM AQUA, en\n"
	.string "avons absolument besoin !$"

Route119_WeatherInstitute_2F_Text_Grunt3Intro:
	.string "Nous sommes l'ÉQUIPE AQUA ! Nous\n"
	.string "apparaissons partout où quelque\p"
	.string "chose de rare est trouvé !$"

Route119_WeatherInstitute_2F_Text_Grunt3Defeat:
	.string "Tu m'as eu !$"

Route119_WeatherInstitute_2F_Text_Grunt3PostBattle:
	.string "Vous n'avez aucune idée de ce vers\n"
	.string "quoi nous, de TEAM AQUA,\p"
	.string "travaillons ! Restez en dehors de\n"
	.string "notre chemin !$"

Route119_WeatherInstitute_2F_Text_Grunt5Intro:
	.string "Ne me dites pas que vous cherchez\n"
	.string "aussi ce POKéMON météo ? C'est un\p"
	.string "non-non ! Nous étions là pour\n"
	.string "l'obtenir en premier !$"

Route119_WeatherInstitute_2F_Text_Grunt5Defeat:
	.string "Oh, tu veux bien regarder mon\n"
	.string "POKéMON ?$"

Route119_WeatherInstitute_2F_Text_Grunt5PostBattle:
	.string "Hum, et alors ? Ce que nous\n"
	.string "voulons… Ce que nous voulons\p"
	.string "vraiment n'est pas là… Ihihihihi…$"

Route119_WeatherInstitute_2F_Text_ShellyIntro:
	.string "Ahahahaha ! Vous allez vous mêler\n"
	.string "des affaires de TEAM AQUA ? Soit\p"
	.string "vous êtes absolument intrépide,\n"
	.string "soit tout simplement ignorant, ou\p"
	.string "les deux ! Tu es si mignon, tu es\n"
	.string "dégoûtant ! Je vais te rabaisser,\p"
	.string "gamin !$"

Route119_WeatherInstitute_2F_Text_ShellyDefeat:
	.string "Ahahahaha ! Tu es incroyablement\n"
	.string "fort !$"

Route119_WeatherInstitute_2F_Text_ShellyPostBattle:
	.string "C'est déjà assez grave que la TEAM\n"
	.string "MAGMA fasse une gaffe, mais\p"
	.string "maintenant vous voilà ! Qu'est-ce\n"
	.string "qui vous donne envie de fouiner\p"
	.string "dans notre métier, de toute façon\n"
	.string "?$"

Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy:
	.string "Nous avons une situation ici ! Une\n"
	.string "foule de TEAM MAGMA vient de passer\p"
	.string "devant le WEATHER INSTITUTE. Ils\n"
	.string "semblent se diriger vers MT. BÛR !$"

Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre:
	.string "Quoi?! On ne peut plus perdre de\n"
	.string "temps ici ! Nous devons nous\p"
	.string "dépêcher vers MT. PYRE aussi !\n"
	.string "Ahahahaha ! TEAM MAGMA, attendez!$"

Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon:
	.string "Merci! Grâce à vous, nous sommes en\n"
	.string "sécurité ! C'est peut-être une\p"
	.string "drôle de façon de vous remercier,\n"
	.string "mais prenez ce POKéMON.$"

@ Unused
Route119_WeatherInstitute_2F_Text_NoRoomForPokemon:
	.string "Hein ? Vous ne semblez pas avoir de\n"
	.string "place pour ce POKéMON.$"

Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform:
	.string "{PLAYER} a reçu CASTFORM ! $"

Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather:
	.string "Ce POKéMON change de forme en\n"
	.string "fonction des conditions\p"
	.string "météorologiques. Il y en a beaucoup\n"
	.string "à l'INSTITUT, allez-y et\p"
	.string "prenez-le.$"

Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous:
	.string "Je fais des recherches sur la pluie\n"
	.string "depuis de nombreuses années, mais\p"
	.string "c'est ridicule de penser que les\n"
	.string "humains peuvent librement modifier\p"
	.string "le temps.$"

Route119_WeatherInstitute_2F_Text_GroudonWeather:
	.string "Je surveille les conditions\n"
	.string "météorologiques dans la région\p"
	.string "HOENN. Actuellement, une sécheresse\n"
	.string "a été enregistrée dans {STR_VAR_1}. Cela\p"
	.string "pourrait-il signifier, quelque part\n"
	.string "près de {STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_KyogreWeather:
	.string "Je surveille les conditions\n"
	.string "météorologiques dans la région\p"
	.string "HOENN. Actuellement, de fortes\n"
	.string "précipitations ont été enregistrées\p"
	.string "sur {STR_VAR_1}. Cela pourrait-il\n"
	.string "signifier, quelque part près de\p"
	.string "{STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_NoAbnormalWeather:
	.string "Les conditions météorologiques\n"
	.string "anormales ne sont plus signalées.\p"
	.string "Les précipitations occasionnelles\n"
	.string "sont vraiment une bénédiction.$"
