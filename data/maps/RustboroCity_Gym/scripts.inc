RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Yo, comment ça va ? Écoute, mon ami\n"
	.string "! Souhaitez-vous devenir CHAMPION ?\p"
	.string "Je ne suis pas un FORMATTHIEUEUR,\n"
	.string "pas moi, mais je peux certainement\p"
	.string "vous donner des conseils gagnants.\n"
	.string "C'est réglé, alors ! Nous viserons\p"
	.string "ensemble le CHAMPIONNAT POKéMON !\n"
	.string "C'est votre travail en tant\p"
	.string "qu'DRESSEUR de collecter des BADGES\n"
	.string "DE GYM, n'est-ce pas ? Mais les GYM\p"
	.string "LEADERS ne sont pas des faciles !\n"
	.string "Et c'est là que j'interviens ! Je\p"
	.string "suis là pour vous donner des\n"
	.string "conseils d'experts ! ROXANNE, la\p"
	.string "GYM LEADER, est une utilisatrice de\n"
	.string "POKéMON de type ROCK. Le type ROCK\p"
	.string "est très résistant, mais il ne\n"
	.string "supporte pas les mouvements de type\p"
	.string "EAU et HERBE. Viens me voir après,\n"
	.string "si tu bats le GYM LEADER. Eh bien,\p"
	.string "foncez !$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Waouh ! Quelle victoire\n"
	.string "époustouflante ! Mes encouragements\p"
	.string "ont dû fonctionner ! Super!\n"
	.string "Vérifiez votre CARTE DE\p"
	.string "FORMATTHIEUEUR. Le BADGE DE PIERRE\n"
	.string "que vous avez obtenu doit être\p"
	.string "correctement enregistré dessus. En\n"
	.string "d'autres termes… Vous avez gravi la\p"
	.string "première marche des escaliers\n"
	.string "menant au CHAMPIONNAT ! Ça doit\p"
	.string "être génial !$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Ne nous prenez pas à la légère les\n"
	.string "GYM DRESSEURS ! Je vais vous\p"
	.string "montrer pourquoi nous sommes\n"
	.string "meilleurs !$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Tu étais trop bien pour moi…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Vous n'avez rien vu de la puissance\n"
	.string "terrifiante du type ROCK !$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Si tu ne peux pas me battre, tu\n"
	.string "n'auras aucune chance contre\p"
	.string "ROXANNE !$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Ouah! Vous avez du potentiel !$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "ROXANNE est plusieurs fois plus\n"
	.string "forte que moi. Tu ferais mieux\p"
	.string "d'être sur tes gardes !$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Nous sommes peut-être au milieu de\n"
	.string "la ville, mais et alors ? Mon\p"
	.string "POKéMON ROCK a besoin d'espace pour\n"
	.string "se déchaîner !$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Oh, mec, oh mec ! Notre challenger\n"
	.string "est un client courageux !$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Je dois le remettre à notre LEADER.\n"
	.string "Il lui a fallu de l'intelligence et\p"
	.string "du bon sens pour choisir le type\n"
	.string "ROCK à son jeune âge.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Bonjour, je suis ROXANNE, la LEADER\n"
	.string "DU POKéMON GYM DE RUSTBORO. Je suis\p"
	.string "devenu GYM LEADER afin de pouvoir\n"
	.string "appliquer au combat ce que j'ai\p"
	.string "appris à l'ÉCOLE DES DRESSEURS DE\n"
	.string "POKéMON. Pourriez-vous gentiment\p"
	.string "nous montrer comment vous combattez\n"
	.string "et avec quel POKéMON ?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Alors… j'ai perdu… Il semble que\n"
	.string "j'ai encore beaucoup à apprendre…\p"
	.string "Je comprends. Les règles de la\n"
	.string "LIGUE POKéMON stipulent que les\p"
	.string "DRESSEURS doivent recevoir cela\n"
	.string "s'ils battent un LEADER DU GYM.\p"
	.string "Veuillez accepter le BADGE DE\n"
	.string "PIERRE officiel DE LA LIGUE\p"
	.string "POKéMON.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} a reçu le BADGE EN PIERRE de\n"
	.string "ROXANNE.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "Le BADGE DE PIERRE augmente la\n"
	.string "puissance d'ATTAQUE de votre\p"
	.string "POKéMON. Cela leur permet également\n"
	.string "d'utiliser le mouvement HM CUT en\p"
	.string "dehors du combat. S'il vous plaît,\n"
	.string "emportez ceci avec vous aussi.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "Cette MACHINE TECHNIQUE, TM39,\n"
	.string "contient un TOMBE ROCK. Non\p"
	.string "seulement cela inflige des dégâts\n"
	.string "en laissant tomber des pierres,\p"
	.string "mais cela réduit également la\n"
	.string "VITESSE. Si vous utilisez une MT,\p"
	.string "elle apprend instantanément à\n"
	.string "passer à un POKéMON. N'oubliez pas\p"
	.string "qu'une MT ne peut être utilisée\n"
	.string "qu'une seule fois, alors\p"
	.string "réfléchissez avant de l'utiliser.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Puisque vous êtes si fort, vous\n"
	.string "devriez défier les autres LEADERS\p"
	.string "DE GYM. En affrontant de nombreux\n"
	.string "FORMATTHIEUEURS, vous devriez\p"
	.string "apprendre beaucoup de choses.$"

