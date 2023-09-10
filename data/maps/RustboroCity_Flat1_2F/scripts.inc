.set LOCALID_WALDAS_DAD, 6

RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Oh, c'est si dur chaque jour…\n"
	.string "Qu'est-ce qui est difficile ? Vous\p"
	.string "devez demander ? Il s’agit\n"
	.string "d’essayer de savoir quoi préparer\p"
	.string "pour les repas chaque jour. Ce\n"
	.string "n'est vraiment pas facile de\p"
	.string "préparer des repas tous les jours.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Oh salut! Bienvenue dans la maison\n"
	.string "PEPPER. J'ai une question pour\p"
	.string "vous. Avez-vous déjà fait du\n"
	.string "baby-sitting ? Vous voyez, je suis\p"
	.string "un nouveau père, donc élever un\n"
	.string "enfant est tout nouveau pour moi.\p"
	.string "Et j'ai un problème. Ma fille WALDA\n"
	.string "ne rit pas assez. Je pense qu'elle\p"
	.string "rirait pour moi si je lui disais\n"
	.string "quelque chose de drôle.\p"
	.string "Connaissez-vous un mot ou une\n"
	.string "phrase drôle à me dire ?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "J'ai dit “ {STR_VAR_1} ” pour l'amuser\n"
	.string "ces derniers temps. Connaissez-vous\p"
	.string "un meilleur mot ou une expression\n"
	.string "qui pourrait fonctionner ?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Oh, c'est merveilleux. Alors,\n"
	.string "écoutons votre suggestion.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Ah, c'est vrai ? Eh bien, si vous\n"
	.string "avez une bonne suggestion, je suis\p"
	.string "tout ouïe.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Ah, je vois. Eh bien, essayons,\n"
	.string "d'accord ?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}. {STR_VAR_1}. Oh oui! Elle\n"
	.string "rigole! Oh, je suis aussi ravie\p"
	.string "qu'elle !$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Ah, je vois. Eh bien, essayons,\n"
	.string "d'accord ?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}. {STR_VAR_1}. Hmmm… Elle ne\n"
	.string "sourit pas du tout. Peut-être que\p"
	.string "WALDA est un enfant sérieux…$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Oh, donc tu ne connais pas de bons\n"
	.string "mots. Je ferais mieux de réfléchir\p"
	.string "par moi-même, alors. Hmm… Que\n"
	.string "diriez-vous de “ {STR_VAR_1} ” ? Voyons\p"
	.string "si cela fonctionnera.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}. {STR_VAR_1}. Hmmm… Elle ne\n"
	.string "sourit pas du tout. Peut-être que\p"
	.string "WALDA est un enfant sérieux…$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Oh, donc tu ne connais pas de bons\n"
	.string "mots. Je suppose que je vais\p"
	.string "essayer de l'amuser avec le dicton\n"
	.string "que j'ai utilisé auparavant. Quoi\p"
	.string "qu'il en soit, si vous avez une\n"
	.string "bonne suggestion, n'hésitez pas à\p"
	.string "me la dire, d'accord ?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Merci! Grâce à toi, ma chérie WALDA\n"
	.string "a ri pour moi ! En fait, je n'ai\p"
	.string "peut-être pas l'air si spécial,\n"
	.string "mais je suis l'un des meilleurs\p"
	.string "chercheurs de DEVON CORPORATION.\n"
	.string "Alors, et si je faisais quelque\p"
	.string "chose en échange pour toi ? Je\n"
	.string "sais, je vais ajouter de nouveaux\p"
	.string "motifs de papier peint pour les\n"
	.string "BOÎTES du système de stockage PC\p"
	.string "POKéMON. Dans le menu des motifs de\n"
	.string "papier peint, sélectionnez “ AMIS\p"
	.string "”. Cela vous donnera accès aux\n"
	.string "nouveaux motifs de papier peint.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "C'est une POUPÉE en peluche POKéMON\n"
	.string "!$"
