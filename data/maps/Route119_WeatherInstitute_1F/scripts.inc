.set LOCALID_LITTLE_BOY, 5

Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "Le BOSS s'est intéressé aux\n"
	.string "recherches qu'ils menaient ici,\p"
	.string "alors il nous a envoyé. Arrêtez de\n"
	.string "vous mêler !$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "Explosé… Explosé par un enfant…$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "Notre BOSS sait tout. Mais je ne\n"
	.string "suis qu'un GRUNT. Que saurais-je de\p"
	.string "ce qu'il pense ?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "Hein? Qu'est-ce qu'un enfant fait\n"
	.string "ici ?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "Hein? J'ai perdu ?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "Oh, non… J'en aurai marre d'avoir\n"
	.string "perdu face à un enfant… Je devrais\p"
	.string "juste faire une sieste dans le\n"
	.string "lit…$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "Pendant que je dormais, tout le\n"
	.string "monde est monté à l'étage !$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "Wow, tu es vraiment fort !\n"
	.string "J'aimerais pouvoir être un DRESSEUR\p"
	.string "DE POKéMON comme toi !$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "Le PROF. aime la pluie. C'est un\n"
	.string "fait. Mais s’il continue de\p"
	.string "pleuvoir, les gens seront en\n"
	.string "difficulté. C'est un autre fait. Et\p"
	.string "ainsi, le PROF. étudie si la pluie\n"
	.string "peut être utilisée à bon escient.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "Au 2ème étage de l'INSTITUT, nous\n"
	.string "étudions les conditions\p"
	.string "météorologiques sur la région\n"
	.string "HOENN. Nous avons remarqué ces\p"
	.string "derniers temps des cas temporaires\n"
	.string "et isolés de sécheresse et de\p"
	.string "fortes pluies…$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "Bonjour! Nous avons été sauvés par\n"
	.string "vos actions ! Ce que je ne\p"
	.string "comprends pas, c'est ce que diable\n"
	.string "faisaient les AQUAS.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "Il y a un lit… Reposons-nous.$"
