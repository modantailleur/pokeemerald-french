.set LOCALID_STAIR_GUARD, 2

RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Bonjour et bienvenue chez DEVON\n"
	.string "CORPORATION. Nous sommes fiers de\p"
	.string "produire des articles et des\n"
	.string "médicaments qui améliorent votre\p"
	.string "vie.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Un de nos chercheurs s'est bêtement\n"
	.string "fait voler un colis important.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Hé, ces CHAUSSURES DE RUNNING !\n"
	.string "C'est un de nos produits ! Cela me\p"
	.string "rend heureux quand je vois\n"
	.string "quelqu'un utiliser quelque chose\p"
	.string "que nous avons fabriqué.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Ce colis volé… Eh bien, bien sûr,\n"
	.string "c'est important, mais ce n'est pas\p"
	.string "quelque chose que n'importe qui\n"
	.string "peut utiliser. À mon avis, ce\p"
	.string "voleur ne devait pas être très\n"
	.string "intelligent.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "On dirait qu'ils ont récupéré les\n"
	.string "DEVON GOODS arrachés.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Je suis désolé, seules les\n"
	.string "personnes autorisées sont\p"
	.string "autorisées à entrer ici.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "C'est plus que stupide. Comment\n"
	.string "pourrions-nous nous faire voler ?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Salut! Vous êtes toujours le\n"
	.string "bienvenu ici !$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Des échantillons de roches et de\n"
	.string "métal sont exposés dans la vitrine.\p"
	.string "Il y a un panneau avec des écrits\n"
	.string "dessus… “ DEVON CORPORATION a fait\p"
	.string "ses débuts en tant que producteur\n"
	.string "de pierres provenant de carrières.\p"
	.string "“ L’entreprise produisait également\n"
	.string "du fer à partir de limaille\p"
	.string "contenue dans le sable. “ À partir\n"
	.string "de ces humbles débuts en tant que\p"
	.string "producteur de matières premières,\n"
	.string "DEVON s'est développé. “ DEVON est\p"
	.string "maintenant un fabricant d'une large\n"
	.string "gamme de produits industriels. ”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "Des prototypes et des produits\n"
	.string "testés remplissent la vitrine en\p"
	.string "verre. Il y a un panneau avec une\n"
	.string "description… “ En plus des produits\p"
	.string "industriels, DEVON commercialise\n"
	.string "désormais des articles divers et\p"
	.string "des produits pharmaceutiques pour\n"
	.string "un meilleur style de vie.\p"
	.string "“Récemment, DEVON a commencé à\n"
	.string "commercialiser des outils pour les\p"
	.string "POKéMON DRESSEURS, notamment les\n"
	.string "systèmes POKé BALLS et POKéNAV.“$"
