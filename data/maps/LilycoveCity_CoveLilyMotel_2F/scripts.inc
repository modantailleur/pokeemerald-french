LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	waitstate
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "Je suis le GAME DESIGNER. Ah, c'est\n"
	.string "vrai ? Vous travaillez sur un\p"
	.string "POKéDEX ? C'est difficile d'essayer\n"
	.string "de le terminer, mais n'abandonnez\p"
	.string "pas. Si vous le complétez, venez me\n"
	.string "le montrer.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Ouah! C'est génial! Ouais, c'est\n"
	.string "totalement génial ! Ce POKéDEX est\p"
	.string "complètement rempli ! Vous devez\n"
	.string "vraiment aimer POKéMON ! Je suis\p"
	.string "tellement impressionné! Laissez-moi\n"
	.string "vous offrir quelque chose en\p"
	.string "reconnaissance de votre exploit !$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Moi? Tu me parles? Je suis le\n"
	.string "PROGRAMMEUR. Je me demande à quoi\p"
	.string "ressemblent les SLOTS ici.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "Je suis le GRAPHISTE ! Les POKéMON\n"
	.string "de HOENN ne sont-ils pas\p"
	.string "intéressants ?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "La fille TUBERS, elles sont\n"
	.string "mignonnes, hein ? Se battre contre\p"
	.string "un TUBER mignon… Oups, c'est trop\n"
	.string "génial ! Et les JUMEAUX ! Ne\p"
	.string "sont-ils pas mignons ? Une bataille\n"
	.string "2 contre 2 avec TWINS… Oups, c'est\p"
	.string "incroyablement amusant !$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "La brise marine me chatouille le\n"
	.string "cœur. C'est merveilleux ici !$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "Vous ne savez jamais quand et où\n"
	.string "les gens vous défieront. C'est\p"
	.string "pourquoi je ne quitte jamais la\n"
	.string "maison sans ma GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SCOTT : … … … … … … … … … … Zzz… …\n"
	.string "… … … … Hein ?! Oh, désolé, désolé\p"
	.string "! Je dormais ! Je suis venu voir ce\n"
	.string "truc de CONCOURS POKéMON. Je dois\p"
	.string "admettre que cela a l'air assez\n"
	.string "divertissant, mais… Considérez-moi\p"
	.string "comme un puriste : je préfère les\n"
	.string "batailles et les DRESSEURS\p"
	.string "coriaces. Mais c'est juste moi.\n"
	.string "{PLAYER}{KUN}, j'espère que vous\p"
	.string "apprécierez tout comme les SALLES\n"
	.string "DE SPORT, LES CONCOURS, la TENTE DE\p"
	.string "COMBAT, tout le travail !$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT : Je pense qu'il faut de la\n"
	.string "stratégie pour gagner un CONCOURS.\p"
	.string "Concevoir des stratégies de\n"
	.string "CONCOURS est une façon de devenir\p"
	.string "un meilleur FORMATTHIEUEUR, je\n"
	.string "dirais.$"
