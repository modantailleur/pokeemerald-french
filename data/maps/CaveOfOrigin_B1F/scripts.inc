.set LOCALID_WALLACE, 1

CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "Ah, alors tu es {PLAYER}{KUN} ? J'ai\n"
	.string "entendu des récits de vos exploits.\p"
	.string "Je m'appelle MARC. J'étais\n"
	.string "autrefois le GYM LEADER de\p"
	.string "SOOTOPOLIS, mais quelque chose\n"
	.string "s'est produit. Alors maintenant,\p"
	.string "j'ai confié à mon mentor JUAN le\n"
	.string "fonctionnement du GYM. … … … … … …\p"
	.string "… … … … … GROUDON et KYOGRE, les\n"
	.string "deux POKéMON qui font des ravages\p"
	.string "ici, sont considérés comme des\n"
	.string "POKéMON super-anciens. Mais il\p"
	.string "n’existe pas seulement deux POKéMON\n"
	.string "super-anciens. Il y en a un de plus\p"
	.string "quelque part. Quelque part, il y a\n"
	.string "un POKéMON super-ancien nommé\p"
	.string "RAYQUAZA. On raconte que c'est\n"
	.string "RAYQUAZA qui a calmé les deux\p"
	.string "combattants dans un passé lointain.\n"
	.string "Mais même moi, je n'ai aucune idée\p"
	.string "de l'endroit où se trouve\n"
	.string "RAYQUAZA…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "MARC : {PLAYER}{KUN}, savez-vous\n"
	.string "peut-être où se trouve RAYQUAZA\p"
	.string "maintenant ? Si c'est le cas,\n"
	.string "dites-le-moi.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "MARC : La GROTTE ORIGINE ? Mais\n"
	.string "c'est ici ! J'ai besoin que tu\p"
	.string "fasses mieux que ça ! S'il vous\n"
	.string "plaît, j'ai besoin que vous\p"
	.string "réfléchissiez à l'endroit où\n"
	.string "RAYQUAZA pourrait se trouver en ce\p"
	.string "moment.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "MARC : MT. PYRE? Mais quand j’y ai\n"
	.string "rencontré la vieille dame plus tôt,\p"
	.string "elle n’en a pas parlé. Je doute\n"
	.string "fort que la vieille dame essaie de\p"
	.string "me cacher quelque chose…\n"
	.string "{PLAYER}{KUN}, pourrais-tu y\p"
	.string "réfléchir plus attentivement pour\n"
	.string "moi ?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "MARC : Hein ? Vous ne vous en\n"
	.string "souvenez pas ? Hmm… C'est un\p"
	.string "problème… Tu ne t'en souviens pas\n"
	.string "d'une manière ou d'une autre ?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "MARC : Le PILIER CELESTE ? C'est\n"
	.string "ça! Ce doit être le PILIER CELESTE\p"
	.string "! {PLAYER}{KUN}, il n'y a pas un\n"
	.string "instant à perdre ! Nous nous\p"
	.string "dirigerons tout de suite vers le\n"
	.string "PILIER CELESTE !$"