RustboroCity_Gym_Text_GymStatue:
	.string "GYM POKéMON DE LA MEROUVILLE$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "DRESSEURS CERTIFIÉS DE ROXANNE\n"
	.string "POKéMON GYM DE MEROUVILLE : {PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … … … … … … … Bip ! ROXANNE\n"
	.string ": Oh, bonjour, {PLAYER} ? Ici ROXANNE\p"
	.string "de MEROUVILLE. BASTIEN m'a dit que\n"
	.string "vous gravissez les échelons des\p"
	.string "FORMATTHIEUEURS à un rythme\n"
	.string "incroyable. Eh bien, je préfère ne\p"
	.string "pas penser que je ne peux pas te\n"
	.string "battre. Je vous le promets,\p"
	.string "j'aménagerai mon GYM pour que vous\n"
	.string "puissiez à nouveau nous défier.\p"
	.string "J'espère que vous attendrez cette\n"
	.string "occasion avec impatience autant que\p"
	.string "moi ! … … … … … … … … … … … Cliquez\n"
	.string "!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "Inscrit GYM LEADER ROXANNE dans le\n"
	.string "POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "ROXANNE : Je suis si heureuse de\n"
	.string "vous revoir. Je m'appelle ROXANNE,\p"
	.string "la GYM LEADER ici. Je suis sûr que\n"
	.string "nous avons tous deux vécu de\p"
	.string "nombreuses batailles depuis notre\n"
	.string "dernière rencontre. J'aimerais voir\p"
	.string "à quel point nous sommes devenus\n"
	.string "meilleurs. Battons-nous !$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr… Encore une fois, j'ai perdu…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "ROXANNE : J'ai encore beaucoup à\n"
	.string "apprendre pour combattre POKéMON.\p"
	.string "Cette prise de conscience me fait\n"
	.string "aimer encore plus me battre !$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE : Je suis si heureuse de\n"
	.string "vous revoir. Je m'appelle ROXANNE,\p"
	.string "la GYM LEADER ici. Je suis sûr que\n"
	.string "nous avons tous deux vécu de\p"
	.string "nombreuses batailles depuis notre\n"
	.string "dernière rencontre. J'aimerais voir\p"
	.string "à quel point nous sommes devenus\n"
	.string "meilleurs… Oh, non… Tu n'as qu'un\p"
	.string "seul POKéMON avec toi ? Veuillez\n"
	.string "revenir avec au moins un POKéMON\p"
	.string "supplémentaire.$"
